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

int a[110];

int main(){
  fast;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  	cin>>a[i];

  long long ans = mod;
  for(int x=1;x<=100;x++)
  {
  	long long tempans=0;
  	for(int i=1;i<=100;i++)
  	{
  		ll temp=abs(x-i)+abs(i-1)+abs(x-1);
  		temp+= abs(x-1)+abs(i-1)+abs(x-i);
  		tempans+=a[i]*temp;
  	}
  	ans=min(ans,tempans);
  }

  cout<<ans<<endl;
  return 0;
}