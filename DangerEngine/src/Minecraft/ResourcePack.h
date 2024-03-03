#ifndef RESOURCE_PACK_H
#define RESOURCE_PACK_H

#include "Core.h"

#include "Minecraft/Manifest.h"
#include "Minecraft/Lang.h"

namespace Minecraft
{
	class DANGER_API ResourcePack
	{
	private:
		Manifest* manifest;

	public:
		ResourcePack(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version);

		Manifest* GetManifest() const { return manifest; }

	};
}

#endif
