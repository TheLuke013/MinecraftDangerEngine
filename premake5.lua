workspace "DangerEngine"
	architecture "x64"

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
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DANGER_ENGINE_EXPORTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/ExampleAddon")
		}

	filter "configurations:Debug"
		defines "DE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DE_DIST"
		optimize "On"

--EXAMPLE ADDON

project "ExampleAddon"
	location "ExampleAddon"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	debugdir ("bin/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DangerEngine/src"
	}

	links
	{
		"DangerEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "AK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AK_DIST"
		optimize "On"
