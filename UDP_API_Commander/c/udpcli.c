
/** 
 ** act.c - Actuator API C client funcions -final version
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

int main(int argc,char* argv[]) 
{ 
    int counter; 
    printf("Program Name Is: %s",argv[0]); 
	printf("\n");
   
   	   if(argc<2) 
		
	{	printf("\n");
        printf("No Extra Command Line Argument Passed Other Than Program Name \n"); 
	    printf("Error in argument! Provide command in correct syntax:\n");
	    printf("set steering x.x   |  Value -90 to 90 (degrees). Effective values are -30 to 30. Example 25.16 (degrees to right)\n");
	    printf("set throttle x.x   |  Value from 0 to 1. Example 0.12   =12% (of max throttle).\n");
	    printf("set braking x.x    |  Value from 0 to 1. Example 0.25  =25 (of max braking).\n");
	    printf("set speed x.x      |  Values in km/h. Example 15.45 (km/h speed).\n");
	    printf("set off 0          |  Set all values to 0.\n");
	    printf("\n");
 			if (!strcmp(argv[1], "help")) 
			{ 
				printf("\nNumber Of Arguments Passed: %d",argc); 
				printf("\n----Following Are The Command Line Arguments Passed----"); 
				for(counter=0;counter<argc;counter++) 
					printf("\nargv[%d]: %s",counter,argv[counter]); 
				printf("\n");
			} 	
	}

	 if(argc>2)
	 {
	 double space = atof(argv[3]);
		if ((!strcmp(argv[1], "set"))&&(!strcmp(argv[2], "steering"))&& (-90 <= space && space <= 90))
		  { printf("\nCongratulations - set_steering(%s",(argv[3]));
			printf(")command recieved\n");	
			printf("\n");
			double angle = atof(argv[3]);
			set_steering(angle);
			printf("\n");
		  }
	  
		else if ((!strcmp(argv[1], "set"))&&(!strcmp(argv[2], "braking"))&& (0 <= space && space <= 1))
		  { printf("\nCongratulations - set_braking(%s",(argv[3]));
			printf(")command recieved\n");	
			printf("\n");
			double brakevalue = atof(argv[3]);
			set_braking(brakevalue);
			printf("\n");
		  }
	  
		else if ((!strcmp(argv[1], "set"))&&(!strcmp(argv[2], "throttle"))&& (0 <= space && space <= 1))
		  { printf("\nCongratulations - set_throttle(%s",(argv[3]));
			printf(")command recieved\n");	
			printf("\n");
			double throttlevalue = atof(argv[3]);
			set_throttle(throttlevalue);
			printf("\n");
		  }
		  
		else if ((!strcmp(argv[1], "set"))&&(!strcmp(argv[2], "speed"))&& (0 <= space && space <= 100))
		  { printf("\nCongratulations - set_speed(%s",(argv[3]));
			printf(")command recieved\n");	
			printf("\n");
			double speedvalue = atof(argv[3]);
			set_speed(speedvalue);
			printf("\n");
		  }
		  
	  	else if ((!strcmp(argv[1], "set"))&&(!strcmp(argv[2], "off")))
		  { printf("\nCongratulations - set_off ");
			printf("command recieved\n");	
			printf("\n");
			set_off();
			printf("\n");
		  }	 
		else {
	    printf("\n");
	    printf("Error in argument! Provide command in correct syntax:\n");
	    printf("set steering x.x   |  Value -90 to 90 (degrees). Effective values are -30 to 30. Example 25.16 (degrees to right)\n");
	    printf("set throttle x.x   |  Value from 0 to 1. Example 0.12   =12% (of max throttle).\n");
	    printf("set braking x.x    |  Value from 0 to 1. Example 0.25  =25 (of max braking).\n");
	    printf("set speed x.x      |  Values in km/h. Example 15.45 (km/h speed).\n");
	    printf("set off 0          |  Set all values to 0.\n");
	    printf("\n");}
	 }


	    return 0; 
} 

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
    printf("***********                       Sig Dir ValH ValL  UDP IP:PORT \n");
    printf("*********** UDP steering SENT     %d    %d    %d   %d   %s:%d \n", x[0], x[1], x[2], x[3], UDP_API_ADDR, UDP_API_PORT );
}

void set_throttle(float v0) {
	float degr = v0;
 //   printf("*********** v0 value %f %f\n", v0, degr);
    uint8_t x[3];
    float v = v0 * 1000.0;
 //	  printf("*********** v value %f \n", v);
    x[0] = THROTTLE;
    x[1] = (uint8_t)(v/256);   // ValH
    x[2] = (uint8_t)v-x[1]*256; //ValL
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
	printf("***********                       Sig ValH ValL  UDP IP:PORT \n");
    printf("*********** UDP throttle SENT     %d     %d   %d      %s:%d \n", x[0], x[1], x[2], UDP_API_ADDR, UDP_API_PORT );
}

void set_braking(float v0) {
    uint8_t x[3];
    float v = v0 * 1000.0;
    x[0] = BRAKING;
    x[1] = (uint8_t)(v/256);
    x[2] = (uint8_t)v-x[1]*256;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
	printf("***********                   Sig ValH ValL  UDP IP:PORT \n" );
    printf("*********** UDP braking SENT  %d    %d    %d   %s:%d\n", x[0], x[1], x[2], UDP_API_ADDR, UDP_API_PORT );
}

void set_speed(float v0) {
    uint8_t x[3];
    float v = v0 * 100.0;
    x[0] = SPEED;
    x[1] = (uint8_t)(v/256);
    x[2] = (uint8_t)v-x[1]*256;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
	printf("***********                    Sig ValH ValL  UDP IP:PORT \n");
    printf("*********** UDP speed SENT     %d    %d   %d   %s:%d \n", x[0], x[1], x[2], UDP_API_ADDR, UDP_API_PORT );
}

void set_off() {
    uint8_t x[1];
    x[0] = OFF;
    send_udp_binary((char *)x, sizeof(x), UDP_API_ADDR, UDP_API_PORT);
    printf("*********** UDP off SENT %d UDP %s:%d \n",x[0], UDP_API_ADDR, UDP_API_PORT);
}



