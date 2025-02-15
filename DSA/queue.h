#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Define the queue node structure
typedef struct queue_node {
  void* data;
  struct queue_node* next;
} queue_node_t;

// Define the queue structure
typedef struct queue {
  queue_node_t* front;
  queue_node_t* rear;
} queue_t;

// Function prototypes
queue_t* queue_create(void);
void queue_destroy(queue_t* q);
bool queue_is_empty(queue_t* q);
bool queue_enqueue(queue_t* q, void* data);
void* queue_dequeue(queue_t* q);
void* queue_peek(queue_t* q);
void queue_print(queue_t* q);

#endif  // QUEUE_H
