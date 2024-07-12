del "compile_commands.json"
call "vendor/premake/premake5.exe" --config=%1 ecc
call  py "scripts/pythonScripts/RemoveStupidCommaToFixCompile_Commands.py" "compile_commands.json"
PAUSE