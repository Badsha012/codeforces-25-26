import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    idx = 1
    results = []
    for _ in range(t):
        n = int(input_data[idx]); idx+=1
        h = int(input_data[idx]); idx+=1
        l = int(input_data[idx]); idx+=1
        arr = list(map(int, input_data[idx:idx+n])); idx+=n
        
        freq = [0] * 1001
        for v in arr:
            freq[v] += 1
        
        sum_row = 0
        for i in range(1, h+1):
            sum_row += freq[i]
        
        sum_col = 0
        for j in range(1, l+1):
            sum_col += freq[j]
        
        ans = min(sum_row, sum_col, n//2)
        results.append(str(ans))
    
    print("\n".join(results))

if __name__ == "__main__":
    solve()