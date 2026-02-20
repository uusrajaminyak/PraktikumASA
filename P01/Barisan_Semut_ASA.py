x, y, n = map(int, input().split())

count = 0
output = 0

while output < n:
    if count % y != 0:
        print(count, end=' ')
        output += 1
    count += 1

print(count)