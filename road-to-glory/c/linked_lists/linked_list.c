#include <stdlib.h>
#include <stdio.h>

SLinkedList *SLL_create() {
    SLinkedList *linked_list = malloc(sizeof(SLinkedList));
    check_address(linked_list);
    Node *first_node = malloc(sizeof(Node));
    check_address(first_node);
    
    linked_list->head = linked_list->tail = first_node;
    linked_list->size = 0;
    // printf("LINKED LIST: %p\n", linked_list);
    // printf("HEAD: %p\n", linked_list->head);
    // printf("TAIL: %p\n", linked_list->tail);

    return linked_list;
}

DLinkedList *DLL_create() {
    DLinkedList *linked_list = malloc(sizeof(DLinkedList));
    check_address(linked_list);
    Node *first_node = malloc(sizeof(Node));
    check_address(first_node);
    
    linked_list->head = linked_list->tail = first_node;
    linked_list->size = 0;
    // printf("LINKED LIST: %p\n", linked_list);
    // printf("HEAD: %p\n", linked_list->head);
    // printf("TAIL: %p\n", linked_list->tail);
    
    return linked_list;
}

int SLL_get_size(SLinkedList *list_ptr) {
    return list_ptr->size;
}

int DLL_get_size(DLinkedList *list_ptr) {
    return list_ptr->size;
}

Node *SLL_get_node_at(SLinkedList *list_ptr, int index) {
    check_index_bounds(list_ptr->size, index);
    Node *current_node = list_ptr->head;

    for(int i = 0; i < index; ++i) {
        current_node = current_node->next;
    }

    return current_node;
}

Node *DLL_get_node_at(DLinkedList *list_ptr, int index) {
    check_index_bounds(list_ptr->size, index);
    Node *current_node = list_ptr->head;

    for(int i = 0; i < index; ++i) {
        current_node = current_node->next;
    }

    return current_node;
}

Node *SLL_get_first_node(SLinkedList *list_ptr) {
    return list_ptr->head;
}

Node *DLL_get_first_node(DLinkedList *list_ptr) {
    return list_ptr->head;
}

Node *SLL_get_last_node(SLinkedList *list_ptr) {
    return list_ptr->tail;
}

Node *DLL_get_last_node(DLinkedList *list_ptr) {
    return list_ptr->tail;
}

void SLL_add_as_first_node(SLinkedList *list_ptr, int value) {
    Node *new_head = malloc(sizeof(Node));
    check_address(new_head);

    new_head->data = value;

    if (list_ptr->size == 0) {
        list_ptr->head = list_ptr->tail = new_head;
        list_ptr->head->next = list_ptr->tail->next = NULL;
    } else {
        new_head->next = list_ptr->head;
        list_ptr->head = new_head;
    }
    ++list_ptr->size;
}

void DLL_add_as_first_node(DLinkedList *list_ptr, int value) {
    Node *new_head = malloc(sizeof(Node));
    check_address(new_head);
    
    new_head->data = value;

    if (list_ptr->size == 0) {
        list_ptr->head = list_ptr->tail = new_head;
        list_ptr->head->next = list_ptr->tail->next = NULL;
        list_ptr->head->prev = list_ptr->tail->prev = NULL;
    } else {
        new_head->prev = NULL;
        new_head->next = list_ptr->head;
        list_ptr->head->prev = new_head;
        list_ptr->head = new_head;
    }
    ++list_ptr->size;
}

int SLL_pop_front(SLinkedList *list_ptr) {
    check_can_remove_from_sll(list_ptr);
    int value_to_be_popped = list_ptr->head->data;

    if (list_ptr->head == list_ptr->tail) {
        free(list_ptr->head);
        free(list_ptr->tail);
        Node *empty_node = malloc(sizeof(Node));
        check_address(empty_node);

        list_ptr->head = list_ptr->tail = empty_node;
    } else {
        Node *new_head = list_ptr->head->next;
        free(list_ptr->head);

        list_ptr->head = new_head;
    }
    --list_ptr->size;

    return value_to_be_popped;
}


int DLL_pop_front(DLinkedList *list_ptr) {
    check_can_remove_from_dll(list_ptr);
    int value_to_be_popped = list_ptr->head->data;

    if (list_ptr->head == list_ptr->tail) {
        free(list_ptr->head);
        free(list_ptr->tail);
        Node *empty_node = malloc(sizeof(Node));
        check_address(empty_node);

        list_ptr->head = list_ptr->tail = empty_node;
    } else {
        Node *new_head = list_ptr->head->next;
        free(list_ptr->head);

        new_head->prev = NULL;
        list_ptr->head = new_head;
    }
    --list_ptr->size;

    return value_to_be_popped;
}

int SLL_pop_back(SLinkedList *list_ptr) {
    check_can_remove_from_sll(list_ptr);
    int value_to_be_popped = list_ptr->tail->data;

    if (list_ptr->head == list_ptr->tail) {
        free(list_ptr->head);
        free(list_ptr->tail);
        Node *empty_node = malloc(sizeof(Node));
        check_address(empty_node);

        list_ptr->head = list_ptr->tail = empty_node;
    } else {    
        free(list_ptr->tail);

        
        // TO GET THE NODE BEFORE THE TAIL
        Node *current_node = list_ptr->head;
        for (int i=0; i < list_ptr->size - 2; ++i)  {
            current_node = current_node->next;
        }
        current_node->next = NULL;

        list_ptr->tail = current_node;
    }
    --list_ptr->size;
    return value_to_be_popped;
}

int DLL_pop_back(DLinkedList *list_ptr) {
    check_can_remove_from_dll(list_ptr);
    int value_to_be_popped = list_ptr->tail->data;

    if (list_ptr->head == list_ptr->tail) {
        free(list_ptr->head);
        free(list_ptr->tail);
        Node *empty_node = malloc(sizeof(Node));
        check_address(empty_node);

        list_ptr->head = list_ptr->tail = empty_node;
    } else {
        Node *new_tail = list_ptr->tail->prev;
        free(list_ptr->tail);

        new_tail->next = NULL;
        list_ptr->tail = new_tail;
    }
    --list_ptr->size;

    return value_to_be_popped;
}

// void SLL_add_as_last_node(SLinkedList *list_ptr, int value) {
//     Node *node = malloc(sizeof(Node));
//     check_address(node);

//     node->data = value;
//     node->next = 0;

//     if (list_ptr->size == 0) {
//         printf("in 1\n");
//         list_ptr->head = node;
//         list_ptr->tail = node;
//     } else {
//         printf("in 2\n");
//         list_ptr->tail->next = node;
//         list_ptr->tail = node;
//         printf("tail %d %s\n", list_ptr->tail->data, list_ptr->tail->next);
//         SLL_print(list_ptr);
//     }
//     ++list_ptr->size;
// }

void SLL_add_as_last_node(SLinkedList *list_ptr, int value) {
    Node *new_tail = malloc(sizeof(Node));
    check_address(new_tail);

    if (list_ptr->size == 0) {
        SLL_add_as_first_node(list_ptr, value);
    } else {
        list_ptr->tail->next = new_tail;
        new_tail->data = value;
        new_tail->next = NULL;

        list_ptr->tail = new_tail;
        ++list_ptr->size;
    }
}

void DLL_add_as_last_node(DLinkedList *list_ptr, int value) {
    Node *new_tail = malloc(sizeof(Node));
    check_address(new_tail);

    if (list_ptr->size == 0) {
        DLL_add_as_first_node(list_ptr, value);
    } else {
        list_ptr->tail->next = new_tail;
        new_tail->data = value;
        new_tail->prev = list_ptr->tail;
        new_tail->next = NULL;

        list_ptr->tail = new_tail;
        ++list_ptr->size;
    }
}

void SLL_insert_at(SLinkedList *list_ptr, int value, int index) {
    check_index_bounds(list_ptr->size, index);

    if(index == 0) {
        SLL_add_as_first_node(list_ptr, value);
    } else if(index == list_ptr->size - 1) {
        SLL_add_as_last_node(list_ptr, value);
    } else {
        Node *new_node = malloc(sizeof(Node));
        check_address(new_node);
        new_node->data = value;

        Node *current_prev_node = SLL_get_node_at(list_ptr, index - 1);
        Node *current_node = current_prev_node->next;

        current_prev_node->next = new_node;
        new_node->next = current_node;
        
        ++list_ptr->size;
    }
}

void DLL_insert_at(DLinkedList *list_ptr, int value, int index) {
    check_index_bounds(list_ptr->size, index);

    if(index == 0) {
        DLL_add_as_first_node(list_ptr, value);
    } else if(index == list_ptr->size - 1) {
        DLL_add_as_last_node(list_ptr, value);
    } else {
        Node *new_node = malloc(sizeof(Node));
        check_address(new_node);
        new_node->data = value;

        Node *current_prev_node = DLL_get_node_at(list_ptr, index - 1);
        Node *current_node = current_prev_node->next;

        current_prev_node->next = new_node;
        new_node->prev = current_prev_node;
        new_node->next = current_node;
        current_node->prev = new_node;
        
        ++list_ptr->size;
    }
}

void SLL_remove_at(SLinkedList *list_ptr, int index) {
    check_index_bounds(list_ptr->size, index);

    if(index == 0) {
        SLL_pop_front(list_ptr);
    } else if(index == list_ptr->size - 1) {
        SLL_pop_back(list_ptr);
    } else {
        Node *current_prev_node = SLL_get_node_at(list_ptr, index - 1);
        Node *target_node = current_prev_node->next;
        Node *current_next_node = target_node->next;

        current_prev_node->next = current_next_node;
        free(target_node);
        
        --list_ptr->size;
    }
}

void DLL_remove_at(DLinkedList *list_ptr, int index) {
    check_index_bounds(list_ptr->size, index);

    if(index == 0) {
        DLL_pop_front(list_ptr);
    } else if(index == list_ptr->size - 1) {
        DLL_pop_back(list_ptr);
    } else {
        Node *current_prev_node = DLL_get_node_at(list_ptr, index - 1);
        Node *target_node = current_prev_node->next;
        Node *current_next_node = target_node->next;

        current_prev_node->next = current_next_node;
        current_next_node->prev = current_prev_node;
        free(target_node);
        
        --list_ptr->size;
    }
}

Node *SLL_get_nth_node_from_end(SLinkedList *list_ptr, int n) {
    check_index_bounds(list_ptr->size, n);
    
    int index = list_ptr->size - n - 1;
    return SLL_get_node_at(list_ptr, index);
}

Node *DLL_get_nth_node_from_end(DLinkedList *list_ptr, int n) {
    check_index_bounds(list_ptr->size, n);

    int index = list_ptr->size - n - 1;
    return DLL_get_node_at(list_ptr, index);
}

// !DOESN'T WORK YET, TRY REWRITING FROM SCRATCH TO FIX
void SLL_reverse(SLinkedList *list_ptr) {
    SLinkedList *new_list_ptr = SLL_create();
    new_list_ptr->head = new_list_ptr->tail = list_ptr->head;
    ++new_list_ptr->size;

    Node *current_node = list_ptr->head;
    Node *previous_node, *new_node;
    for(int i = 1; i < list_ptr->size; ++i) {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
        
        new_node = malloc(sizeof(Node));
        check_address(new_node);
        new_node->data = current_node->data;
        new_node->next = new_list_ptr->head;
        new_list_ptr->head = new_node;
    }

    new_list_ptr->tail->next = NULL;
    
    free(list_ptr->tail);
    list_ptr = new_list_ptr;
    free(new_list_ptr);
}

// !DOESN'T WORK YET, TRY REWRITING FROM SCRATCH TO FIX
void DLL_reverse(DLinkedList *list_ptr) {
    DLinkedList *new_list_ptr = DLL_create();
    new_list_ptr->head = new_list_ptr->tail = list_ptr->head;
    ++new_list_ptr->size;

    Node *current_node = list_ptr->head;
    Node *previous_node, *new_node;
    for(int i = 1; i < list_ptr->size; ++i) {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
        
        new_node = malloc(sizeof(Node));
        check_address(new_node);
        new_node->data = current_node->data;
        new_node->next = new_list_ptr->head;
        new_list_ptr->head->prev = new_node->next;
        new_list_ptr->head = new_node;
        
        ++new_list_ptr->size;
    }

    new_list_ptr->tail->next = NULL;
    new_list_ptr->head->prev = NULL;
    
    free(list_ptr->tail);
    list_ptr = new_list_ptr;
    free(new_list_ptr);
}

int SLL_remove_value(SLinkedList *list_ptr, int value) {
    Node *current_node = list_ptr->head;

    for(int i = 0; i < list_ptr->size; ++i) {
        if(current_node->data == value) {
            SLL_remove_at(list_ptr, i);
            return value;
        } else {
            current_node = current_node->next;
        }
    }

    // return -1;
}

int DLL_remove_value(DLinkedList *list_ptr, int value) {
    check_can_remove_from_dll(list_ptr);
    Node *current_node = list_ptr->head;

    for(int i = 0; i < list_ptr->size; ++i) {
        if(current_node->data == value) {
            DLL_remove_at(list_ptr, i);
            return value;
        } else {
            current_node = current_node->next;
        }
    }

    return -1;
}

void SLL_print(SLinkedList *list_ptr) {
    Node *current_node = list_ptr->head;
    
    for(int i = 0; i < list_ptr->size; ++i) {
        if (i == list_ptr->size - 1) {
                printf("%d", current_node->data);
        } else {
            printf("%d --> ", current_node->data);
        }
        current_node = current_node->next;
    }
    printf("\n");
}

void DLL_print(DLinkedList *list_ptr) {
    Node *current_node = list_ptr->head;

    for(int i = 0; i < list_ptr->size; ++i) {
        if (i == list_ptr->size - 1) {
            printf("%d", current_node->data);
        } else {
            printf("%d <--> ", current_node->data);
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

void check_index_bounds(int boundary, int index) {
    if ((index < 0) || (index >= boundary)) {
        printf("Index is out of bounds");
        exit(EXIT_FAILURE);
    }
}

void check_can_remove_from_sll(SLinkedList *list_ptr) {
    if (list_ptr->size == 0) {
        printf("There is nothing to remove in an empty list\n");
        exit(EXIT_FAILURE);
    }
}

void check_can_remove_from_dll(DLinkedList *list_ptr) {
    if (list_ptr->size == 0) {
        printf("There is nothing to remove in an empty list\n");
        exit(EXIT_FAILURE);
    }
}