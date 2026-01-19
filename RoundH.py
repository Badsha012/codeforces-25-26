import sys

def solve():

    gdCode = sys.stdin.read().split()
    if not gdCode:
        return
    
    ptr = 0
    t = int(gdCode[ptr])
    ptr += 1
    
    results = []
    
    for _ in range(t):
        n = int(gdCode[ptr])
        k = int(gdCode[ptr+1])
        ptr += 2
        
        a = [int(x) for x in gdCode[ptr : ptr + n]]
        ptr += n
        
        # Total sum of all cows
        total_sum = sum(a)
        
        
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i+1] = prefix_sum[i] + a[i]
            
        ans = []
        for i in range(n):
            # Target cow skill
            my_skill = a[i]
            # Sum of all OTHER cows
            others_sum = total_sum - my_skill
            
           
            
            count_good_positions = 0
       
          
          
            if k >= n - 1:
                ans.append(n)
                continue
          
            ans.append(min(n, k + 1 + (1 if a[i] == max(a) else 0))) # Placeholder logic
            
        results.append(" ".join(map(str, ans)))

  
    sys.stdout.write("\n".join(results) + "\n")
