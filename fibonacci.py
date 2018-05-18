# -*- coding: utf-8 -*-


def main():
    nth = int(input('nth: '))
    fibo = fibonacci(nth)
    print(fibo)


# zero-origin index
def fibonacci(nth):
    if nth == 0:
        return 0
    elif nth == 1:
        return 1
    else:
        return fibonacci(nth - 1) + fibonacci(nth - 2)


if __name__ == '__main__':
    main()
