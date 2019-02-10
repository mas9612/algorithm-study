# -*- coding: utf-8 -*-

from linked_list import LinkedList


class NewLinkedList(LinkedList):
    def return_nth_from_last(self, nth):
        length = self.length()
        if length <= nth:
            return None

        count = length - 1 - nth
        node = self.head
        for i in range(count):
            node = node.next
        return node


def main():
    linked_list = NewLinkedList()
    linked_list.insert(0, 1)
    linked_list.insert(1, 2)
    linked_list.insert(2, 3)
    linked_list.insert(3, 4)
    linked_list.insert(4, 5)

    node = linked_list.return_nth_from_last(3)
    if node is not None:
        print(node.data)
    else:
        print('nothing')

    node = linked_list.return_nth_from_last(10)
    if node is not None:
        print(node.data)
    else:
        print('nothing')


if __name__ == '__main__':
    main()
