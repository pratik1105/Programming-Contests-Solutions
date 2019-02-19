#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 2e5+10; 

vector< pair<int,int> > ans[N];
vector<pair<int,int> > single[N];
vector<int> primes;
vector<int> temp;
vector<int> edges[N];
int a[N];

void dfs(int s,int p)
{
	for(int i=0;i<edges[s].size();i++)
	{
		if(edges[s][i]==p)
		continue;

		dfs(edges[s][i],s);
	}
	primes.clear();

	if(a[s]%2==0)
	primes.pb(2);
	while(a[s]%2==0)
	a[s]/=2;
	
	int root =sqrt(a[s]);	
	for(int i=3;i<=root+2;i+=2)
	{
		if(a[s]%i==0)
		{
			primes.pb(i);
			while(a[s]%i==0)
			a[s]/=i;
		}
	}

	if(a[s]>1)
	primes.push_back(a[s]);
	
	for(int i=0;i<primes.size();i++)
	{
		temp.clear();
		for(int j=0;j<edges[s].size();j++)
		{
			if(edges[s][j]==p)continue;

			for(int k=0;k<single[edges[s][j]].size();k++)
			{
				if(single[edges[s][j]][k].F==primes[i])
				temp.push_back(single[edges[s][j]][k].S);
			}
		}

		if(temp.size()==0)
		{
			single[s].push_back(mp(primes[i],1));
			ans[s].push_back(mp(primes[i],1));
			continue;
		}
		

		sort(temp.begin(),temp.end());
		reverse(temp.begin(),temp.end());

		if(temp.size()==1)
		{
			single[s].push_back(mp(primes[i],1+temp[0]));
			ans[s].push_back(mp(primes[i],1+temp[0]));
		}
		else
		{
			single[s].push_back(mp(primes[i],1+temp[0]));
			ans[s].push_back(mp(primes[i],1+temp[0]+temp[1]));
		}

	}
}

int main(){
  fast;
  
  int n;
  cin>>n; 

  for(int i=1;i<=n;i++)
  {
  	ans[i].clear();
  	single[i].clear();
  }

  for(int i=1;i<=n;i++)
  cin>>a[i];
  
  for(int i=1;i<=n-1;i++)
  {
  	int x,y;
  	cin>>x>>y;
  	edges[x].pb(y);
  	edges[y].pb(x);
  }	
  
  dfs(1,0);

  int final=0;
  for(int i=1;i<=n;i++)
  {
  	for(int j=0;j<ans[i].size();j++)
  	{
  		if(ans[i][j].F==1)continue;

  		final=max(final,ans[i][j].S);
  	}
  }

  cout<<final<<endl;
  return 0;

}