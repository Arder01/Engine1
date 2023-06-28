workspace "Engine1"

architecture "x64"

configurations
{
	"Debug",
	"Release",
	"Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine1"
	location "Engine1"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" ..outputdir .."/%{prj.name}")
	objdir("bin-int/" ..outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Vendors/spdlog/include;"
	}

	filter "system:windows"
		cppdialect  "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"E1_PLATFORM_WINDOWS",
			"E1_BUILD_DLL"
		}

	postbuildcommands
	{
		"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
	}

	filter "configurations:Debug"
	defines "E1_DEBUG"
	symbols "On"

	filter "configurations:Release"
	defines "E1_RELEASE"
	optimize "On"

	filter "configurations:Dist"
	defines "E1_DIST"
	optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" ..outputdir .."/%{prj.name}")
	objdir("bin-int/" ..outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Engine1/Vendors/spdlog/include",
		"Engine1/src"
	}

	links
	{
		"Engine1"
	}

	filter "system:windows"
		cppdialect  "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"E1_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
	defines "E1_DEBUG"
	symbols "On"

	filter "configurations:Release"
	defines "E1_RELEASE"
	optimize "On"

	filter "configurations:Dist"
	defines "E1_DIST"
	optimize "On"