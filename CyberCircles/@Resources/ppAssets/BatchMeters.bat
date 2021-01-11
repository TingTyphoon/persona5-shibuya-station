
:: Use this script to create batches of meters with a numeric pattern.

@echo off
echo.
echo Creating meters...
echo If you see any text after this, check the code.

set temp=0
set temp2=1
:loop
echo.>>temp.txt
echo [Button%temp2%]>>temp.txt
echo Meter=Shape>>temp.txt
echo Shape=Rectangle 30,(((32 * %temp2%) + #bStartY#) + #anchor#),330,30,#buttonRoundness#,#buttonRoundness# ^| Fill Color #buttonC%temp2%# ^| StrokeWidth 0 >>temp.txt
echo MouseOverAction=[^!SetVariable buttonC%temp2% #buttonHover#][^!Update]>>temp.txt
echo MouseLeaveAction=[^!SetVariable buttonC%temp2% #backgroundColour#][^!Update]>>temp.txt
echo LeftMouseUpAction=[^!WriteKeyValue Variables selectedPlayer "%temp2%" "#@#vars.ini"][^!WriteKeyValue Variables playerName "Spotify" "#@#vars.ini"][^!WriteKeyValue Variables playerF "Spotify" "#@#vars.ini"][^!Refresh][^!Refresh #refreshDir#]>>temp.txt
echo Container=OptionContainer>>temp.txt
echo DynamicVariables=1 >>temp.txt

set /a temp+=1
set /a temp2+=1
if %temp%==20 goto end
goto loop

:end
echo.
pause
exit