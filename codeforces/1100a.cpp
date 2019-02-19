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

int val[110];
int e,s;
int main(){
  fast;
  
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
  	cin>>val[i];
  	if(val[i]==1)e++;
  	if(val[i]==-1)s++;
  }
  
  int ans=0; 					
  for(int b=1;b<=n;b++)
  {
  	int ne=e;
  	int ns=s;
  	int cur=b;
  	if(val[b]==1)ne--;
  	else
  	ns--;

  	cur=b-k;
  	while(cur>=1)
  	{
  		if(val[cur]==1)ne--;
  		else ns--;

  		cur=cur-k;
  	}

  	cur=b+k;
  	while(cur<=n)
  	{
  		if(val[cur]==1)ne--;
  		else ns--;

  		cur=cur+k;
  	}

  	ans=max(ans,abs(ne-ns));
  }

  cout<<ans<<endl;
  return 0;
}