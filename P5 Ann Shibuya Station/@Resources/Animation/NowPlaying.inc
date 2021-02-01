[profile_counter]
measure=calc
formula=profile_counter+1
dynamicvariables=1
group=test
disabled=1

[counter_start_at_2]
measure=calc
formula=1+profile_counter
dynamicvariables=1
group=test
disabled=1

[profile_zoom_in]
measure=calc
formula=(counter_start_at_2*(35*#scale#))
ifcondition=profile_zoom_in >= (175*#scale#)
iftrueaction=[!setoption profile_zoom_in formula "(140*#scale#)"][!delay 80][!pausemeasuregroup test]
dynamicvariables=1
group=test
disabled=1

[text_box_counter]
measure=calc
formula=text_box_counter+1
group=textbox_animation
dynamicvariables=1
disabled=1

[text_box_animation]
measure=calc
formula=(text_box_counter*(133.25*#scale#))
ifcondition=text_box_animation >= (533*#scale#)
iftrueaction=[!pausemeasure text_box_counter][!pausemeasure text_box_animation]
group=textbox_animation
dynamicvariables=1
disabled=1

[text_fade]
measure=calc
formula=text_fade+63.75
ifcondition=text_fade >= 255
iftrueaction=!pausemeasure text_fade
dynamicvariables=1
disabled=1