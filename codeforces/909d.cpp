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
const int N = 1e6+10; 

ii grp[N];
ii temp[N];

int main(){
  fast;
  string s;
  cin>>s;
  
  int ch=0;
  int cnt=0;
  int cur=0;

  FOR(i,0,sz(s)-1)
  {
  	if(s[i]!=ch)
  	{
  		grp[cnt++]=mp(ch,cur);
  		ch=s[i];
  		cur=1;
  	}
  	else
  	cur++;
  }
  
  grp[cnt]=mp(ch,cur);

  int ans=0;
  while(cnt>1)
  {

  	ans++;
  	int cnt2=0;
  	FOR(i,1,cnt)
  	{
  		ii x=grp[i];
  		if(i==1 or i==cnt)
  		x.S--;
  		else
  		x.S-=2;

  		if(x.S>0)
  		temp[++cnt2]=x;
  	}
  	
  	cnt=0;
  	ch=temp[1].F;
  	cur=0;

  	FOR(i,1,cnt2)
  	{
  		if(temp[i].F != ch)
  		{
  			grp[++cnt]=mp(ch,cur);
  			ch=temp[i].F;
  			cur=temp[i].S;
  		}
  		else
  		cur+=temp[i].S;
  	}
  	grp[++cnt]=mp(ch,cur);
  		
  }

  cout<<ans<<endl;
  return 0;
}