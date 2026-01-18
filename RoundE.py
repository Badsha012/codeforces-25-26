import sys
import bisect

def solve():
    gdCode = sys.stdin.read().split()
    if not gdCode:
        return
    
    ptr = 0
    t = int(gdCode[ptr])
    ptr += 1
    
    output = []
    
    for _ in range(t):
        n = int(gdCode[ptr])
        m = int(gdCode[ptr+1])
        k = int(gdCode[ptr+2])
        ptr += 3
        
        a = sorted([int(x) for x in gdCode[ptr:ptr+n]])
        ptr += n
        
        b = sorted([int(x) for x in gdCode[ptr:ptr+m]])
        ptr += m
        
        s = gdCode[ptr]
        ptr += 1
        
        min_reach = [0] * (k + 1)
        max_reach = [0] * (k + 1)
        curr = 0
        mn = 0
        mx = 0
        
        for i in range(k):
            if s[i] == 'L':
                curr -= 1
            else:
                curr += 1
            mn = min(mn, curr)
            mx = max(mx, curr)
            min_reach[i+1] = mn
            max_reach[i+1] = mx
            
        death_time = []
        
        for pos in a:
            idx = bisect.bisect_left(b, pos)
            
            time_to_die = k + 1
            
            if idx > 0:
                dist_left = pos - b[idx-1]
                low, high = 1, k
                best = k + 1
                while low <= high:
                    mid = (low + high) // 2
                    if min_reach[mid] <= -dist_left:
                        best = mid
                        high = mid - 1
                    else:
                        low = mid + 1
                time_to_die = min(time_to_die, best)
                
            if idx < m:
                dist_right = b[idx] - pos
                low, high = 1, k
                best = k + 1
                while low <= high:
                    mid = (low + high) // 2
                    if max_reach[mid] >= dist_right:
                        best = mid
                        high = mid - 1
                    else:
                        low = mid + 1
                time_to_die = min(time_to_die, best)
            
            if time_to_die <= k:
                death_time.append(time_to_die)
        
        death_time.sort()
        
        ans = []
        current_dead = 0
        death_ptr = 0
        for i in range(1, k + 1):
            while death_ptr < len(death_time) and death_time[death_ptr] <= i:
                current_dead += 1
                death_ptr += 1
            ans.append(n - current_dead)
        
        output.append(" ".join(map(str, ans)))
        
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == "__main__":
    solve()