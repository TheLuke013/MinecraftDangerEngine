#include "Addon.h"

namespace DE
{
	Addon::Addon(const std::string& _workspacePath, const std::string& _minecraftPath, unsigned int formatVersion,
		const std::string& name, const std::string& description,
		std::vector<unsigned int> version, const std::string& author, const std::string& license, const std::string& url)
		: workspacePath(_workspacePath), rp(new Minecraft::ResourcePack(formatVersion, name, description, version)), bp(new Minecraft::BehaviourPack(formatVersion, name, description, version)),
		propertiesJson(rapidjson::kObjectType)
	{
		bp->GetManifest()->AddMetadataAuthor(author);
		bp->GetManifest()->SetMetadataLicense(license);
		bp->GetManifest()->SetMetadataUrl(url);

		rp->GetManifest()->AddMetadataAuthor(author);
		rp->GetManifest()->SetMetadataLicense(license);
		rp->GetManifest()->SetMetadataUrl(url);

		properties.name = name;
		properties.minecraftPath = _minecraftPath;
		properties.rpHeaderUUID = rp->GetManifest()->GetHeaderUuid();
		properties.bpHeaderUUID = bp->GetManifest()->GetHeaderUuid();
		properties.rpModuleUUID = rp->GetManifest()->GetModuleUuid(0);
		properties.bpModuleUUID = bp->GetManifest()->GetModuleUuid(0);

		std::cout << GetJsonAddonProperties() << "\n\n";
	}

	std::string Addon::GetJsonAddonProperties()
	{
		rapidjson::Document::AllocatorType& allocator = propertiesJson.GetAllocator();

		JSONUtils::AddStringMember(propertiesJson, "name", properties.name, allocator);
		JSONUtils::AddStringMember(propertiesJson, "minecraft_path", properties.minecraftPath, allocator);
		JSONUtils::AddStringMember(propertiesJson, "resource_header_uuid", properties.rpHeaderUUID, allocator);
		JSONUtils::AddStringMember(propertiesJson, "behaviour_header_uuid", properties.bpHeaderUUID, allocator);
		JSONUtils::AddStringMember(propertiesJson, "resource_module_uuid", properties.rpModuleUUID, allocator);
		JSONUtils::AddStringMember(propertiesJson, "behaviour_module_uuid", properties.bpModuleUUID, allocator);

		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writter(buffer);
		propertiesJson.Accept(writter);

		return buffer.GetString();
	}

	void Addon::SaveAddonPropertiesFile()
	{

	}
}
