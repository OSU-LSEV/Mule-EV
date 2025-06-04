/** 
 ** udp_api.h - UDP API for commander
 **/

#ifndef ACT_H
#define ACT_H

/*
 * @brief Commands
 *
 */
#define STEERING      1
#define THROTTLE      2
#define BRAKING       3
#define SPEED         4
#define OFF           0

/*
 * @brief Connection
 *
 */
#define UDP_API_ADDR      "127.0.0.1"
#define UDP_API_PORT      8050

/*
 * @brief Car actuator API functions
 *
 */
void set_steering(float);
void set_throttle(float);
void set_braking(float);
void set_speed(float);
void set_off();

#endif /* ACT_H */

