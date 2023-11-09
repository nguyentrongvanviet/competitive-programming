#include<bits/stdc++.h>
#define TASK "shopping"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

using namespace std;
vector<int> G[5005];
int n,b,c[5005],d[5005],got[5005],sizen[5005],dp[5005][5005][2];
void dfs(int now)
{
	sizen[now]=1;
	dp[now][0][0]=0;
	dp[now][1][0]=c[now];
	dp[now][1][1]=c[now]-d[now];
	for(unsigned int i=0;i<G[now].size();++i)
	{
		int to=G[now][i];
		dfs(G[now][i]);
		for(int j=sizen[now];~j;--j)	for(int k=0;k<=sizen[to];++k)	dp[now][j+k][0]=min(dp[now][j+k][0],dp[now][j][0]+dp[to][k][0]),dp[now][j+k][1]=min(dp[now][j+k][1],dp[now][j][1]+min(dp[to][k][0],dp[to][k][1]));
		sizen[now]+=sizen[to];
	}
}
int main(){
	  if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    
	scanf("%d %d %d %d",&n,&b,&c[1],&d[1]);
	for(int i=2;i<=n;++i)
	{
		scanf("%d %d %d",&c[i],&d[i],&got[i]);
		G[got[i]].push_back(i);
	}
	memset(dp,127/2,sizeof dp);
	dfs(1);
	for(int i=n;i;--i)	if(dp[1][i][0]<=b || dp[1][i][1]<=b)	return printf("%d",i)&0;
	return puts("0")&0;
}