#Erlang example compilation

Install Erlang:
```
sudo apt-get install erlang
```
Compile act.erl:
```
@: cd /home/commander_api/erlang
@: erl
Erlang/OTP 19 [erts-8.2.1] [source] [smp:4:4] [async-threads:10] [kernel-poll:false]
Eshell V8.2.1  (abort with ^G)
1> c(act).
{ok,act}
2>
```
As result act.beam should be created

The use:
```
@: erl
Erlang/OTP 19 [erts-8.2.1] [source] [smp:4:4] [async-threads:10] [kernel-poll:false]
Eshell V8.2.1  (abort with ^G)
1> act:set_steering(10).
[1,0,3,232]
ok
2>
```


Commands:
```
set_steering(Angle) ->
set_throttle(Val) ->
set_braking(Val) ->
set_speed(Speed) ->
set_off() ->
```
