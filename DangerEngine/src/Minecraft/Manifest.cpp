#include "Manifest.h"

namespace DE
{
	Manifest::Manifest(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version)
		: formatVersion(formatVersion), hasDependencie(false), manifestJson(rapidjson::kObjectType)
	{
		//HEADER
		headerData.name = name;
		headerData.description = description;
		headerData.uuid = uuid.GenerateUUIDV4();
		headerData.version = version;

		//MAIN MODULE
		mainModule.description = description;
		mainModule.type = ModuleType::NONE;
		mainModule.uuid = uuid.GenerateUUIDV4();
		mainModule.version = version;

		modulesVec.push_back(mainModule);
	}

	void Manifest::AddModule(std::vector<unsigned int> version, const std::string& uuid, const std::string& description, ModuleType type)
	{
		ModuleTemplate newModule;
		newModule.description = description;
		newModule.type = type;
		newModule.uuid = uuid;
		newModule.version = version;

		modulesVec.push_back(newModule);
	}

	void Manifest::AddDependencie(std::vector<unsigned int> version, const std::string& uuid)
	{
		dependenciesData.uuid = uuid;
		dependenciesData.version = version;

		hasDependencie = true;
	}

	std::string Manifest::JsonParse()
	{
		rapidjson::Document::AllocatorType& allocator = manifestJson.GetAllocator();

		manifestJson.AddMember("format_version", formatVersion, allocator);

		//HEADER
		rapidjson::Value header(rapidjson::kObjectType);
		AddStringMember(header, "description", headerData.description, allocator);
		AddStringMember(header, "name", headerData.name, allocator);
		AddStringMember(header, "uuid", headerData.uuid, allocator);
		AddUIntVectorMember("version", headerData.version, header, allocator);
		AddUIntVectorMember("min_engine_version", headerData.minEngineVersion, header, allocator);

		manifestJson.AddMember("header", header, allocator);

		//MODULES
		rapidjson::Value modules(rapidjson::kArrayType);

		for (int i = 0; i < modulesVec.size(); i++)
		{
			rapidjson::Value _module(rapidjson::kObjectType);
			AddStringMember(_module, "description", modulesVec[i].description, allocator);
		
			//TYPE
			switch (modulesVec[i].type)
			{
			case ModuleType::RESOURCES:
				AddStringMember(_module, "type", moduleTypeString[0], allocator);
				break;
			case ModuleType::DATA:
				AddStringMember(_module, "type", moduleTypeString[1], allocator);
				break;
			case ModuleType::WORLD_TEMPLATE:
				AddStringMember(_module, "type", moduleTypeString[2], allocator);
				break;
			case ModuleType::SCRIPT:
				AddStringMember(_module, "type", moduleTypeString[3], allocator);
				break;
			}
			
			AddStringMember(_module, "uuid", modulesVec[i].uuid, allocator);
			AddUIntVectorMember("version", modulesVec[i].version, _module, allocator);

			modules.PushBack(_module, allocator);
		}

		manifestJson.AddMember("modules", modules, allocator);

		//DEPENDENCIES
		if (hasDependencie)
		{
			rapidjson::Value dependencies(rapidjson::kArrayType);

			rapidjson::Value dependencie(rapidjson::kObjectType);
			AddStringMember(dependencie, "uuid", dependenciesData.uuid, allocator);
			AddUIntVectorMember("version", dependenciesData.version, dependencie, allocator);
			dependencies.PushBack(dependencie, allocator);

			manifestJson.AddMember("dependencies", dependencies, allocator);
		}

		//METADATA
		rapidjson::Value metadata(rapidjson::kObjectType);
		AddStringVectorMember("authors", metadataData.authors, metadata, allocator);
		AddStringMember(metadata, "license", metadataData.license, allocator);
		AddStringMember(metadata, "url", metadataData.url, allocator);

		//METADATA - GENERATED_WITH
		rapidjson::Value generatedW(rapidjson::kObjectType);
		AddStringVectorMember("DangerEngine", metadataData.version, generatedW, allocator);
		metadata.AddMember("generated_with", generatedW, allocator);

		manifestJson.AddMember("metadata", metadata, allocator);

		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writter(buffer);
		manifestJson.Accept(writter);

		return buffer.GetString();
	}

	void Manifest::AddStringMember(rapidjson::Value& member, const char* key, const std::string& value, rapidjson::Document::AllocatorType& allocator)
	{
		rapidjson::Value v;
		v.SetString(value.c_str(), value.size(), allocator);
		member.AddMember(rapidjson::StringRef(key), v, allocator);
	}
}