from typing import Literal, Union
class Node:
    def __init__(self, data, linked_list=None, next_node=None, prev_node=None):
        self.data = data
        self.next = next_node
        self.prev = prev_node
        self.linked_list = linked_list

    @property
    def id(self):
        if self.linked_list:
            if self.linked_list._last_added_node_id:
                return self.linked_list._last_added_node_id
            else:
                return 1

    def __str__(self) -> str:
        return str(self.data)


class SinglyLinkedList:
    def __init__(self, values: Union[list, tuple] = None):
        self.head = None
        self.tail = None
        self._length = 0
        self._last_added_node_id = None

        if values is not None:
            self.add_multiple_nodes(values)

    def _check_index_bounds(self, ind):
        if not (0 <= ind < self._length):
            raise IndexError(f"{ind} is out of bound")
        return

    def _run_common_actions(
        self, action_type: Literal["add_node", "remove_node"]
    ):
        if action_type == "add_node":
            self._length += 1
            if self._last_added_node_id:
                self._last_added_node_id += 1
            else:
                self._last_added_node_id = 1
        elif action_type == "remove_node":
            self._length -= 1

    def __iter__(self):
        current = self.head
        while current:
            yield current
            current = current.next

    # O(1)
    @property
    def length(self):
        return self._length

    @property
    def values(self):
        values = []
        for node in self:
            values.append(node.data)
            
        return values
        # return [node.data for node in self]

    def add_multiple_nodes(self, values: list | tuple):
        for value in values:
            self.add_node(value)

    # O(1)
    def add_node(self, data):
        if self.head is None:
            self.tail = self.head = Node(data, self)
        else:
            self.tail.next = Node(data, self)
            self.tail = self.tail.next
        self._run_common_actions("add_node")
        return self.tail

    # O(1)
    def add_first_node(self, data):
        if self._length == 0:
            self.add_node(data)
        self.insert_after(self.head.data, self.head)
        self.head.data = data

        self._run_common_actions("add_node")
        return self.head

    # O(n)
    def get_node(self, pos):
        self._check_index_bounds(pos)
        
        if pos == 0:
            return self.head
        if pos == self._length - 1:
            return self.tail
        
        pointer: int = 0
        for node in self:
            if pointer == pos:
                return node
            pointer += 1
            
    # O(n)
    def index_of(self, data):
        pointer: int = 0
        for node in self:
            if node.data == data:
                return pointer
            pointer += 1
        
        raise (ValueError(f'Linked list has no node with value {data}'))

    def _insert(self, data, prev_node: Node):
        next_node: Node = prev_node.next
        new_node: Node = Node(data, self)

        prev_node.next = new_node
        new_node.next = next_node
        self._run_common_actions("add_node")
        return new_node

    # O(1)
    def insert_after(self, data, prev_node: Node):
        if type(prev_node) != Node:
            raise (TypeError("prev_node is not of type Node"))

        if prev_node.linked_list == self:
            if prev_node == self.tail:
                self.add_node(data)
            else:
                return self._insert(data, prev_node)
        else:
            raise ValueError(f"Node {prev_node} does not belong to this linked list")

    # O(n)
    def insert_at(self, data, pos: int):
        if pos == 0:
            return self.add_first_node(data)
        else:
            self._check_index_bounds(pos)
            prev_node: Node = self.get_node(pos - 1)
            return self._insert(data, prev_node)
        
    def _remove(self, prev_node: Node):
        old_next = prev_node.next.next
        
        # Memory cleanup
        prev_node.next.data = prev_node.next.next = None
        del prev_node.next
        
        prev_node.next = old_next
        self._run_common_actions("remove_node")
        
    # O(1)
    def remove_first(self):
        second_node = self.head.next
        
        # Memory cleanup
        del self.head
        
        self.head = second_node
        self._run_common_actions("remove_node")
    
    # O(1)
    def remove_last(self):
        penultimate_node = self.tail.prev
        
        # Memory cleanup
        self.tail.data = self.tail.prev = None
        del self.tail
        
        self.tail = penultimate_node
        self._run_common_actions("remove_node")
        
    # O(n)
    def remove_at(self, pos: int):
        if pos == 0 and self._length > 0:
            return self.remove_first()
        if (pos == self._length - 1) and self._length > 0:
            return self.remove_last()
        
        self._check_index_bounds(pos)
        prev_node: Node = self.get_node(pos - 1)
        return self._remove(prev_node)
    
    # O(n)
    def find_node(self, data):
        for node in self:
            if node.data == data:
                return node
            
        return None
    
    # O(n)
    def clear(self):
        trav = self.head
        while trav:
            next_node = trav.next
            trav.next = trav.prev = None
            trav.data = None
            
            trav = next_node
            
        self.head = self.tail = self._last_added_node_id = None
        self._length = 0
            

    # O(n)
    def __str__(self):
        return " --> ".join([str(node) for node in self])


if __name__ == "__main__":
    singly_linked_list = SinglyLinkedList()
    singly_linked_list.add_node(5)
    singly_linked_list.add_node("fds")
    singly_linked_list.add_node(439)
    print(singly_linked_list)
    singly_linked_list.insert_at("new", 0)
    print('added', singly_linked_list)
    # target_node = singly_linked_list.head.next
    # singly_linked_list.insert_after('newer', target_node)
    # print(singly_linked_list)
    # singly_linked_list2 = SinglyLinkedList()
    # singly_linked_list2.add_node(5)
    # singly_linked_list2.add_node("fds")
    # singly_linked_list2.add_node(439)
    # singly_linked_list.insert_after('new', singly_linked_list.head.next)
    # my_iter = iter(singly_linked_list)

    # print(next(my_iter))
    # print(next(my_iter))
    # print(next(my_iter))
    # print(singly_linked_list)
    # print(singly_linked_list.values)

    # TODO: IMPLEMENT THE FOLLOWING METHODS
    # ✅ add_node_as_head / insert_at_the_beginning / add_first: O(1)

    # ✅ __str__
    
    # ✅ __len__
    
    # ✅ __iter__

    # ✅ @property: values - to access the values of all nodes included  in the sequence

    # ✅ insert_after - insert after a node
    
    # ✅ insert_at - insert after a node

    # ✅ remove_first: O(1)
    
    # ✅ remove_last: O(1)
    
    # ✅ remove_at: O(n) - remove from a position
    
    # ✅ remove: O(n)

    # ✅ search_node O(n)
    
    # ✅ clear: O(n)

    # ✅ indexOf: O(n)
 