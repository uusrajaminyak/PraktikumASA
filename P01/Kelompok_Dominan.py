N,Q = map(int, input().split())
L1 = list(map(int, input().split()))

for i in range(Q):
    A1, A2 = map(int, input().split())
    i = 0
    found = False
    L2 = sorted(L1[A1-1:A2])
    count = 0
    value = L2[i]
    
    while i < len(L2) and not found:
        if L2[i] == value:
            count += 1
        else:
            count = 1
            value = L2[i]
        if count > len(L2 // 2):
            print(value)
            found = True
        i += 1
        
    if not found:
        print(-1)