#ifndef BUILD_CLASS_H
#define BUILD_CLASS_H

#include "Core.h"
#include "Addon.h"

namespace DE
{
	class Build
	{
	private:
		Addon* addon;

	public:
		Build(Addon* addonPtr);

		void BuildAddon();
		void BuildMcaddon();
		void BuildMcpack();

	private:
		std::string GetMinecraftPath();

	};
}

#endif


