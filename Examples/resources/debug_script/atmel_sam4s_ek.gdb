#*******************************************************
#
#  Connect to J-Link and debug application in flash.
#

# define 'reset' command
define reset

# Connect to the J-Link gdb server
#target remote localhost:4444
target remote | openocd -f "../resources/openocd/atmel_sam4s_xplained.cfg" -c "gdb_port pipe; log_output openocd.log"

# Reset the chip to get to a known state
monitor reset

# Select flash device (Should be AT91SAM4S16C, but it is not available now)
monitor flash device = AT91SAM4S16C
# Enable flash download and flash breakpoints
monitor flash download = 1

# Load the program
load

# Reset peripheral  (RSTC_CR)
set *0x400e1400 = 0xA5000004

# Initializing PC and stack pointer
mon reg sp=(0x400000)
mon reg pc=(0x400004)
info reg

# end of 'reset' command
end
