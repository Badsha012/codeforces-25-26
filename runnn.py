import sys

def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    
    ops = 0
    # Work backwards from the second-to-last element
    for i in range(n - 2, -1, -1):
        # We need a[i] < a[i+1]
        while a[i] >= a[i+1] and a[i] > 0:
            a[i] //= 2
            ops += 1
        
        # If we couldn't make a[i] smaller than a[i+1]
        # (Usually happens if a[i+1] is 0)
        if a[i] >= a[i+1]:
            print("-1")
            return

    print(ops)

def main():
    line = sys.stdin.readline()
    if line:
        t = int(line)
        for _ in range(t):
            solve()

if __name__ == "__main__":
    main()