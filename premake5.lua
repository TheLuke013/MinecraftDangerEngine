workspace "DangerEngine"
	architecture "x64"
	startproject "Addon"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--DANGER ENGINE

project "DangerEngine"
	location "DangerEngine"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
	}

	includedirs
	{
		"%{prj.name}/include",
		"ThirdParty/rapidjson/include",
		"ThirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

--ADDON

project "Addon"
	location "Addon"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
	}

	includedirs
	{
		"DangerEngine/include",
		"ThirdParty/rapidjson/include",
		"ThirdParty/spdlog/include"
	}

	links
	{
		"DangerEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
