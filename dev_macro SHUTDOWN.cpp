[gcode_macro SHUTDOWN]
variable_printer_active: 0
variable_wants_shutdown: 0
gcode:
  {action_call_remote_method("shutdown_machine")}

[gcode_macro CONDITIONAL_SHUTDOWN]
gcode:
  {% if printer["gcode_macro SHUTDOWN"].wants_shutdown == 1 %}
    SHOW_MSG MSG="Conditional shutdown wants shutdown, waiting for cooling down then i will shutdown"
    M140 S0 ; start heating the bed to what is set in Cura
    M104 S0 T0 ; start heating T0 to what is set in Cura
    TEMPERATURE_WAIT SENSOR="extruder" MAXIMUM=60
    SHUTDOWN
  {% endif %}

[gcode_macro GET_COMPLETE_SHUTDOWN]
gcode:
  {% set shutdown_wanted = printer["gcode_macro SHUTDOWN"].wants_shutdown %}
  SHOW_MSG MSG="Cmpl shutd: {shutdown_wanted}"

[gcode_macro SET_COMPLETE_SHUTDOWN]
gcode:
  {% set wants_shutdown = params.ENABLE|default(1)|int %}
  {% if wants_shutdown >= 1 %}
    {% set wants_shutdown = 1 %}
    SHOW_MSG MSG="print cmpl->shutdown"
  {% else %}
    SHOW_MSG MSG="print cmpl->stay on"
  {% endif %}
  SET_GCODE_VARIABLE MACRO=SHUTDOWN VARIABLE=wants_shutdown VALUE={wants_shutdown}

[gcode_macro SAFE_SHUTDOWN]
gcode:
  {% if printer_active == 0 %}
  SHOW_MSG MSG="Performing safe shutdown"
  SHUTDOWN
  {% else %}
  SHOW_MSG MSG="Job is active. No shutdown!"
  {% endif %}

[gcode_macro SHUTDOWN_HANDLER_START_PRINT]
gcode:
  SET_GCODE_VARIABLE MACRO=SHUTDOWN VARIABLE=printer_active VALUE=1

[gcode_macro SHUTDOWN_HANDLER_STOP_PRINT]
gcode:
  ; This needs to be at the end of your stop_gcode!!!!!!!
  SET_GCODE_VARIABLE MACRO=SHUTDOWN VARIABLE=printer_active VALUE=0
  CONDITIONAL_SHUTDOWN

[gcode_macro SHUTDOWN_HANDLER_CANCEL_PRINT]
gcode:
  SHUTDOWN_HANDLER_STOP_PRINT

[gcode_macro SHOW_MSG]
gcode:
  {% set MSG = params.MSG|default("No msg")|string %}
  M117 {MSG}
  RESPOND MSG={'"%s"' % MSG}

#TODO: AUTO SHUTDOWN POSSIBLY NOT WORK ON ERRORS!

#place the file shutdown.cfg into you config dir
#include this on the top of your printer.cfg
# [include shutdown.cfg]

#Call this in your start_gcode:
# SHUTDOWN_HANDLER_START_PRINT

#Call this AT THE END OF YOUR stop_gcode:
# SHUTDOWN_HANDLER_STOP_PRINT

#Call this in your cancel_gcode:
# SHUTDOWN_HANDLER_CANCEL_PRINT

#if non exists you can allways set one:
#[gcode_macro CANCEL_PRINT]
#rename_existing: CANCEL_PRINT_BASE
#gcode:
#  SHUTDOWN_HANDLER_CANCEL_PRINT
#  CANCEL_PRINT_BASE