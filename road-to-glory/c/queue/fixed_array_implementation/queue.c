#include <stdlib.h>
#include <stdio.h>

Queue *queue_create(int capacity) {
    Queue *queue_ptr = malloc(sizeof(Queue));
    queue_ptr->front = queue_ptr->rear = -1;
    queue_ptr->size = 0;
    queue_ptr->capacity = capacity;
    
    queue_ptr->data = malloc(sizeof(int) * capacity);
    return queue_ptr;
}

bool queue_is_empty(Queue *queue_ptr) {
    if (queue_ptr->front == -1 && queue_ptr->rear == -1) {
        return true;
    }
    return false;
}

bool queue_is_full(Queue *queue_ptr) {
    if (queue_ptr->size == queue_ptr->capacity) {
        return true;
    }
    return false;
}

void enqueue(Queue *queue_ptr, int value) {
    if (queue_is_full(queue_ptr)) {
        printf("Enqueue operation failed! Queue is full");
        exit(EXIT_FAILURE);
    }

    if (queue_is_empty(queue_ptr)) {
        queue_ptr->front = queue_ptr->rear = 0;
    } else {
        queue_ptr->rear += 1;
    }
    
    queue_ptr->data[queue_ptr->rear] = value;
    queue_ptr->size += 1;
}

int dequeue(Queue *queue_ptr) {
    if (queue_is_empty(queue_ptr)) {
        printf("Dequeue operation failed! Queue is empty");
        exit(EXIT_FAILURE);
    }

    if (queue_ptr->rear == 0) {
        queue_ptr->front = queue_ptr->rear = -1;        
    } else {
        queue_ptr->front += 1;
    }

    queue_ptr->size -= 1;
}

int queue_peekFront(Queue *queue_ptr) {
    if (queue_is_empty(queue_ptr)) {
        printf("Queue is empty");
        exit(EXIT_FAILURE);
    }

    return queue_ptr->data[queue_ptr->front];
}

int queue_peekRear(Queue *queue_ptr) {
    if (queue_is_empty(queue_ptr)) {
        printf("Queue is empty");
        exit(EXIT_FAILURE);
    }
    
    return queue_ptr->data[queue_ptr->rear];
}

void queue_print(Queue *queue_ptr) {
    printf("[");

    for (int i = queue_ptr->front; i < (queue_ptr->front + queue_ptr->size); ++i) {
        if (i == queue_ptr->rear) {
            printf("%d", queue_ptr->data[i]);
        } else {
            printf("%d, ", queue_ptr->data[i]);
        }
    }

    printf("]\n");
}

void queue_destroy(Queue *queue_ptr) {
    free(queue_ptr->data);
    free(queue_ptr);
}


void check_address(void *ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}