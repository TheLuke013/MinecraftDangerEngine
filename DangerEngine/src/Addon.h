#ifndef ADDON_CLASS_H
#define ADDON_CLASS_H

#include "Minecraft/ResourcePack.h"
#include "Minecraft/BehaviourPack.h"

namespace DE
{
	class Addon
	{
	private:
		struct AddonProperties
		{
			std::string name, minecraftPath;
			std::string rpHeaderUUID, bpHeaderUUID, rpModuleUUID, bpModuleUUID;
		};

		std::filesystem::path* workspacePath;

		Minecraft::ResourcePack* rp;
		Minecraft::BehaviourPack* bp;

		AddonProperties* properties;

		rapidjson::Document* propertiesJson;

	public:
		Addon(const std::string& _workspacePath, unsigned int formatVersion, const std::string& name,
			const std::string& description, std::vector<unsigned int> version,
			const std::string& author, const std::string& license, const std::string& url);
		~Addon();

		Minecraft::ResourcePack* GetRp() { return rp; };
		Minecraft::BehaviourPack* GetBp() { return bp; };

		AddonProperties* GetProperties() { return properties; };
		std::filesystem::path GetWorkspacePath() { return *workspacePath; };

	private:
		std::string GetJsonAddonProperties();
		void CheckAddonProperties();
		void LoadAddonPropertiesFromFile(std::ifstream& propertiesFile);
		void SetAddonUUIDProperties();
		void SetAddonPropertiesFromJson(const std::string& jsonContent);

		std::string GetMinecraftPath();

	};
}

#endif


