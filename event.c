/*
   event.c

   - events and event queue (PQ)
   - calls priority to create an event PQ

   ?-
*/

#include "defs.h"


/* initializes events, creates a priority queue */

void event_init(void){
  eq = priority_init(MAX_PASS);
}

/*
******MEM LEAK IN THIS FUNCTION?*********************
   frees up all event space, including space in the priority
   queue */
void event_fini(event_t *ev){
<<<<<<< HEAD
=======

>>>>>>> 8d2934c82979b625ac5a3eef0d372b8e2b4cb34d
  //if(ev != NULL){
    
    //free(ev->queue);
    //free(ev->passenger);
    //free(ev);
  // }
<<<<<<< HEAD
=======

>>>>>>> 8d2934c82979b625ac5a3eef0d372b8e2b4cb34d
  priority_finalize(eq);
}

event_t *event_create(void){
  event_t *new_ev = (event_t *)malloc(sizeof(event_t));
<<<<<<< HEAD
  //new_ev->passenger = (passenger_t *)malloc(sizeof(passenger_t));
  //new_ev->queue = (queue_t *)malloc(sizeof(queue_t));
  new_ev->event_type = EV_ARRIVE; // allows for first increment to be EV_ARRIVE
=======

  //new_ev->passenger = (passenger_t *)malloc(sizeof(passenger_t));
  //new_ev->queue = (queue_t *)malloc(sizeof(queue_t));
  new_ev->event_type = EV_ARRIVE; // allows for first increment to be EV_ARRIVE

>>>>>>> 8d2934c82979b625ac5a3eef0d372b8e2b4cb34d

  return new_ev;
}

/* removes and frees top event*/
void event_destroy(event_t *ev){
  //free(ev->queue);
  //free(ev->passenger);
<<<<<<< HEAD
=======

>>>>>>> 8d2934c82979b625ac5a3eef0d372b8e2b4cb34d
  free(ev);


}

/* inserts ev into pq */
void event_schedule(event_t *ev){

  switch(ev->event_type) {
  case (EV_ARRIVE):
    // add time to new event from current time
    ev->event_time = time_get() + interarrival_time();
    break;
  case (EV_AIRLINEQ) :
    // add time to new event from current time
    ev->event_time = time_get() + enter_airline_queue_time();
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
  }

  priority_insert(eq,ev);
  
}

/* pops top off */
event_t *event_cause(void){
  event_t * ev = priority_remove(eq);
  time_set(ev->event_time + time_get());

  return ev;
}
