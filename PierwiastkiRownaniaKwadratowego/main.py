import math
from decimal import Decimal, getcontext
def find_solution(a,b,c,k):
    getcontext().prec = k+2
    a = Decimal(a)
    b = Decimal(b)
    c = Decimal(c)
    delta = b**2 - 4*a*c
    if delta<0:
        print("0")
    elif delta==0:
        print("1", end=' ')
        x = (-b/(2*a))
        print(x)
    else:
        print("2", end=' ')
        x1 = (-b + delta.sqrt()) / (2 * a)
        x2 = (-b - delta.sqrt()) / (2 * a)
        print(min(x1, x2), end=' ')
        print(max(x1, x2), end=' ')



def main():
    n = (int(input()))
    for i in range(1,n+1):
        inputs = input().strip().split(" ")
        a = Decimal(inputs[0])
        b = Decimal(inputs[1])
        c = Decimal(inputs[2])
        k = int(inputs[3])
        find_solution(a,b,c,k)

# Call the main function
if __name__ == "__main__":
    main()