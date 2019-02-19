#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 


ll freq[N];
ll a[N];
vector<ii> temp;

int main(){
  fast;
  int n;
  cin>>n;
  fill(freq,0);
  temp.clear();

  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
  	a[i]=n-a[i];
  	temp.push_back(mp(a[i],i));
  	freq[a[i]]++;
  }

  sort(temp.begin(),temp.end());

  bool val=true;
  ll cnt=0;
  for(int i=1;i<=n;i++)
  {
  	if(freq[i]!=0 and (freq[i]%i) != 0)
  		val=false;
  	cnt+=freq[i];
  }

  int cur=1;
  int pos=0;
  if(val and cnt==n)
  {
  	cout<<"Possible"<<endl;
  	for(int i=1;i<=n;i++)
  	{
  		while(freq[i])
  		{
  			for(int j=1;j<=i;j++)
  			{
  				a[temp[pos].S]=cur;
  				pos++;
  			}
  			freq[i]-=i;
  			cur++;
  		}
  	}

  	for(int i=1;i<=n;i++)
  		cout<<a[i]<<" ";
  }
  else
  	cout<<"Impossible"<<endl;

  return 0;
}