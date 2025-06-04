%% 
%% act.erl - Actuator API Erlang client funcions
%%

-module(act).
-compile(export_all).

-define(STEERING,        1).
-define(THROTTLE,        2).
-define(BRAKING,         3).
-define(SPEED,           4).
-define(OFF,             0).

-define(UDP_API_ADDR,    "127.0.0.1").
-define(UDP_API_PORT,    8050).


set_steering(Angle) ->
    A = abs(round(Angle*100.0)),
    Sign = if Angle < 0   -> 1; 
    	      true        -> 0 
    	   end,
    send([?STEERING, Sign, A div 256, A rem 256]).

set_throttle(Val) ->
    A = abs(round(Val*100.0)),
    Sign = if Val < 0     -> 1; 
    	      true        -> 0 
    	   end,
    send([?THROTTLE, Sign, A div 256, A rem 256]).

set_braking(Val) ->
    A = abs(round(Val*100.0)),
    send([?BRAKING, A div 256, A rem 256]).

set_speed(Speed) ->
    A = abs(round(Speed*100.0)),
    send([?SPEED, A div 256, A rem 256]).

set_off() ->
    send([?OFF]).

send(Msg) ->
    {ok, Socket} = gen_udp:open(0, [binary]),
    io:format("~p~n",[Msg]),
    ok = gen_udp:send(Socket, ?UDP_API_ADDR, ?UDP_API_PORT, Msg),
    gen_udp:close(Socket).


test0() ->
    set_off(),
    set_throttle(10),
    set_braking(10),
    set_speed(-10),
    set_steering(0),
    set_steering(1),
    set_steering(2),
    set_steering(-1),
    set_steering(-2),
    set_steering(77),
    set_steering(-77),
    true.


test() ->
    set_off(),
    timer:sleep(1000),

    set_throttle(35),
    set_steering(30),
    timer:sleep(3000),

    set_throttle(30),
    set_steering(70),
    timer:sleep(3000),

    set_off(),

    set_throttle(-30),
    timer:sleep(3000),
    set_off(),
    true.

