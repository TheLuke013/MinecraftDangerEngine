#include "Manifest.h"

namespace DE
{
	Manifest::Manifest(unsigned int formatVersion, const std::string& name, const std::string& description)
		: formatVersion(formatVersion), hasDependencie(false)
	{
		//HEADER
		headerData.name = name;
		headerData.description = description;
		headerData.uuid = "";

		//MAIN MODULE
		mainModule.description = description;
		mainModule.type = ModuleType::NONE;
		mainModule.uuid = "";

		modules.push_back(mainModule);
	}

	void Manifest::AddModule(std::vector<unsigned int> version, const std::string& uuid, const std::string& description, ModuleType type)
	{
		ModuleTemplate newModule;
		newModule.description = description;
		newModule.type = type;
		newModule.uuid = uuid;
		newModule.version = version;

		modules.push_back(newModule);
	}

	void Manifest::AddDependencie(std::vector<unsigned int> version, const std::string& uuid)
	{
		dependenciesData.uuid = uuid;
		dependenciesData.version = version;

		hasDependencie = true;
	}

	std::string Manifest::JsonParse()
	{
		manifestJson["format_version"] = formatVersion;
		manifestJson["header"]["description"] = headerData.description;
		manifestJson["header"]["name"] = headerData.name;
		manifestJson["header"]["uuid"] = headerData.uuid;
		manifestJson["header"]["version"] = headerData.version;
		manifestJson["header"]["min_engine_version"] = headerData.minEngineVersion;

		for (int i = 0; i < modules.size(); i++)
		{
			manifestJson["modules"][i]["description"] = modules[i].description;
			manifestJson["modules"][i]["type"] = modules[i].type;
			manifestJson["modules"][i]["uuid"] = modules[i].uuid;
			manifestJson["modules"][i]["version"] = modules[i].version;
		}

		if (hasDependencie)
		{
			manifestJson["dependencies"][0]["uuid"] = dependenciesData.uuid;
			manifestJson["dependencies"][0]["version"] = dependenciesData.version;
		}

		manifestJson["metadata"]["authors"] = metadata.authors;
		manifestJson["metadata"]["license"] = metadata.license;
		manifestJson["metadata"]["url"] = metadata.url;
		manifestJson["metadata"]["generated_with"]["DangerEngine"][0] = "1.0.0";

		return manifestJson.dump(DANGER_INDENT);
	}
}