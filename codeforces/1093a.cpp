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

int ways[110];
int main(){
  fast;
  int t;
  cin>>t;
  fill(ways,0);
  for(int i=2;i<=7;i++)
  ways[i]=1;
  for(int i=8;i<=100;i++)
  {
  	for(int j=2;j<=7;j++)
  	if(ways[i-j])
  	{
  		ways[i]=ways[i-j]+1;
  		break;
  	}	
  }

  while(t--)
  {
  	int n;
  	cin>>n;
  	cout<<ways[n]<<endl;
  }	 
  
  return 0;
}