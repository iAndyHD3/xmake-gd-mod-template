add_rules("mode.release")

--equivalent to
--if is_mode("release") then
--	set_symbols("hidden")
--	set_optimize("fastest")
--	set_strip("all")
--end

add_rules("mode.releasedbg")

--equivalent to
--if is_mode("releasedbg") then
--	set_symbols("debug")
--	set_optimize("fastest")
--	set_strip("all")
--end

set_allowedarchs("windows|x86") --allow only windows x86
set_defaultarchs("windows|x86") --set default windows x86
set_allowedmodes("release", "releasedbg") --allow only Release and RelWithDebInfo
set_defaultmode("release");
set_languages("c++20") --set c++20


--create options with loop and array
options_table = {"cppath", "gdpath", "gdexec"}

for i = 1, #options_table do
	option(options_table[i])
		set_default("")
		set_showmenu(true)
	option_end()
end

add_requires("minhook")
add_requires("fmt")

includes("**/xmake.lua") -- recursively add files through pattern matching

target("gdmod") --dll name and target name
	set_default(true)
	set_kind("shared")
	add_files("src/*.cpp")
	add_packages("minhook")
	add_packages("fmt")
	add_deps("cocos-headers")
	add_deps("mat-dash")
	add_deps("gd.h")
	set_rundir("/bin")
	
	
	--this will run when xmake run gdmod is called
	on_run(function (target)
		local function isempty(s) return s == nil or s == '' or s == "" end
		local function notempty(s) return isempty(s) == false end
		
		--print("cppath: $(cppath) | gdpath: $(gdpath) | gdexec: $(gdexec)")
		
		if notempty("$(cppath)") then
			cprint(string.format("${green}%s${clear} -> ${green}%s${clear}", target:targetfile(), "$(cppath)"))
			os.cp(target:targetfile(), "$(cppath)")
		end

		if notempty("$(gdexec") and notempty("$(gdpath") then
			local scriptdir = os.scriptdir()
			os.cd("$(gdpath)")
			cprint("${green}$(gdpath)\\$(gdexec)${clear} -> CTRL+C or close the game to exit")
			os.run("$(gdexec)")
		end
			
	end)
	
target_end() --target_end() is optional


--xmake website (recommended) https://xmake.io
-- xmake f --import=cfg.txt