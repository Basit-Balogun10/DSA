#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void run_all_tests() {
    test_queue_create();
    printf("PASSED 1/6\n");
    test_queue_is_empty();
    printf("PASSED 2/6\n");
    test_enqueue();
    printf("PASSED 3/6\n");
    test_dequeue();
    printf("PASSED 4/6\n");
    test_queue_peekFront();
    printf("PASSED 5/6\n");
    test_queue_peekRear();
    printf("PASSED 6/6\n");
}

void test_queue_create() {
    Queue *queue_ptr = queue_create();

    assert(queue_ptr->front == NULL);
    assert(queue_ptr->rear == NULL);
}

void test_queue_is_empty() {
    Queue *queue_ptr = queue_create();
    assert(queue_is_empty(queue_ptr) == true);
    
    enqueue(queue_ptr, 1);
    assert(queue_is_empty(queue_ptr) == false);
}

void test_enqueue() {
    Queue *queue_ptr = queue_create();

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = 1 -> 2 -> 3

    Node *old_rear = queue_ptr->rear;

    enqueue(queue_ptr, 0);

    assert(queue_ptr->rear->data == 0);
    // NOT SURE, COMPARE DATA IF THIS FAILS
    assert(old_rear->next == queue_ptr->rear);
}

void test_dequeue() {
    Queue *queue_ptr = queue_create();

    // TEST WITH A SINGLE ITEM IN QUEUE
    enqueue(queue_ptr, 0);
    dequeue(queue_ptr);

    assert(queue_ptr->front == NULL);
    assert(queue_ptr->rear == NULL);

    // TEST WITH MULTIPLE ITEMS IN QUEUE
    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = 1 -> 2 -> 3

    Node *old_front = queue_ptr->front;
    Node *new_front_to_be = queue_ptr->front->next;
    
    dequeue(queue_ptr);

    assert(queue_ptr->front == new_front_to_be);
}

void test_queue_peekFront() {
    Queue *queue_ptr = queue_create();

    for(int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = 1 -> 2 -> 3

    assert(queue_peekFront(queue_ptr) == 1);
};

void test_queue_peekRear() {
    Queue *queue_ptr = queue_create();

    for (int i = 0; i < 3; ++i) {
        enqueue(queue_ptr, i+1);
    } // QUEUE = 1 -> 2 -> 3

    assert(queue_peekRear(queue_ptr) == 3);
};

// void test_queue_destroy() {
//     Queue *queue_ptr = queue_create();

//     for (int i = 0; i < 3; ++i) {
//         enqueue(queue_ptr, i+1);
//     } // QUEUE = 1 -> 2 -> 3

//     queue_destroy(queue_ptr);

//     assert(queue_ptr == NULL);
//     printf("passed 3\n");
// }