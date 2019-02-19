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

int a[N];
int pos[N];
bool state[N];
int main(){
  fast;
  int n;
  cin>>n;
  fill(state,0);

  for(int i=1;i<=n;i++)
  {
  	
  	cin>>a[i];
  	pos[a[i]]=i;
  }

  state[n]=false;
  for(int i=n-1;i>=1;i--)
  {
	ll dist=i;
	bool val=false;
	while(dist<=n)
	{
		if(pos[i]-dist>=1 and a[pos[i]-dist] > i)
		val = val or !(state[a[pos[i]-dist]]);

		if(pos[i]+dist <=n  and a[pos[i]+dist] >i)
		val = val or !(state[a[pos[i]+dist]]);

		dist+=i;
	}

	state[i]=val;  	
  }

  string s="";

  for(int i=1;i<=n;i++)
  {
  	if(state[a[i]])
  		s+="A";
  	else
  		s+="B";
  }

  cout<<s<<endl;
  return 0;
}