class Node:
    def __init__(self, value=None, next_node=None):
        self.next_node = next_node
        self.value = value

    def __str__(self):
        return str(self.value)


class List:
    def __init__(self):
        self.top = Node()
        self.tail = None
        self.top.next_node = self.tail

    def prepend(self, value):
        tmp = Node(value)
        tmp.next_node = self.top.next_node
        self.top.next_node = tmp

    def append(self, value):
        if self.tail is None:
            self.top.next_node = Node(value)
            self.tail = self.top.next_node
            return
        self.tail.next_node = Node(value)
        self.tail = self.tail.next_node

    def find(self, value):
        current = self.top.next_node
        while current is not None:
            if current.value == value:
                return current
            current = current.next_node
        return None

    def insert(self, value_for_insert, value_target):
        target = self.find(value_target)
        if target is None:
            print("Target value does not exist")
            return
        tmp = Node(value_for_insert)
        tmp.next_node = target.next_node
        target.next_node = tmp

    def delete(self, value):
        current = self.top.next_node
        prev = self.top
        while current is not None:
            if current.value == value:
                if current == self.tail:
                    self.tail = prev
                prev.next_node = current.next_node
                return
            prev = current
            current = current.next_node

    def __str__(self):
        current = self.top.next_node
        values = "["
        while current is not None:
            end = ", " if current.next_node else ""
            values += str(current) + end
            current = current.next_node
        return values + "]"


lst = List()
lst.append(5)
lst.append(17)
lst.append(23)
lst.delete(17)
lst.delete(23)
lst.prepend(11)
lst.prepend(23)
lst.insert(7, 11)
print(lst)