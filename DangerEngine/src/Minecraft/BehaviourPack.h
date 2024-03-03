#ifndef BEHAVIOUR_PACK_H
#define BEHAVIOUR_PACK_H

#include "Core.h"

#include "Minecraft/Manifest.h"
#include "Minecraft/Lang.h"

namespace DE
{
	class DANGER_API BehaviourPack
	{
	private:
		Manifest* manifest;

	public:
		BehaviourPack(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version);

		Manifest* GetManifest() const { return manifest; }

	};
}

#endif