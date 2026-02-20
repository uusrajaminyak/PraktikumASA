panjangD, panjangM = map(int, input().split())
D = list(map(int, input().split()))

if panjangM > 0:
    M = list(map(int, input().split()))
else:
    M = []
    
kill = set(M)
survivor = []

for angka in D:
    if angka not in kill:
        survivor.append(str(angka))
        
if len(survivor) == 0:
    print("KOSONG")
else:
    print(" ".join(survivor))