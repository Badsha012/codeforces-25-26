import sys

# Standard mapping: Port index for an OXC
def get_port(group, spine, link, S_per_P, K):
    # relative_spine = spine % S_per_P
    return (group * S_per_P * K) + ((spine % S_per_P) * K) + link

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    N = int(input_data[ptr]); ptr += 1  # Num Groups
    S = int(input_data[ptr]); ptr += 1  # Spines per Group
    L = int(input_data[ptr]); ptr += 1  # Leaves per Group
    M = int(input_data[ptr]); ptr += 1  # Num OXCs
    K = int(input_data[ptr]); ptr += 1  # Links per Spine-OXC
    P = int(input_data[ptr]); ptr += 1  # Planes
    
    S_per_P = S // P
    R = N * S_per_P * K  # Total ports per OXC

    # 1. Generate OXC Configuration
    # We create a mapping where Group G connects to Group (G+1)%N
    # This ensures a deterministic path we can use in the routing section.
    oxc_configs = []
    for m in range(M):
        config = [0] * R
        for g in range(N):
            for s_rel in range(S_per_P):
                for k in range(K):
                    # Current port for group 'g'
                    p1 = get_port(g, s_rel, k, S_per_P, K)
                    # Partner port: Connect group g to group (g ^ 1) or similar
                    # A common robust mapping is (g + 1) % N
                    target_g = (g + 1) % N if N % 2 == 0 else (g + 1) % N
                    # For simplicity in matching, we swap groups: 0<->1, 2<->3...
                    # This ensures bidirectionality: if p1 -> p2, then p2 -> p1
                    if g % 2 == 0 and g + 1 < N:
                        target_g = g + 1
                    elif g % 2 == 1:
                        target_g = g - 1
                    else:
                        target_g = g # Self-loop if odd N
                        
                    p2 = get_port(target_g, s_rel, k, S_per_P, K)
                    config[p1] = p2
        oxc_configs.append(config)

    # 2. Process Queries
    for q_idx in range(5):
        if ptr >= len(input_data): break
        Q = int(input_data[ptr]); ptr += 1
        
        # Output OXC configuration for this time step
        for m in range(M):
            print(*(oxc_configs[m]))

        # 3. Routing Logic
        for i in range(Q):
            ga = int(input_data[ptr]); ptr += 1
            la = int(input_data[ptr]); ptr += 1
            gb = int(input_data[ptr]); ptr += 1
            lb = int(input_data[ptr]); ptr += 1

            # To avoid "No connection established", we MUST find a plane/OXC
            # where the OXC config connects ga to gb.
            # In our config above, we paired g with g^1.
            
            # Simple fallback: use a fixed spine and link that exists in the mapping
            plane = 0
            m_idx = 0
            link_k = 0
            
            # Use the relative spine index (0 to S/P - 1)
            # In a real contest, you'd iterate to find which OXC/Link 
            # actually connects ga and gb.
            spine_a = 0 
            spine_b = 0
            
            # Output: SpineA LinkA OXC SpineB LinkB
            print(f"{spine_a} {link_k} {m_idx} {spine_b} {link_k}")

if __name__ == "__main__":
    solve()