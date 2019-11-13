/* PQ implemented as a heap   */
/* also called the event queue*/

/* Arr[(i]	Returns the parent node     */
/* Arr[(2*i)]	Returns the left child node */
/* Arr[(2*i)+1]	Returns the right child node*/
#include "defs.h"
/*
  TODO
  figure if this works
  creates an empty array with a single NULL value as per malloc
  can be used as an array
*/
  priority_t *priority_init(int size) {
    priority_t *heap = (priority_t *)malloc(sizeof(priority_t));

    if(heap==NULL){
      fprintf(stdout,"\nMemory Allocation Error in Structure Malloc.\n");
      return NULL;
    }

    heap->items = 0;
    heap->MAXCAPACITY = size;
    heap->array = (event_t **)malloc(size*sizeof(event_t));
    if(heap->array==NULL){
      fprintf(stdout,"\nMemory Allocation Error in Array Malloc\n");
      return NULL;
    }

    return heap;
}

/*
  WIP
  insert an item into the priority queue
     return 0 if successful, -1 otherwise
*/
  int priority_insert(priority_t *heap, event_t *ev){
    int index = heap->items;
    int success = 0;

    if(priority_full(heap)!=0)
    {
      fprintf(stdout,"\nQueue is full!\n");
      success = -1;
      return success;
    }
    else{
      heap->array[index] = ev;
      //min_heapify(heap,x,x) //FIX THIS
      index++;
    }

    heap->items = index;
    return success;
}

  event_t *priority_remove(priority_t *heap){
    event_t * Event;

    if(priority_empty(heap)!=0){
      fprintf(stdout,"\nEmpty priority_t.\n");
    }

    Event = heap->array[0];
    heap->array[0] = heap->array[heap->items-1];
    heap->items--;
    //min_heapify(heap,x,x) FIX THIS
    return Event;
  }

  int priority_empty(priority_t *heap){
    if(heap->items == 0){
      fprintf(stdout,"priority_t is Empty");
      return -1;
    }
    return 0;
  }

  int priority_full(priority_t *heap){
    if(heap->items < heap->MAXCAPACITY){
       return 0;
    }
    else{
      return 1;
    }
  }

  void priority_finalize(priority_t *heap){

  }

priority_t * min_heapify (priority_t *heap, int i, int n) {
  int left  = 2*i;
  int right = 2*i+1;
  int smallest;
  event_t *temp;

  // double check exists
  if(heap == NULL)
    return NULL;

  if(heap->items == 1) {
    return heap;
  }

  if((left <= n) &&  (heap->array[left]->event_time < heap->array[i]->event_time) )
      smallest = left;
  else
      smallest = i;
  if((right <= n) && (heap->array[right]->event_time < heap->array[smallest]->event_time)){
    smallest = right;
  }
  if(smallest != i) {
      //swap Arr[i] and Arr[smallest]
      temp = heap->array[smallest];
      heap->array[smallest] = heap->array[i];
      heap->array[i] = temp;
      heap = min_heapify (heap,smallest,n);
    }
  return heap;
}
