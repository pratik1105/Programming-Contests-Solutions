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
string res;
int main(){
  fast;
  cin>>s;

  int len =s.size();
  res=s;
  if(len<=2)
  {
  	cout<<s<<endl;
  	return 0;
  }

  int st1=(len+1)/2 -1;
  int st2 = st1+1;

  int i=0;
  while(st1>=0)
  {
  	res[i]=s[st1];
  	i+=2;
  	st1--;
  }

  i=1;
  while(st2<len)
  {
  	res[i]=s[st2];
  	i+=2;
  	st2++;
  }

  cout<<res<<endl;
  return 0;
}