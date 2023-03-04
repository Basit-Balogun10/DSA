#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// #include "tests.h"


void test_sll_create() {
    SLinkedList *list_ptr = SLL_create();
    assert(list_ptr->size == 0);
    assert(list_ptr->head == list_ptr->tail);
}

void test_dll_create() {
    DLinkedList *list_ptr = DLL_create();
    assert(list_ptr->size == 0);
    assert(list_ptr->head == list_ptr->tail);
}

void test_sll_get_node_at() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 4; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    SLL_print(list_ptr);
    
    assert(SLL_get_node_at(list_ptr, 0)->data == 1);
    assert(SLL_get_node_at(list_ptr, 1)->data == 2);
    assert(SLL_get_node_at(list_ptr, 2)->data == 3);
    assert(SLL_get_node_at(list_ptr, 3)->data == 4);
    printf("passed \n");
}

void test_dll_get_node_at() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 4; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    DLL_print(list_ptr);

    assert(DLL_get_node_at(list_ptr, 0)->data == 1);
    assert(DLL_get_node_at(list_ptr, 1)->data == 2);
    assert(DLL_get_node_at(list_ptr, 2)->data == 3);
    assert(DLL_get_node_at(list_ptr, 3)->data == 4);
}

void test_sll_get_first_node() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 3; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    Node *first_node = SLL_get_first_node(list_ptr);

    assert(first_node->data == 1);
    assert(first_node->data == list_ptr->head->data);

}

void test_dll_get_first_node() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 3; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    Node *first_node = DLL_get_first_node(list_ptr);

    assert(first_node->data == 1);
    assert(first_node->data == list_ptr->head->data);
}

void test_sll_get_last_node() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 3; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    Node *last_node = SLL_get_last_node(list_ptr);

    assert(last_node->data == 3);
    assert(last_node->data == list_ptr->tail->data);
}

void test_dll_get_last_node() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 3; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    Node *last_node = DLL_get_last_node(list_ptr);

    assert(last_node->data == 3);
    assert(last_node->data == list_ptr->tail->data);
}

void test_sll_add_as_first_node() {
    SLinkedList *list_ptr = SLL_create();

    // TEST WITH AN EMPTY LIST
    SLL_add_as_first_node(list_ptr, 5);
    
    assert(list_ptr->head == list_ptr->tail);
    assert(list_ptr->head->data == list_ptr->tail->data);
    assert(list_ptr->head->data == 5);
    assert(list_ptr->tail->data == 5);
    assert(list_ptr->head->next == NULL);
    assert(list_ptr->tail->next == NULL);

    // TEST WITH NON-EMPTY LIST
    for (int i = 0; i < 3; ++i) {
        SLL_add_as_first_node(list_ptr, i+1);
    }

    assert(list_ptr->head->data == 3);
    assert(list_ptr->tail->data == 5);
}

void test_dll_add_as_first_node() {
    DLinkedList *list_ptr = DLL_create();

    // TEST WITH AN EMPTY LIST
    DLL_add_as_first_node(list_ptr, 5);
    
    assert(list_ptr->head == list_ptr->tail);
    assert(list_ptr->head->data == list_ptr->tail->data);
    assert(list_ptr->head->data == 5);
    assert(list_ptr->tail->data == 5);
    assert(list_ptr->head->prev == NULL);
    assert(list_ptr->tail->prev == NULL);
    assert(list_ptr->tail->next == NULL);
    assert(list_ptr->tail->next == NULL);


    // TEST WITH NON-EMPTY LIST
    for (int i = 0; i < 3; ++i) {
        DLL_add_as_first_node(list_ptr, i+1);
    }

    assert(list_ptr->head->prev == NULL);
    assert(list_ptr->head->data == 3);
    assert(list_ptr->tail->data == 5);
}

void test_sll_pop_front() {
    SLinkedList *list_ptr = SLL_create();

    // TEST WITH A SINGLE NODE IN LIST
    SLL_add_as_first_node(list_ptr, 0);
    SLL_pop_front(list_ptr);

    assert(list_ptr->size == 0);
    assert(list_ptr->head == list_ptr->tail);

    // TEST WITH MULTIPLE NODES IN LIST
    for (int i = 0; i < 3; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    int old_size = list_ptr->size;
    Node *old_head = list_ptr->head;
    Node *new_head_to_be = list_ptr->head->next;
    
    SLL_pop_front(list_ptr);

    assert(list_ptr->size == (old_size - 1));
    assert(list_ptr->head == new_head_to_be);
}

void test_dll_pop_front() {
    DLinkedList *list_ptr = DLL_create();
    
    // TEST WITH A SINGLE NODE IN LIST
    DLL_add_as_first_node(list_ptr, 0);
    DLL_pop_front(list_ptr);

    assert(list_ptr->size == 0);
    assert(list_ptr->head == list_ptr->tail);

    // TEST WITH MULTIPLE NODES IN LIST
    for (int i = 0; i < 3; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    int old_size = list_ptr->size;
    Node *old_head = list_ptr->head;
    Node *new_head_to_be = list_ptr->head->next;
    
    DLL_pop_front(list_ptr);

    assert(list_ptr->size == (old_size - 1));
    assert(list_ptr->head == new_head_to_be);
    assert(list_ptr->head->prev == NULL);
}

void test_sll_pop_back() {
    SLinkedList *list_ptr = SLL_create();

    // TEST WITH A SINGLE NODE IN LIST
    SLL_add_as_last_node(list_ptr, 0);
    SLL_pop_back(list_ptr);

    assert(list_ptr->size == 0);
    assert(list_ptr->head == list_ptr->tail);

    // TEST WITH MULTIPLE NODES IN LIST
    for (int i = 0; i < 3; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    int old_size = list_ptr->size;
    Node *old_tail = list_ptr->tail;
    
    SLL_pop_back(list_ptr);

    assert(list_ptr->size == (old_size - 1));
    assert(list_ptr->tail != old_tail);
}

void test_dll_pop_back() {
    DLinkedList *list_ptr = DLL_create();

    // TEST WITH A SINGLE NODE IN LIST
    DLL_add_as_last_node(list_ptr, 0);
    DLL_pop_back(list_ptr);

    assert(list_ptr->size == 0);
    assert(list_ptr->head == list_ptr->tail);

    // TEST WITH MULTIPLE NODES IN LIST
    for (int i = 0; i < 3; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    int old_size = list_ptr->size;
    Node *old_tail = list_ptr->tail;
    Node *new_tail = list_ptr->tail->prev;
    
    DLL_pop_back(list_ptr);

    assert(list_ptr->size == (old_size - 1));
    
    
    // NOT SURE (COMPARING POINTERS, TRY COMPARING DATA IF THIS FAILS)
    assert(list_ptr->tail == new_tail);
    assert(list_ptr->tail->next == NULL);
    
    assert(list_ptr->tail != old_tail);
}

void test_sll_add_as_last_node() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 3; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    int old_size = list_ptr->size;
    Node *old_tail = list_ptr->tail;
    
    SLL_add_as_last_node(list_ptr, 0);

    assert(list_ptr->size == (old_size + 1));
    assert(list_ptr->tail->data == 0);
    // NOT SURE, COMPARE DATA IF THIS FAILS
    assert(old_tail->next == list_ptr->tail);
}

void test_dll_add_as_last_node() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 3; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    int old_size = list_ptr->size;
    Node *old_tail = list_ptr->tail;
    
    DLL_add_as_last_node(list_ptr, 0);

    assert(list_ptr->size == (old_size + 1));
    assert(list_ptr->tail->data == 0);
    // NOT SURE, COMPARE DATA IF THIS FAILS
    assert(old_tail->next == list_ptr->tail);
    assert(list_ptr->tail->prev == old_tail);
}

void test_sll_insert_at() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 4; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    SLL_insert_at(list_ptr, 5, 0);
    SLL_insert_at(list_ptr, 6, 1);
    SLL_insert_at(list_ptr, 7, 2);
    SLL_insert_at(list_ptr, 8, 3);

    assert(SLL_get_node_at(list_ptr, 0)->data == 5);
    assert(SLL_get_node_at(list_ptr, 1)->data == 6);
    assert(SLL_get_node_at(list_ptr, 2)->data == 7);
    assert(SLL_get_node_at(list_ptr, 3)->data == 8);
}

void test_dll_insert_at() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 4; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    DLL_insert_at(list_ptr, 5, 0);
    DLL_insert_at(list_ptr, 6, 1);
    DLL_insert_at(list_ptr, 7, 2);
    DLL_insert_at(list_ptr, 8, 3);

    assert(DLL_get_node_at(list_ptr, 0)->data == 5);
    assert(DLL_get_node_at(list_ptr, 1)->data == 6);
    assert(DLL_get_node_at(list_ptr, 2)->data == 7);
    assert(DLL_get_node_at(list_ptr, 3)->data == 8);
}

void test_sll_remove_at() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 5; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    } // LIST = 1 -> 2 -> 3 -> 4 -> 5

    SLL_remove_at(list_ptr, 0); // LIST = 2 -> 3 -> 4 -> 5
    assert(SLL_get_node_at(list_ptr, 0)->data == 2);

    SLL_remove_at(list_ptr, 1); // LIST = 2 -> 4 -> 5
    assert(SLL_get_node_at(list_ptr, 1)->data == 4);

    SLL_remove_at(list_ptr, 2); // LIST = 2 -> 4
    assert(SLL_get_node_at(list_ptr, 1)->data == 4);
}

void test_dll_remove_at() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 5; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    } // LIST = 1 -> 2 -> 3 -> 4 -> 5

    DLL_remove_at(list_ptr, 0); // LIST = 2 -> 3 -> 4 -> 5
    assert(DLL_get_node_at(list_ptr, 0)->data == 2);

    DLL_remove_at(list_ptr, 1); // LIST = 2 -> 4 -> 5
    assert(DLL_get_node_at(list_ptr, 1)->data == 4);

    DLL_remove_at(list_ptr, 2); // LIST = 2 -> 4
    assert(DLL_get_node_at(list_ptr, 1)->data == 4);
}

void test_sll_get_nth_node_from_end() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 4; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    } // LIST = 1 -> 2 -> 3 -> 4

    assert(SLL_get_nth_node_from_end(list_ptr, 0)->data == 4);
    assert(SLL_get_nth_node_from_end(list_ptr, 1)->data == 3);
    assert(SLL_get_nth_node_from_end(list_ptr, 2)->data == 2);
    assert(SLL_get_nth_node_from_end(list_ptr, 3)->data == 1);
}

void test_dll_get_nth_node_from_end() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 4; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    } // LIST = 1 -> 2 -> 3 -> 4

    assert(DLL_get_nth_node_from_end(list_ptr, 0)->data == 4);
    assert(DLL_get_nth_node_from_end(list_ptr, 1)->data == 3);
    assert(DLL_get_nth_node_from_end(list_ptr, 2)->data == 2);
    assert(DLL_get_nth_node_from_end(list_ptr, 3)->data == 1);
}

void test_sll_remove_value() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 5; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    } // LIST = 1 -> 2 -> 3 -> 4 -> 5

    SLL_remove_value(list_ptr, 1); // LIST = 2 -> 3 -> 4 -> 5
    assert(SLL_get_node_at(list_ptr, 0)->data == 2);

    SLL_remove_value(list_ptr, 3); // LIST = 2 -> 4 -> 5
    assert(SLL_get_node_at(list_ptr, 1)->data == 4);

    SLL_remove_value(list_ptr, 5); // LIST = 2 -> 4
    assert(SLL_get_node_at(list_ptr, 1)->data == 4);
}

void test_dll_remove_value() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 5; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    } // LIST = 1 -> 2 -> 3 -> 4 -> 5

    DLL_remove_value(list_ptr, 1); // LIST = 2 -> 3 -> 4 -> 5
    assert(DLL_get_node_at(list_ptr, 0)->data == 2);

    DLL_remove_value(list_ptr, 3); // LIST = 2 -> 4 -> 5
    assert(DLL_get_node_at(list_ptr, 1)->data == 4);

    DLL_remove_value(list_ptr, 5); // LIST = 2 -> 4
    assert(DLL_get_node_at(list_ptr, 1)->data == 4);
}

void test_sll_reverse() {
    SLinkedList *list_ptr = SLL_create();

    for (int i = 0; i < 4; ++i) {
        SLL_add_as_last_node(list_ptr, i+1);
    }

    SLL_print(list_ptr);
    SLL_reverse(list_ptr);
    SLL_print(list_ptr);
}

void test_dll_reverse() {
    DLinkedList *list_ptr = DLL_create();

    for (int i = 0; i < 4; ++i) {
        DLL_add_as_last_node(list_ptr, i+1);
    }

    DLL_print(list_ptr);
    DLL_reverse(list_ptr);
    DLL_print(list_ptr);
}

void run_all_tests() {
    test_sll_create();
    printf("PASSED 1/26\n");
    test_dll_create();
    printf("PASSED 2/26\n");
    test_sll_get_node_at();
    printf("PASSED 3/26\n");
    test_dll_get_node_at();
    printf("PASSED 4/26\n");
    test_sll_get_first_node();
    printf("PASSED 5/26\n");
    test_dll_get_first_node();
    printf("PASSED 6/26\n");
    test_sll_get_last_node();
    printf("PASSED 7/26\n");
    test_dll_get_last_node();
    printf("PASSED 8/26\n");
    test_sll_add_as_first_node();
    printf("PASSED 9/26\n");
    test_dll_add_as_first_node();
    printf("PASSED 10/26\n");
    test_sll_pop_front();
    printf("PASSED 11/26\n");
    test_dll_pop_front();
    printf("PASSED 12/26\n");
    test_sll_pop_back();
    printf("PASSED 13/26\n");
    test_dll_pop_back();
    printf("PASSED 14/26\n");
    test_sll_add_as_last_node();
    printf("PASSED 15/26\n");
    test_dll_add_as_last_node();
    printf("PASSED 16/26\n");
    test_sll_insert_at();
    printf("PASSED 17/26\n");
    test_dll_insert_at();
    printf("PASSED 18/26\n");
    test_sll_remove_at();
    printf("PASSED 19/26\n");
    test_dll_remove_at();
    printf("PASSED 20/26\n");
    test_sll_get_nth_node_from_end();
    printf("PASSED 21/26\n");
    test_dll_get_nth_node_from_end();
    printf("PASSED 22/26\n");
    // test_sll_reverse();
    // printf("PASSED 23\n");
    // test_dll_reverse();
    // printf("PASSED 24\n");
    test_sll_remove_value();
    printf("PASSED 25/26\n");
    test_dll_remove_value();    
    printf("PASSED 26/26\n");
}
