import unittest
from linked_list import LinkedList, Node


class LinkedListTest(unittest.TestCase):
    def setUp(self):
        self.linked_list = LinkedList()
        self.test_values = ["item1", "item2", 40]

    def test_add_node(self):
        self.linked_list.add_node(5)
        self.assertEqual(self.linked_list.head.data, 5)
        self.assertEqual(self.linked_list.tail.data, 5)
        self.assertEqual(self.linked_list.length, 1)

    def test_add_multiple_nodes(self):
        self.linked_list.add_multiple_nodes(self.test_values)
        for val in self.test_values:
            self.assertIn(val, self.linked_list.values)

    def test_values_property(self):
        self.linked_list.add_multiple_nodes(self.test_values)
        self.assertEqual(self.test_values, self.linked_list.values)

    def test_linked_list_length_with_add_node(self):
        self.linked_list.add_node("test_node")
        self.assertEqual(self.linked_list.length, 1)

        # Change to self.linked_list.clear() once you implement clear()
        self.linked_list = LinkedList()

    def test_linked_list_length_with_add_multiple_nodes(self):
        self.linked_list.add_multiple_nodes(self.test_values)
        self.assertEqual(self.linked_list.length, len(self.test_values))

    def test_add_first_node(self):
        first_node = ["first_node", "is_an_array"]
        self.linked_list.add_first_node(first_node)
        self.assertEqual(self.linked_list.head.data, first_node)

    def test_get_node(self):
        self.linked_list.add_node("first")
        self.linked_list.add_node("second")
        self.linked_list.add_node(3)

        head = self.linked_list.get_node(0)
        second_node = self.linked_list.get_node(1)
        tail = self.linked_list.get_node(2)

        self.assertEqual(head.data, "first")
        self.assertEqual(second_node.data, "second")
        self.assertEqual(tail.data, 3)

    def test_last_added_node(self):
        self.linked_list.add_node("first")
        self.linked_list.add_node("second")
        last_added_node = self.linked_list.add_node("last")
        self.assertEqual(self.linked_list._last_added_node, self.linked_list.tail)
        self.assertEqual(self.linked_list._last_added_node, last_added_node)

    def test_insert_after(self):
        first_node = self.linked_list.add_node("first")
        self.linked_list.insert_after("second", first_node)
        self.assertEqual(self.linked_list.get_node(1).data, "second")
        
    def test_insert_at(self):
        self.linked_list.insert_at('first', 0)
        self.assertEqual(self.linked_list.head.data, 'first')
        
        self.linked_list.add_multiple_nodes(self.test_values)
        new_node = {'new': ['newly', 'inserted', 'node']}
        self.linked_list.insert_at(new_node, 2)
        self.assertEqual(self.linked_list.get_node(2).data, new_node)

    # INTEGRATION TESTS
    def test_get_node_node_after_insertion(self):
        # BEFORE INSERTION
        self.linked_list.add_node("first")
        self.linked_list.add_node("fourth")

        # AFTER CALLING insert_at
        second_node = self.linked_list.insert_at("second", 1)
        self.assertEqual(self.linked_list.get_node(1).data, "second")

        # AFTER CALLING insert_after
        self.assertEqual(self.linked_list.get_node(2).data, "fourth")
        self.linked_list.insert_after("third", second_node)
        self.assertEqual(self.linked_list.get_node(2).data, "third")


    def test_last_added_node_after_insertion(self):
        first_node = self.linked_list.add_node("first")
        third_node = self.linked_list.add_node('third')
        last_added_node = self.linked_list.insert_after("second", first_node)
        self.assertEqual(self.linked_list._last_added_node, last_added_node)
        

class NodeTest(unittest.TestCase):
    def setUp(self):
        self.node = Node('test_node_data')
        self.node3 = Node('Yet another node')
        
    def test_node_data(self):
        self.assertEqual(self.node.data, 'test_node_data')
    
    def test_next_node(self):
        self.node2 = Node('Another node', self.node)
        self.assertEqual(self.node2.next, self.node)
    
    
        

if __name__ == "__main__":
    unittest.main()

# Test Node.data, Node.next, Node.prev, Node.__str__, LinkedList.__str__