
#Drive By Wire UDP API command line tool

##Installation instructions

To compile run:
```
cd /home/pi/commander_api/c
gcc -o udpcli udpcli.c
```

To add the path permanently, add the following line at the end of ~/.bashrcfile
```
sudo nano ~/.bashrc
```
Add the below line at the end
```
export PATH=$PATH:/path/to/the/directory
```
like
```
export PATH=$PATH:/home/pi/commander_api/c
```

Use:
```
udpcli set steering 20  /// Set the steering value to 20 degrees
udpcli set braking 0.20   /// Set braking from 0  to 1
udpcli set throttle 0.20  /// Set throttle from 0 to 1
udpcli set speed 20
udpcli set off 
```

## set_throttle(Value)

Press throttle pedal to given position [0.0 ... 1.0].
(1.0 - pressed to maximum, 0.0 - released)


## set_breaking(Value)

Press braking pedal to given position [0.0 ... 1.0].
(1.0 - pressed to maximum, 0.0 - released)


## set_steering(Angle)

Position the car's front wheels to a given angle in degrees [-30.0 ... 30.0].
  - >0.0 - right
  - <0.0 - left
  - =0.0 - stright


## set_speed(Speed)

Drive the car at a given speed in km/h [0.0 ... 50.0].


## set_off()

Turn off all actuators.


#Monitoring

see the UDP packets on localhost
```
sudo tcpdump -i lo -n udp port 8050 -X
tcpdump -i lo udp port 8125 -vv -X
```
To show all UDP packets:
```
sudo tcpdump -n udp dst -i any portrange 8040-8060
```

To show listening UDP ports:
```
netstat -vaun
```