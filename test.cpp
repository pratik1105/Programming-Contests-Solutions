#include <bits/stdc++.h>
#define mod 1000000007LL
#define MAX 1000000000
#define sz 100009
#define ull unsigned long long
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define ios ios::sync_with_stdio(false)

using namespace std;

/*
##########################
## Author: Viral Mehta  ##
## College: BITS Pilani ##
##########################
*/
int n;
int col[sz];
vector<int> adj[sz],dp[sz],vis[sz];
void dfs(int from,int to_idx)
{
	if(vis[from][to_idx]==1) return;
	vis[from][to_idx]=1;
	int to=adj[from][to_idx];
	int i;
	int val=1;
	for(i=0;i<adj[to].size();i++)
	{
		int nxt=adj[to][i];
		if(nxt==from) continue;
		dfs(to,i);
		cout<<"dfs called from "<<to<<" to "<<i<<endl;
		val=(val&dp[to][i]&((int)(col[nxt]==col[to])));
	}
	dp[from][to_idx]=val;
}
int main() 
{
	scanf("%d",&n);
	int i,j,u,v;
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
		dp[u].pb(0);
		dp[v].pb(0);
		vis[u].pb(0);
		vis[v].pb(0);
	}
	for(i=1;i<=n;i++) scanf("%d",&col[i]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<adj[i].size();j++)
		{
			if(vis[i][j]==0)
			{
				dfs(i,j);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		int val=1;
		for(j=0;j<adj[i].size();j++)
		{
			val=(val&dp[i][j]);
		}
		if(val==1)
		{
			printf("YES\n%d\n",i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}