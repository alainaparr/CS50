# TODO

from cs50 import get_int
# prompt user for height
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(0, n, 1):
    # print space
    for j in range(0, n, 1):
        if (i+j < n-1):
            print(" ", end="")
        # print #
        else:
            print("#", end="")
    print()
