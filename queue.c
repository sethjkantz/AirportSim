/* FIFO queues */
/*
  Seth Kantz
  Brandon Shumin
  Bradly Sanders
  queue.c
   - function definitions and stuff

  TODO:
  - add peek, size, and full functions
  - change #define (in .h? ) data types so
    functions with new setup
 */

#ifndef Q_C
#define Q_C 1

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
  initializes and returns a pointer to a new queue
*/

qData * queue_init(int size){

  queue *newQ = (queue *)malloc(size * sizeof(queue));
  newQ->head = NULL;
  newQ->tail = NULL;
  return (qData)newQ;
}

/*
  Adds qData d to a new node at the tail of the queue
*/
void queue_insert(qData *qptr, qData d){
  queue *q = (queue *) qptr;
  qNode *new = (qNode *)malloc(sizeof(qNode *));
  qNode *temp;
  if(q !=NULL && new != NULL){
    // if q exists and space for new exists
    if(q->head == NULL){
      // if empty list
      new->data = d;
      new->next = NULL;
      new->prev = NULL;
      q->head = new;
      q->tail = new;
    } else {
      temp = q->tail;
      new->data = d;
      new->next = NULL;
      new->prev = temp;
      temp->next = new;
      q->tail = new;
    }
    testq("added %p \n",new);
  }
}

/*WIP - find next item in list but dont remove it*/
qData * queue_peek(qData qPtr){

}
/*
  removes the first node and sets the qData pointer to the
  value removed
*/

void queue_remove(qData *qptr, qData *d){
  queue *q = (queue *) qptr;
  qNode *temp;
  if(q != NULL){

    // if not empty
    if(q->head != NULL){
      temp = q->head;
      // if one element
      if(temp->next == NULL){
	q->head = NULL;
	q->tail = NULL;
      }else{
	// if multiple elements
	q->head = temp->next;
	q->head->prev = NULL;
      }

      if(d != NULL){
	       *d = temp->data;
      }
      testq("removed %p \n",temp);
      free(temp);

    }
  }
}

/*
  TODO
  check that this
  returns size of Q
*/
int queue_size(qData *qPtr){
  queue *q = (queue *) *qptr;
  qNode *rov;
  int count = 0;

  //check if queue is not equal
  if(q==NULL) {
    return 0;

  } else {
    rov = q->head;

    while(rov != NULL){
      count++;
      rov = rov->next;
    }

    return count;
  }

}

/*
  TODO
  return nonzero if full
*/
int queue_full(qData *qPtr){

}

/*
  frees each nodes data
  frees said node
  frees queue
*/
void queue_finalize(qData **qptr){
  queue *q = (queue *) *qptr;
  qNode *rov, *prev;
  if(q!=NULL){
    rov = q->head;
    while(rov != NULL){
      free(rov->data);
      prev = rov;
      rov = rov->next;
      testq("removed %p \n",prev);
      free(prev);
    }
    free(q);
  }
}

void q_print(qData *qptr){
  if(qptr != NULL){
    testq("head: %p \n",((queue *)qptr)->head);
    testq("tail: %p \n",((queue *)qptr)->tail);
    testq("\n");
  }else{
   testq("no queue to print \n");
  }
}


#endif
