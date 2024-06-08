# MinecraftDangerEngine
Danger Engine is a tool with which you can create your Minecraft addons in C++ using just a few lines of code to generate huge JSONs.

This tool is intended for the minecraft bedrock community that creates addons. This tool will be very useful if you want to focus on productivity and let the tool generate the entire addon for you without having to edit json manually, and also if you don't want to have a headache when Mojang changes something and your entire addon breaks, because this tool will always be updating its backend every time Mojang changes something, so you wouldn't need to modify the code that was already written, just recompile your addon.

## Features
- JSON Generator
- UUID Generator
- Add-on Generator

## Prerequisites
- Windows 10/11;
- x64 system architecture;
- Visual Studio 2022.

## Build and Installation
1. Clone the repository using `git clone --recurse-submodules https://github.com/TheLuke013/MinecraftDangerEngine.git`;
2. Go to the cloned repository folder and run the bat script `GenerateSolution.bat`;
3. Click on the `DangerEngine.sln` file to open the solution in Visual Studio;
4. Press `F5` to build the entire solution and run it.

## Basic Example
This is a basic example of how to create an addon using the **DE::Addon** class
```cpp
#include <DangerEngine/DangerEngine.h>

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::Addon addon(
		".",
		2,
		"MyAddon",
		"An addon made using an amazing tool!",
		ADDON_VERSION,
		"TheLuke013",
		"MIT",
		"https://github.com/TheLuke013/MinecraftDangerEngine.git");

	addon.GetBp()->GetManifest()->AddDependencie(ADDON_VERSION, addon.GetRp()->GetManifest()->GetHeaderUuid());

	DE::Build build(&addon);
	build.BuildAddon(DE::BuildMode::BUILD_IN_WORKSPACE);
	//build.BuildAddon(DE::BuildMode::BUILD_IN_MC_PATH);

	return 0;
}
```

## ThirdParty
- [RapidJson](https://github.com/Tencent/rapidjson.git)
