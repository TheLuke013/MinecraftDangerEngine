#include <DangerEngine/DangerEngine.h>

int main()
{
	DE::InitDE();

	DE::Addon addon(
		".",
		2,
		"MyAddon",
		"An addon made using an amazing tool!",
		DE_DEFAULT_VERSION,
		"TheLuke013",
		"MIT",
		"https://github.com/TheLuke013/MinecraftDangerEngine.git");

	addon.AddDependencie(DE::ResourcePack, DE::BehaviourPack, DE_DEFAULT_VERSION);

	DE::Build build(&addon);
	build.BuildAddon(DE::BuildMode::BUILD_IN_WORKSPACE);
	//build.BuildAddon(DE::BuildMode::BUILD_IN_MC_PATH);

	return 0;
}