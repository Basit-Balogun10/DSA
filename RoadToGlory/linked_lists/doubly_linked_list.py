from singly_linked_list import Node, SinglyLinkedList

class DoublySinglyLinkedList(SinglyLinkedList):
    # O(1)
    
    def __iter__(self):
        current = self.head
        while current:
            yield current
            current = current.next
    
    def add_node(self, data):
        if self.head is None:
            self.tail = self.head = Node(data, self)
        else:
            self.tail.next = Node(data, self)
            self.tail.next.prev = self.tail
            self.tail = self.tail.next
        self._run_common_actions("add_node")
        return self.tail
    
    def _insert(self, data, prev_node: Node):
        new_node = Node(data, self)
        next_node = prev_node.next
        
        prev_node.next = new_node
        
        new_node.prev = prev_node
        new_node.next = next_node
        
        next_node.prev = new_node
        self._run_common_actions("add_node")
        return new_node
        
    def insert_after(self, data, prev_node: Node):
        if type(prev_node) != Node:
            raise (TypeError('prev_node is not of type Node'))
        
        if prev_node.linked_list == self:
            if prev_node == self.tail:
                old_tail = self.tail
                self.add_node(data)
                self.tail.prev = old_tail
            return self._insert(data, prev_node)
        else:
            raise ValueError(f"Node {prev_node} does not belong to this linked list")
        
    def _remove(self, prev_node: Node):
        # If prev_node.next (i.e target node to remove) is the tail, 
        # prev_node.next.next (hence, next_node) will be None
        # and trying to access next_node.prev as done later will throw an AttributeError
        if prev_node.next != self.tail:
            next_node = prev_node.next.next
        else:
            next_node = None
        
        # Memory cleanup
        # prev_node.next.data = prev_node.next.next = prev_node.next.prev = None
        # del next_node.next
        
        prev_node.next = next_node
        
        if next_node:
            next_node.prev = prev_node
        
        self._run_common_actions("remove_node")
        
    def remove(self, data, count=1):
        if count < 1:
            raise (ValueError('count must be a positive integer greater than or equal to 1'))
        removals = 0
        for node in self:
            if node.data == data:
                self._remove(prev_node=node.prev)
                
                removals += 1
                if removals == count:
                    break
        
        if removals == 0:
            raise (ValueError(f'Linked list has no node with value {data}'))
                
                
    def remove_all(self, data):
        found_any = False
        for node in self:
            if node.data == data:
                found_any = True
                self._remove(prev_node=node.prev)
        if not found_any: raise (ValueError(f'Linked list has no node with value {data}'))
        
    
    def remove_first(self):
        old_head, new_head = self.head, self.head.next
        
        # self.head.data = self.head.prev = self.head.next = None
        self.head = new_head
        self.head.prev = None
        
        self._run_common_actions("remove_node")

        
        return old_head
        
    def remove_last(self):
        old_tail, new_tail = self.tail, self.tail.prev
        # self.tail.data = self.tail.prev = self.tail.next = None
        self.tail = new_tail
        self.tail.next = None
        
        self._run_common_actions("remove_node")
        
        return old_tail
    
    def __str__(self):
        return " <--> ".join([str(node) for node in self])
    

# ✅  _insert()
# ✅ insert_after()
# ✅ _remove()
# ✅ remove()
# ✅ remove_first()
# ✅ remove_last()
# ✅  __str__