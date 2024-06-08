#ifndef SOUNDS_H
#define SOUNDS_H

#include "DangerEngine/JSON.h"
#include "DangerEngine/Minecraft/Sound.h"

namespace Minecraft
{
	class Sounds
	{
	public:
		Sounds();
		~Sounds();

		void AddSound(Sound* sound);
		std::string JsonParse();

	private:
		rapidjson::Document* soundsJson;
		rapidjson::Document::AllocatorType& allocator;
		rapidjson::Value entitySounds;
		rapidjson::Value entities;
	};
}

#endif
