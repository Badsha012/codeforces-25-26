import sys

def solve():
    # Read n
    line1 = sys.stdin.readline()
    if not line1:
        return
    n = int(line1)
    
    # Read array a
    a = list(map(int, sys.stdin.readline().split()))
    
    # 1. Remove duplicates and sort
    unique_a = sorted(list(set(a)))
    
    if not unique_a:
        print(0)
        return

    # 2. Find the longest consecutive sequence
    max_mex = 0
    current_streak = 1
    
    # Even if we have only 1 element, we can shift it to 0, making MEX = 1
    max_mex = 1 
    
    for i in range(1, len(unique_a)):
        # Check if the current element is exactly 1 greater than the previous
        if unique_a[i] == unique_a[i-1] + 1:
            current_streak += 1
        else:
            current_streak = 1
        
        if current_streak > max_mex:
            max_mex = current_streak
            
    print(max_mex)

def main():
    line = sys.stdin.readline()
    if line:
        t = int(line)
        for _ in range(t):
            solve()

if __name__ == "__main__":
    main()
    