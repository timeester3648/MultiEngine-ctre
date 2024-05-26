include "../../premake/common_premake_defines.lua"

project "ctre"
	kind "None"
	language "C++"
	cppdialect "C++latest"
	cdialect "C17"
	targetname "%{prj.name}"
	inlining "Auto"

	files {
		"./include/**.hpp",
	}

	includedirs {
		"%{IncludeDir.ctre}"
	}