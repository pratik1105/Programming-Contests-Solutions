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

string s;
int group[N];
int ones[N];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	cin>>s;
  	s='a'+s;
  	group[0]=0;
  	FOR(i,1,sz(s)-1)
  	{
  		if(s[i]=='0')
  		{
  			group[i]=group[i-1];
  			continue;
  		}

  		if(s[i]==s[i-1])
  			group[i]=group[i-1];
  		else
  			group[i]=group[i-1]+1;
  	}

  	ones[sz(s)-1]=0;
  	NFOR(i,sz(s)-2,1)
  	{
  		if(s[i+1]=='1')
  			ones[i]=ones[i+1]+1;
  		else
  			ones[i]=ones[i+1];
  	}

  	ll ans=0;
  	FOR(i,1,sz(s)-1)
  	{
  		if(s[i]=='1')
  		{
  			ans+=group[sz(s)-1]-group[i];
  			if(s[sz(s)-1]=='0')
  				ans++;
  			ans+=sz(s)-ones[i]-1-i;
  		}
  	}
  	cout<<ans<<endl;
  }	
  return 0;
}