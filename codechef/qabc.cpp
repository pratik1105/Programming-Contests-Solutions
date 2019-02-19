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

ll A[N];
ll B[N];

int main(){
  fast;
  int t;
  cin>>t;

  while(t--)
  {
  	int n;
  	cin>>n;

  	for(int i=1;i<=n;i++)
  		cin>>A[i];
  	for(int i=1;i<=n;i++)
  		cin>>B[i];

  	string ans="TAK";
  	for(int i=1;i<=n-2;i++)
  	{
  		if(A[i]>B[i])
  		{
  			ans="NIE";
  			break;
  		}

  		ll num = B[i]-A[i];
  		A[i]+=num;
  		A[i+1]+=2*num;
  		A[i+2]+=3*num;
  	}

  	if(A[n-1]!=B[n-1] or A[n]!=B[n])
  	ans = "NIE";
  
  	cout<<ans<<endl;
  }
  return 0;
}