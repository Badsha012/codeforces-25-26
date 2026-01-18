def array_value(arr):
    cur_max = 0
    total = 0
    for x in arr:
        cur_max = max(cur_max, x)
        total += cur_max
    return total


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    # value without any swap
    best = array_value(a)

    # try all possible swaps
    for i in range(n):
        for j in range(i + 1, n):
            a[i], a[j] = a[j], a[i]      # swap
            best = max(best, array_value(a))
            a[i], a[j] = a[j], a[i]      # swap back

    print(best)
