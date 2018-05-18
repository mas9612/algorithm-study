# -*- coding: utf-8 -*-


def main():
    n = int(input('n: '))
    fact = factorial(n)
    print(fact)


def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


if __name__ == '__main__':
    main()
