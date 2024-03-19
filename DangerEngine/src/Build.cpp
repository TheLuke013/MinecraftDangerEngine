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
			rpPath = addon->GetProperties()->minecraftPath + RP_MC_NAME;
			bpPath = addon->GetProperties()->minecraftPath + BP_MC_NAME;

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
		rpPath = rpFolderName / addon->GetProperties()->name;
		bpPath = bpFolderName / addon->GetProperties()->name;

		try
		{
			//Creates BP & RP folders
			std::filesystem::create_directories(rpPath);
			std::filesystem::create_directories(bpPath);

			//Creates all manifests
			JSONUtils::SaveJsonFile(rpPath / "manifest.json", addon->GetRp()->GetManifest()->JsonParse());
			JSONUtils::SaveJsonFile(bpPath / "manifest.json", addon->GetBp()->GetManifest()->JsonParse());

			//Copy pack_icon
			try {
				std::filesystem::copy_file(addon->GetWorkspacePath() / PICON_NAME, rpPath / PICON_NAME, std::filesystem::copy_options::overwrite_existing);
				std::filesystem::copy_file(addon->GetWorkspacePath() / PICON_NAME, bpPath / PICON_NAME, std::filesystem::copy_options::overwrite_existing);
			}
			catch (const std::filesystem::filesystem_error& e) {
				std::cerr << "Error: unable to copy pack_icon file: " << e.what() << std::endl;
			}
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cerr << "Error: unable to create addon folder: " << e.what() << std::endl;
		}
	}
}
