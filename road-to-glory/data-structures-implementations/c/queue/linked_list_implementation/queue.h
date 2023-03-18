#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Creates a new queue
Queue *queue_create();

// Returns true if queue is empty, otherwise false
bool queue_is_empty(Queue *queue_ptr);

// Adds item to the rear of the queue
void enqueue(Queue *queue_ptr, int value);

// Deletes item at the front of queue
int dequeue(Queue *queue_ptr);

// Returns item at the front of queue
int queue_peekFront(Queue *queue_ptr);

// Returns item at the rear of queue
int queue_peekRear(Queue *queue_ptr);

// Outputs items in queue
void queue_print(Queue *queue_ptr);

// Free up memory used by queue
void queue_destroy(Queue *queue_ptr);

// Checks to see if given value is valid for memory, and exits if otherwise
void check_address(void *ptr);