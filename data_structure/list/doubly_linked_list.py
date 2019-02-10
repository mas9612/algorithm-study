# -*- coding: utf-8 -*-


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, index, data):
        new_node = Node(data)

        if index == 0:
            new_node.next = self.head
            if self.head is not None:
                self.head.prev = new_node
            self.head = new_node
        else:
            tmp = self.head
            i = 0
            while (tmp.next is not None) and (i < index - 1):
                tmp = tmp.next
                i += 1

            new_node.next = tmp.next
            new_node.prev = tmp
            tmp.next = new_node
            if tmp.next is not None:
                tmp.next.prev = new_node

    def delete(self, index):
        if index == 0:
            data = self.head.data
            self.head = self.head.next
            self.head.prev = None
        else:
            tmp = self.head
            i = 0
            while (tmp.next is not None) and (i < index):
                tmp = tmp.next
                i += 1

            data = tmp.data
            tmp2 = tmp
            tmp2.prev.next = tmp.next
            if tmp2.next is not None:
                tmp2.next.prev = tmp.prev

        return data

    def print_nodes(self):
        tmp = self.head

        print('[ ', end='')
        while tmp is not None:
            print('{} '.format(tmp.data), end='')
            tmp = tmp.next
        print(']')


def main():
    doubly_list = DoublyLinkedList()
    doubly_list.insert(0, 1)
    doubly_list.print_nodes()

    doubly_list.insert(1, 3)
    doubly_list.print_nodes()

    doubly_list.insert(2, 5)
    doubly_list.print_nodes()

    doubly_list.insert(1, 4)
    doubly_list.print_nodes()

    doubly_list.insert(1, 2)
    doubly_list.print_nodes()

    doubly_list.delete(0)
    doubly_list.print_nodes()

    doubly_list.delete(3)
    doubly_list.print_nodes()

    doubly_list.delete(1)
    doubly_list.print_nodes()


if __name__ == '__main__':
    main()
