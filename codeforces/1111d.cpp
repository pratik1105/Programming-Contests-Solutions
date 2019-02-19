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

string s;
int freql[30];
ll vall[30];
ll valu[30];
int frequ[30];

ll fac[N];
ll invfac[N];

int main(){
  fast;
  fill(frequ,0);
  fill(freql,0);

  cin>>s;
  for(int i=0;i<s.size();i++)
  {
  	if(s[i]>='a' and s[i]<='z')
  	freql[s[i]-'a']++;
  	if(s[i]>='A' and s[i]<='Z')
  	frequ[s[i]-'A']++l
  }

  fac[1]=1;
  for(int i=2;i<N;i++)
  {
  	fac[i]=fac[i-1]*(i)
  }

  return 0;
}