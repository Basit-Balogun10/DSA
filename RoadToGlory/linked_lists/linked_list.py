class Node:
    def __init__(self, data, next_node=None, prev_node=None):
        self.data = data
        self.next = next_node
        self.prev = prev_node
        
    def __str__(self) -> str:
        return str(self.data)
        

class LinkedList:
    def __init__(self, values: list | tuple =None):
        self.head = None
        self.tail = None
        
        if values is not None:
            self.add_multiple_nodes(values)    
    
    def add_multiple_nodes(self, values):
        for value in values:
            self.add_node(value)
    
    # O(1)
    def add_node(self, data):
        if self.head is None:
            self.tail = self.head = Node(data)
        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next
            return self.tail
        #* NOTE: IMPLEMENT PRIVATE remove() METHOD TO BE CALLED BY remove_at() and remove() (public one)
        
        #! add_node_as_head / insert_at_the_beginning / add_first: O(1)
        #! __str__
        #! __len__
        #! __iter__
        #! @property: values - to access the values of all nodes included  in the sequence
        #! insert_at_middle
        #! insert_after - insert after a node
        #! remove_first: O(1)
        #! remove_last: O(1)
        #! remove_at: O(n) - remove from a position
        #! remove: O(n)
        #! search_node
        
        # JAVA
        #! clear: O(n)
        #! is_empty
        #! peekFirst: O(1) - return value of head
        #! peekLast: O(1) - return value of tail
        #! indexOf: O(n)
        #! contains / search
        