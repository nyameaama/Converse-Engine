# Firmware RoadMap

STM32F7 

## Component Drivers Development

Control:
- Solenoid Valve
- Pump 

Measurement:b
- Pressure Transducers
- Thermocouple

## Battery Management 

- Lithium Ion Battery Interface

## Engine Control

- Starting enigine
- Terminating engine

## AETS (Automatic Engine Termination System)

- AETS compares simulation data to actual engine performance. If operation is not in bounds engine is terminated

## Telemetry-Communication Module

-  Compile transducer and thermocouple data and send comms


## Engine Setup

- State
* ARMED -> 1 minute timer |  
* PREP -> 
* IDLE -> NO PROCESS | init terminal connection

** IF CONNECTION TO TERMINAL-CONTROLLER BREAKS, ENGINE OPERATION STOPS

Pre-conditioning Systems

- Engine Chill
* Check pipe temps
* if temps < (t(nominal)) -> Start chill
* Open LOX valves
* Pipe temp Feedback Control

- Engine Purging
* Remove residual propellant through gas flow





