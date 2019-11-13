/* 
   event.c

   - events and event queue (PQ) 
   - calls priority to create an event PQ

   ?-
   - is eq a global pq?
   - is init doing anything?
   - is any of this doing anythin?
   - why did we choose this major?
*/

#include "defs.h"


/* initializes events, creates a priority queue */
/* should this be a void void? / is anything happening in this function
   ? - SJK
*/
void event_init(void){
  eq = priority_init(MAX_PASS);
}

/* 
******MEM LEAK IN THIS FUNCTION?*********************
   frees up all event space, including space in the priority
   queue */
void event_fini(event_t *ev){
  if(ev != NULL){
    queue_finalize(ev->queue);
    priority_finalize(eq);
    free(ev->passenger);
    free(ev);
    ev = NULL;
  }
}

event_t *event_create(void){
  event_t *new_ev = (event_t *)malloc(sizeof(event_t));
  new_ev->passenger = (passenger_t *)malloc(sizeof(passenger_t));
  new_ev->queue = (queue_t *)malloc(sizeof(queue_t));
  return new_ev;
}

/* removes and frees top event*/
void event_destroy(event_t *ev){
  ev = priority_remove(eq);
  event_fini(ev);
  
}

/* inserts ev into pq */
void event_schedule(event_t *ev){
  priority_insert(eq,ev);
}

/* pops top off */
/* Is eq a global ? - SJK*/
event_t *event_cause(void){
  event_t * ev = priority_remove(eq);
  return ev;
}
