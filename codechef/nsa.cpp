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

int freq[30];
int freq2[30];

ll val[N];

string s;
int main(){
  fast;
  int t;
  cin>>t;

  while(t--)
  {
  	fill(freq,0);
  	fill(freq2,0);
  	fill(val,0);
  	cin>>s;

  	int n=sz(s);

  	for(int i=0;i<n;i++)
  	{
  		if(i==0)
  			val[i]=0;
  		else
  		val[i]=val[i-1];
  		
  		freq[s[i]-'a']++;
  		
  		for(int j=0;j<s[i]-'a';j++)
  		val[i]+=freq[j]; 			
  	}
  	
  	ll ans=INF;
  	ll cur=0;

  	for(int i=24;i>=0;i--)
  		freq[i]+=freq[i+1];

  	for(int i=0;i<n;i++)
  	{
  		cur=val[n-1];
  		cur-=freq[s[i]-'a'+1];
  		cur-=freq2[s[i]-'a'-1];

  		
  		freq[s[i]-'a']--;
  		
  		for(int j=s[i]-'a'-1;j>=0;j--)
  		freq[j]--;

  		ll temp=cur;
  		for(int j=0;j<26;j++)
  		{

  			temp+=abs(j-(s[i]-'a'));
  			
  			if(j!=0)
  			temp+=freq2[j-1];
  			if(j!=25)
  			temp+=freq[j+1];

  			
  			ans=min(ans,temp);
  			temp=cur;
  		}

  		freq2[s[i]-'a']++;
  		for(int j=s[i]-'a'+1;j<26;j++)
  		freq2[j]++;
  	}

  	cout<<ans<<endl;
  }
  return 0;
}