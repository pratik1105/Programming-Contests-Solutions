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
  string s;
  string t;
  cin>>s>>t;

  if(s.size()!=t.size())
  {
  	cout<<"No"<<endl;
  	return 0;
  }

  for(int i=0;i<s.size();i++)
  {
  	if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
  	{
  		if(t[i]!='a' and t[i]!='e' and t[i]!='i' and t[i]!='o' and t[i]!='u')
  		{
  			cout<<"No"<<endl;
  			return 0;
  		}
  	}

  	if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u')
  	{
  		if(t[i]=='a' or t[i]=='e' or t[i]=='i' or t[i]=='o' or t[i]=='u')
  		{
  			cout<<"No"<<endl;
  			return 0;
  		}
  	}
  }

  cout<<"Yes"<<endl;
  return 0;
}