def isHard(a):
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            return True
    return False


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if isHard(sum(a)):
        print(n)
        print(" ".join([str(i + 1) for i in range(n)]))
    else:
        for i in range(n):
            if isHard(sum(a) - a[i]):
                print(n - 1)
                print(" ".join([str(j + 1) for j in range(n) if j != i]))
                break
            
