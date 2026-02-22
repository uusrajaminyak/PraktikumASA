SA, X, Y, N = map(int, input().split())
HP = list(map(int, input().split()))
t = int(input().strip())

max_HP_awal = max(HP)

SA_akhir = SA + (X * t)

max_HP_akhir = max_HP_awal - (Y * t)

if max_HP_akhir < 0:
    max_HP_akhir = 0
    
if SA_akhir >= max_HP_akhir:
    print("WIN")
else:
    print("LOSE")