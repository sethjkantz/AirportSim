/* various time related functions */
static double sim_time;
//delta time
//current time
void time_init(void){
  sim_time = 0;
}

void time_fini(void){

}

double time_get(void){
  return sim_time;
}

void time_set(double t){
  sim_time = t;
}

double time_arrive(){

}

double time_airline(){

}

double time_id(){

}

double time_scan(){

}

double time_train(){

}

double time_gate(){

}
