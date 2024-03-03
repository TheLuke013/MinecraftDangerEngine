#ifndef MANIFEST_H
#define MANIFEST_H

#include "Core.h"
#include "UUID.h"
#include "JSON.h"

namespace Minecraft
{
	enum class ModuleType
	{
		NONE,
		RESOURCES,
		DATA,
		WORLD_TEMPLATE,
		SCRIPT
	};

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
		struct MetadataTemplate
		{
			std::vector<std::string> authors;
			std::string license = "<LICENSE>";
			std::string url = "<URL>";
			std::vector<std::string> version = { "1.0.0" };
		};

	public:
		Manifest(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version);

		void AddModule(std::vector<unsigned int> version, const std::string& uuid, const std::string& description, ModuleType type);
		void AddDependencie(std::vector<unsigned int> version, const std::string& uuid);
		std::string JsonParse();


		/*GETTERS*/


		//HEADER
		inline unsigned int GetFormatVersion() { return formatVersion; }

		inline std::string GetHeaderDescription() const { return headerData.description; }
		inline std::string GetHeaderName() const { return headerData.name; }
		inline std::string GetHeaderUuid() const { return headerData.uuid; }
		inline std::vector<unsigned int> GetHeaderVersion() const { return headerData.version; }
		inline std::vector<unsigned int> GetHeaderMinEngineVersion() const { return headerData.minEngineVersion; }

		//MODULES
		inline std::string GetModuleDescription(unsigned int index) const { return modulesVec[index].description; }
		inline ModuleType GetModuleType(unsigned int index) const { return modulesVec[index].type; }
		inline std::string GetModuleUuid(unsigned int index) const { return modulesVec[index].uuid; }
		inline std::vector<unsigned int> GetModuleVersion(unsigned int index) const { return modulesVec[index].version; }

		//DEPENDENCIES
		inline std::string GetDependenciesUuid() const { return dependenciesData.uuid; }
		inline std::vector<unsigned int> GetDependenciesVersion() const { return dependenciesData.version; }

		//METADATA
		inline std::vector<std::string> GetMetadataAuthors() const { return metadataData.authors; }
		inline std::string GetMetadataLicense() const { return metadataData.license; }
		inline std::string GetMetadataUrl() const { return metadataData.url; }


		/*SETTERS*/


		//HEADER
		inline void SetFormatVersion(unsigned int p_formatVersion) { formatVersion = p_formatVersion; }

		inline void SetHeaderDescription(const std::string& newDescription) { headerData.description = newDescription; }
		inline void SetHeaderName(const std::string& newName) { headerData.name = newName; }
		inline void SetHeaderUuid(const std::string& newUuid) { headerData.uuid = newUuid; }
		inline void SetHeaderVersion(std::vector<unsigned int> newVersion) { headerData.version = newVersion; }
		inline void SetHeaderMinEngineVersion(std::vector<unsigned int> newEngineVersion) { headerData.minEngineVersion = newEngineVersion; }

		//MODULES
		inline void SetModuleDescription(unsigned int index, const std::string& newDescription) { modulesVec[index].description = newDescription; }
		inline void SetModuleType(unsigned int index, ModuleType newType) { modulesVec[index].type = newType; }
		inline void SetModuleUuid(unsigned int index, const std::string& newUuid) { modulesVec[index].uuid = newUuid; }
		inline void SetModuleVersion(unsigned int index, std::vector<unsigned int> newVersion) { modulesVec[index].version = newVersion; }

		//DEPENDENCIES
		inline void SetDependenciesUuid(const std::string& newUuid) { dependenciesData.uuid = newUuid; }
		inline void SetDependenciesVersion(std::vector<unsigned int> newVersion) { dependenciesData.version = newVersion; }

		//METADATA
		inline void SetMetadataAuthors(std::vector<std::string> newMetadataAuthors) { metadataData.authors = newMetadataAuthors; }
		inline void SetMetadataLicense(const std::string& newLicense) { metadataData.license = newLicense; }
		inline void SetMetadataUrl(const std::string& newUrl) { metadataData.url = newUrl; }

		inline void AddMetadataAuthor(const std::string& newAuthor) { metadataData.authors.push_back(newAuthor); }

	private:
		unsigned int formatVersion;

		bool hasDependencie;

		DE::UUID uuid;

		HeaderTemplate headerData;
		ModuleTemplate mainModule;
		DependenciesTemplate dependenciesData;
		MetadataTemplate metadataData;

		std::vector<ModuleTemplate> modulesVec;

		rapidjson::Document manifestJson;

		std::vector<std::string> moduleTypeString = {
			"resources",
			"data",
			"world_template",
			"script"
		};

	};
}

#endif
