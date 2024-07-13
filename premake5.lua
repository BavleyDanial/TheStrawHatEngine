require "ecc"

local workspaceName = "TheStrawHat"
local engineName = "TheStrawHatEngine"
local gameName = "TheStrawHatGame"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

dependencies = {}
dependencies["glfw"] = engineName .. "/vendor/glfw"

workspace (workspaceName)
    startproject (gameName)
    configurations {"Debug", "Release"}
    architecture "x64"
    
    group "Dependencies"
        include (engineName .. "/vendor/glfw") 
    group ""
    
    project (engineName)
        location (engineName)
        kind "StaticLib"
        language "C++"
        cppdialect "C++20"
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
        
        includedirs {
            "%{prj.name}/src",
            "%{dependencies.glfw}/include/",
        }

        links {
            "GLFW",
            "opengl32.lib" 
        }

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
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
        includedirs {
            engineName .. "/src",
            "%{dependencies.glfw}/include"
        }
        links {
            engineName,
        }

        filter "configurations:Debug"
            defines {"TSH_DEBUG"}
            symbols "On"
        filter "configurations:Release"
            defines {"TSH_NDEBUG"}
            optimize "On"