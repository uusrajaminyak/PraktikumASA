def elemen_terbesar_ke_x(arr, x):
    if x > len(arr) or x <= 0:
        return None

    length = len(arr)
    dum = 0
    arr1 = arr.copy()
    for i in range(x):
        for j in range(length):
            if arr1[j] > arr1[dum]:
                dum = j
        arr1[dum] = 0
    return arr[dum]

arr = [1,2,3,4]
x = 4
ans = elemen_terbesar_ke_x(arr, x)
print(ans)