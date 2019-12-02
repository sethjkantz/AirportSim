/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "sim.h"
#include "event.h"
#include "queue.h"
#include "time.h"
 
#define MAX_PASS 100
#define MAX_SCAN 4
#define QSZ 100 /* not used by queue.c */

static void parse_args(argc, argv);

int num_passengers = 0; /* counts the number of passengers */

queue_t *airlineQ;
queue_t *idQ;
queue_t *scanQ[MAX_SCAN];
queue_t *trainQ;

int main(int argc, char **argv)
{
    /* process command line arguments */
    parse_args(argc, argv);

    /* initialize modules */
    event_init(QSZ);
    time_init();
    
    event_t *start_ev;
    start_ev = event_create();
    start_ev->passenger = passenger_create();
    start_ev->passenger->pass_id = ++num_passengers;
    start_ev->event_time = 0.0;
    start_ev->event_type = EV_ARRIVE;
    event_schedule(start_ev);
    /* run main loop */
    while(!event_empty())
    {
        event_t *new_ev;
        new_ev = event_cause();
        time_set(new_ev->event_time);
        switch (new_ev->event_type)
        {
        case (EV_ARRIVE) :
        {
            event_t *airline_ev;

            printf("new passenger %d arrives: %f\n",
                   new_ev->passenger->pass_id, 
                   new_ev->event_time);

            airline_ev = event_create();
            airline_ev->passenger = new_ev->passenger;
            airline_ev->passenger->arrival_time = time_get();
            airline_ev->event_time = time_airlineQ();
            airline_ev->event_type = EV_AIRLINEQ;
            event_schedule(airline_ev);
            if (MAX_PASS > num_passengers++)
            {
                event_t *arrive_ev;
                arrive_ev = event_create();
                arrive_ev->passenger = passenger_create();
                arrive_ev->passenger->pass_id = ++num_passengers;
                arrive_ev->event_time = time_arrive();
                arrive_ev->event_type = EV_ARRIVE;
                event_schedule(arrive_ev);
            }
        }
            break;
        case (EV_AIRLINEQ) :
            printf("passenger %d departs: %f\n", 
                   new_ev->passenger->pass_id,
                   new_ev->event_time);
            passenger_destroy(new_ev->passenger);
            break;
        case (EV_AIRLINE) :
            break;
        case (EV_IDQ) :
            break;
        case (EV_ID) :
            break;
        case (EV_SCANQ) :
            break;
        case (EV_SCAN) :
            break;
        case (EV_TRAINQ) :
            break;
        case (EV_TRAIN) :
            break;
        case (EV_GATE) :
            break;
    
        default :
            /* error */
            break;
        }
        /* free event */
        event_destroy(new_ev);
    }
    /* Print overall stats */
    /* finalize modules */
    event_finalize();
    time_finalize();
    return 0;
}

static void parse_args(argc, argv)
{
    /* optional command line args processed here */
}
