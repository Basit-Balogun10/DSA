#include <stdbool.h>

const int kMinCapacity = 2;

typedef struct JArray {
    int size;
    int capacity;
    int *data;
} myArray;

// Creates a new array
myArray *jarray_new(int capacity);

// Returns number of elements in array
int jarray_size(myArray *arr_ptr);

// Returns number of elements array can hold
int jarray_capacity(myArray *arr_ptr);

// Check if array is empty
bool jarray_is_empty(myArray *arr_ptr);

// Returns item at index, exits if index is out of bounds
int jarray_at(myArray *arr_ptr, int index);

// Inserts item at the end of array
int jarray_push(myArray *arr_ptr, int item);

// Inserts item in array at specified index
// Shifts that index's old value and trailing elements to the right
int jarray_insert(myArray *arr_ptr, int index, int item);

// Replaces element at specified index in array with item
int jarray_replace(myArray *arr_ptr, int index, int item);

// Inserts item at the beginning of array
int jarray_prepend(myArray *arr_ptr, int item);

// Deletes last item from array (from the end)
// Returns popped value
int jarray_pop(myArray *arr_ptr);

// Deletes item from array at specified index
// Shifts all trailing elements left
void jarray_delete(myArray *arr_ptr, int index);

// Looks for value in array and removes index holding it (even if in multiple cases)
void jarray_remove(myArray *arr_ptr, int item);

// Looks for value in array and returns first item with that value
// Returns -1 if not found
int jarray_find(myArray *arr_ptr, int item);

// When array's size reaches its capacity, resize to double the size
// When array's size is 1/4 of its capacity, resize to double the size
void jarray_resize(myArray *arr_ptr);

// Prints out elements of array
void jarray_print(myArray *arr_ptr, char *mode);

// Checks to see if given value is valid for memory, and exits if otherwise
void check_address(void *ptr);

void check_index_bounds(myArray *arr_ptr, int item);

// TESTS