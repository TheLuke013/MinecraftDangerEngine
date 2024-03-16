# MinecraftDangerEngine
Danger Engine is a tool with which you can create your Minecraft addons in C++ using just a few lines of code to generate huge JSONs.

This tool is intended for the minecraft bedrock community that creates addons. This tool will be very useful if you want to focus on productivity and let the tool generate the entire addon for you without having to edit json manually, and also if you don't want to have a headache when Mojang changes something and your entire addon breaks, because this tool will always be updating its backend every time Mojang changes something, so you wouldn't need to modify the code that was already written, just recompile your addon.

You can use the **Addon** class to create an addon with Resource Pack and Behavior pack or create separate packages using the **BehaviorPack** and **ResourePack** classes.

## Features
- JSON Generator
- UUID Generator
- Add-on Generator

## Prerequisites
- Windows.
- Visual Studio 2019 or higher installed.

## Build and Installation
1. Clone the repository using `git clone https://github.com/TheLuke013/MinecraftDangerEngine.git`.
2. Go to the cloned repository folder and run the bat script `GenerateProjects.bat`.
3. Click on the `DangerEngine.sln` file to open the solution in Visual Studio.
4. Press `F5` to build the entire solution and run it.

## Basic Example
This is a basic example of how to create an addon using the **DE::Addon** class
```cpp
#include "DangerEngine.h"

#define ADDON_VERSION {1, 0, 0}

int main()
{
	DE::Addon addon(
		"<WORKSPACE_PATH>",
		"<MINECRAFT_PATH>",
		2,
		"MyAddon",
		"An addon made using an amazing tool!",
		ADDON_VERSION,
		"TheLuke013",
		"MIT",
		"https://github.com/TheLuke013/MinecraftDangerEngine.git");

	addon.GetBp()->GetManifest()->AddDependencie(ADDON_VERSION, addon.GetRp()->GetManifest()->GetHeaderUuid());

	return 0;
}
```

## ThirdParty
- [RapidJson](https://github.com/Tencent/rapidjson.git)
