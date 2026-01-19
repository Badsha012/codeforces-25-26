import sys

# gdCode: Instructions/Variables as requested
def solve():
    gdCode_input = sys.stdin.read().split()
    if not gdCode_input:
        return
    
    ptr = 0
    t = int(gdCode_input[ptr])
    ptr += 1
    
    output = []
    
    for _ in range(t):
        n = int(gdCode_input[ptr])
        ptr += 1
        
        arrays = []
        for i in range(n):
            length = int(gdCode_input[ptr])
            ptr += 1
            arrays.append([int(x) for x in gdCode_input[ptr : ptr + length]])
            ptr += length
            
        mex_list = []
        next_mex_list = []
        source_change_total = 0
        
        # Precompute MEX and the 'Next MEX' (MEX if the current MEX is filled)
        for i in range(n):
            s = set(arrays[i])
            m = 0
            while m in s:
                m += 1
            mex_list.append(m)
            
            nm = m + 1
            while nm in s:
                nm += 1
            next_mex_list.append(nm)
            
            # Source change logic:
            # If removing arrays[i][j] where it's the ONLY instance of val < mex
            counts = {}
            for x in arrays[i]:
                if x < m:
                    counts[x] = counts.get(x, 0) + 1
            
            for x in arrays[i]:
                change = 0
                if x < m and counts[x] == 1:
                    change = x - m
                source_change_total += change * (n - 1)
        
        total_initial_mex = sum(mex_list)
        total_elements = sum(len(a) for a in arrays)
        
        # Base sum: (Initial sum of MEXes) * (Total possible operations)
        ans = total_initial_mex * total_elements * (n - 1)
        ans += source_change_total
        
        # Destination change logic:
        # Array k's MEX increases if we add x where x == mex_list[k]
        # Calculate how many times each value appears as an element in any array i
        val_freq = {}
        for arr in arrays:
            for x in arr:
                val_freq[x] = val_freq.get(x, 0) + 1
        
        # We need sum_{i} sum_{j} sum_{k != i, mex[k] == a[i,j]} (next_mex[k] - mex[k])
        # This is equivalent to sum_{k} (next_mex[k] - mex[k]) * (Total_freq[mex[k]] - freq_in_array_k[mex[k]])
        dest_change_total = 0
        for k in range(n):
            m_k = mex_list[k]
            nm_k = next_mex_list[k]
            
            # How many times does m_k appear in arrays OTHER than k?
            total_m_k = val_freq.get(m_k, 0)
            in_k = 0
            for x in arrays[k]:
                if x == m_k: in_k += 1
            
            count_others = total_m_k - in_k
            dest_change_total += count_others * (nm_k - m_k)
            
        ans += dest_change_total
        output.append(str(ans))
        
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    solve()