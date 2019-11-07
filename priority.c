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
event_t * make_PQ(void) {
  event_t *heap = (event_t*)malloc(sizeof(event_t*));
  return heap;
}

/*
  TODO
  code from online to max heapify, check if correct
*/
int * max_heapify(int Arr[], int i, int n)
{
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
