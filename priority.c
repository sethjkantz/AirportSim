/*
   priority.c

   PQ implemented as a heap
   also called the event queue

   Arr[(i)]	Returns the parent node
   Arr[(2*i)+1]	Returns the left child node
   Arr[(2*i)+2]	Returns the right child node*/

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
    printf("init\n");
    return heap;
}

/*
  insert an item into the priority queue
     return 0 if successful, -1 otherwise
*/
  int priority_insert(priority_t *heap, event_t *ev){
    int index;
    int success = -1;

    if(heap==NULL) return -1;

    index = heap->items;

    if(!priority_full(heap)){
      heap->array[index] = ev;
      (heap->items)++;
      heap = min_heapify(heap,0);
      success = 0;
    }
    printf("insert\n");
    return success;
}

/*
  removes top priority event and returns it
*/
  event_t *priority_remove(priority_t *heap){
    event_t * Event;

    if(heap == NULL){

      return NULL;
    }
    if(priority_empty(heap)) return NULL;

    Event = heap->array[0];
    /*
      I'm kinda tired but I dont think this is the correct removal process - SJK
     */
    heap->array[0] = heap->array[heap->items - 1];
    free(heap->array[heap->items - 1]);
    heap->items--;
    min_heapify(heap,0);
    printf("remove\n");
    return Event;
  }

/*1 if empty*/
  int priority_empty(priority_t *heap){
    int ret = 0;
    if(heap==NULL) return 1;

    if(heap->items == 0){
      fprintf(stdout,"priority_t is Empty");
      ret = 1;
    }
    return ret;
  }

/* 1 if full*/
  int priority_full(priority_t *heap){
    int ret = 0;

    if(heap==NULL) return 0;
    if(heap->items >= heap->MAXCAPACITY) ret = 1;
    return ret;
  }

/*
  terminates heap
*/
void priority_finalize(priority_t *heap){
  if(heap==NULL) return;

  while(!priority_empty(heap)){
    free(priority_remove(heap));
  }

  free(heap);
}

/* swaps vals downward to get min to top */
priority_t * min_heapify (priority_t *heap, int i) {
  int left  = 2*i+1;
  int right = 2*i+2;
  int smallest, n;
  event_t *temp;

  // double check exists
  if(heap == NULL) return NULL;
  if(((heap->items) == 1) || (i <= 0)) return heap;

  //number of nodes to heapify
  n = heap->MAXCAPACITY;


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
      heap = min_heapify (heap,smallest);
    }
  return heap;
}

priority_t* heapify_bottom_top(priority_t *h,int i){
    int temp;
    int parent = (i-1)/2;

    //check if nodes need to be swapped
    if(h->array[parent] > h->array[i]){
        //swap and recursive call
        temp = h->array[parent];
        h->array[parent] = h->array[i];
        h->array[i] = temp;
        heapify_bottom_top(h,parent);
    }
}

void heapify_top_bottom(Heap *h, int parent_node){
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != parent_node){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        // recursive  call
        heapify_top_bottom(h, min);
    }
}
