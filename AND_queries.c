#include<stdio.h>
typedef unsigned long long int ll;
const ll mod=1000000007;
int arr[100003];
int ss[257];
ll cc[257];
int aa[257];
ll count[257];
int check[100002][257];
int main()
{
    int n,q,l,r,x,i,j,k,id;
    ll ans,temp,c,temp1,temp2,temp3;
    //input N
    scanf("%d",&n);
    //input array
    for(i=1;i<=n;i++) 
        scanf("%d",&arr[i]);
    //init set 'ss' and count 'cc' with 0
    for(i=0;i<=256;i++)
    {
        ss[i]=0;
        cc[i]=0;
    }
    //fill 'check' array
    for(i=n;i>=1;i--)
    {
        if(ss[arr[i]]==0)
        {
            ss[arr[i]]=1;
            cc[arr[i]]=1;
        }
        else
        {
            cc[arr[i]]++;
        }
        for(j=0;j<=255;j++)
        {
            check[i][j]=cc[j];
        }
    }
    //last insert 0
    for(i=0;i<=255;i++)
    {
        check[n + 1][i]=0;
    }
    //input Q
    scanf("%d",&q);
    while(q--)
    {
        //input L,R,X
        scanf("%d %d %d",&l,&r,&x);
        //solve start
        if(l==r)
        {
            if(arr[l]==x)
            {
                ans= 1;
            }
            else
            {
                ans = 0;
            }
        }
        else if((r-l+1)==2)
        {
            ans=0;
            if((arr[r] & arr[l])==x)
                ans=ans+6;
            if(arr[r]==x)
                ans++;
            if(arr[l]==x)
                ans++;
        }
        else if((r-l+1)==3)
        {
            ans=0;
            if((arr[l] & arr[l+1] & arr[l+2])==x)
                ans=ans+6;
            if((arr[l] & arr[l+1])==x)
                ans=ans+6;
            if((arr[l] & arr[l+2])==x)
                ans=ans+6;
            if((arr[l+1] & arr[l+2])==x)
                ans=ans+6;
            if(arr[l]==x)
                ans++;
            if(arr[l+1]==x)
                ans++;
            if(arr[l+2]==x)
                ans++;
        }
        else 
        {
            ans=0; 
            id=0;
            for(i=0;i<=255;i++)
            {
                cc[i]=0;
                ss[i]=0;
            }
            for(i=x;i<=255;i++)
            {
                if((i&x)==x)
                { 
                    temp=check[l][i]-check[r+1][i];
                    if(temp>0)
                    {
                        aa[id]=i;
                        cc[i]=temp;
                        id++; 
                    }
                }
            }  
            c=0;
            for(i=0;i<id;i++)
            {
                c=c+cc[aa[i]];
                ss[i]=c;
            }
            for(i=0;i<id-2;i++)
            {
                for(j=i+1;j<id-1;j++)
                {
                    if((aa[i]&aa[j])>x)
                    {
                        temp=0;
                        for(k=j+1;k<id;k++)
                        {
                            if((aa[i]&aa[j]&aa[k])==x)
                            {
                                temp=temp+cc[aa[k]];
                            }
                        }
                        temp1=6*cc[aa[i]]*cc[aa[j]]*temp;
                        ans=ans+temp1;
                    }
                    else
                    {
                        temp=ss[id-1]-ss[j];
                        temp1=6*cc[aa[i]]*cc[aa[j]]*temp;
                        ans=ans+temp1;
                    }
                }
            }
            ans=ans-mod*(ans/mod);
            for(i=0;i<id-1;i++) 
            {
                for(j=i+1;j<id;j++)
                {
                    if((aa[i]&aa[j])==x)
                    {
                        temp1=6*cc[aa[i]]*cc[aa[j]];
                        //for iij
                        temp=cc[aa[i]];
                        temp=(temp*(temp-1))/2;
                        temp2=6*temp*cc[aa[j]];
                        //for ijj
                        temp=cc[aa[j]];
                        temp=(temp*(temp-1))/2;
                        temp3=6*temp*cc[aa[i]];
                        ans = ans + temp1 + temp2 + temp3;
                   }
                }
            }
            temp=cc[x];
            temp1=(temp*(temp-1)*(temp-2))/6;
            temp1=6*temp1;
            temp2=(temp*(temp-1))/2;
            temp2=6*temp2;
            ans=ans+temp1+temp+temp2;
            ans=ans-mod*(ans/mod);
        }
        //print the ans
        printf("%lld\n",ans);
    }
}
