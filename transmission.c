/*
 * transmission.c
 *
 *  Created on: Aug 21, 2019
 *      Author: user
 */


#include "tx_rx.h"

double bytes = 0;
long long int noPkt = 0;



void *start_transmission(void *arg)
{
    int usrID = *((int *)arg);

    clock_t time;

    time = clock();
    double time_taken;

    while (time_taken < (SIMULATION_RUN_TIME_MINUTE * 240))
    {
        int i;
        for (i = 0; i<TOTAL_NUMBER_OF_PACKET; i++)
        {
            pthread_mutex_lock(&lock);

            bytes += packet_size[usrID][i];
            noPkt++;
            pthread_mutex_unlock(&lock);

            nanosleep_manually_compensated (packet_time[usrID][i]);
    //        usleep (packet_time[usrID][i]);
        }

        time = clock () - time;
        time_taken = ((double)time)/CLOCKS_PER_SEC;
    }
}


void *receiver (void *arg)
{
//	long long init_time = clock_now();
	FILE *traffic_write;
	traffic_write = fopen ("traffic_simulation.csv","w+");
	setbuf(traffic_write, NULL);
	if (traffic_write == NULL)
	{
		printf ("File not created okay, errno = %d\n", errno);
	}

	fprintf (traffic_write,"Time Scale; Number of Packets; Total data; \n");
	long int time_index = 0;

    clock_t time;
    time = clock();
    double time_taken;

	while (time_taken < (SIMULATION_RUN_TIME_MINUTE * 240))
	{
		sleep (1);

		time_index++;
		pthread_mutex_lock(&lock);
		printf ("%f\n", bytes);

		fprintf (traffic_write,"%ld; %lld; %f; \n", time_index, noPkt, bytes);
		bytes = 0;
		noPkt = 0;
		pthread_mutex_unlock(&lock);

        time = clock () - time;
        time_taken = ((double)time)/CLOCKS_PER_SEC;
	}

}
