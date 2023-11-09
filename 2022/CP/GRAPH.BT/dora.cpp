#include <cstdio>
#include <iostream>
#include <cstring>
#define ya(k)   (sb[k]*sb[k]-f[i-1][k])
#define xa(k)   (sb[k])
#define yb(k)   (sa[k]*sa[k]-f[k][j-1])
#define xb(k)   (sa[k])
using namespace std;
typedef long long ll;
int n;
ll a[1010],b[1010],qa[1010][1010],qb[1010][1010],sa[1010],sb[1010],ha[1010],hb[1010],ta[1010],tb[1010];
ll f[1010][1010],ans;
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)    scanf("%lld",&a[i]),sa[i]=sa[i-1]+a[i];
    for(i=1;i<=n;i++)    scanf("%lld",&b[i]),sb[i]=sb[i-1]+b[i];
    for(i=1;i<=n;i++)    ha[i]=hb[i]=1,f[0][i]=-sb[i]*sb[i],f[i][0]=-sa[i]*sa[i];
    ans=-1,ans<<=60;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            f[i][j]=-sa[i-1]*sa[i-1]-sb[j-1]*sb[j-1]+a[i]*b[j];
            while(ha[i]<ta[i]&&(ya(qa[ha[i]+1][i])-ya(qa[ha[i]][i]))<=(xa(qa[ha[i]+1][i])-xa(qa[ha[i]][i]))*2*sb[j-1])    ha[i]++;
            if(i>1)  f[i][j]=max(f[i][j],f[i-1][qa[ha[i]][i]]+a[i]*b[j]-(sb[j-1]-sb[qa[ha[i]][i]])*(sb[j-1]-sb[qa[ha[i]][i]]));
            while(ha[i]<ta[i]&&(ya(qa[ta[i]][i])-ya(qa[ta[i]-1][i]))*(xa(j)-xa(qa[ta[i]][i]))>=(ya(j)-ya(qa[ta[i]][i]))*(xa(qa[ta[i]][i])-xa(qa[ta[i]-1][i])))    ta[i]--;
            qa[++ta[i]][i]=j;
            while(hb[j]<tb[j]&&(yb(qb[hb[j]+1][j])-yb(qb[hb[j]][j]))<=(xb(qb[hb[j]+1][j])-xb(qb[hb[j]][j]))*2*sa[i-1])    hb[j]++;
            if(j>1)  f[i][j]=max(f[i][j],f[qb[hb[j]][j]][j-1]+a[i]*b[j]-(sa[i-1]-sa[qb[hb[j]][j]])*(sa[i-1]-sa[qb[hb[j]][j]]));
            while(hb[j]<tb[j]&&(yb(qb[tb[j]][j])-yb(qb[tb[j]-1][j]))*(xb(i)-xb(qb[tb[j]][j]))>=(yb(i)-yb(qb[tb[j]][j]))*(xb(qb[tb[j]][j])-xb(qb[tb[j]-1][j])))    tb[j]--;
            qb[++tb[j]][j]=i;
            ans=max(ans,f[i][j]-(sa[n]-sa[i])*(sa[n]-sa[i])-(sb[n]-sb[j])*(sb[n]-sb[j]));
        }
    }
    printf("%lld",ans);
    return 0;
}
