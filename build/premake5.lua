workspace "Data Structure"
    location "../"
    platforms { "x32" , "x64"}
    configurations { "Debug", "Release" }

    filter "configurations:Debug"    defines { "DEBUG" }  symbols  "On"
    filter "configurations:Release"  defines { "NDEBUG" } optimize "On"

    filter { "platforms:*32" } architecture "x86"
    filter { "platforms:*64" } architecture "x64"

    filter { "system:windows", "action:vs*"}
        flags         { "MultiProcessorCompile", "NoMinimalRebuild" }
        linkoptions   { "/ignore:4099" }

    filter { "action:gmake" }
        cppdialect "C++14"
    
    filter { "system:macosx", "action:gmake"}
        toolset "clang"

    filter {}

project "myDSlib"
    location "../myDSlib"
    kind "StaticLib"
    language "C++"

    targetdir ("../binaries/%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}/%{prj.name}")
    objdir ("../intermediates/%{cfg.buildcfg}-obj/%{cfg.system}-%{cfg.architecture}/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
