import sys

def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    
    
    a.sort()
  
    def check(arr):
        n = len(arr)
    
        prefix_mex = [0] * n
        seen = set()
        curr_mex = 0
        for i in range(n):
            seen.add(arr[i])
            while curr_mex in seen:
                curr_mex += 1
            prefix_mex[i] = curr_mex
            
      
        suffix_mex = [0] * n
        seen = set()
        curr_mex = 0
        for i in range(n-1, -1, -1):
            seen.add(arr[i])
            while curr_mex in seen:
                curr_mex += 1
            suffix_mex[i] = curr_mex
            
        
        for i in range(n - 1):
            if prefix_mex[i] == suffix_mex[i+1]:
                return False
        return True

    
    if check(a):
        print("YES")
        return

    
    a.sort(reverse=True)
    if check(a):
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