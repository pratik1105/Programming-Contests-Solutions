#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
 
#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e3+10; 
 
int n;
vi edges[N];
int ansfor[N][N];
int fans[N];
int flen[N];
int temp[N];
 
void dfs(int source,int par)
{
	if(sz(edges[source])==1 and edges[source][0]==par)
	{
		ansfor[source][0]=0;
		fans[source]=0;
		flen[source]=0;
		return;
	}
	
 
	cout<<"called for "<<source<<" from "<<par<<endl;
	
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
 
		dfs(edges[source][i],source);
	}
 
	
	fans[source]=mod;
	flen[source]=0;
 
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
 
		FOR(j,0,n)
		temp[j]=-1;
 
		if(ansfor[edges[source][i]][0]!=-1)
		temp[1]=ansfor[edges[source][i]][0]+1;
		
		FOR(j,2,n)
		if(ansfor[edges[source][i]][j-1]!=-1)
		temp[j]=ansfor[edges[source][i]][j-1]-ceil(log2(j-1))+ceil(log2(j));
		
		FOR(j,0,sz(edges[source])-1)
		{
			if(edges[source][j]==par or edges[source][j]==edges[source][i])
				continue;
 
			temp[0]=max(temp[0],fans[edges[source][j]]+1);
 
		}
 
		int maxi=0;
		int len=0;
		FOR(j,0,n)
		{
			if(temp[j]>=maxi)
			{
				maxi=temp[j];
				len=j;
			}
		}
		
		if(fans[source]>maxi or (fans[source]==maxi and flen[source]<len)) 
		{
			FOR(j,0,n)
			ansfor[source][j]=temp[j];
 
			flen[source]=len;
			fans[source]=maxi;
 
			FOR(j,0,n)
			if(ansfor[source][j]!=-1)
			cout<<source<<" "<<j<<" "<<ansfor[source][j]<<endl;
			
			cout<<source<<" maxval is obtained at prefix "<<len<<endl;		
		}
		
	}
 
	cout<<source<<" "<<fans[source]<<endl;
	//cout<<"max black val for "<<source<<" is "<<dp[0][source]<<endl;
	//cout<<"max red val for "<<source<<" is "<<dp[1][source]<<endl;
	return ;
}
 
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
	
  	cin>>n;
 
  	fill(ansfor,-1);
 
 
	FOR(i,1,n)
	edges[i].clear();
 
 
  	FOR(i,1,n-1)
  	{
  		int a,b;
  		cin>>a>>b;
  		edges[a].pb(b);
  		edges[b].pb(a);
  	}
 
  	dfs(1,0);
  	cout<<fans[1]<<endl;
  }
 
  return 0;
} 