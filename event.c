/* events and event queue (PQ) */
//calls priority to create an event PQ

// //event_time takes in event type and returns the time
// double event_time(event_t *ev){
//   return ev->time;
// }
#include "defs.h"
/* initializes events, creates a priority queue */
void event_init(void){
  int size;
  size = MAX_PASS;
  priority_t Events = priority_init(size);
}

/* frees up all event space, including space in the priority
   queue */
void event_fini(event_t *ev){
  qNode *rov;
  if(ev != NULL){
    queue_finalize(&(ev->queue));
  
  
    free(ev);
  }
}

event_t *event_create(void){
  event_t *new_ev = (event_t *)malloc(sizeof(event_t));
  new_ev->passenger = (passenger_t *)malloc(sizeof(passenger_t));
  new_ev->queue = (queue_t *)malloc(sizeof(queue_t));
  return new_ev;
}

void event_destroy(event_t *ev){

}

void event_schedule(event_t *ev){

}

/* pops top off */
event_t *event_cause(void){
  event_t * ev = priority_remove(eq);
  return ev;
}
