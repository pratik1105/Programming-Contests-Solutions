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

int main(){
  fast;
  string s1,s2;

  cin>>s1>>s2;

  string ans="";
  ans=s1[0];

  if(sz(s1)==1)
  {
  	ans=ans+s2[0];
  }
  else
  {
  	for(int i=1;i<sz(s1);i++)
  	{
  		if(s1[i]<s2[0])
  		{
  			ans+=s1[i];
  			if(i==sz(s1)-1)
  			{
  				ans+=s2[0];
  			}
  		}
  		else
  		{
  			ans+=s2[0];
  			break;
  		}
  	}
  }

  cout<<ans<<endl;

  return 0;
}