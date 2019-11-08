/* events and event queue (PQ) */
//calls priority to create an event PQ

//event_time takes in event type and returns the time
double event_time(event_t *ev) {
  return ev->time;
}

/* initializes events, creates a priority queue */
void event_init(void){

}

/* frees up all event space, including space in the priority
   queue */
void event_fini(event_t *ev){

}

event_t *event_create(void){
  event_t *new_ev;
  new_ev.passenger = (passenger_t *)malloc(sizeof(passenger_t));
  new_ev.queue = (queue_t *)malloc(sizeof(queue_t));
  return new_ev;
}

void event_destroy(event_t *ev){

}

void event_schedule(event_t *ev){

}

event_t *event_cause(void){

}
