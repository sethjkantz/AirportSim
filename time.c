/* various time related functions */
static double sim_time;
//delta time
//current time
void time_init(void){
  sim_time = 0;
}

void time_fini(void){
  //not implemented in this stage
}

double time_get(void){
  return sim_time;
}

void time_set(double t){
  sim_time = t;
}

// returns arrival time
double time_arrive(){
  return interarrival_time();
}

// blank
double time_airline(){
  return enter_airline_queue_time();
}

// blank
double time_id(){
  return enter_airline_queue_time();
}

// blank
double time_scan(){
  return enter_airline_queue_time();
}

// blank
double time_train(){
  return enter_airline_queue_time();
}

// blank
double time_gate(){
  return enter_airline_queue_time();
}
