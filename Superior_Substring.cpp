#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t,n,ans,k,temp,max,c,x,i,j,b[100001],arr[27],set[27],prev[27],next[100001];
    string s;
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        cin>>n;
        cin>>s;
        for(i=0;i<=27;i++)
        {
            arr[i]=0;
            set[i]=0;
            prev[i]=-1;
        }
        for(i=n-1;i>=0;i--)
        {
            temp=s[i];
            if(set[temp-97]==0)
            {
                set[temp-97]=1;
                arr[temp-97]=1;
            }
            else
            {
                arr[temp-97]++;
            }
            b[i]=arr[temp-97];
            next[i]=prev[temp-97];
            prev[temp-97]=i;
        }
        if(n<=3)
            ans=n;
        else
        {
            max=0;temp=0;c=0;k=0;
            for(i=0;i<n;i++)
            {
                temp=(b[i]*2)+1;
                c=1;
                k=i;
                if(temp>max)
                {
                    while(1)
                    {
                        x=(c*2)+1;
                        if(x>=((k-i)+1) and x>max and x<=n)
                            max=x;
                        else if(x>n)
                        {
                            max=n;
                            break;
                        }
                        j=next[k];
                        if(c>=b[i])
                           break;
                        k=j;
                        c++;
                        if(k-i+1>temp)
                            break;
                    }
                }
                if(c==1 and max==0)
                    max=3;
                if(max==n)
                    break;
            }
            ans=max;
        }
        cout<<ans<<endl;
    }
}
