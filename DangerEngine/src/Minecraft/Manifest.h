#ifndef MANIFEST_H
#define MANIFEST_H

#include "../Core.h"
#include "../nlohmann/json.hpp"

namespace DE
{
	//HEADER
	struct HeaderTemplate
	{
		std::string description;
		std::string name;
		std::string uuid;
		unsigned int version[4];
		unsigned int minEngineVersion[4];
	};

	//MODULES
	struct ModuleTemplate
	{
		std::string description;
		ModulesType type;
		std::string uuid;
		unsigned int version[4];
	};

	enum class ModuleType
	{
		RESOURCES = "resources",
		DATA = "data",
		WORLD_TEMPLATE = "world_template",
		SCRIPT = "script"
	};

	//DEPENDENCIES
	struct DependenciesTemplate
	{
		std::string uuid;
		unsigned int version[4];
	};

	//METADATA
	struct MetadataTemplate
	{
		std::vector<std::string> authors;
		std::string license;
		std::string url;
		GeneratedWithTemplate generatedWith;
	};

	struct GeneratedWithTemplate
	{
		std::string generatedWith;
		std::vector<std::string> version;
	};

	class DANGER_API Manifest
	{
	private:
		unsigned int formatVersion;

		HeaderTemplate headerData;
		ModuleTemplate mainModule;

		std::vector<ModuleTemplate> modules;

	public:

	};
}

#endif
