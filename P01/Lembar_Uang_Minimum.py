x = int(input().strip())

pecahan = [50, 25, 10, 5, 1]

total_lembar = 0

for uang in pecahan:
    lembar = x // uang
    total_lembar += lembar
    x = x % uang
    
print(total_lembar)