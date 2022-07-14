import ctypes


class DynamicArray(object):
    def __init__(self):
        self.n = 0
        self.capacity = 1
        self.arr = self._make_array(self.capacity)

    def _make_array(self, capacity):
        return (capacity * ctypes.py_object)()

    def _resize(self):
        new_arr = self._make_array(self.capacity * 2)
        for ind in range(self.n):
            new_arr[ind] = self.arr[ind]

        self.arr = new_arr
        self.capacity *= 2

    def _check_index_bounds(self, ind):
        if not (0 <= ind < self.n):
            raise IndexError(f'{ind} is out of bounds')
        return

    def __len__(self):
        return self.n

    def __getitem__(self, pos):
        self._check_index_bounds(pos)
        return self.arr[pos]

    def is_empty(self):
        return self.n == 0

    def clear(self):
        self.arr = self._make_array(1)
        self.n = 0
        self.capacity = 1

    def delete(self):
        if self.n == 0:
            raise IndexError('Deletion from empty list is not possible')

        self.arr[self.n - 1] = None
        self.n -= 1

    def removeAt(self, pos):
        self._check_index_bounds(pos)
        if self.n == 0:
            raise IndexError('Deletion from empty list is not possible')

        if pos == self.n - 1:
            self.arr[self.n - 1] = None

        for ind in range(pos, self.n - 1):
            self.arr[ind] = self.arr[ind + 1]

        self.n -= 1

    def append(self, ele):
        if self.n == self.capacity:
            self._resize()
        self.arr[self.n] = ele
        self.n += 1

    def insertAt(self, pos, ele):
        self._check_index_bounds(pos)

        old_arr_len = self.n
        if self.n == self.capacity:
            self._resize()

        for ind in range((old_arr_len - 1), (pos - 1), -1):
            self.arr[ind + 1] = self.arr[ind]

        self.arr[pos] = ele


my_array = DynamicArray()

print(my_array.__len__())
print(my_array.capacity)
print(my_array.is_empty())
my_array.append(5)
my_array.append(6)
my_array.append(7)
my_array.append(8)
my_array.append(8)
my_array.insertAt(0, 20)
print(my_array[0], my_array[1], my_array[2], my_array[3], my_array[4])
print(my_array.__len__())
print(my_array.capacity)
print(my_array.is_empty())
my_array.clear()
print(my_array.__len__())
print(my_array.capacity)
print(my_array.is_empty())
