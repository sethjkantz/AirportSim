/* FIFO queues */
/*
  Seth Kantz
  Brandon Shumin
  Bradly Sanders
  queue.c
   - function definitions and stuff

  TODO:
  - test peek, size, and full functions
  - test functions with new typedefs
  - update queue dType
 */

#ifndef Q_C
#define Q_C 1

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
  initializes and returns a pointer to a new queue
  INPUT: size of queue to be made (as an int)
  OUTPUT:  vP to queue_t
*/
queue_t * queue_init(void){

  queue_t *newQ = (queue_t *)malloc(sizeof(queue_t));
  newQ->head = NULL;
  newQ->tail = NULL;
  newQ->max = size;
  return newQ;
}

/*
  Adds qData d to a new node at the tail of the queue
  INPUT: vP to queue_t, vP to data
  OUTPUT: void
*/
void queue_insert(queue_t *qPtr, int d){
  queue_t *q = qPtr;
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

/*
  INPUT: - void pointer to queue_t
  OUTPUT:  vP to node
  - find next item in list but dont remove it
*/
queue_t * queue_peek(queue_t *qPtr){
  // if not empty
  queue_t *q = qPtr;
  qNode *temp;
  if(q != NULL){
    // if not empty
    if(q->head != NULL)
      return q->head;
  }
  else{
    // if couldnt find item
    return NULL;
  }
}

/*
  removes the first node and sets the qData pointer to the
  value removed
  INPUT: vP to queue_t, vp *d that will be set to removed data
*/
void queue_remove(queue_t *qPtr, int d){
  queue_t *q = qPtr;
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
	       d = temp->data;
      }
      testq("removed %p \n",temp);
      free(temp);
    }
  }
}

/*
  returns size of queue
  INPUT:     vP to queue_t
  OUTPUT:    size as int

*/
int queue_size(queue_t *qPtr){
  queue_t *q = qPtr;
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
  - Checks to see if queue is full
  INPUT:     vP * to queue_t
  OUTPUT:    returns 0 always since linked list
*/
int queue_full(queue_t *qPtr){
  return 0;
}

/*
  frees each nodes data
  frees said node
  frees queue
  INPUT: vP ** to queue_t
*/
void queue_finalize(queue_t **qPtr){
  queue_t *q = *qPtr;
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

void q_print(queue_t *qPtr){
  if(qPtr != NULL){
    testq("head: %p \n",qPtr->head);
    testq("tail: %p \n",qPtr->tail);
    testq("\n");
  }else{
   testq("no queue to print \n");
  }
}


#endif
