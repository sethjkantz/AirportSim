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
event_t *priority_init(int size) {
  event_t *heap = size * (event_t*)malloc(sizeof(event_t*));
  return heap;
}

/*
  TODO
  code from online to max heapify, check if correct
*/
priority_t * max_heapify(priority_t *Arr, int i, int n) {
    int left = 2*i;                //left child
    int right = 2*i + 1;           //right child
    int largest;
    int temp;

    if(left<= n & Arr[left] > Arr[i] )
          largest = left;
    else
         largest = i;
    if(right <= n and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        // swap Arr[i] and Arr[largest]
        temp = Arr[i];
        Arr[i] = Arr[largest];
        Arr[largest] = temp;

        Arr = max_heapify(Arr, largest,n);
    }

    return Arr;
 }

priority_t * min_heapify (priority_t *Arr, int i, int n) {
  int left  = 2*i;
  int right = 2*i+1;
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
      temp = Arr[i];
      Arr[i] = Arr[largest];
      Arr[largest] = temp;
      min_heapify (Arr, smallest,n);
    }
  return Arr;
}
