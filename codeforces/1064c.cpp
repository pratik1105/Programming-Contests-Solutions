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

ll freq[30];
vector<string> SS(30);

int main(){
  fast;
  int n;
  cin>>n;
  string s;
  fill(freq,0);
  SS.clear();

  cin>>s;
  for(int i=0;i<n;i++)
  {
  	freq[s[i]-'a']++;
  	SS[s[i]-'a']=s[i];
  }	
  
  for(int i=0;i<26;i++)
  {
  	for(int j=0;j<freq[i];j++)
  	cout<<SS[i];
  }
  

  return 0;
}