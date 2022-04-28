# Voron2.4_klipper-MS_config
Just my MainSailOS and Klipper Configs for my 350mm Voron 2.4
- This is my frist voron build and coming from Marlin FW
- Built from a formbot3d kit. 
- The printer is functional but needs all its panels and skirts

# MODS #
These are my printers user based mods
- [PCB Cover](https://github.com/craxoor/VoronMods/tree/master/PCB%20Cover)

# TODO
- Install Panels, Skirts/Fans & Seal Exhaust Fan
- [Deck Panel Support Clips](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/wile-e1/Deck_Panel_Support_Clips)
- [Auto Z Calibration](https://github.com/protoloft/klipper_z_calibration)
- [Frame Expansion Compensation](https://github.com/tanaes/whopping_Voron_mods/tree/main/docs/frame_expansion)
- [GE5C Z Joints](https://github.com/hartk1213/MISC/tree/main/Voron%20Mods/Voron%202/2.4/Voron2.4_GE5C)
- ["Other" V2 Idlers](https://github.com/selliott79/Other-V2-Idlers) or [Rama's Front Idlers](https://github.com/Ramalama2/Voron-2-Mods/tree/main/Front_Idlers)
- [Stealthburner + CW2](https://github.com/VoronDesign/Voron-Afterburner/tree/sb-beta)
- [VEFACH](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/KevinAkaSam/VEFACH) or [HEPA Filter Exhaust for Voron 2.x](https://github.com/marcdebruijn/VoronUsers/tree/Voron-1.x/2.x-HEPA-Filter-Exhaust/printer_mods/dePrintinator/HEPA_Filter_Exhaust) (Maybe)
- [KoiosLabs LED Mounts](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/Koios/LED_Mounts) or [DerekBackus LED Holder](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/DerekBackus/LED_Holder) or [EddieTheEngineer LED Bar Clip](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/eddie/LED_Bar_Clip)
- [Sturdy Handles](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/jeoje/Sturdy_Handles)
- A Filament Runout Sensor (TBD)
- [Randell Hinge Mod for 3mm Doors w/ 3mm Foam](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/randell/Door_Hinges) or [ChrisGonzales 270° Hinge Parametric](https://github.com/VoronDesign/VoronUsers/tree/master/printer_mods/chrisrgonzales/270_degree_hinge)
- [RocknRoll](https://github.com/RockNLol/VoronUsers/tree/master/printer_mods/RockNLol/RockNRoll)
more text should be here!

# Use dictionaries for _USER_VARIABLE #
# REFED USER VARS #
Use dictionaries for _USER_VARIABLE
Like the printer. object _USER_VARIABLES are now grouped in a handful of dictionaries. The big advantage of this is that you can use them like you are used to it. As an example:

printer['gcode_macro _USER_VARIABLE'].homing.z_endstop.x
this will be the x position of the z_endstop.

Following describes the variable as is today, that does not mean that there might be additions in the future that are not descript here:

hw enables or disables extra hardware following are detected

auto_z_offset :
type : none/flexplate/z_calib/z_calib+flexplate depending what is found in cfg
ena : True if type != none
auto : True if type is z_calib or z_calib+flexplate
manu : True if type is flexplate or z_calib+flexplate
caselight.ena : True if caselight is found in cfg
chamber :
type : none/fan/sensor depending what is found in cfg
ena : True if type != none
fan : True if type is fan
display.ena : True if display with neopixel in cfg
endstop_temp: True is the endstop tempsensor is found in cfg
filter.ena : True if filter is found in cfg
mag_probe.ena: True is a mag probe is found in cfg
relay.ena : True if safety relais are found in cfg
runout :
type : none/file/motion/switch depending on cfg
ena : True if type != none
sensor : True if type is motion or switch
homing

z_endstop : [x,y,z,hop] x,y are the endstop coordinates, z is the minimum lift calculated from the endstop z_offset to do not press the pin and hop is the z hop for the G28 moves
z_current : z motor current during homing and QGL commands
accel : accereration during homing
z_hop : minimal z height for all movment

speed all speeds are defined in [mm/s]

z_hop : speed for all z hop moves
travel : speed for all travel moves
dock : speed for the docking moves of the mag probe
retract : retract and extrude speed
load : filament load speed
wipe : wipe speed on the brush
prime : prime line speed
probe these are only needed if you use a magnetic probe like klicky

dock : [x,y] coordinates of the probe mount in dock position
store : [x,y] coordinates of the probe mount in store position
park different park positions

bed : [x,y,z] middle of bed, hight is user defined
center : [x,y,z] middle of print volume
frontlow : [x,y,z] front middle height is user defined
front : [x,y,z] front middle height is user defined
rear : [x,y,z] rear left height is user defined
pause : [x,y,dz] x,y are the same position as purge, dz is the delta increase of the toolhead
park_at_cancel : Enable/Disable parkimg to the PAUSE position in CANCEL_PRINT
filament all values are in mm

load_distance : filament distance used in load macro to get the filament in clockworks
load_extrude : additional distance used in load macro
unload_distance : filament distance used in the unload macro
retract : [end,pause,cancel] different retract/unretract distances
purge all variables needed to for the purge bucket and brush

purge : [x,y,z] coordinates to do the filament purge
wipe :
start : [x,y,z] coordinates for the wipe start
end : [x,y,z] coordinates for the wipe start
offset : offset for each wipe move in Y direction
cnt : number of wipe moves
print_start different variables used in PRINT_START

bed_up : increase of bed temp for faster heat soak
ival : interval between the loops while doing PRINT_START
time :
extruder : start time of heating the extruder to target (e.g 3 min before heat soak is over)
bed : start time of decreasing bed to target (e.g 3 min before heat soak is over)
prime_mult : height multiplier for the layer hight during purge
unload_sd : unload sd file at PRINT_END or CANCEL_PRINT. Set this to False if you often reprint the same file

prime

pos : [x,y,z] start poaition for the prime line
dir : direction of the prime line valid inputs X+, X-, Y+, Y-
spacing : distance between the two lines
length_per_seg : prime line is separated in segments to make baby-stepping easier. This is the length of a single segment
seg : number of segments per line
extrude_per_seg : amount of filament per segment in mm
respond enable or disable the default of outputs to the console

z_current : default behavior for output messages of _SET_Z_CURRENT macro 0: no output 1: console output
acc : default behavior for output messages of _SET_LAYER 0: no output 1: console output
probe_action : default behavior for output messages of _PROBE_ACTION macro 0: no output 1: console output
layer : default behavior for output messages of _LAYER macro 0: no output 1: console output
peripheral values needed for different hardware

filter (Nevermore Mini)
on_val : target speed when turned on
warning : time in hours after the filter material change warning should be displayed
run_after_print : time in minutes that the filter should run after the print is finished
vent (Exhaust set up as temperature_fan)
on_val : target temperature the Exhaust should be set to suck the air out of the chamber
run_after_print : time in minutes that the filter should run after the print is finished
caselight
on_val : target output when led are turned on
run: used internal to detect that the _USER_VARIABLE was executed

This should be the last bigger change of the variables as I am now quiet happy with the readability of it.

Config and layouts draw from users zellneralex, sdavis175 and others in the Voron discord. Thanks Guys
