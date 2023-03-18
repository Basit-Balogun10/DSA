#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// Creates a new queue
Queue *queue_create();

// Returns true if queue is empty, otherwise false
bool queue_is_empty(Queue *queue);

// Returns true if queue is empty, otherwise false
bool queue_is_full(Queue *queue);

// Adds item to the rear of the queue
void enqueue(Queue *queue, int value);

// Deletes item at the front of queue
int dequeue(Queue *queue);

// Returns item at the front of queue
int queue_peekFront(Queue *queue);

// Returns item at the rear of queue
int queue_peekRear(Queue *queue);

// Outputs items in queue
void queue_print(Queue *queue);

// Free up memory used by queue
void queue_destroy(Queue *queue);

// Checks to see if given value is valid for memory, and exits if otherwise
void check_address(void *ptr);