#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Queue *queue_create() {
    Queue *queue_ptr = malloc(sizeof(Queue));
    queue_ptr->front = queue_ptr->rear = NULL;

    return queue_ptr;
}

bool queue_is_empty(Queue *queue_ptr) {
    if (queue_ptr->front == NULL) {
        return true;
    }
    return false;
}

void enqueue(Queue *queue_ptr, int value) {
    Node *new_rear = malloc(sizeof(Node));
    check_address(new_rear);

    new_rear->data = value;
    new_rear->next = NULL;
    if (queue_ptr->front == NULL) {
        queue_ptr->front = queue_ptr->rear = new_rear;
    } else {
        queue_ptr->rear->next = new_rear;
        queue_ptr->rear = new_rear;
    }
}

int dequeue(Queue *queue_ptr) {
    if (queue_is_empty(queue_ptr)) {
        printf("There is nothing to dequeue from an empty queue\n");
        exit(EXIT_FAILURE);
    };

    int dequeued_value = queue_ptr->front->data;

    if (queue_ptr->front == queue_ptr->rear) {
        free(queue_ptr->front);
        free(queue_ptr->rear);

        queue_ptr->front = queue_ptr->rear = NULL;
    } else {
        Node *new_front = queue_ptr->front->next;
        free(queue_ptr->front);

        queue_ptr->front = new_front;
    }

    return dequeued_value;
}

int queue_peekFront(Queue *queue_ptr) {
    return queue_ptr->front->data;
}

int queue_peekRear(Queue *queue_ptr) {
    return queue_ptr->rear->data;
}


void queue_destroy(Queue *queue_ptr) {
    Node *current_node = queue_ptr->front;
    Node *previous_node, *new_node;

    while(current_node != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
    }

    // queue_print(queue_ptr);

    free(queue_ptr);
}

void queue_print(Queue *queue_ptr) {
    if (queue_is_empty(queue_ptr))
        printf("QUEUE IS EMPTY");

    Node *current_node = queue_ptr->front;
    
    while(current_node != NULL) {
        if (current_node->next == NULL) {
                printf("%d", current_node->data);
        } else {
            printf("%d --> ", current_node->data);
        }
        current_node = current_node->next;
    }
    printf("\n");
}

void check_address(void *ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}