N = int(input())
W = list(map(int, input().split()))
X1, X2, X3 = 0, 0, 0

for i in range(N):
    if W[i] % 2 == 1:
        if W[i] > X1:
            if X1 > X3:
                if X3 > X2:
                    X2 = X3
                X3 = X1
            X1 = W[i]
        elif W[i] > X3:
            if X3 > X2:
                X2 = X3
            X3 = W[i]
        elif W[i] > X2:
            X2 = W[i]
    elif W[i] > X2:
        X2 = W[i]
        
if X1 == 0 or X2 == 0 or X3 == 0:
    print(-1)
else:
    print(X1 + X2 + X3)