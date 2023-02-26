#include "array.h"
#include "array.c"
#include "tests.h"
#include "tests.c"

int main () {
    run_all_tests();

    // int capacity = 8;
    // myArray *arr_ptr = jarray_new(capacity);
    // // jarray_push(arr_ptr, 3);

    // for (int i = 3; i < 8; ++i) {
    //     jarray_push(arr_ptr, i);
    //     printf("---------------------------------\n");
    // }

    // // int indexed = jarray_at(arr_ptr, 3);
    // // printf("%d\n", indexed);

    // jarray_insert(arr_ptr, 3, 12);
    // jarray_print(arr_ptr, "inline");

    // printf("---------------------------------\n");

    // jarray_prepend(arr_ptr, 55);
    // jarray_print(arr_ptr, "inline");

    // printf("---------------------------------\n");

    // printf("%d\n", arr_ptr->size);
    // jarray_delete(arr_ptr, 5);
    // jarray_print(arr_ptr, "inline");

    // printf("---------------------------------\n");
    
    // printf("Find item: %d\n", jarray_find(arr_ptr, 7));
    // jarray_print(arr_ptr, "inline");
    
    // printf("---------------------------------\n");
    
    // jarray_replace(arr_ptr, 3, 4);
    // jarray_print(arr_ptr, "inline");

    // // char *output = "";
    // // char *arr_str = jarray_stringify(arr_ptr);
    // // printf("Location %s", arr_str);
    
    // // // printf("---------------------------------\n");
    // // // jarray_remove(arr_ptr, 3);
    // // // jarray_print(arr_ptr, "inline");


    return 0;
}

// test out resizing
// write tests for other functions (DONE)
// fix remove function (DONE)