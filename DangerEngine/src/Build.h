#ifndef BUILD_CLASS_H
#define BUILD_CLASS_H

#include "Core.h"
#include "Addon.h"

#define RP_WS_NAME "\\build\\RP"
#define BP_WS_NAME "\\build\\BP"

#define RP_MC_NAME "\\development_resource_packs"
#define BP_MC_NAME "\\development_behavior_packs"

namespace DE
{
	enum class BuildMode
	{
		BUILD_IN_WORKSPACE,
		BUILD_IN_MC_PATH
	};

	class Build
	{
	private:
		Addon* addon;

		std::filesystem::path rpPath;
		std::filesystem::path bpPath;

	public:
		Build(Addon* addonPtr);

		void BuildAddon(BuildMode buildMode);
		void BuildMcaddon();
		void BuildMcpack();

	private:
		void CreateAddonFolders(const std::filesystem::path& rpFolderName, const std::filesystem::path& bpFolderName);

	};
}

#endif


