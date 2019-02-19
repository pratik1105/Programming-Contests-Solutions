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
const int N = 2e5+10; 

vector<pair< pair<int,int>,int> > seg;
int mini[N];
int fin[N];
int main(){
  fast;
  int t;
  cin>>t;

  while(t--)
  {
  	int n;
  	cin>>n;

  	seg.clear();
  	for(int i=1;i<=n;i++)
  	{
  		int l,r;
  		cin>>l>>r;
  		seg.push_back(make_pair(make_pair(r,l),i));
  	}

  	mini[n]=N;
  	sort(seg.begin(),seg.end());

  	for(int i=n-1;i>=0;i--)
  	mini[i]=min(mini[i+1],seg[i].F.S);
  	
  	int ans=-1;
  	for(int i=0;i<n-1;i++)
  	{
  		if(seg[i].F.F<mini[i+1])
  		{
  			ans=i;
  			break;
  		}
  	}

  	if(ans==-1)
  		cout<<-1<<endl;
  	else
  	{
  		for(int i=0;i<=ans;i++)
  		fin[seg[i].S]=1;
  		for(int i=ans+1;i<n;i++)
  		fin[seg[i].S]=2;

  		for(int i=1;i<=n;i++)
  		cout<<fin[i]<<" ";
  		cout<<endl;
  	}

  }
  return 0;
}