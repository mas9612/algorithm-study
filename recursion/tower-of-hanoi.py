# -*- coding: utf-8 -*-


def main():
    n = int(input('How many plates: '))

    print()
    tower_of_hanoi(n, 1, 3, 2)


def tower_of_hanoi(n, src, dest, aux):
    if n == 1:
        print('move #{}: from {} to {}'.format(n, src, dest))
    else:
        tower_of_hanoi(n - 1, src, aux, dest)
        print('move #{}: from {} to {}'.format(n, src, dest))
        tower_of_hanoi(n - 1, aux, dest, src)


if __name__ == '__main__':
    main()
