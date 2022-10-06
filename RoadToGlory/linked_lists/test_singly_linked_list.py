import unittest
from singly_linked_list import SinglyLinkedList, Node


class SinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.singly_linked_list = SinglyLinkedList()
        self.test_values = ["item1", "item2", 40]

    def test_check_index_bounds(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        self.singly_linked_list._check_index_bounds(0)
        self.singly_linked_list._check_index_bounds(1)
        self.singly_linked_list._check_index_bounds(2)
        self.assertRaises(IndexError, self.singly_linked_list._check_index_bounds, -1)
        self.assertRaises(IndexError, self.singly_linked_list._check_index_bounds, 3)

    def test_add_node(self):
        self.singly_linked_list.add_node(5)
        self.assertEqual(self.singly_linked_list.head.data, 5)
        self.assertEqual(self.singly_linked_list.tail.data, 5)
        self.assertEqual(self.singly_linked_list.length, 1)

    def test_add_multiple_nodes(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        for val in self.test_values:
            self.assertIn(val, self.singly_linked_list.values)

    def test_values_property(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        self.assertEqual(self.test_values, self.singly_linked_list.values)

    def test_singly_linked_list_length_with_add_node(self):
        self.singly_linked_list.add_node("test_node")
        self.assertEqual(self.singly_linked_list.length, 1)

        # Change to self.singly_linked_list.clear() once you implement clear()
        self.singly_linked_list = SinglyLinkedList()

    def test_singly_linked_list_length_with_add_multiple_nodes(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        self.assertEqual(self.singly_linked_list.length, len(self.test_values))

    def test_add_first_node(self):
        first_node = ["first_node", "is_an_array"]
        self.singly_linked_list.add_first_node(first_node)
        self.assertEqual(self.singly_linked_list.head.data, first_node)

    def test_get_node(self):
        self.singly_linked_list.add_node("first")
        self.singly_linked_list.add_node("second")
        self.singly_linked_list.add_node(3)

        head = self.singly_linked_list.get_node(0)
        second_node = self.singly_linked_list.get_node(1)
        tail = self.singly_linked_list.get_node(2)

        self.assertEqual(head.data, "first")
        self.assertEqual(second_node.data, "second")
        self.assertEqual(tail.data, 3)
        
    def test_index_of(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        
        self.assertEqual(self.singly_linked_list.index_of("item1"), 0)
        self.assertEqual(self.singly_linked_list.index_of("item2"), 1)
        self.assertEqual(self.singly_linked_list.index_of(40), 2)
        self.assertRaises(ValueError, self.singly_linked_list.index_of, "missing node")

    def test_last_added_node_id(self):
        self.singly_linked_list.add_node("first")
        self.singly_linked_list.add_node("second")
        last_added_node = self.singly_linked_list.add_node("last")
        self.assertEqual(self.singly_linked_list._last_added_node_id, self.singly_linked_list.tail.id)
        self.assertEqual(self.singly_linked_list._last_added_node_id, last_added_node.id)

    def test_insert_after(self):
        first_node = self.singly_linked_list.add_node("first")
        self.singly_linked_list.insert_after("second", first_node)

        
        self.assertEqual(self.singly_linked_list.get_node(1).data, "second")

    def test_insert_after_with_invalid_node_of_another_singly_linked_list(self):
        new_singly_linked_list = SinglyLinkedList()
        new_singly_linked_list.add_node('new_node')
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        
        self.assertRaises(ValueError, self.singly_linked_list.insert_after, 'item3', new_singly_linked_list.head)

    def test_insert_after_with_invalid_prev_node_type(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        
        self.assertRaises(TypeError, self.singly_linked_list.insert_after, 'item3', 'item2')
    
    def test_insert_at(self):
        self.singly_linked_list.insert_at("first", 0)
        self.assertEqual(self.singly_linked_list.head.data, "first")

        self.singly_linked_list.add_multiple_nodes(self.test_values)
        new_node = {"new": ["newly", "inserted", "node"]}
        self.singly_linked_list.insert_at(new_node, 2)

        self.assertEqual(self.singly_linked_list.get_node(2).data, new_node)
        
    def test_remove_first(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        head = self.singly_linked_list.head
        singly_linked_list_length = self.singly_linked_list._length
        self.singly_linked_list.remove_first()

        self.assertNotEqual(self.singly_linked_list.head, head)
        self.assertEqual(self.singly_linked_list.head, head.next)
        self.assertNotEqual(self.singly_linked_list.head.next, None)
        self.assertEqual(self.singly_linked_list._length, singly_linked_list_length - 1)

    def test_remove_last(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        tail = self.singly_linked_list.tail
        singly_linked_list_length = self.singly_linked_list._length
        self.singly_linked_list.remove_last()

        self.assertNotEqual(self.singly_linked_list.tail, tail)
        self.assertEqual(self.singly_linked_list._length, singly_linked_list_length - 1)

    def test_remove_at(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        singly_linked_list_length = self.singly_linked_list._length
        self.singly_linked_list.remove_at(1)
        for node in self.singly_linked_list:
            self.assertNotEqual(node.data, "item2")

        self.assertEqual(self.singly_linked_list._length, singly_linked_list_length - 1)

    def test_find_node(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)

        self.assertNotEqual(self.singly_linked_list.find_node("item1"), None)
        self.assertNotEqual(self.singly_linked_list.find_node("item2"), None)
        self.assertNotEqual(self.singly_linked_list.find_node(40), None)
        self.assertEqual(self.singly_linked_list.find_node("missing node"), None)

    def test_clear(self):
        self.singly_linked_list.add_multiple_nodes(self.test_values)
        self.singly_linked_list.clear()

        self.assertEqual(self.singly_linked_list.head, None)
        self.assertEqual(self.singly_linked_list.tail, None)
        self.assertEqual(self.singly_linked_list._last_added_node_id, None)
        self.assertEqual(self.singly_linked_list._length, 0)

    def test_singly_linked_list_print(self):
        self.singly_linked_list.add_node("first")
        self.singly_linked_list.add_node("second")
        self.assertEqual(self.singly_linked_list.__str__(), "first --> second")

    # INTEGRATION TESTS
    def test_get_node_node_after_insertion(self):
        # BEFORE INSERTION
        self.singly_linked_list.add_node("first")
        self.singly_linked_list.add_node("fourth")

        # AFTER CALLING insert_at
        second_node = self.singly_linked_list.insert_at("second", 1)
        self.assertEqual(self.singly_linked_list.get_node(1).data, "second")

        # AFTER CALLING insert_after
        self.assertEqual(self.singly_linked_list.get_node(2).data, "fourth")
        self.singly_linked_list.insert_after("third", second_node)
        self.assertEqual(self.singly_linked_list.get_node(2).data, "third")

    def test_last_added_node_id_after_insertion(self):
        first_node = self.singly_linked_list.add_node("first")
        self.singly_linked_list.add_node("third")
        last_added_node = self.singly_linked_list.insert_after("second", first_node)
        self.assertEqual(self.singly_linked_list._last_added_node_id, last_added_node.id)


class NodeTest(unittest.TestCase):
    def setUp(self):
        self.node = Node("test_node_data")
        self.test_singly_linked_list = SinglyLinkedList()

    def test_node_data(self):
        self.assertEqual(self.node.data, "test_node_data")

    def test_next_node(self):
        self.node2 = Node("Another node", self.node)
        self.assertEqual(self.node2.next, None, self.node)

    def test_prev_node(self):
        self.node2 = Node("Yet another node", None, None, self.node)
        self.assertEqual(self.node2.prev, self.node)

    def test_node_id_with_nullish_last_added_node_id(self):
        self.assertEqual(self.test_singly_linked_list._last_added_node_id, None)
        self.node2 = Node("Another node", self.test_singly_linked_list)
        self.assertEqual(self.node2.id, 1)

    def test_node_id_with_real_last_added_node_id(self):
        self.test_singly_linked_list.add_node("A new node")
        self.assertNotEqual(self.test_singly_linked_list._last_added_node_id, None)
        second_node = self.test_singly_linked_list.add_node("Yet another node")

        self.assertEqual(second_node.id, 2)

    def test_node_print(self):
        self.assertEqual(self.node.__str__(), self.node.data)


if __name__ == "__main__":
    unittest.main()
