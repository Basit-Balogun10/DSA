#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

myArray *jarray_new(int capacity) {
    myArray *new_array = malloc(sizeof(myArray));
    check_address(new_array);
    
    new_array->size = 0;
    new_array->capacity = capacity * 2;
    new_array->data = malloc(sizeof(int) * capacity * 2);
    check_address(new_array->data);

    return new_array;
}


void inner_resize(myArray *arr_ptr, int capacity) {
    int *new_arr_data = realloc(arr_ptr->data, sizeof(int) * capacity);
    check_address(new_arr_data);
    arr_ptr->capacity = capacity;
    arr_ptr->data = new_arr_data;
}

void jarray_resize(myArray *arr_ptr) {
    int new_capacity = arr_ptr->size * 2;

    if (arr_ptr->size == arr_ptr->capacity) {

        inner_resize(arr_ptr, new_capacity);
    
    } else if (arr_ptr->size <= arr_ptr->capacity/4) {

        if (arr_ptr->capacity > kMinCapacity) {
            inner_resize(arr_ptr, new_capacity);
        }

    }
}

int jarray_size(myArray *arr_ptr) {
    return arr_ptr->size;
}

int jarray_capacity(myArray *arr_ptr) {
    return arr_ptr->capacity;
}

bool jarray_is_empty(myArray *arr_ptr) {
    return arr_ptr->size == 0;
}

int jarray_push(myArray *arr_ptr, int item) {
    // printf("%p %p %d\n", arr_ptr, arr_ptr->data, sizeof(arr_ptr->data));
    // memset(arr_ptr->data, item, 2);
    *(arr_ptr->data + arr_ptr->size) = item;
    // printf("%d %p %d\n", *(arr_ptr->data + arr_ptr->size), (arr_ptr->data + arr_ptr->size), sizeof(arr_ptr->data));
    
    arr_ptr->size += 1;
}

int jarray_at(myArray *arr_ptr, int index) {
    check_index_bounds(arr_ptr, index);

    return *(arr_ptr->data + index);
}

int jarray_insert(myArray *arr_ptr, int index, int item) {
    check_index_bounds(arr_ptr, index);

    for (int i = arr_ptr->size; i > index; --i ) {
        *(arr_ptr->data + i) = *(arr_ptr->data + i - 1);

        printf("%d insert\n", i);
    }

    *(arr_ptr->data + index) = item;
    ++arr_ptr->size;
}

int jarray_replace(myArray *arr_ptr, int index, int item) {
    check_index_bounds(arr_ptr, index);

    *(arr_ptr->data + index) = item;
}

int jarray_prepend(myArray *arr_ptr, int item) {
    jarray_insert(arr_ptr, 0, item);
}


void jarray_delete(myArray *arr_ptr, int index) {
    check_index_bounds(arr_ptr, index);

    // THE BELOW IF-ELSE BLOCK WORKS FINE FOR DELETION EXCEPT WHEN REMOVING ITEMS USING jarray_remove()
    
    // if (index == arr_ptr->size - 1) {
    //     jarray_pop(arr_ptr);
    // } else {
    //     for (int i = index; i <= arr_ptr->size; ++i) {
    //         *(arr_ptr->data + index) = *(arr_ptr->data + index + 1);
    //     }
    //     --arr_ptr->size; 
    // }

    // SUBSTITUTE FOR ABOVE IF-ELSE BLOCK, WORKS WHEN REMOVING 
    memmove(arr_ptr->data + index, arr_ptr->data + index + 1, (arr_ptr->size - index) * sizeof(int));
    
    --arr_ptr->size;

}

int jarray_pop(myArray *arr_ptr) {
    if (arr_ptr->size == 0) {
        printf("Cannot pop item out of an empty array");
        exit(EXIT_FAILURE);
    }

    int popped_value = *(arr_ptr->data + arr_ptr->size - 1);
    --arr_ptr->size;

    return popped_value;
}
// void jarray_delete(myArray *arrptr, int index) {
//   if (index < 0 || index >= arrptr->size) {
//     exit(EXIT_FAILURE);
//   }

// //   jarray_resize_for_size(arrptr, arrptr->size - 1);

//   memmove(arrptr->data + index, arrptr->data + index + 1, (arrptr->size - index) * sizeof(int));

//   --(arrptr->size);
// }

void jarray_remove(myArray *arr_ptr, int item) {
    if (arr_ptr->size == 0) {
        printf("Cannot remove item from empty array");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr_ptr->size; ++i) {
        int current_value = *(arr_ptr->data + i);
 
        if (current_value == item) {
            jarray_delete(arr_ptr, i);
            --i;
        }
}
}


int jarray_find(myArray *arr_ptr, int item) {
    for (int i = 0; i < arr_ptr->size; ++i) {
        if (*(arr_ptr->data + i) == item) {
            return *(arr_ptr->data + i);
        }
    }

    return -1;
}

// !TOFIX: NOT WORKING
char *jarray_stringify(myArray *arr_ptr) {
    char arr_string[] = "[";
    char *str_ptr = malloc(arr_ptr->size + 3);
    // str_ptr[0] = '\0';
    // str_ptr = "[ade";
    // strcpy(str_ptr, "ola");

    for (int i = 0; i < arr_ptr->size; ++i) {
        char str_ele = *(arr_ptr->data + i) + '0';
        printf("%c ELE\n", str_ele);
        *(str_ptr + i) = str_ele;
        // strcat(arr_string, str_ele);
    }

    // strcpy(str_ptr, arr_string);
    return str_ptr;
}

void jarray_print(myArray *arr_ptr, char *mode) {
    if (mode == "block") {
        for (int i = 0; i < arr_ptr->size; ++i) {
            printf("%d: %d\n", i, *(arr_ptr->data + i));
        }
    } else if (mode == "inline") {
        printf("[");

        for (int i = 0; i < arr_ptr->size; ++i) {
            if (i == arr_ptr->size - 1) {
                printf("%d", *(arr_ptr->data + i));
            } else {
                printf("%d, ", *(arr_ptr->data + i));
            }
        }

        printf("]\n");
    }
}

void check_address(void *ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void check_index_bounds(myArray *arr_ptr, int index) {
    if ((index < 0) || (index >= arr_ptr->size)) {
        printf("Index is out of bounds");
        exit(EXIT_FAILURE);
    }
}

// ---------------- TESTS --------------------



// WHAT HAPPENS WHEN YOU USE A %d FORMAT SPECIFIER TO PRINT OUT A POINTER

// WHY DO I NEED TO RESIZE ARRAY? WHEN CODE STILL WORKS FINE EVEN WHEN I DON'T RESIZE
// ALSO, CODE WORKS FINE EVEN WHEN I DON'T ALLOCATE ENOUGH MEMORY TO ARRAY FOR ITS ELEMENTS

// * HOW MEMSET WORKS...