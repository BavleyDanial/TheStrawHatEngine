require "ecc"

local workspaceName = "TheStrawHat"
local engineName = "TheStrawHatEngine"
local gameName = "TheStrawHatGame"

local targetDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace (workspaceName)
    configurations {"Debug", "Release"}
    architecture "x64"

    project (engineName)
        location (engineName)
        kind "StaticLib"
        language "C++"
        cppdialect "C++20"
        targetdir ("bin/" .. targetDir .. "/%{prj.name}")
	    objdir ("bin-int/" .. targetDir .. "/%{prj.name}")

        files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
        includedirs {"%{prj.name}/src"}
        filter "configurations:Debug"
            defines {"TSH_DEBUG"}
            symbols "On"
        filter "configurations:Release"
            defines {"TSH_NDEBUG"}
            optimize "On"
    
    project (gameName)
        location (gameName)
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"
        targetdir ("bin/" .. targetDir .. "/%{prj.name}")
	    objdir ("bin-int/" .. targetDir .. "/%{prj.name}")

        files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
        includedirs { engineName .. "/src" }
        links { engineName }

        filter "configurations:Debug"
            defines {"TSH_DEBUG"}
            symbols "On"
        filter "configurations:Release"
            defines {"TSH_NDEBUG"}
            optimize "On"