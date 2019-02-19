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

int main(){
  fast;
  cin>>s;
  int ob,cb,oc,cc;
  ob=cb=oc=cc=-1;
  
  for(int i=0;i<s.size();i++)
  if(s[i]=='[')
  {
  	ob=i;
  	break;
  }

  if(ob==-1)
  {
  	cout<<-1<<endl;
  	return 0;
  }

  for(int i=ob+1;i<s.size();i++)
  if(s[i]==':')
  {
  	oc=i;
  	break;
  }

  if(oc==-1)
  {
  	cout<<-1<<endl;
  	return 0;
  }

  for(int i=s.size()-1;i>oc;i--)
  if(s[i]==']')
  {
  	cb=i;
  	break;
  }

  if(cb==-1)
  {
  	cout<<-1<<endl;
  	return 0;
  }
  
  for(int i=cb-1;i>oc;i--)
  if(s[i]==':')
  {
  	cc=i;
  	break;
  }

  if(cc==-1)
  {
  	cout<<-1<<endl;
  	return 0;
  }

  if(!(ob<oc and oc<cc and cc<cb))
  {
  	cout<<-1<<endl;
  	return 0;
  }

  int ans=4;

  for(int i=oc+1;i<cc;i++)
  if(s[i]=='|')
  ans++;

  cout<<ans<<endl;
  return 0;
}