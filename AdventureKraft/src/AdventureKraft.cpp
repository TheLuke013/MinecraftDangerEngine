#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::Manifest manifest(2, "AdventureKraft", "An official port of the AdventureKraft mod for Minecraft Bedrock");

	manifest.AddModule(ADDON_VERSION, "uuid", "description", DE::ModuleType::SCRIPT);
	manifest.AddDependencie(ADDON_VERSION, "uuid");

	std::cout << manifest.JsonParse() << "\n\n";

	DE::Lang langs;
	langs.AddLanguage(DE::Languages::pt_BR);
	langs.AddLanguage(DE::Languages::en_US);
	langs.AddLanguage(DE::Languages::es_ES);

	std::cout << langs.JsonParse();

	return 0;
}