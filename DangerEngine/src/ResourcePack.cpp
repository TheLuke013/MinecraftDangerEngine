#include "ResourcePack.h"

namespace DE
{
	ResourcePack::ResourcePack(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version)
		: manifest(new Manifest(formatVersion, name, description, version))
	{
		manifest->SetModuleType(0, ModuleType::RESOURCES);
	}
}
