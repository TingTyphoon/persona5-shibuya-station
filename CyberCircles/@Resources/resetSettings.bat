
@echo off

title Resetting Skin Settings...

echo.
echo * Deleting backup settings...
del settingsBackup.ini
echo * Backing up current settings...
ren settings.ini settingsBackup.ini
echo * Loading default settings...
md temp
copy /Y settingsDefaults.ini .\temp
ren .\temp\settingsDefaults.ini settings.ini
copy /Y .\temp\settings.ini .\
rd /S /Q temp
goto end

:end
exit