# -*- coding: utf-8 -*-


class FixedArrayStack:
    def __init__(self, capacity):
        self.head = -1
        self.capacity = capacity
        self.stack = [None for i in range(capacity)]

    def push(self, value):
        if self.is_full():
            raise Exception('Stack Overflow')

        self.head += 1
        self.stack[self.head] = value

    def pop(self):
        if self.is_empty():
            raise Exception('Stack Underflow')

        old_index = self.head
        self.head -= 1
        return self.stack[old_index]

    def top(self):
        if self.is_empty():
            raise Exception('Stack Underflow')
        return self.stack[self.head]

    def size(self):
        return self.head + 1

    def is_empty(self):
        return self.head == -1

    def is_full(self):
        return self.head == self.capacity - 1


def main():
    stack = FixedArrayStack(5)

    print('is empty:', stack.is_empty())
    print('is full:', stack.is_full())

    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(5)

    print('is empty:', stack.is_empty())
    print('is full:', stack.is_full())
    print('size:', stack.size())
    print('top:', stack.top())

    print(stack.pop())
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())


if __name__ == '__main__':
    main()
