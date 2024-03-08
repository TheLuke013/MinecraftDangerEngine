#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	std::vector<unsigned int> addonVersion = { 1, 0, 0 };

	DE::Addon addon(
		"",
		"<MINECRAFT_PATH>",
		2,
		"Example Addon",
		"An addon made using an amazing tool!",
		ADDON_VERSION,
		"TheLuke013",
		"MIT",
		"https://youtube.com/@TheLuke013?si=bX8nObGICp4SdhKN");

	addon.GetBp()->GetManifest()->AddDependencie(addonVersion, addon.GetRp()->GetManifest()->GetHeaderUuid());

	std::cout << addon.GetBp()->GetManifest()->JsonParse() << "\n\n";
	std::cout << addon.GetRp()->GetManifest()->JsonParse() << "\n\n";

	return 0;
}