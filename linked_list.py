# -*- coding: utf-8 -*-


class Node:
    def __init__(self, data):
        self.next = None
        self.data = data


class LinkedList:
    def __init__(self):
        self.head = None

    def length(self):
        length = 0
        current = self.head

        while current is not None:
            current = current.next
            length += 1

        return length

    def insert(self, index, data):
        new_node = Node(data)
        tmp = self.head

        if index == 0:
            self.head = new_node
            new_node.next = tmp
        else:
            i = 0
            while (tmp is not None) and (i < index):
                prev = tmp
                tmp = tmp.next
                i += 1

            prev.next = new_node
            new_node.next = tmp

    def delete(self, index):
        deleted = None

        if index == 0:
            deleted = self.head.data
            self.head = self.head.next
        else:
            tmp = self.head
            i = 0
            while (tmp is not None) and (i < index):
                prev = tmp
                tmp = tmp.next
                i += 1

            deleted = tmp.data
            prev.next = tmp.next

        return deleted

    def delete_all(self):
        self.head = None

    def print_all(self):
        current = self.head

        print('[ ', end='')
        while current is not None:
            print('{} '.format(current.data), end='')
            current = current.next
        print(']')


def main():
    linked_list = LinkedList()
    linked_list.insert(0, 1)
    linked_list.print_all()

    linked_list.insert(1, 3)
    linked_list.print_all()

    linked_list.insert(1, 9)
    linked_list.print_all()

    length = linked_list.length()
    print('Length: {}\n'.format(length))

    linked_list.delete(1)
    linked_list.print_all()

    linked_list.insert(2, 5)
    linked_list.print_all()

    linked_list.insert(100, 8)
    linked_list.print_all()

    linked_list.delete_all()
    length = linked_list.length()
    print('Length: {}\n'.format(length))
    linked_list.print_all()


if __name__ == '__main__':
    main()
