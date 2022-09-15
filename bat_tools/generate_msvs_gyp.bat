@echo off
setlocal

set BAT_TOOLS_DIR=%CD%
cd %BAT_TOOLS_DIR%
if not exist "../gyp_tools/gyp" (
	call init_gyp_tools.bat
)

cd ../
gyp_tools/gyp/forWindows/generate_msvs_2022.bat msbuild.gyp
cd %BAT_TOOLS_DIR%