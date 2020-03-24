/*
 * tx_rx.h
 *
 *  Created on: Aug 21, 2019
 *      Author: user
 */


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <error.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include "common.h"
#include "pthread.h"


#define TOTAL_USER 							1000
//#define TOTAL_NUMBER_OF_PACKET  			100000
#define TOTAL_NUMBER_OF_PACKET  			100000
#define SEC_TO_NANO_SECONDS  				1000000000
#define SIMULATION_RUN_TIME_MINUTE			60

POneSourceOnOff completeSetOfSourcesToUse [TOTAL_USER];

double packet_size[TOTAL_USER][TOTAL_NUMBER_OF_PACKET];
double packet_time[TOTAL_USER][TOTAL_NUMBER_OF_PACKET];

pthread_mutex_t lock;

//void receiver ();
void *receiver (void *arg);
void *start_transmission(void *arg);
void nanosleep_manually_compensated(myInteger expected_duration);
myInteger clock_now(void);
void initialize_stat_report ();
