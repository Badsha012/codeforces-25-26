import sys

def solve():
    
    try:
        line1 = sys.stdin.readline()
        if not line1:
            return
        n = int(line1.strip())
        line2 = sys.stdin.readline()
        if not line2:
            return
        a = list(map(int, line2.split()))
    except ValueError:
        return

 
    indexed_a = []
    for i in range(n):
        indexed_a.append((a[i], i % 2))

  
    indexed_a.sort()

    
    possible = True
    for i in range(1, n):
      
        if indexed_a[i][1] == indexed_a[i-1][1]:
            possible = False
            break
    
    if possible:
        print("YES")
    else:
        print("NO")

def main():
    line = sys.stdin.readline()
    if line:
        t = int(line.strip())
        for _ in range(t):
            solve()

if __name__ == "__main__":
    main()