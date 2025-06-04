
# Commander API functions

Functions for control of car's actuators (steering, throttle, braking)


## Configuration

Set IP address and port number of commender node UDP server (in act.h file)

```
#define UDP_API_ADDR      "127.0.0.1"
#define UDP_API_PORT      8050
```


## set_throttle(Value)

Press throttle pedal to given position [0.0 ... 1.0].
(1.0 - pressed to maximum, 0.0 - released)


## set_breaking(Value)

Press braking pedal to given position [0.0 ... 1.0].
(1.0 - pressed to maximum, 0.0 - released)


## set_steering(Angle)

Position the car's front wheels to a given angle in degrees [-22.0 ... 22.0].
  - >0.0 - right
  - <0.0 - left
  - =0.0 - stright


## set_speed(Speed)

Drive the car at a given speed in km/h [0.0 ... 50.0].


## set_off()

Turn off all actuators.


