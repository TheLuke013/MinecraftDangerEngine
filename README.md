# MinecraftDangerEngine
Danger Engine is a tool with which you can create your Minecraft Add-ons in C++ using just a few lines of code to generate huge JSONs.

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

	return 0;
}
```

## ThirdParty
- [RapidJson](https://github.com/Tencent/rapidjson.git)
