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

// returns arrival time
double time_arrive(){

}

// blank
double time_airline(){
  return 0;
}

// blank
double time_id(){
  return 0;
}

// blank
double time_scan(){
  return 0;
}

// blank
double time_train(){
  return 0;
}

// blank
double time_gate(){
  return 0;
}
