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

int cnt[30];
string s;
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	fill(cnt,0);
  	
  	int n;
  	cin>>n;

  	for(int i=1;i<=n;i++)
  	{
  		cin>>s;
  		for(int j=0;j<s.size();j++)
  		{
  			if(cnt[s[j]-'a']==i-1 or cnt[s[j]-'a']==i)
  			cnt[s[j]-'a']=i;
  			else
  			cnt[s[j]-'a']=-1;
  		}

  	}

  	int ans=0;
  	for(int i=0;i<26;i++)
  	if(cnt[i]==n)
  	ans++;

  	cout<<ans<<endl;

  }
  return 0;
}