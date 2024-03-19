#include "Build.h"

namespace DE
{
	Build::Build(Addon* addonPtr)
		: addon(addonPtr), rpPath(""), bpPath("")
	{
	}

	void Build::BuildAddon(BuildMode buildMode)
	{
		switch (buildMode)
		{
		case DE::BuildMode::BUILD_IN_WORKSPACE:
		{
			rpPath = addon->GetWorkspacePath().string() + RP_WS_NAME;
			bpPath = addon->GetWorkspacePath().string() + BP_WS_NAME;

			CreateAddonFolders(rpPath, bpPath);
			break;
		}
		case DE::BuildMode::BUILD_IN_MC_PATH:
		{
			rpPath = addon->GetProperties().minecraftPath + RP_MC_NAME;
			bpPath = addon->GetProperties().minecraftPath + BP_MC_NAME;

			CreateAddonFolders(rpPath, bpPath);
			break;
		}
		default:
			break;
		}
	}

	void Build::BuildMcaddon()
	{
	}

	void Build::BuildMcpack()
	{
	}

	void Build::CreateAddonFolders(const std::filesystem::path& rpFolderName, const std::filesystem::path& bpFolderName)
	{
		rpPath = rpFolderName / addon->GetProperties().name;
		bpPath = bpFolderName / addon->GetProperties().name;

		try
		{
			std::filesystem::create_directories(rpPath);
			std::filesystem::create_directories(bpPath);
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cerr << "Error: unable to create directory: " << e.what() << std::endl;
		}
	}
}
