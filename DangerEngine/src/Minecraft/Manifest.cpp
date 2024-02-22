#include "Manifest.h"

namespace DE
{
	Manifest::Manifest(unsigned int formatVersion, const std::string& name, const std::string& description)
		: formatVersion(formatVersion)
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

	std::string Manifest::ParseJson()
	{
		manifestJson["format_version"] = formatVersion;
		manifestJson["header"]["description"] = headerData.description;
		manifestJson["header"]["name"] = headerData.name;
		manifestJson["header"]["uuid"] = headerData.uuid;
		manifestJson["header"]["version"] = headerData.version;
		manifestJson["header"]["min_engine_version"] = headerData.minEngineVersion;

		for (int i = 0; i < modules.size(); i++)
		{
			manifestJson["modules"]["description"] = modules[i].description;
			manifestJson["modules"]["type"] = modules[i].type;
			manifestJson["modules"]["uuid"] = modules[i].uuid;
			manifestJson["modules"]["version"] = modules[i].version;
		}

		//TODO: Dependencies and Metadata

		return manifestJson.dump(4);
	}
}