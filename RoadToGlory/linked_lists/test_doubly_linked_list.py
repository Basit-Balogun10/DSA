import unittest
from doubly_linked_list import DoublySinglyLinkedList


class DoublySinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.doubly_linked_list = DoublySinglyLinkedList()
        self.test_values = ["item1", "item2", 40]
        
    def test_insert_after(self):
        first_node = self.doubly_linked_list.add_node("first")
        second_node = self.doubly_linked_list.insert_after("second", first_node)

        self.assertEqual(self.doubly_linked_list.get_node(1).data, "second")
        self.assertEqual(self.doubly_linked_list.head.next, second_node)
        self.assertEqual(self.doubly_linked_list.get_node(1).prev, first_node)
        
        
    def test_values_property(self):
        self.doubly_linked_list.add_multiple_nodes(self.test_values)
        self.assertEqual(self.test_values, self.doubly_linked_list.values)

    
    def test_remove_once(self):
        self.doubly_linked_list.add_multiple_nodes(self.test_values)
        # self.doubly_linked_list.add_node("item2")
        self.doubly_linked_list.remove("item2")

        self.assertEqual(self.doubly_linked_list.length, 2)
        self.assertEqual(self.doubly_linked_list.values, ["item1", 40])
        
            
    def test_remove_multiple_times(self):
        self.doubly_linked_list.add_multiple_nodes(self.test_values)
        self.doubly_linked_list.add_node(40)
        self.doubly_linked_list.add_multiple_nodes(self.test_values)
        self.doubly_linked_list.remove(40, 3)
        
        self.assertEqual(self.doubly_linked_list.length, 4)
        self.assertEqual(self.doubly_linked_list.values, ["item1", "item2", "item1", "item2"])
        
    def test_remove_with_missing_node(self):
        self.doubly_linked_list.add_node('first node')
        
        self.assertRaises(ValueError, self.doubly_linked_list.remove, 'missing node')
        
    
    def test_remove_all(self):
        self.doubly_linked_list.add_multiple_nodes(self.test_values + [40, 40])
        initial_length = self.doubly_linked_list.length
        self.doubly_linked_list.remove_all(40)
        
        self.assertEqual(self.doubly_linked_list.length, initial_length - 3)
        self.assertEqual(self.doubly_linked_list.values, ["item1", "item2"])
        
    def test_remove_first(self):
        self.doubly_linked_list.add_multiple_nodes(self.test_values)
        head = self.doubly_linked_list.head
        doubly_linked_list_length = self.doubly_linked_list._length
        self.doubly_linked_list.remove_first()

        self.assertNotEqual(self.doubly_linked_list.head, head)
        self.assertEqual(self.doubly_linked_list.head, head.next)
        self.assertEqual(self.doubly_linked_list.head.prev, None)
        self.assertNotEqual(self.doubly_linked_list.head.next, None)
        self.assertEqual(self.doubly_linked_list._length, doubly_linked_list_length - 1)

    def test_remove_last(self):
        self.doubly_linked_list.add_multiple_nodes(self.test_values)
        tail = self.doubly_linked_list.tail
        doubly_linked_list_length = self.doubly_linked_list._length
        self.doubly_linked_list.remove_last()

        self.assertNotEqual(self.doubly_linked_list.tail, tail)
        self.assertEqual(self.doubly_linked_list.tail, tail.prev)
        self.assertEqual(self.doubly_linked_list.tail.next, None)
        self.assertNotEqual(self.doubly_linked_list.tail.prev, None)
        self.assertEqual(self.doubly_linked_list._length, doubly_linked_list_length - 1)
        
    def test_doubly_linked_list_print(self):
        self.doubly_linked_list.add_node("first")
        self.doubly_linked_list.add_node("second")
        self.assertEqual(self.doubly_linked_list.__str__(), "first <--> second")

        
if __name__ == "__main__":
    unittest.main()
