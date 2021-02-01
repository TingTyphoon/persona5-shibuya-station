[counter]
measure=calc
formula=counter+1
ifcondition=counter=11
iftrueaction=[!hidefade][!pausemeasure counter][!delay 600][play #@#Sound\00007.wav][!refreshgroup desktop][!delay 10][!showfadegroup desktop]
disabled=1

[on_state]
measure=calc
formula=on_state+1
ifcondition=on_state=40
iftrueaction=[!enablemeasure counter][!disablemeasure on_state]

[title]
meter=image
imagename=#@#Image\Startup\[counter].png
antialias=1
dynamicvariables=1