#ifndef BEHAVIOUR_PACK_H
#define BEHAVIOUR_PACK_H

#include "DangerEngine/Minecraft/Manifest.h"
#include "DangerEngine/Minecraft/Lang.h"

namespace Minecraft
{
	class BehaviourPack
	{
	public:
		BehaviourPack(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version);
		~BehaviourPack();

		Manifest* GetManifest() const { return manifest; }

	private:
		Manifest* manifest;
	};
}

#endif
