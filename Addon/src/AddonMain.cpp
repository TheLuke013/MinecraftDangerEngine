#include <DangerEngine/DangerEngine.h>

int main()
{
	DE::InitDE();

	DE::Addon addon
	(
		DE_WORKSPACE,
		DE_FORMAT_VERSION,
		"MyAddon",
		"An addon made using an amazing tool!",
		DE_VERSION,
		"TheLuke013",
		DE_LICENSE,
		DE_URL
	);

	addon.AddDependencie(DE::ResourcePack, DE::BehaviourPack, DE_VERSION);

	Minecraft::Sounds sounds;

	Minecraft::Sound* cowSound = new Minecraft::Sound("minecraft:cow", 1, { 1.0f, 1.0f });
	cowSound->AddSoundEvent(Minecraft::death, "cow.death");
	cowSound->AddSoundEvent(Minecraft::hurt, "cow.hurt");
	sounds.AddSound(cowSound);

	Minecraft::Sound* chickenSound = new Minecraft::Sound("minecraft:chicken", 1, { 1.0f, 1.0f });
	chickenSound->AddSoundEvent(Minecraft::death, "chicken.death");
	sounds.AddSound(chickenSound);
	LOG_INFO(sounds.JsonParse());

	DE::Build build(&addon);
	build.BuildAddon(DE::BuildMode::BUILD_IN_WORKSPACE);
	//build.BuildAddon(DE::BuildMode::BUILD_IN_MC_PATH);

	return 0;
}