/*
桥距离很长，但石子很少
考虑在不影响答案的情况下缩减石头间的距离
就是不改变相对位置
可以对(1~10)的最小公倍数取模,因为青蛙跳的长度在1~10间。 
试了几次下界就出来了，跑得飞快。 
*/
#include <bits/stdc++.h>
using namespace std;
#define N 110

using namespace std;
int L,S,T,M;
int a[N],b[N*N*10],f[N*N*10];

int main()
{
    scanf("%d%d%d%d",&L,&S,&T,&M);
    for (int i=1; i<=M; i++) scanf("%d",&a[i]);
    sort(a+1,a+M+1);
    if (S==T)
    {
        int ans=0;
        for (int i=1; i<=M; i++)
            if (a[i]%S==0)ans++;
        printf("%d",ans);
        return 0;
    }
    int last=0;
    for (int i=1; i<=M; i++)
    {
        int tmp=a[i];
        if (a[i]-last>=90)a[i]=a[i-1]+90;
        else a[i]=a[i-1]+a[i]-last;
        last=tmp;
        b[a[i]]=1;
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for (int i=S;i<=a[M]+T;i++)
        for (int j=i-T;j<=i-S;j++)
            if (j>=0)f[i]=min(f[i],f[j]+b[i]);
    int ans=0x3f3f3f3f;
    for (int i=a[M];i<=a[M]+T; i++)
        ans=min(ans,f[i]);
    printf("%d",ans);
}

/*
10
2 3 5
2 3 5 6 7
*/