import ctypes


class DynamicArray(object):
    def __init__(self):
        self.__n = 0
        self.__capacity = 1
        self.arr = self._make_array(self.__capacity)

    def _make_array(self, capacity: int):
        return (capacity * ctypes.py_object)()

    def _resize(self):
        new_arr = self._make_array(self.__capacity * 2)
        for ind in range(self.__n):
            new_arr[ind] = self.arr[ind]

        self.arr = new_arr
        self.__capacity *= 2

    def _check_index_bounds(self, ind):
        if not (0 <= ind < self.__n):
            raise IndexError(f"{ind} is out of bound")
        return

    def __len__(self):
        return self.__n

    def __getitem__(self, pos):
        self._check_index_bounds(pos)
        return self.arr[pos]

    def __str__(self) -> str:
        if self.__n == 0:
            return "[]"
        stringified_array = ", ".join([str(self.arr[ind]) for ind in range(self.__n)])
        return f"[{stringified_array}]"

    def is_empty(self):
        return self.__n == 0

    def clear(self):
        self.arr = self._make_array(1)
        self.__n = 0
        self.__capacity = 1

    def delete(self):
        if self.__n == 0:
            raise IndexError("Deletion from empty list is not possible")

        self.arr[self.__n - 1] = None
        self.__n -= 1

    def removeAt(self, pos):
        self._check_index_bounds(pos)
        if self.__n == 0:
            raise IndexError("Deletion from empty list is not possible")

        if pos == self.__n - 1:
            self.arr[self.__n - 1] = None

        for ind in range(pos, self.__n - 1):
            self.arr[ind] = self.arr[ind + 1]

        self.__n -= 1

    def append(self, ele):
        if self.__n == self.__capacity:
            self._resize()
        self.arr[self.__n] = ele
        self.__n += 1

    def insertAt(self, pos, ele):
        if pos == 0 and self.__n == 0:
            self.append(ele)
        else:
            self._check_index_bounds(pos)

            old_arr_len = self.__n
            if self.__n == self.__capacity:
                self._resize()
            for ind in range((old_arr_len - 1), (pos - 1), -1):
                self.arr[ind + 1] = self.arr[ind]

            self.arr[pos] = ele
            self.__n += 1

    def index(self, ele):
        pointer = 0
        for ind in range(self.__n):
            if self.arr[ind] == ele:
                return pointer
            pointer += 1
        raise ValueError(f"{ele} is not in array")

    def contains(self, ele):
        try:
            self.index(ele)
            return True
        except ValueError:
            return False

    def extend(self, arr):
        for ele in arr:
            self.append(ele)

    def reverse(self):

        # # Less Efficient
        # if self.__n <= 1:
        #     return

        # new_arr = self._make_array(self.__capacity)
        # for ind in range(self.__n - 1, -1, -1):
        #     ele = self.arr[ind]
        #     new_arr[(self.__n - 1) - ind] = ele
        # self.arr = new_arr
        # return

        # More Efficient
        lp, rp = 0, self.__n - 1
        while lp < rp:
            temp = self.arr[lp]
            self.arr[lp] = self.arr[rp]
            self.arr[rp] = temp
            lp += 1
            rp -= 1


my_array = DynamicArray()
print(my_array.__str__())
print(my_array.__len__())
print(my_array.is_empty())
my_array.insertAt(0, 20)
my_array.append(5)
my_array.append(6)
my_array.append(7)
my_array.append(8)
print("fafsf", my_array)
print("ind...", my_array.index(7))
print("cont", my_array.contains(6))
my_array.extend(["boy", "girl", "man", 9])
iter_obj = iter(my_array)
print(iter_obj, next(iter_obj), iter_obj.__next__(), len(my_array), my_array)
my_array.reverse()
print(my_array)
# print(my_array[0], my_array[1], my_array[2], my_array[3], my_array[4])
# print(my_array.__len__())
# print(my_array.capacity)
# print(my_array.is_empty())
# my_array.clear()
# print(my_array.__len__())
# print(my_array.capacity)
# print(my_array.is_empty())
