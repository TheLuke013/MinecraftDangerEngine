#ifndef MANIFEST_H
#define MANIFEST_H

#include "../Core.h"
#include "../nlohmann/json.hpp"

namespace DE
{
	class DANGER_API Manifest
	{
	private:
		//HEADER
		struct HeaderTemplate
		{
			std::string description = "<DESCRIPTION>";
			std::string name = "<NAME>";
			std::string uuid = "<UUID>";
			std::vector<unsigned int> version = { 1, 0, 0 };
			std::vector<unsigned int> minEngineVersion = { 1, 16, 0 };
		};

		//MODULES
		enum class ModuleType
		{
			NONE,
			RESOURCES,
			DATA,
			WORLD_TEMPLATE,
			SCRIPT
		};

		struct ModuleTemplate
		{
			std::string description = "<DESCRIPTION>";
			ModuleType type = ModuleType::NONE;
			std::string uuid = "<UUID>";
			std::vector<unsigned int> version = { 1, 0, 0 };
		};

		//DEPENDENCIES
		struct DependenciesTemplate
		{
			std::string uuid = "<UUID>";
			std::vector<unsigned int> version = { 1, 0, 0 };
		};

		//METADATA
		struct GeneratedWithTemplate
		{
			std::string generatedWith = "DangerEngine";
			std::vector<std::string> version;
		};

		struct MetadataTemplate
		{
			std::vector<std::string> authors;
			std::string license = "<LICENSE>";
			std::string url = "<URL>";
			GeneratedWithTemplate generatedWith;
		};

	public:
		Manifest(unsigned int formatVersion, const std::string& name, const std::string& description);

		std::string ParseJson();


		/*SETTERS*/


		//HEADER
		unsigned int GetFormatVersion() { return formatVersion; }

		std::string GetHeaderDescription() { return headerData.description; }
		std::string GetHeaderName() { return headerData.name; }
		std::string GetHeaderUuid() { return headerData.uuid; }
		std::vector<unsigned int> GetHeaderVersion() { return headerData.version; }
		std::vector<unsigned int> GetHeaderMinEngineVersion() { return headerData.minEngineVersion; }

		//MODULES
		std::string GetModuleDescription(unsigned int index) { return modules[index].description; }
		ModuleType GetModuleType(unsigned int index) { return modules[index].type; }
		std::string GetModuleUuid(unsigned int index) { return modules[index].uuid; }
		std::vector<unsigned int> GetModuleVersion(unsigned int index) { return modules[index].version; }

		//DEPENDENCIES
		std::string GetDependenciesUuid() { return dependenciesData.uuid; }
		std::vector<unsigned int> GetDependenciesVersion() { return dependenciesData.version; }

		//METADATA
		std::vector<std::string> GetMetadataAuthors() { return metadata.authors; }
		std::string GetMetadataLicense() { return metadata.license; }
		std::string GetMetadataUrl() { return metadata.url; }


		/*SETTERS*/


		//HEADER

		//MODULES

		//DEPENDENCIES

		//METADATA

	private:
		unsigned int formatVersion;

		HeaderTemplate headerData;
		ModuleTemplate mainModule;
		DependenciesTemplate dependenciesData;
		MetadataTemplate metadata;

		std::vector<ModuleTemplate> modules;

		nlohmann::json manifestJson;

	};
}

#endif
