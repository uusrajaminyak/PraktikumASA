n = int(input().strip())
height = list(map(int, input().split()))
path = []

for h in height:
    if len(path) == 0 or h != path[-1]:
        path.append(h)
        
if len(path) < 2:
    print(0)
else:
    extreme = []
    extreme.append(path[0])

    for i in range(1, len(path) - 1):
        before = path[i - 1]
        current = path[i]
        after = path[i + 1]
    
        if(current > before and current > after) or (current < before and current < after):
            extreme.append(current)
    
    extreme.append(path[-1])
    
    max_diff = 0
    
    for i in range(len(extreme) - 1):
        diff = abs(extreme[i] - extreme[i + 1])
        if diff > max_diff:
            max_diff = diff
    
    print(max_diff)