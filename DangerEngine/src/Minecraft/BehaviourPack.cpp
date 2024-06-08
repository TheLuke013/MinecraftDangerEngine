#include "DangerEngine/Minecraft/BehaviourPack.h"

namespace Minecraft
{
	BehaviourPack::BehaviourPack(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version)
		: manifest(new Manifest(formatVersion, name, description, version))
	{
		manifest->SetModuleType(0, ModuleType::DATA);
	}
}
