#include "Build.h"

namespace DE
{
	Build::Build(Addon* addonPtr)
		: addon(addonPtr), rpPath(""), bpPath("")
	{
	}

	void Build::BuildAddon(BuildMode buildMode)
	{
		LOG_TRACE("Initializing Building...");
		LOG_TRACE("Building " + addon->GetProperties()->name);

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
			LOG_TRACE("Created the Resource Pack Manifest");
			
			JSONUtils::SaveJsonFile(bpPath / "manifest.json", addon->GetBp()->GetManifest()->JsonParse());
			LOG_TRACE("Created the Behaviour Pack Manifest");

			//Copy pack_icon
			try
			{
				std::filesystem::copy_file(addon->GetWorkspacePath() / PICON_NAME, rpPath / PICON_NAME, std::filesystem::copy_options::overwrite_existing);
				LOG_TRACE("Copied pack_icon.png to Resource Pack folder");

				std::filesystem::copy_file(addon->GetWorkspacePath() / PICON_NAME, bpPath / PICON_NAME, std::filesystem::copy_options::overwrite_existing);
				LOG_TRACE("Copied pack_icon.png to Behaviour Pack folder");
			}
			catch (const std::filesystem::filesystem_error& e) 
			{
				std::string err = e.what();
				LOG_CRITICAL("Error: unable to copy pack_icon file: " + err);
			}
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::string err = e.what();
			LOG_CRITICAL("Error: unable to create addon folder: " + err);
		}
	}
}
