#ifndef ADDON_CLASS_H
#define ADDON_CLASS_H

#include "Core.h"

#include "Minecraft/ResourcePack.h"
#include "Minecraft/BehaviourPack.h"

namespace DE
{
	class DANGER_API Addon
	{
	private:
		ResourcePack* rp;
		BehaviourPack* bp;

	public:
		Addon(unsigned int formatVersion, const std::string& name,
			const std::string& description, std::vector<unsigned int> version,
			const std::string& author, const std::string& license, const std::string& url);

		ResourcePack* GetBp() { return rp; };
		BehaviourPack* GetRp() { return bp; };

	};
}

#endif


