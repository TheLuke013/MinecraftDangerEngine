#include "DangerEngine/Minecraft/Sound.h"

namespace Minecraft
{
	Sound::Sound(const std::string& _namespace, unsigned int volume, std::vector<float> pitch)
		: _namespace(_namespace), soundJson(rapidjson::kObjectType)
	{
		properties.volume = volume;
		properties.pitch = pitch;

		evTypeListString =
		{
			"ambient",
			"hurt",
			"death",
			"step",
			"fall.big",
			"fall.small",
			"splash",
			"attack",
			"shoot",
			"cast.spell",
			"prepare.attack",
			"roar"
		};
	}

	Sound::~Sound()
	{

	}

	void Sound::AddSoundEvent
	(
		SoundEventType eventType,
		const std::string& sound,
		unsigned int volume,
		std::vector<float> pitch
	)
	{
		SoundEvent ev;
		ev.eventType = eventType;
		ev.sound = sound;
		properties.volume = volume;
		properties.pitch = pitch;

		soundEvents.push_back(ev);
	}

	rapidjson::Value& Sound::GetSoundJson(rapidjson::Document::AllocatorType& allocator)
	{
		//PROPERTIES
		soundJson.AddMember("volume", properties.volume, allocator);

		rapidjson::Value pitchArray(rapidjson::kArrayType);
		for (const auto& pitch : properties.pitch)
		{
			pitchArray.PushBack(pitch, allocator);
		}
		soundJson.AddMember("pitch", pitchArray, allocator);

		AddSoundEventsJson(allocator);

		return soundJson;
	}

	void Sound::AddSoundEventsJson(rapidjson::Document::AllocatorType& allocator)
	{
		for (const auto& soundEvent : soundEvents)
		{
			rapidjson::Value eventJson(rapidjson::kObjectType);

			//SOUND EVENT PROPERTIES
			DE::JSONUtils::AddStringMember(eventJson, "sound", soundEvent.sound, allocator);
			eventJson.AddMember("volume", soundEvent.properties.volume, allocator);
			DE::JSONUtils::AddFloatVectorMember("pitch", soundEvent.properties.pitch, eventJson, allocator);

			//SOUND EVENT TYPE NAME
			std::string evTypeStr;
			for (int i = 0; i < evTypeListString.size(); i++)
			{
				if (soundEvent.eventType == i)
				{
					evTypeStr = evTypeListString[i];
					break;
				}
			}

			rapidjson::Value name(evTypeStr.c_str(), allocator);
			soundJson.AddMember(name, eventJson, allocator);
		}
	}
}