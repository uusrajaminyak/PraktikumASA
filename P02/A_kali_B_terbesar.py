# Brute force solution
# def AB(c):
#     max = 0
#     for i in range(c//2 + 1):
#         if (max < (i * (c - i))):
#             max = i * (c - i)
#     return max

# Optimal solution
def AB(c):
    return (c//2) * (c - (c//2))

c = 10
print(AB(c))