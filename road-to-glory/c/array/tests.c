#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void run_all_tests() {
    test_is_empty();
    test_jarray_size();
    test_jarray_at();
    test_jarray_insert();
    test_jarray_prepend();
    test_jarray_delete();
    test_jarray_pop();
    test_jarray_remove();
    test_jarray_find();
}

myArray *initialize_test_jarray(int first_ele) {
    myArray *arr_ptr = jarray_new(8);

    for (int i = first_ele; i < 8; ++i) {
        jarray_push(arr_ptr, i);
    }

    return arr_ptr;
}


void test_new_jarray() {
    int capacity = 5;
    myArray *arr_ptr = jarray_new(capacity);
    assert(arr_ptr->size == 0);
    assert(arr_ptr->capacity == capacity * 2);
    printf("test complete\n");
}

void test_is_empty() {
    myArray *arr_ptr = jarray_new(5);
    assert(jarray_is_empty(arr_ptr) == true);
    printf("test complete\n");
}

void test_jarray_size() {
    myArray *arr_ptr = jarray_new(5);
    assert(arr_ptr->size == 0);
    
    int no_of_items = 3;
    for (int i = 0; i < no_of_items; ++i) {
        jarray_push(arr_ptr, i);
    }

    assert(arr_ptr->size ==  no_of_items);
}

void test_jarray_at() {
    int first_ele = 3;
    myArray *arr_ptr = initialize_test_jarray(3);
    
    assert(jarray_at(arr_ptr, 0) == first_ele);
    assert(jarray_at(arr_ptr, 1) == first_ele + 1);
    assert(jarray_at(arr_ptr, 2) == first_ele + 2);

    // TEST ARRAY_AT EXITS CODE WITH OUT OF BOUND INDEX
}

void test_jarray_insert() {
    myArray *arr_ptr = initialize_test_jarray(3);
    int initial_jarray_size = arr_ptr->size;

    jarray_print(arr_ptr, "inline");
    printf("at3, %d\n", jarray_at(arr_ptr, 3));
    jarray_insert(arr_ptr, 3, 12);
    jarray_print(arr_ptr, "inline");
    printf("at3, %d\n", jarray_at(arr_ptr, 3));
    assert(jarray_at(arr_ptr, 3) == 12);
    assert(jarray_size(arr_ptr) == initial_jarray_size + 1);
}

void test_jarray_prepend() {
    myArray *arr_ptr = initialize_test_jarray(3);
    int initial_jarray_size = arr_ptr->size;

    jarray_prepend(arr_ptr, 55);
    assert(jarray_at(arr_ptr, 0) == 55);
    assert(jarray_size(arr_ptr) == initial_jarray_size + 1);
}

void test_jarray_delete() {
    myArray *arr_ptr = initialize_test_jarray(3);
    int initial_jarray_size = arr_ptr->size;

    int deletion_index = 3;
    int ele_at_index = *(arr_ptr->data + deletion_index);
    jarray_delete(arr_ptr, deletion_index);

    assert(jarray_at(arr_ptr, 3) != ele_at_index);
    assert(jarray_size(arr_ptr) == initial_jarray_size - 1);
}

void test_jarray_pop() {
    myArray *arr_ptr = initialize_test_jarray(3);
    int initial_jarray_size = arr_ptr->size;

    int last_ele = *(arr_ptr->data + arr_ptr->size - 1);
    jarray_pop(arr_ptr);

    assert(jarray_size(arr_ptr) == initial_jarray_size - 1);
    assert(jarray_at(arr_ptr, arr_ptr->size - 1) != last_ele);
}

void test_jarray_replace() {
    myArray *arr_ptr = initialize_test_jarray(3);
    int initial_jarray_size = arr_ptr->size;

    int replacement_index = 2;
    int ele_at_index = *(arr_ptr->data + replacement_index);
    int new_ele = 10;

    jarray_replace(arr_ptr, 2, new_ele);

    assert(jarray_at(arr_ptr, 2) == new_ele);
    assert(jarray_size(arr_ptr) == initial_jarray_size);
}

void test_jarray_remove() {
    myArray *arr_ptr = initialize_test_jarray(3);

    jarray_print(arr_ptr, "inline");
    jarray_remove(arr_ptr, 4);
    jarray_print(arr_ptr, "inline");
    
    assert(jarray_find(arr_ptr, 4) == -1);
}

void test_jarray_find() {
    myArray *arr_ptr = initialize_test_jarray(3);

    assert(jarray_find(arr_ptr, 3) == 3);
    assert(jarray_find(arr_ptr, 4) == 4);
    assert(jarray_find(arr_ptr, 5) == 5);
    assert(jarray_find(arr_ptr, 6) == 6);
    assert(jarray_find(arr_ptr, 7) == 7);
    
    // TEST MISSING ELEMENTS
    assert(jarray_find(arr_ptr, 8) == -1);
    assert(jarray_find(arr_ptr, 0) == -1);
}