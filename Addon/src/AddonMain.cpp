#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::Addon addon(
		"",
		"<MINECRAFT_PATH>",
		2,
		"MyAddon",
		"An addon made using an amazing tool!",
		ADDON_VERSION,
		"TheLuke013",
		"MIT",
		"https://github.com/TheLuke013/MinecraftDangerEngine.git");

	addon.GetBp()->GetManifest()->AddDependencie(ADDON_VERSION, addon.GetRp()->GetManifest()->GetHeaderUuid());

	DE::Build build(&addon);

	return 0;
}