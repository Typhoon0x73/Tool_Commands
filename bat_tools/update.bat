@echo off
setlocal

set BAT_TOOLS_DIR=%CD%
cd %BAT_TOOLS_DIR%
if not exist "../gyp_tools" (
	cd ../
	mkdir gyp_tools
	cd %BAT_TOOLS_DIR%
)
if not exist "../gyp_tools/gyp" (
	call init_gyp_tools.bat
)
cd ../gyp_tools/gyp
git pull
cd %BAT_TOOLS_DIR%
call generate_msvs_gyp.bat
pause