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

vector <ii> arr(2010);
bool done[2010];
int hero[2010];

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(done,false);
  fill(hero,0);

  for(int i=1;i<=2*n;i++)
  {
  	cin>>arr[i].F;
  	arr[i].S=i;
  }

  sort(arr.begin()+1,arr.end());
  reverse(arr.begin()+1,arr.end());

  for(int i=1;i<=m;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	hero[a]=b;
  	hero[b]=a;
  }

  int t;
  cin>>t;

  int noChoice=0;
  
  for(int k=1;k<=2*n;k++)
  {
  	if(t==1)
  	{
  		bool turnOver=false;
  		if(noChoice)
  		{
  			cout<<noChoice<<endl;
  			done[noChoice]=true;
  			turnOver=true;
  		}

  		if(turnOver==false)
  		{
  			for(int i=1;i<=2*n;i++)
  			{
  				if(!done[arr[i].S] and hero[arr[i].S])
  				{
  					cout<<arr[i].S<<endl;
  					done[arr[i].S]=true;
  					turnOver=true;
  					break;
  				}
  			}
  		}

  		if(turnOver==false)
  		{
  			for(int i=1;i<=2*n;i++)
  			{
  				if(!done[arr[i].S])
  				{
  					cout<<arr[i].S<<endl;
  					done[arr[i].S]=true;
  					break;
  				}	
  			}
  		}

  	}
  	else
  	{
  		int x;
  		cin>>x;
  		for(int i=1;i<=2*n;i++)
  		if(arr[i].S==x)
  		{
  			done[arr[i].S]=true;
  			break;
  		}

  		if(hero[x] and !done[hero[x]])
  		noChoice=hero[x];
  		else
  		noChoice=0;	
  	}

  	t=3-t;
  }

  return 0;
}