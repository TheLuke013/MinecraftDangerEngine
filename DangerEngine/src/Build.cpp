#include "Build.h"

namespace DE
{
	Build::Build(Addon* addonPtr)
		: addon(addonPtr)
	{
		std::cout << GetMinecraftPath() << "\n";
	}

	void Build::BuildAddon()
	{

	}

	void Build::BuildMcaddon()
	{
	}

	void Build::BuildMcpack()
	{
	}

	std::string Build::GetMinecraftPath()
	{
		std::filesystem::path minecraftPath = "";

		//GETTING Local Appdata
		char* localAppdataDir = nullptr;
		errno_t err = _dupenv_s(&localAppdataDir, 0, "LOCALAPPDATA");

		if (!(err == 0 && localAppdataDir != nullptr))
		{
			std::cerr << "Error: unable to access local appdata!\n";
			return "";
		}

		//GETTING Minecraft package folder
		std::filesystem::path packagesDir = localAppdataDir;
		packagesDir = packagesDir / "Packages";

		std::string keywordDir = "Microsoft.MinecraftUWP";

		//Search for the MinecraftUWP package directory
		for (const auto& entry : std::filesystem::directory_iterator(packagesDir))
		{
			if (std::filesystem::is_directory(entry) && entry.path().filename().string().find(keywordDir) != std::string::npos)
			{
				minecraftPath = entry.path();
				break;
			}
		}

		free(localAppdataDir);

		//Minecraft full path
		minecraftPath = minecraftPath / "LocalState" / "games" / "com.mojang";

		return minecraftPath.string();
	}
}
