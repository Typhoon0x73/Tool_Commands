@echo off
setlocal

set BAT_TOOLS_DIR=%CD%
cd %BAT_TOOLS_DIR%/../gyp_tools
if not exist "gyp" (
	mkdir gyp
)
cd gyp
git clone -b master https://github.com/Typhoon0x73/gyp.git ./
python setup.py install
cd %BAT_TOOLS_DIR%
