n,m=map(int,input().split())
result=0
for i in range(n):
    A=list(map(int,input().split()))
    B=min(A)
    result=max(result,B)
print(result)

