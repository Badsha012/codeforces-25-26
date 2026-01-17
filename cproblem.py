import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        s = data[idx]
        idx += 1
        
        # Check if string is sorted (all 0s then all 1s)
        sorted_str = True
        seen_one = False
        for char in s:
            if char == '1':
                seen_one = True
            elif char == '0' and seen_one:
                sorted_str = False
                break
        
        if sorted_str:
            results.append("Bob")
        else:
            # Find first '1' and last '0'
            first_one = -1
            last_zero = -1
            for i in range(n):
                if s[i] == '1' and first_one == -1:
                    first_one = i
                if s[i] == '0':
                    last_zero = i
            
            # We know first_one < last_zero because string is not sorted
            results.append("Alice")
            results.append(f"2\n{first_one + 1} {last_zero + 1}")
    
    print("\n".join(results))

if __name__ == "__main__":
    solve()