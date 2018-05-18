# -*- coding: utf-8 -*-


def main():
    n = int(input('length: '))
    buf = [0 for i in range(n)]

    generate_bits(n, buf)


def generate_bits(n, array):
    if n < 1:
        print(''.join(map(str, array)))
    else:
        array[n - 1] = 0
        generate_bits(n - 1, array)

        array[n - 1] = 1
        generate_bits(n - 1, array)


if __name__ == '__main__':
    main()
