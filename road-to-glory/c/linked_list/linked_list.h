#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct SinglyLinkedList {
    int size;
    Node *head;
    Node *tail;
} SLinkedList;

typedef struct DoublyLinkedList {
    int size;
    Node *head;
    Node *tail;
} DLinkedList;

// Creates a new singly Linked List
SLinkedList *SLL_create();

// Creates a new doubly Linked List
DLinkedList *DLL_create();

// Returns number of nodes in linked List
int SLL_get_size(SLinkedList *list_ptr);
int DLL_get_size(DLinkedList *list_ptr);
#define linked_list_get_size(list) _Generic((list), SLinkedList *: SLL_get_size, DLinkedList *: DLL_get_size)(list)

// Returns true if linked list is empty, otherwise false
bool SLL_is_empty(SLinkedList *list_ptr);
bool DLL_is_empty(DLinkedList *list_ptr);
#define linked_list_is_empty(list) _Generic((list), SLinkedList *: SLL_is_empty, DLinkedList *: DLL_is_empty)(list)

// Returns the nth node (starting at 0 for first)
Node *SLL_get_node_at(SLinkedList *list_ptr, int index);
Node *DLL_get_node_at(DLinkedList *list_ptr, int index);
#define linked_list_get_node_at(list, index) _Generic((list), SLinkedList *: SLL_get_node_at, DLinkedList *: DLL_get_node_at)(list, index)

// Returns the first node
Node *SLL_get_first_node(SLinkedList *list_ptr);
Node *DLL_get_first_node(DLinkedList *list_ptr);
#define linked_list_get_first_node(list) _Generic((list), SLinkedList *: SLL_get_first_node, DLinkedList *: DLL_get_first_node)(list)

// Returns the last node (tail)
Node *SLL_get_last_node(SLinkedList *list_ptr);
Node *DLL_get_last_node(DLinkedList *list_ptr);
#define linked_list_get_last_node(list) _Generic((list), SLinkedList *: SLL_get_last_node, DLinkedList *: DLL_get_last_node)(list)

// Adds a new node with provided value as first node of the linked list
void SLL_add_as_first_node(SLinkedList *list_ptr, int value);
void DLL_add_as_first_node(DLinkedList *list_ptr, int value);
#define linked_list_add_as_first_node(list, value) _Generic((list), SLinkedList *: SLL_add_as_first_node, DLinkedList *: DLL_add_as_first_node)(list, value)

// Removes first node and returns its value
int SLL_pop_front(SLinkedList *list_ptr);
int DLL_pop_front(DLinkedList *list_ptr);
#define linked_list_pop_front(list) _Generic((list), SLinkedList *: SLL_pop_front, DLinkedList *: DLL_pop_front)(list)

// Removes last node (tail) and returns its value
int SLL_pop_back(SLinkedList *list_ptr);
int DLL_pop_back(DLinkedList *list_ptr);
#define linked_list_pop_back(list) _Generic((list), SLinkedList *: SLL_pop_back, DLinkedList *: DLL_pop_back)(list)

// *Adds an item as the tail of the linked list
void SLL_add_as_last_node(SLinkedList *list_ptr, int value);
void DLL_add_as_last_node(DLinkedList *list_ptr, int value);
#define linked_list_add_as_last_node(list, value) _Generic((list), SLinkedList *: sll_add_as_last_node, DLinkedList *: dll_add_as_last_node)(list, value)

// *Inserts a new node with provided value at given index, then new node now points to current node at index
void SLL_insert_at(SLinkedList *list_ptr, int value, int index);
void DLL_insert_at(DLinkedList *list_ptr, int value, int index);
#define linked_list_insert_at(list, value, index) _Generic((list), SLinkedList *: SLL_insert_at, DLinkedList *: DLL_insert_at)(list, value, index)

// *Removes node at given index
void SLL_remove_at(SLinkedList *list_ptr, int index);
void DLL_remove_at(DLinkedList *list_ptr, int index);
#define linked_list_remove_at(list, index) _Generic((list), SLinkedList *: SLL_remove_at, DLinkedList *: DLL_remove_at)(list, index)

// *Returns the value of the node at nth position from the end of the linked list
Node *SLL_get_nth_node_from_end(SLinkedList *list_ptr, int n);
Node *DLL_get_nth_node_from_end(DLinkedList *list_ptr, int n);
#define linked_list_get_nth_node_from_end(list, n) _Generic((list), SLinkedList *: SLL_get_nth_node_from_end, DLinkedList *: DLL_get_nth_node_from_end)(list, n)

// *Reverses linked list
void SLL_reverse(SLinkedList *list_ptr);
void DLL_reverse(DLinkedList *list_ptr);
#define linked_list_reverse(list) _Generic((list), SLinkedList *: DLL_reverse, DLinkedList *: DLL_reverse)(list)

// *Removes first node with provided value from the linked list
int SLL_remove_value(SLinkedList *list_ptr, int value);
int DLL_remove_value(DLinkedList *list_ptr, int value);
#define linked_list_remove_value(list, value) _Generic((list), SLinkedList *: SLL_remove_value, DLinkedList *: DLL_remove_value)(list, value)

// *Outputs nodes in linked list
void SLL_print(SLinkedList *list_ptr);
void DLL_print(DLinkedList *list_ptr);
#define linked_list_print(list) _Generic((list), SLinkedList *: SLL_remove_value, DLinkedList *: DLL_remove_value)(list)

// Checks to see if given value is valid for memory, and exits if otherwise
void check_address(void *ptr);

// Check if index is withing bound (0 <= index < list_size)
void check_index_bounds(int boundary, int index);

// Check if list has element to remove or pop
void check_can_remove_from_sll(SLinkedList *list_ptr);
void check_can_remove_from_dll(DLinkedList *list_ptr);