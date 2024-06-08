#include "DangerEngine/Minecraft/Sounds.h"

namespace Minecraft
{
	Sounds::Sounds()
		: soundsJson(new rapidjson::Document(rapidjson::kObjectType)), 
		allocator(soundsJson->GetAllocator()),
		entitySounds(rapidjson::kObjectType), entities(rapidjson::kObjectType)
	{

	}

	Sounds::~Sounds()
	{
		delete soundsJson;
	}

	void Sounds::AddSound(Sound* sound)
	{
		rapidjson::Value key;
		key.SetString(sound->GetNamespace().c_str(), allocator);
		entities.AddMember(key, sound->GetSoundJson(allocator), allocator);
	}

	std::string Sounds::JsonParse()
	{
		entitySounds.AddMember("entities", entities, allocator);
		soundsJson->AddMember("entity_sounds", entitySounds, allocator);

		return *DE::JSONUtils::GetJsonString(*soundsJson);
	}
}