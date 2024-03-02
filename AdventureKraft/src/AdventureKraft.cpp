#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::Addon addon(
		2,
		"AdventureKraft",
		"An official port of the AdventureKraft mod for Minecraft Bedrock",
		ADDON_VERSION,
		"TheLuke013",
		"MIT",
		"https://youtube.com/@TheLuke013?si=bX8nObGICp4SdhKN");

	std::cout << addon.GetBp()->GetManifest()->JsonParse() << "\n\n";

	std::cout << addon.GetRp()->GetManifest()->JsonParse() << "\n\n";

	return 0;
}