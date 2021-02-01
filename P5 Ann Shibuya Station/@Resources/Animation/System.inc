[start_0]
measure=calc
formula=start_0+25
ifcondition=start_0=200
iftrueaction=[!pausemeasure start_0]

[start_1]
measure=calc
formula=(random*50)
highbound=8
lowbound=4
onupdateaction=[!delay [start_1]][!enablemeasure extend_1][!showmeter cpu_bar_back]
updatedivider=-1

[start_2]
measure=calc
formula=(random*50)
highbound=8
lowbound=4
onupdateaction=[!delay [start_2]][!enablemeasure extend_2][!showmeter ram_bar_back]
updatedivider=-1

[start_3]
measure=calc
formula=(random*50)
highbound=8
lowbound=4
onupdateaction=[!delay [start_3]][!enablemeasure extend_3][!showmeter gpu_bar_back]
updatedivider=-1

[start_4]
measure=calc
formula=(random*50)
highbound=8
lowbound=4
onupdateaction=[!delay [start_4]][!enablemeasure extend_4][!showmeter bat_bar_back]
updatedivider=-1

[start_5]
measure=calc
formula=(random*50)
highbound=8
lowbound=4
onupdateaction=[!delay [start_5]][!enablemeasure extend_5][!showmeter hdd_bar_back]
updatedivider=-1

[limit_1]
measure=calc
formula=floor((385*[m_cpu])+10)
dynamicvariables=1
updatedivider=-1

[limit_2]
measure=calc
formula=floor((385*[m_ram_percent])+10)
dynamicvariables=1
updatedivider=-1

[limit_3]
measure=calc
formula=floor((385*[m_gpu])+10)
dynamicvariables=1
updatedivider=-1

[limit_4]
measure=calc
formula=floor((385*[m_battery_percent])+10)
dynamicvariables=1
updatedivider=-1

[limit_5]
measure=calc
formula=floor((385*[m_storage_percent])+10)
dynamicvariables=1
updatedivider=-1

[extend_1]
measure=calc
formula=extend_1+38.5
ifcondition=extend_1>=(limit_1+15)
iftrueaction=[!pausemeasure extend_1][!setvariable flag_1 1]
disabled=1

[extend_2]
measure=calc
formula=extend_2+38.5
ifcondition=extend_2>=(limit_2+15)
iftrueaction=[!pausemeasure extend_2][!setvariable flag_2 1]
disabled=1

[extend_3]
measure=calc
formula=extend_3+38.5
ifcondition=extend_3>=(limit_3+15)
iftrueaction=[!pausemeasure extend_3][!setvariable flag_3 1]
disabled=1

[extend_4]
measure=calc
formula=extend_4+38.5
ifcondition=extend_4>=(limit_4+15)
iftrueaction=[!pausemeasure extend_4][!setvariable flag_4 1]
disabled=1

[extend_5]
measure=calc
formula=extend_5+38.5
ifcondition=extend_5>=(limit_5+15)
iftrueaction=[!pausemeasure extend_5][!setvariable flag_5 1]
disabled=1

[return_to_real]
measure=calc
formula=(#flag_1#+#flag_2#+#flag_3#+#flag_4#+#flag_5#)
dynamicvariables=1
ifcondition=return_to_real=5
iftrueaction=[!delay 200][!setoption cpu_bar_back shape "rectangle 200,40,(385*[*m_cpu*]+10),40 | strokewidth 0 | extend MyFillColor"][!setoption ram_bar_back shape "rectangle 200,70,((385*[*m_ram_percent*])+10),40 | strokewidth 0 | extend MyFillColor"][!setoption gpu_bar_back shape "rectangle 200,100,((385*[*m_gpu*])+12),40 | strokewidth 0 | extend MyFillColor"][!setoption bat_bar_back shape "rectangle 200,130,(385*[*m_battery_percent*]+14),40 | strokewidth 0 | extend MyFillColor"][!setoption hdd_bar_back shape "rectangle 200,160,((385*[*m_storage_percent*])+14),40 | strokewidth 0 | extend MyFillColor"][!delay 50][!showmetergroup real][!unpausemeasuregroup system][!pausemeasure return_to_real]