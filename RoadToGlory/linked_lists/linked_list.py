from typing import Literal, Union

class Node:
    def __init__(self, data, linked_list=None, next_node=None, prev_node=None):
        self.data = data
        self.next = next_node
        self.prev = prev_node
        self.linked_list = linked_list

    @property
    def id(self):
        if self.linked_list._last_added_node:
            return self.linked_list._last_added_node.id + 1
        else:
            return 1

    def __str__(self) -> str:
        return str(self.data)


class LinkedList:
    def __init__(self, values: Union[list, tuple] = None):
        self.head = None
        self.tail = None
        self._length = 0
        self._last_added_node = None

        if values is not None:
            self.add_multiple_nodes(values)

    def _check_index_bounds(self, ind):
        if not (0 <= ind < self._length):
            raise IndexError(f"{ind} is out of bound")
        return
    
    def _run_common_actions(self, action_type: Literal['add_node', 'remove_node'] , data):
        if action_type == 'add_node':
            self._length += 1
            self._last_added_node = data
            

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
        return [node.data for node in self]

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
        self._run_common_actions('add_node', self.tail)
        return self.tail

    # O(1)
    def add_first_node(self, data):
        if self._length == 0:
            self.add_node(data)
        self.head.next = self.head
        self.head = Node(data, self)
        
        self._run_common_actions('add_node', self.head)
        return self.head

    # O(n)
    def get_node(self, pos):
        self._check_index_bounds(pos)
        pointer: int = 0
        for node in self:
            if pointer == pos:
                return node
            pointer += 1
            
    def _insert(self, data, prev_node: Node):
        next_node: Node = prev_node.next
        new_node: Node = Node(data, self)

        prev_node.next = new_node
        new_node.next = next_node
        self._run_common_actions('add_node', new_node)
        return new_node

    # O(1)
    def insert_after(self, data, prev_node: Node):
        if type(prev_node) != Node:
            raise(TypeError('prev_node is not of type Node'))
        
        if prev_node.linked_list == self:
            if prev_node == self.tail:
                self.add_node(data)
            return self._insert(data, prev_node)
        else:
            raise ValueError(f'Node {prev_node} does not belong to this linked list')

    # O(n)
    def insert_at(self, data, pos):
        if (pos == 0 and self._length == 0):
            self.add_node(data)
        else:
            self._check_index_bounds(pos)
            prev_node: Node = self.get_node(pos - 1)
            return self._insert(data, prev_node)

    # O(n)
    def __str__(self):
        return " --> ".join([str(node) for node in self])


if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.add_node(5)
    linked_list.add_node("fds")
    linked_list.add_node(439)
    print(linked_list)
    linked_list.insert_at("new", 1)
    print(linked_list)
    target_node = linked_list.head.next
    linked_list.insert_after('newer', target_node)
    print(linked_list)
    # linked_list2 = LinkedList()
    # linked_list2.add_node(5)
    # linked_list2.add_node("fds")
    # linked_list2.add_node(439)
    # linked_list.insert_after('new', linked_list.head.next)
    # my_iter = iter(linked_list)

    # print(next(my_iter))
    # print(next(my_iter))
    # print(next(my_iter))
    # print(linked_list)
    # print(linked_list.values)

    # * NOTE: IMPLEMENT PRIVATE remove() METHOD TO BE CALLED BY remove_at() and remove() (public one)

    # ? add_node_as_head / insert_at_the_beginning / add_first: O(1)

    # ? ! __str__
    # ? __len__
    # ? __iter__

    # ? @property: values - to access the values of all nodes included  in the sequence

    #! insert_after - insert after a node
    #! insert_at - insert after a node

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
