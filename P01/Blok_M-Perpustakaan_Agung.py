n = int(input())
T = int(input())
N = list(map(int, input().split()))

N = sorted(N)

found = True
for i in range(n - 1):
    if N[i] == N[i + 1] and N[i] + N[i + 1] == T:
        print(N[i] * N[i])
        found = False
        
if found:
    print(-1)