from linked_list import Node, LinkedList

class DoublyLinkedList(LinkedList):
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
        next_node = prev_node.next.next
        
        # Memory cleanup
        prev_node.next.data = prev_node.next.next = prev_node.next.prev = None
        del next_node.next
        
        prev_node.next = next_node
        next_node.prev = prev_node
        
        self._run_common_actions("remove_node")
        
    def remove(self, data, count=1):
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
        
        
    def __str__(self):
        return " <--> ".join([str(node) for node in self])
    

# ✅  _insert()
# ✅ insert_after()
# ✅ insert_at()
# _remove()
# remove()
# remove_first()
# remove_last()
# remove_at()
# ✅  __str__