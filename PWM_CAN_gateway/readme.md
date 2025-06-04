# Woodpecker 
## PWM CAN Gateway

Woodpecker PWM CAN Gateway is custom made Arduino based system with CAN external shield and relay module.
Module consist from: 

1. Arduino Due Mega2560 R3 JOY-IT ARD-Mega2560R3 https://docs.arduino.cc/hardware/due/
2. SeedStudio CAN shield https://wiki.seeedstudio.com/CAN-BUS_Shield_V2.0/
3. 8 Relay Module 
4. Taranis Remote module

The module operates:
1. Recieving the radio commands from Tarranis remote in up to 8 channels;
2. Converts recieved PWM values to CAN messages for steering, braking, acceleration regardig the code;
3. Converts PWM signals to signals for switching the relays on or off - Ķey On", Reverse/Forward.

The logics of operation is easy readable in comments in ARduino scetch code: 
https://bitbucket.org/pilotautomotive/woodpecker-detroit-documentation/src/master/PWM_CAN_gateway/Woodpecker_PWM_CAN_GTW_Detroit/Woodpecker_PWM_CAN_GTW_Detroit.ino

