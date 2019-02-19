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
  int t;
  cin>>t;

  while(t--)
  {
  	int n,m;
  	cin>>n>>m;

  	int cnt=1;
  	int val;
  	for(int i=0;i<n;i++)
  	{
  		cin>>val;
  		if(val%m==0)
  			cnt*=2;
  	}
  	cnt--;
  	cout<<cnt<<endl;
  }
  return 0;
}