/*
   main.c
   -Brandon Shumin
   -Seth Kantz
   -Bradly Sanders

 initialize queues
 */

#include"defs.h"

int main(void){
  /* malloc new EV_ARRIVE event and passenger */
  event_t *new_ev, *airq_ev, *arrival_ev;
  passenger_t *temp_pass;

  event_init();
  time_init();

  new_ev = event_create();
  num_passengers = 1;

  /* schedule EV_ARRIVE event at t=0 and put in event queue */
  new_ev->event_time = time_get();
  event_schedule(new_ev);


  /* run main loop */
  while(!priority_empty(eq))
  {
      //create new event
      new_ev = event_cause();
      fprintf(stdout," ev type = %d \n",new_ev->event_type);
      switch (new_ev->event_type) {
      case (EV_ARRIVE) :
          new_ev->passenger->arrival_time = time_get();
          fprintf(stdout,"Passenger arrived at %f\n",new_ev->passenger->arrival_time);
          temp_pass = new_ev->passenger; //hold out passenger

          //move old passenger to next event
	   event_destroy(new_ev); //clear old event

	        airq_ev = event_create(); //pass to next event
          airq_ev->passenger = temp_pass;
          airq_ev->event_type = EV_AIRLINEQ;

          airq_ev->event_time = enter_airline_queue_time();
          fprintf(stdout, "Passenger will arrive at queue at %f\n", airq_ev->event_time);
          event_schedule(airq_ev);

          /* create EV_ENQUEUE event for this passenger */
          /* schedule EV_ENQUEUE event */
          if (MAX_PASS > num_passengers)
          {
	    // create new EV_ARRIVE event and passsenger
	    // schedule EV_ARRIVE event
	    fprintf(stdout,"New arrival\n");
              arrival_ev = event_create();
              arrival_ev->event_time = interarrival_time();
              event_schedule(arrival_ev);

              num_passengers++; //add new passenger count
          }
          break;
      case (EV_AIRLINEQ) :
        new_ev->passenger->airlineQ_time = time_get();
        fprintf(stdout,"Passenger arrived at airline queue %f\n",new_ev->passenger->airlineQ_time);
        event_destroy(new_ev);
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
      // remaining event types
      default :
          // error
          fprintf(stderr, "Something went wrong.");
          //return -1;
          break;
      }
      // free event

  }

  event_fini(new_ev);
  /* Print overall stats */

  return 0;
}
