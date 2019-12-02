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

static void parse_args(int argc, char** argv);

int num_passengers = 0; /* counts the number of passengers */
int atAirlineDesk = 0;

queue_t *airlineQ;
queue_t *idQ;
queue_t *scanQ[MAX_SCAN];
queue_t *trainQ;
queue_t *id;

int main(int argc, char **argv)
{
  int i;
  event_t *airline_ev;
  event_t *new_ev;
  event_t *start_ev;
  event_t *arrive_ev;
  event_t *scan_ev;
  event_t *train_ev;
  event_t *id_ev;

  /* process command line arguments */
    parse_args(argc, argv);

    /* initialize modules */
    event_init(QSZ);
    time_init();


    start_ev = event_create();
    start_ev->passenger = passenger_create();
    start_ev->passenger->pass_id = ++num_passengers;
    start_ev->event_time = 0.0;
    start_ev->event_type = EV_ARRIVE;
    event_schedule(start_ev);

    airlineQ = queue_init(QSZ);
    idQ = queue_init(QSZ);
    trainQ = queue_init(QSZ);
    for(i=0;i<MAX_SCAN;i++)
      scanQ[i] = queue_init(QSZ);

    /* run main loop */
    while(!event_empty())
    {

        new_ev = event_cause();
        //time_set(new_ev->event_time);
        switch (new_ev->event_type)
        {
        case (EV_ARRIVE) :
        {

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

                arrive_ev = event_create();
                arrive_ev->passenger = passenger_create();
                arrive_ev->passenger->pass_id = num_passengers;
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

          if((atAirlineDesk == 1) ){
             queue_insert(airlineQ, new_ev);
          }

          else if(atAirlineDesk == 0){

            if(queue_peek(airlineQ)!=NULL){
              new_ev = queue_remove(airlineQ);
            }

            airline_ev = event_create();
            airline_ev->passenger = new_ev->passenger;
            airline_ev->passenger->airlineQ_time = time_get();
            airline_ev->event_time = time_airline();
            airline_ev->event_type = EV_AIRLINE;
            event_schedule(airline_ev);
          }
          break;

        case (EV_AIRLINE) :
          printf("new passenger %d arrives at airline desk: %f\n",
               new_ev->passenger->pass_id,
               new_ev->event_time);

          id_ev = event_create();
          id_ev->passenger = new_ev->passenger;
          id_ev->passenger->airline_time = time_get();
          id_ev->event_time = time_airlineQ();
          id_ev->event_type = EV_IDQ;
          //grab next passenger from queue
        event_schedule(id_ev);

            break;
        case (EV_IDQ) :

            break;
        case (EV_ID) :
          printf("new passenger %d arrives at ID desk: %f\n",
               new_ev->passenger->pass_id,
               new_ev->event_time);

          scan_ev = event_create();
          scan_ev->passenger = new_ev->passenger;
          scan_ev->passenger->id_time = time_get();
          scan_ev->event_time = time_airlineQ();
          scan_ev->event_type = EV_SCANQ;
        //grab next person from queue
            break;
        case (EV_SCANQ) :
            break;
        case (EV_SCAN) :
        //empty for now
            break;
        case (EV_TRAINQ) :
            break;
        case (EV_TRAIN) :
          printf("new passenger %d arrives at train: %f\n",
               new_ev->passenger->pass_id,
               new_ev->event_time);

          train_ev = event_create();
          train_ev->passenger = new_ev->passenger;
          train_ev->passenger->train_time = time_get();
          train_ev->event_time = time_airlineQ();
          train_ev->event_type = EV_SCANQ;
        //grab next person from queue
            break;
        case (EV_GATE) :
          printf("passenger %d departs: %f\n",
               new_ev->passenger->pass_id,
               new_ev->event_time);
          new_ev->passenger->gate_time = time_get();
          passenger_destroy(new_ev->passenger);
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

static void parse_args(int argc,char **argv)
{
    /* optional command line args processed here */
}
