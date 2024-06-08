#ifndef RESOURCE_PACK_H
#define RESOURCE_PACK_H

#include "DangerEngine/Minecraft/Manifest.h"
#include "DangerEngine/Minecraft/Lang.h"

namespace Minecraft
{
	class ResourcePack
	{
	public:
		ResourcePack(unsigned int formatVersion, const std::string& name, const std::string& description, std::vector<unsigned int> version);
		~ResourcePack();

		Manifest* GetManifest() const { return manifest; }

	private:
		Manifest* manifest;

	};
}

#endif
