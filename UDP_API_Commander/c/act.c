
/** 
 ** act.c - Actuator API C client funcions
 **/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>  //For ether_header
#include <netinet/in.h>
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/if_ether.h>  //For ETH_P_ALL

#include "act.h"


int send_udp_binary(char *pmessage, int length, char *addr, int port)
{
    struct sockaddr_in si_other;
    int s, slen=sizeof(si_other);

    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        perror("socket()");
        exit(1);
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(port);

    if (inet_aton(addr , &si_other.sin_addr) == 0)
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }

        //send the message
        if (sendto(s, pmessage, length, 0, (struct sockaddr *) &si_other, slen)==-1)
        {
            perror("sendto()");
            exit(1);
        } 

    close(s);
    return 0;
}


void set_steering(float v0) {  // v0: front wheel angle in degrees [-90..90]
    uint8_t x[4];
    float v = v0 * 100.0;
    float _v = v;
    x[0] = STEERING;
    if (v<0) 
    {
        x[1] = 1; 
        _v=-_v; 
    }
    else
    {
        x[1] = 0;
    }
    x[2] = (uint8_t)(_v/256);
    x[3] = (uint8_t)_v-x[2]*256;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
    printf("*********** UDP steering SENT     %d %d %d \n", x[1], x[2], x[3] );
}

void set_throttle(float v0) {
    uint8_t x[3];
    float v = v0 * 1000.0;
    x[0] = THROTTLE;
    x[1] = (uint8_t)(v/256);
    x[2] = (uint8_t)v-x[1]*256;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
    printf("*********** UDP throttle SENT     %d %d \n", x[1], x[2] );
}

void set_braking(float v0) {
    uint8_t x[3];
    float v = v0 * 1000.0;
    x[0] = BRAKING;
    x[1] = (uint8_t)(v/256);
    x[2] = (uint8_t)v-x[1]*256;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
    printf("*********** UDP braking SENT     %d %d \n", x[1], x[2] );
}

void set_speed(float v0) {
    uint8_t x[3];
    float v = v0 * 100.0;
    x[0] = SPEED;
    x[1] = (uint8_t)(v/256);
    x[2] = (uint8_t)v-x[1]*256;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
    printf("*********** UDP speed SENT     %d %d \n", x[1], x[2] );
}

void set_off() {
    uint8_t x[1];
    x[0] = OFF;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
    printf("*********** UDP off SENT\n" );
}


