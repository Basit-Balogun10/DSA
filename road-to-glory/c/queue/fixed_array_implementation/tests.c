#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void run_all_tests() {
    test_queue_create();
    printf("PASSED 1/7\n");
    test_queue_is_empty();
    printf("PASSED 2/7\n");
    test_queue_is_full();
    printf("PASSED 3/7\n");
    test_enqueue();
    printf("PASSED 4/7\n");
    test_dequeue();
    printf("PASSED 5/7\n");
    test_queue_peekFront();
    printf("PASSED 6/7\n");
    test_queue_peekRear();
    printf("PASSED 7/7\n");
}

void test_queue_create() {
    int capacity = 10;
    Queue *queue_ptr = queue_create(capacity);

    assert(queue_ptr->front == -1);
    assert(queue_ptr->rear == -1);
    assert(queue_ptr->size == 0);
    assert(queue_ptr->capacity == capacity);
}

void test_queue_is_empty() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);
    assert(queue_is_empty(queue_ptr) == true);
    
    enqueue(queue_ptr, 1);
    assert(queue_is_empty(queue_ptr) == false);
}

void test_queue_is_full() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = [1, 2, 3]

    assert(queue_is_full(queue_ptr) == false);
    enqueue(queue_ptr, 4);
    
    assert(queue_is_full(queue_ptr) == true);
}

void test_enqueue() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = [1, 2, 3]

    int old_size = queue_ptr->size;
    int old_rear = queue_ptr->rear;

    enqueue(queue_ptr, 0);

    assert(queue_ptr->size == (old_size + 1));
    assert(queue_ptr->data[queue_ptr->rear] == 0);
    assert(queue_ptr->rear == (old_rear + 1));
}

void test_dequeue() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);

    // TEST WITH A SINGLE ITEM IN QUEUE
    enqueue(queue_ptr, 0);
    dequeue(queue_ptr);

    assert(queue_ptr->size == 0);
    assert(queue_ptr->front == -1);
    assert(queue_ptr->rear == -1);

    // TEST WITH MULTIPLE ITEMS IN QUEUE
    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = [1, 2, 3]

    int old_size = queue_ptr->size;
    int old_front = queue_ptr->front;
    int new_front_to_be = queue_ptr->front + 1;
    
    dequeue(queue_ptr);

    assert(queue_ptr->size == (old_size - 1));
    assert(queue_ptr->front == new_front_to_be);
}

void test_queue_peekFront() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = [1, 2, 3]

    assert(queue_peekFront(queue_ptr) == 1);
};

void test_queue_peekRear() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = [1, 2, 3]

    assert(queue_peekRear(queue_ptr) == 3);
};

void test_queue_destroy() {
    int capacity = 4;
    Queue *queue_ptr = queue_create(capacity);

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = [1, 2, 3]

    queue_destroy(queue_ptr);

    assert(queue_ptr == NULL);
}