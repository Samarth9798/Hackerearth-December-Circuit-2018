t=int(input())
while t:
    n,k=map(int,input().split())
    if k==n:
        print("Alice")
    elif k>n:
        print("Bob")
    else:
        i=1
        ans=0
        if k==1:
            if n%2==0:
                ans=1
            else:
                ans=0
        else:
            while 1:
                temp=k**i
                if n>=temp:
                    n-=temp
                    ans=0
                if n>=temp:
                    n-=temp
                    ans=1
                if n<temp:
                    break
                i+=1
        if ans==1:
            print("Bob")
        else:
            print("Alice")
    t-=1
