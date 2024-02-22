#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::Manifest manifest(2, "AdventureKraft", "An official port of the AdventureKraft mod for Minecraft Bedrock");

	manifest.AddModule(ADDON_VERSION, "uuid", "description", DE::ModuleType::SCRIPT);
	manifest.AddDependencie(ADDON_VERSION, "uuid");

	std::cout << manifest.JsonParse();

	return 0;
}