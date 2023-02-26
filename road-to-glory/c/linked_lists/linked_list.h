typedef struct Node {
    int data;
    Node *next;
    Node *prev;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

// Creates new Linked List
LinkedList *create_new_linked_list();

// Returns number of nodes in linked List
int get_linked_list_size(LinkedList *list_ptr);

// Returns true if linked list is empty, otherwise false
bool linked_list_is_empty(LinkedList *list_ptr);

