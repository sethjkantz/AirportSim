/* queue.h */
// FIXME change all return types to non-void types
// just shlappin this in here for now, prolly gonna alter
typedef void * vP; //FIXME get rid of this bad boy and replace everywhere
typedef int q_dtype;

typedef struct node{
  int data;
  struct node *next;
  struct node *prev;
} qNode;

typedef struct queue_s{
  qNode *head;
  qNode *tail;
  int max;
} queue_t;

/* create and initialize a new queue
   must be able to hold at least size items
   return pointer to the new queue, NULL if error */
queue_t * queue_init(void);

/* insert an item into the queue
   return 0 if successful, -1 otherwise */
void queue_insert(vP *qptr, int d);

/* return the next item in the queue but do not remove it
   return NULL if the queue is empty or an error */
vP * queue_peek(vP qPtr);

/* remove the next item from the queue
   and return it, return NULL if there is an error */
void queue_remove(vP *qptr, vP *d);

/* return the number of items in the queue
   You can see if queue is empty with this */
int queue_size(queue_t *q);

/* return nono-zero if the queue is full
   This may be trivial using a linked implementation */
int queue_full(vP *qPtr);

/* free all resourced used by the queue then free
   the queue itself */
void queue_finalize(vP **qptr);

/* FIXME prints out the queue */
void q_print(vP *qptr);
