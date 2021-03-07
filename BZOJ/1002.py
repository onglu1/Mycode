f1 = 1
f2 = 5
f3 = 0
a = int(input())
if a == 1:
    print(1)
elif a == 2:
    print(5)
else :
    for i in range(2, a):
        f3 = 3 * f2 -  f1 + 2
        f1 = f2
        f2 = f3
    print(f3)
