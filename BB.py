import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    # suffix maximum of b
    best = [0] * n
    best[-1] = b[-1]
    for i in range(n - 2, -1, -1):
        best[i] = max(best[i + 1], b[i])

    # final array after best replacements
    c = [max(a[i], best[i]) for i in range(n)]

    # prefix sum
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i + 1] = pref[i] + c[i]

    # process queries
    res = []
    for _ in range(q):
        l, r = map(int, input().split())
        res.append(str(pref[r] - pref[l - 1]))

    print(" ".join(res))
