#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::ResourcePack rp(2, "AdventureKraft RP", "An official port of the AdventureKraft mod for Minecraft Bedrock", ADDON_VERSION);
	DE::BehaviourPack bp(2, "AdventureKraft BP", "An official port of the AdventureKraft mod for Minecraft Bedrock", ADDON_VERSION);

	std::cout << bp.GetManifest()->JsonParse() << "\n\n";

	std::cout << rp.GetManifest()->JsonParse() << "\n\n";

	return 0;
}