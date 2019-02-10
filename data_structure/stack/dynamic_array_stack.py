# -*- coding: utf-8 -*-


class DynamicArrayStack:
    def __init__(self):
        self.head = -1
        self.capacity = 1
        self.stack = [None]

    def push(self, value):
        if self.is_full():
            self.capacity *= 2
            new_stack = [None for i in range(self.capacity)]
            for i in range(self.head + 1):
                new_stack[i] = self.stack[i]
            self.stack = new_stack

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
        return self.head

    def is_empty(self):
        return self.head == -1

    def is_full(self):
        return self.head == self.capacity - 1


def main():
    stack = DynamicArrayStack()

    print('is empty:', stack.is_empty())
    print('is full:', stack.is_full())
    print('size:', stack.size())
    print('capacity:', stack.capacity)

    print('\npush 1')
    stack.push(1)
    print('size:', stack.size())
    print('capacity:', stack.capacity)

    print('\npush 2')
    stack.push(2)
    print('size:', stack.size())
    print('capacity:', stack.capacity)

    print('\npush 3')
    stack.push(3)
    print('size:', stack.size())
    print('capacity:', stack.capacity)

    print('\npush 4')
    stack.push(4)
    print('size:', stack.size())
    print('capacity:', stack.capacity)

    print('\npush 5')
    stack.push(5)
    print('size:', stack.size())
    print('capacity:', stack.capacity)

    print('\npop', stack.pop())
    print('pop', stack.pop())
    print('pop', stack.pop())
    print('pop', stack.pop())
    print('pop', stack.pop())


if __name__ == '__main__':
    main()
