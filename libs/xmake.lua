--[[

target("minhook")
	set_kind("static")
	add_includedirs("src/", "src/hde/")
	add_files("src/*.c", "src/hde/hde32.c")
	add_shflags("/def:dll_resources/MinHook.def")
	add_headerfiles("include/MinHook.h")
	add_includedirs("include", {public = true})
target_end()
--]]