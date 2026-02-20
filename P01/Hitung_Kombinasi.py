kata = input().strip()
N = len(kata)

frekuensi = {}
for huruf in kata:
    if huruf in frekuensi:
        frekuensi[huruf] += 1
    else:
        frekuensi[huruf] = 1
        
def faktorial(angka):
    hasil = 1
    for i in range(2, angka + 1):
        hasil *= i
    return hasil

pembilang = faktorial(N)

penyebut = 1

for jumlah in frekuensi.values():
    penyebut *= faktorial(jumlah)
    
hasil_akhir = pembilang // penyebut

print(hasil_akhir)