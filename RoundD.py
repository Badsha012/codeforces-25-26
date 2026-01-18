import sys

def solve():
    # Use fast I/O
    input = sys.stdin.read().split()
    if not input:
        return
    
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    
    results = []
    
    for _ in range(t):
        n = int(input[ptr])
        m = int(input[ptr+1])
        h = int(input[ptr+2])
        ptr += 3
        
        # Original array
        original_a = []
        for i in range(n):
            original_a.append(int(input[ptr]))
            ptr += 1
            
        # Current working values
        current_a = list(original_a)
        # last_modified tracks when we last touched an index in the current cycle
        last_modified = [-1] * n 
        
        last_reset_op = -1
        
        # Store operations to replay them if needed, 
        # but we can actually find the last crash in one pass.
        ops = []
        for i in range(m):
            b = int(input[ptr]) - 1 # 0-indexed
            c = int(input[ptr+1])
            ptr += 2
            ops.append((b, c))
            
            # If this element hasn't been touched since the last reset, 
            # it should be the original value.
            if last_modified[b] < last_reset_op:
                current_a[b] = original_a[b]
            
            # Check for crash
            if current_a[b] + c > h:
                last_reset_op = i
                # We don't need to clear current_a, 
                # the last_modified check handles it.
            else:
                current_a[b] += c
                last_modified[b] = i

        # Final pass: reconstruct the array based on the last_reset_op
        final_array = list(original_a)
        # We only apply operations that happened AFTER the last reset
        for i in range(last_reset_op + 1, m):
            b, c = ops[i]
            final_array[b] += c
            
        results.append(" ".join(map(str, final_array)))
    
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()