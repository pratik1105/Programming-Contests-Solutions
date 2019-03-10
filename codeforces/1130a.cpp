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
  int n;
  cin>>n;
  
  int zero=0;
  int pos=0;
  int neg=0;

  for(int i=0;i<n;i++)
  {
  	int x;
  	cin>>x;
  	if(x==0)
  	zero++;
    else if(x>0)
    pos++;
    else if(x<0)
    neg++;
  }
  
  if(pos>=(n+1)/2)
  cout<<1<<endl;
  else if(neg>=(n+1)/2)
  cout<<-1<<endl;
  else
  cout<<0<<endl;


  return 0;
}	