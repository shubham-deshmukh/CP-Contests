import math
tc = int(input())

for i in range(tc):
    n,t = map(int, input().split())
    a = [int(x) for x in input().split()]
    s = 0
    ss = 0

    for x in a:
        s += x
        ss += x * x
    
    A = n * 4
    B = 4 * s
    C = ss - t
    D1 = B * B - 4 * A * C
    D = s * s - n * C
    ans = (-B + 4 * math.sqrt(D)) / (2 * A)
    print(int(ans))