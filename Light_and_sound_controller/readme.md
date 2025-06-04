# Woodpecker 
## Sound and light controller

Woodpecker Sound and light controller is custom made Arduino based system with CAN extarnal board and relay module.
Module consist from: 

1. Arduino Due Mega2560 R3 JOY-IT ARD-Mega2560R3 https://docs.arduino.cc/hardware/due/
2. SeedStudio CAN shield https://wiki.seeedstudio.com/CAN-BUS_Shield_V2.0/
3. 8 Relay Module 

External illunination is done by 6 WS2812B LED strips

Module is operating in 2 ways:
```
1. Prerecorded sequence of illuminations
2. Different signals when connected to CAN and recieve CAN signals (like turns or brakes).
```
The module operates:
1. Led light strips for signal lights;
2. Relays for optional stiop, blinker lamps and headlights;
3. Horn.

The logics of operation is easy readable in comments in ARduino scetch code: https://bitbucket.org/pilotautomotive/woodpecker-detroit-documentation/src/master/Light_and_sound_controller/LED_woodpecker_final_2023_Detroit/LED_woodpecker_final_2023_Detroit.ino