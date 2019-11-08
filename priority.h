/* priority.h */




struct Heap{
  event_t *array;
  int Items;
  int MAXCAPACITY;
};

typedef struct priority_s priority_t;



/* create and initialize a new priority queue
   must be able to hold at least size items
   return pointer to the new priority queue, NULL if error */
priority_t *priority_init(int size);

/* insert an item into the priority queue
   return 0 if successful, -1 otherwise */
int priority_insert(priority_t *heap, event_t *ev);

/* remove the highest priority item from the queue
   and return it, return NULL if there is an error */
event_t *priority_remove(priority_t *heap);

/* return non-zero if the priority queue is empty */
int priority_empty(priority_t *heap);

/* return nono-zero if the priority queue is full
   This may be trivial using a linked implementation */
int priority_full(priority_t *heap);

/* free all resources used by the priority queue then free
   the queue itself */
void priority_finalize(priority_t *heap);

/* heapify the heap with max at top */
priority_t * max_heapify(priority_t *Arr, int i, int n);

/* heapify the heap with main at top */
priority_t * min_heapify (priority_t *Arr, int i, int n);
