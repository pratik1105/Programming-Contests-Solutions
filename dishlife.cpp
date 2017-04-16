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
const int N = 1e5+10; 

vi islands[N];
vi ingred[N];

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,k;
  	cin>>n>>k;

  	FOR(i,1,n)
  	islands[i].clear();
  	FOR(i,1,k)
  	ingred[i].clear();

  	FOR(i,1,n)
  	{
  		int p;
  		cin>>p;
  		FOR(j,1,p)
  		{
  			int ing;
  			cin>>ing;
  			islands[i].pb(ing);
  			ingred[ing].pb(i);
  		}
  	}

  	bool flag=true;
  	FOR(i,1,k)
  	{
  		if(!sz(ingred[i]))
  		{
  			flag=false;
  			break;
  		}
  	}
  	if(!flag)
  	{
  		cout<<"sad"<<endl;
  		continue;
  	}

  	FOR(i,1,n)
  	{
  		flag=true;
  		FOR(j,0,sz(islands[i])-1)
  		{
  			if(sz(ingred[islands[i][j]])==1)
  				{
  					flag=false;
  					break;
  				}
  		}
  		if(flag)
  		{
  			cout<<"some"<<endl;
  			break;
  		}
  	}

  	if(!flag)
  		cout<<"all"<<endl;
  }
  return 0;
}