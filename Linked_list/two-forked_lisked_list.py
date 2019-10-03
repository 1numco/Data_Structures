class Node:
    def __init__(self, value=None, next_node=None, prev_node=None):
        self.next_node = next_node
        self.prev_node = prev_node
        self.value = value

    def __str__(self):
        return str(self.value)


class List:
    def __init__(self):
        self.top = Node()

    def append(self, value):
        current = self.top
        while current.next_node is not None:
            current = current.next_node
        new_node = Node(value)
        current.next_node = new_node
        new_node.prev_node = current

    def prepend(self, value):
        new_node = Node(value, self.top.next_node, self.top)
        if self.top.next_node is not None:
            self.top.next_node.prev_node = new_node
        self.top.next_node = new_node

    def insert(self, after_value, value):
        current = self.top.next_node
        while current is not None:
            if current.value == after_value:
                new_node = Node(value, current.next_node, current)
                if current.next_node is not None:
                    current.next_node.prev_node = new_node
                current.next_node = new_node
                return
            current = current.next_node

    def remove(self, value):
        current = self.top.next_node
        while current is not None:
            if current.value == value:
                if current.next_node is not None:
                    current.next_node.prev_node = current.prev_node
                current.prev_node.next_node = current.next_node
                return
            current = current.next_node

    def __str__(self):
        current = self.top.next_node
        values = "["
        while current is not None:
            end = ", " if current.next_node else ""
            values += str(current) + end
            current = current.next_node

        return values + "]"


# lst = List()
# lst.append(1)
# lst.append(2)
# lst.append(3)
# lst.append(5)
# lst.append(7)
# print(lst.__str__())
# "[1, 2, 3, 5, 7]"
# lst.remove(3)
# lst.remove(7)
# print(lst.__str__())
# "[1, 2, 5]"
# five = lst.top.next_node.next_node.next_node
# print(five.value)
# print(five.next_node)
# print(five.prev_node.value)