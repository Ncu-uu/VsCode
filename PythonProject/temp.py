from math import sqrt
from sys import stdout

def main():
    h =0 
    leap = 1
    
    for m in range(101,201):
        k = int(sqrt(m+1))
        for i in range(2,k+1):
            if m % i == 0:
                leap = 0
                break
        if leap == 1:
            print('%-4d' % m)
            h += 1
            if h % 10 == 0:
                print('')
        leap = 1
    print('The total is %d' % h)

if __name__ == '__main__':
    main()