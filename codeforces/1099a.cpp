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
  int w,h;
  int u1,d1;
  int u2,d2;

  cin>>w>>h;
  cin>>u1>>d1;
  cin>>u2>>d2;

  for(int i=h;i>=0;i--)
  {
  	w=w+i;
  	if(d1==i)
  	w=w-u1;
  	if(d2==i)
  	w=w-u2;

  	w=max(w,0);
  }
  
  cout<<w<<endl;
  return 0;
}