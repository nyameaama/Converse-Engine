
# FULL BUILD
ECU_BUILD.out: COMPONENTS.o MODULEROUTER.o AETS.o CONTROL.o TELEMETRY.o UTILITY.o GPIO.o
	g++ -o COMPONENTS.o MODULEROUTER.o AETS.o CONTROL.o TELEMETRY.o UTILITY.o GPIO.o

# COMPONENT BUILD
COMPONENTS.o: ecu_components.h ecu_components.c
	g++ -c ecu_components.h ecu_components.c

# MODULE ROUTER BUILD
MODULEROUTER.o: route.h route.c
	g++ -c route.h route.c

# AETS BUILD
AETS.o: _AETS.h _AETS.c 
	g++ -c _AETS.h _AETS.c

# CONTROL BUILD
CONTROL.o: tasks.h tasks.c
	g++ -c tasks.h tasks.c

#TELEMETRY BUILD
TELEMETRY.o: _telemetry.h _telemetry.c
	g++ -c _telemetry.h _telemetry.c

# UTILITY BUILD
UTILITY.o: ecu_time.h ecu_time.c
	g++ -c ecu_time.h ecu_time.c

# GPIO BUILD
GPIO.o: ecu_gpio.h ecu_gpio.c
	g++ -c ecu_gpio.h ecu_gpio.c 