# -*- coding: utf-8 -*-


def main():
    length = int(input('length: '))
    base = int(input('base: '))
    buf = [0 for i in range(length)]

    generate_n_base(length, base, buf)


def generate_n_base(length, base, array):
    if length < 1:
        print(''.join(map(str, array)))
    else:
        for i in range(base):
            array[length - 1] = i
            generate_n_base(length - 1, base, array)


if __name__ == '__main__':
    main()
