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

<<<<<<< HEAD
double time_arrive(void){
  
}

double time_airline(void){

}

double time_id(void){

}

double time_scan(void){

}

double time_train(void){

}

double time_gate(void){

=======
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
>>>>>>> 2a1ce9aab1756a3349786952fd81abbd8e2d8650
}
