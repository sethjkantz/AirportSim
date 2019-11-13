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
  event_t *start_ev, *new_ev;
  start_ev = event_create();  // this causes a mem leak - prolly not being finilized
  new_ev = event_create();
  /* schedule EV_ARRIVE event at t=0 and put in event queue */
  start_ev->event_time = 0.0;
  event_schedule(start_ev);
  new_ev = start_ev;
  //eq = priority_init();

  /* run main loop */
  while(!priority_empty(eq))
  {
      new_ev = event_cause();
      time_set(new_ev->event_time);

      switch (new_ev->event_type)
      {
      case (EV_ARRIVE) :
          new_ev->passenger->arrival_time = time_get();
          /* create EV_ENQUEUE event for this passenger */
          /* schedule EV_ENQUEUE event */
          if (MAX_PASS > num_passengers++)
          {
              /* create new EV_ARRIVE event and passsenger */
              /* schedule EV_ARRIVE event */
          }
          break;
      case (EV_AIRLINEQ) :
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
      /* remaining event types */
      default :
          /* error */
          fprintf(stderr, "Something went wrong.");
          //return -1;
          break;
      }
      /* free event */
  }
  event_fini(start_ev);
  event_fini(new_ev);
  /* Print overall stats */
  return 0;
}
