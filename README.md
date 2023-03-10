# xmake GD Mod Template

This Github repository provides a ready-to-use GD mod template using the xmake build system, along with an automated copy DLL and run command that allows for quick testing of modifications.

## About xmake

[xmake](https://xmake.io/) is a lightweight, cross-platform build utility based on Lua that uses `xmake.lua` to maintain project builds with a simple and readable syntax. It is very lightweight and has no dependencies due to the integration of the Lua runtime.

## Why xmake?
Compared to CMake, I find xmake much simpler to use when it comes to getting started, compiling, and running projects. As a result, I created this template to practice and learn.
## Windows Setup
To ensure a smooth experience, xmake attempts to detect [Visual Studio Community with C++](https://visualstudio.microsoft.com/vs/community/), making it highly recommended to have it installed.

### Install xmake
To get started with this template, download and install xmake using the installer from [Releases](https://github.com/xmake-io/xmake/releases/latest). Verify the installation by opening a console and running `xmake --version`.

### Build
Once xmake is installed, clone this repository and change to the directory using the following commands:

```
git clone https://github.com/<your_username>/gdmod.git
cd gdmod
```


Then, compile the mod using xmake by simply running `xmake`. For the first compile, use `xmake -y` to auto-accept y/n install packages.

## Run Command Setup
To automate the process of copying the DLL and running the mod, modify `cfg.txt` and set your own paths for the following variables:

- `cppath`: the directory where the DLL will be copied to
- `gdpath`: the directory where the Geometry Dash executable is located
- `gdexec`: the file name of the Geometry Dash executable (usually `GeometryDash.exe`)

Next, import the settings with `xmake f --import=cfg.txt`.<br>
You can view the current values using `xmake f --menu` and entering `Project Configuration`.

Finally, use the following command to run the mod and specify the target:

```
xmake run gdmod
```
in the [future](https://github.com/xmake-io/xmake/pull/3496), `xmake run` will work just fine, but for now the target name must be specified

## xmake'd libraries

check out the `xmake.lua` of [matdash](), [cocos headers]() and [gd.h]()

## xrepo

xmake has its own package called [xrepo](https://xrepo.xmake.io/#/) which integrates very well with xmake.lua


# GD Modding Resources

- [geode docs](https://docs.geode-sdk.org/) modding tutorials cover tradditional modding aswell
- [cocos-headers api docs](https://hjfod.github.io/cocos-headers/)
- [gd-docs](https://docs.gdprogra.me/#/) endpoints info and how to make requests to gd servers
- [GD Programming](https://discord.gg/jEwtDBK) discord server
- [GD Modding](https://discord.gg/K9Kuh3hzTC) (community) discord server

# Credits

- [xmake](https://xmake.io/) and [xrepo](https://xrepo.xmake.io/#/) for an amazing build system
- [matdash](https://github.com/matcool/mat-dash) simple lightweight tradditional modding hooking library
- [MinHook](https://github.com/TsudaKageyu/minhook) The Minimalistic x86/x64 API Hooking Library for Windows
- [gd.h](https://github.com/hjfod/gd.h) and [cocos-headers](https://github.com/hjfod/cocos-headers)
