#ifndef SOUND_H
#define SOUND_H

#include "DangerEngine/JSON.h"

namespace Minecraft
{
	enum SoundEventType
	{
		ambient,
		hurt,
		death,
		step,
		fall_big,
		fall_small,
		splash,
		attack,
		shoot,
		cast_spell,
		prepare_attack,
		roar
	};

	struct SoundProperties
	{
		unsigned int volume = 1;
		std::vector<float> pitch = { 1.0f, 1.0f };
	};

	struct SoundEvent
	{
		SoundEventType eventType;
		std::string sound = "<SOUND>";
		SoundProperties properties;
	};

	class Sound
	{
	public:
		Sound(const std::string& pNamespace, unsigned int volume, std::vector<float> pitch);
		~Sound();

		void AddSoundEvent
		(
			SoundEventType eventType,
			const std::string& sound,
			unsigned int volume = 1,
			std::vector<float> pitch = { 1.0f, 1.0f }
		);

		rapidjson::Value& GetSoundJson(rapidjson::Document::AllocatorType& allocator);
		std::string GetNamespace() const { return _namespace; }

	private:
		rapidjson::Value soundJson;
		std::string _namespace;
		SoundProperties properties;
		std::vector<SoundEvent> soundEvents;
		std::vector<std::string> evTypeListString;

		void AddSoundEventsJson(rapidjson::Document::AllocatorType& allocator);
	};
}

#endif
