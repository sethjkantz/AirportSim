/* PQ implemented as a heap   */
/* also called the event queue*/

/* Arr[(i-1)/2]	Returns the parent node     */
/* Arr[(2*i)+1]	Returns the left child node */
/* Arr[(2*i)+2]	Returns the right child node*/

/*
  TODO
  figure if this works
  creates an empty array with a single NULL value as per malloc
  can be used as an array
*/
  priority_t *priority_init(int size) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));

    if(heap==NULL){
      printf("\nMemory Allocation Error in Structure Malloc.\n");
      return;
    }

    heap->Items = 0;
    heap->MAXCAPACITY = size;
    heap->array = (event_t *)malloc(size*sizeof(int));

    if(heap->array==NULL){
      printf("\nMemory Allocation Error in Array Malloc\n");
      return;
    }
    return heap;
}

/*
  WIP
  insert an item into the priority queue
     return 0 if successful, -1 otherwise
*/
  int priority_insert(priority_t *heap, event_t *ev){
    int index = heap->Items;
    int success = 0;

    if(priority_full(heap)!=0)
    {
      printf("\nQueue is full!\n");
      success = -1;
      return success;
    }
    else{
      heap->array[index] = ev;
      //min_heapify(heap,x,x) //FIX THIS
      index++;
    }

    heap->Items = index;
    return success;
}

  event_t *priority_remove(priority_t *heap){
    event_t Event;

    if(priority_empty(heap)!=0){
      printf("\nEmpty Heap.\n");
    }

    Event = heap->array[0];
    heap->array[0] = heap->array[heap->Items-1];
    heap->Items--;
    //min_heapify(heap,x,x) FIX THIS
    return Event;
  }

  int priority_empty(priority_t *heap){
    if(heap->Items == 0){
      printf("Heap is Empty");
      return -1;
    }
    return 0;
  }

// /*
//   code from online to max heapify, not needed pretty sure
// */
// priority_t * max_heapify(priority_t *Arr, int i, int n) {
//     int left = 2*i;                //left child
//     int right = 2*i + 1;           //right child
//     int largest;
//     int temp;
//
//     if(left<= n & Arr[left] > Arr[i] )
//           largest = left;
//     else
//          largest = i;
//     if(right <= n and Arr[right] > Arr[largest] )
//         largest = right;
//     if(largest != i )
//     {
//         // swap Arr[i] and Arr[largest]
//         temp = Arr[i];
//         Arr[i] = Arr[largest];
//         Arr[largest] = temp;
//
//         Arr = max_heapify(Arr, largest,n);
//     }
//
//     return Arr;
//  }

/*
   code from online to min heapify
*/
priority_t * min_heapify (priority_t *Arr, int i, int n) {
  int left  = 2*i+1;
  int right = 2*i+2;
  int smallest, temp;

  if(left <= n and Arr[left] < Arr[i] )
       smallest = left;
  else
      smallest = i;
  if(right <= n and Arr[right] < Arr[smallest]){
    smallest = right;
  }
  if(smallest != i) {
      //swap Arr[i] and Arr[smallest]
      temp = Arr[smallest];
      Arr[smallest] = Arr[i];
      Arr[i] = temp;
      min_heapify (Arr,smallest,n);
    }
  return Arr;
}
