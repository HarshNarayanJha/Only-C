#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new empty queue
queue_t *queue_create(void) {
  queue_t *q = malloc(sizeof(queue_t));
  if (q == NULL) {
    return NULL;
  }
  q->front = q->rear = NULL;
  return q;
}

// Destroy the queue and free all allocated memory
void queue_destroy(queue_t *q) {
  queue_node_t *current = q->front;
  while (current != NULL) {
    queue_node_t *next = current->next;
    free(current);
    current = next;
  }
  free(q);
}

// Check if the queue is empty
bool queue_is_empty(queue_t *q) { return q->front == NULL; }

// Add a new element to the back of the queue
bool queue_enqueue(queue_t *q, void *data) {
  queue_node_t *new_node = malloc(sizeof(queue_node_t));
  if (new_node == NULL) {
    return false;
  }
  new_node->data = data;
  new_node->next = NULL;

  if (queue_is_empty(q)) {
    q->front = q->rear = new_node;
  } else {
    q->rear->next = new_node;
    q->rear = new_node;
  }
  return true;
}

// Remove and return the element at the front of the queue
void *queue_dequeue(queue_t *q) {
  if (queue_is_empty(q)) {
    fprintf(stderr, "Error: Cannot dequeue from an empty queue.\n");
    return NULL;
  }

  queue_node_t *temp = q->front;
  void *data = temp->data;
  q->front = temp->next;
  free(temp);

  if (q->front == NULL) {
    q->rear = NULL;
  }

  return data;
}

// Return the element at the front of the queue without removing it
void *queue_peek(queue_t *q) {
  if (queue_is_empty(q)) {
    fprintf(stderr, "Error: Cannot peek into an empty queue.\n");
    return NULL;
  }

  return q->front->data;
}

// Print the queue elements
void queue_print(queue_t *q) {
  if (queue_is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue: ");
  queue_node_t *current = q->front;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int my_main() {
  queue_t *q = queue_create();

  queue_enqueue(q, (void *)1);
  queue_enqueue(q, (void *)2);
  queue_enqueue(q, (void *)3);
  printf("%d ", queue_dequeue(q));
  queue_enqueue(q, (void *)4);
  queue_enqueue(q, (void *)5);
  queue_enqueue(q, (void *)6);

  queue_print(q);

  printf("%d ", queue_dequeue(q));
  printf("%d ", queue_dequeue(q));
  printf("%d ", queue_dequeue(q));
  printf("%d ", queue_dequeue(q));
  printf("%d ", queue_dequeue(q));

  queue_print(q);

  return 0;
}
