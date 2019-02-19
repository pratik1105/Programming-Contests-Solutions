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
const ll mod = 998244353;
const int N = 1e6+10; 

ll B[N];
ll A[N];
int main(){
  fast;
  
  int n;
  cin>>n;

  B[0]=B[1]=0;
  for(int i=2;i<=n+1;i++)
  {
  	B[i]=((B[i-1]+1)*(i))%mod;
  	if(B[i]<0)
  	B[i]+=mod;
  }

  if(n==1)
  {
  	cout<<1<<endl;
  	return 0;
  }
  if(n==2)
  {
  	cout<<2<<endl;
  	return 0;
  }

  A[2]=1;
  for(int i=3;i<=n;i++)
  {
  	A[i]=(A[i-1]*i)%mod;
  	if(A[i]<0)
  	A[i]+=mod;

  	A[i]=(A[i]+B[i-2])%mod;
  	if(A[i]<0)
  	A[i]+=mod;
  }

  A[n]=(n*A[n])%mod;
  if(A[n]<0)
  A[n]+=mod;


  cout<<A[n]<<endl;
  return 0;
}