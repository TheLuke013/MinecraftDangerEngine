#include "Addon.h"

namespace DE
{
	Addon::Addon(const std::string& _workspacePath, unsigned int formatVersion,
		const std::string& name, const std::string& description,
		std::vector<unsigned int> version, const std::string& author, const std::string& license, const std::string& url)
		: workspacePath(new std::filesystem::path(_workspacePath)), rp(new Minecraft::ResourcePack(formatVersion, name, description, version)), bp(new Minecraft::BehaviourPack(formatVersion, name, description, version)),
		propertiesJson(new rapidjson::Document(rapidjson::kObjectType)), properties(new AddonProperties())
	{
		bp->GetManifest()->AddMetadataAuthor(author);
		bp->GetManifest()->SetMetadataLicense(license);
		bp->GetManifest()->SetMetadataUrl(url);

		rp->GetManifest()->AddMetadataAuthor(author);
		rp->GetManifest()->SetMetadataLicense(license);
		rp->GetManifest()->SetMetadataUrl(url);

		properties->name = name;

		CheckAddonProperties();
	}

	Addon::~Addon()
	{
		delete rp;
		delete bp;
		delete propertiesJson;
	}

	std::string Addon::GetJsonAddonProperties()
	{
		rapidjson::Document::AllocatorType& allocator = propertiesJson->GetAllocator();

		JSONUtils::AddStringMember(*propertiesJson, "name",						properties->name,		   allocator);
		JSONUtils::AddStringMember(*propertiesJson, "minecraft_path",			properties->minecraftPath, allocator);
		JSONUtils::AddStringMember(*propertiesJson, "resource_header_uuid",		properties->rpHeaderUUID,  allocator);
		JSONUtils::AddStringMember(*propertiesJson, "behaviour_header_uuid",	properties->bpHeaderUUID,  allocator);
		JSONUtils::AddStringMember(*propertiesJson, "resource_module_uuid",		properties->rpModuleUUID,  allocator);
		JSONUtils::AddStringMember(*propertiesJson, "behaviour_module_uuid",	properties->bpModuleUUID,  allocator);

		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writter(buffer);
		propertiesJson->Accept(writter);

		return buffer.GetString();
	}

	void Addon::CheckAddonProperties()
	{
		std::string fileName = properties->name + ".json";
		std::filesystem::path path = *workspacePath / fileName;

		std::ifstream propertiesFile(path);

		if (!propertiesFile.good())
		{
			properties->minecraftPath = GetMinecraftPath();
			SetAddonUUIDProperties();
			JSONUtils::SaveJsonFile(path, GetJsonAddonProperties());
		}
		else
		{
			LoadAddonPropertiesFromFile(propertiesFile);
		}
	}

	void Addon::LoadAddonPropertiesFromFile(std::ifstream& propertiesFile)
	{
		std::string fileContent;

		//LOAD THE FILE
		if (propertiesFile.is_open())
		{
			std::string line;
			while (std::getline(propertiesFile, line))
			{
				fileContent += line + "\n";
			}
			propertiesFile.close();
		}

		SetAddonPropertiesFromJson(fileContent);

		rp->GetManifest()->SetHeaderUuid(properties->rpHeaderUUID);
		bp->GetManifest()->SetHeaderUuid(properties->bpHeaderUUID);

		rp->GetManifest()->SetModuleUuid(0, properties->rpModuleUUID);
		bp->GetManifest()->SetModuleUuid(0, properties->bpModuleUUID);
	}

	void Addon::SetAddonUUIDProperties()
	{
		properties->rpHeaderUUID = rp->GetManifest()->GetHeaderUuid();
		properties->bpHeaderUUID = bp->GetManifest()->GetHeaderUuid();
		properties->rpModuleUUID = rp->GetManifest()->GetModuleUuid(0);
		properties->bpModuleUUID = bp->GetManifest()->GetModuleUuid(0);
	}

	void Addon::SetAddonPropertiesFromJson(const std::string& jsonContent)
	{
		rapidjson::Document propertiesJson;
		propertiesJson.Parse(jsonContent.c_str());

		properties->name = propertiesJson["name"].GetString();
		properties->minecraftPath = propertiesJson["minecraft_path"].GetString();
		properties->rpHeaderUUID = propertiesJson["resource_header_uuid"].GetString();
		properties->bpHeaderUUID = propertiesJson["behaviour_header_uuid"].GetString();
		properties->rpModuleUUID = propertiesJson["resource_module_uuid"].GetString();
		properties->bpModuleUUID = propertiesJson["behaviour_module_uuid"].GetString();
	}

	std::string Addon::GetMinecraftPath()
	{
		std::filesystem::path minecraftPath = "";

		//GETTING Local Appdata
		char* localAppdataDir = nullptr;
		errno_t err = _dupenv_s(&localAppdataDir, 0, "LOCALAPPDATA");

		if (!(err == 0 && localAppdataDir != nullptr))
		{
			std::cerr << "Error: unable to access local appdata!\n";
			return "";
		}

		//GETTING Minecraft package folder
		std::filesystem::path packagesDir = localAppdataDir;
		packagesDir = packagesDir / "Packages";

		std::string keywordDir = "Microsoft.MinecraftUWP";

		//Search for the MinecraftUWP package directory
		for (const auto& entry : std::filesystem::directory_iterator(packagesDir))
		{
			if (std::filesystem::is_directory(entry) && entry.path().filename().string().find(keywordDir) != std::string::npos)
			{
				minecraftPath = entry.path();
				break;
			}
		}

		free(localAppdataDir);

		//Minecraft full path
		minecraftPath = minecraftPath / "LocalState" / "games" / "com.mojang";

		return minecraftPath.string();
	}
}
