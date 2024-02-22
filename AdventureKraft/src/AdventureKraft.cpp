#include "DangerEngine.h"

int main()
{
	DE::Manifest manifest(2, "AdventureKraft", "An official port of the AdventureKraft mod for Minecraft Bedrock");

	manifest.SetFormatVersion(3);
	manifest.SetHeaderDescription("new description!");
	manifest.SetHeaderName("new name!");
	manifest.SetHeaderUuid("new uuid!");

	std::cout << manifest.GetFormatVersion() << std::endl;

	std::cout << manifest.GetHeaderDescription() << std::endl;
	std::cout << manifest.GetHeaderName() << std::endl;
	std::cout << manifest.GetHeaderUuid() << std::endl;

	std::cout << manifest.GetModuleDescription(0) << std::endl;
	std::cout << manifest.GetModuleUuid(0) << std::endl;

	std::cout << manifest.GetDependenciesUuid() << std::endl;

	std::cout << manifest.GetMetadataLicense() << std::endl;
	std::cout << manifest.GetMetadataUrl() << std::endl;

	return 0;
}