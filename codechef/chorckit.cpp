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

string s;
string t;
int maxind=-1;
int maxl=-1;
int maxp=-1;

int lower[30];
int upper[30];

int cursize;
vector< pair<string,int> > T;
vector< pair<int, ii> > moves;
vector< pair<int, ii> > temp_moves;
int reform(int pos)
{
	int tot=0;
	for(int i=pos;i<pos+maxl;i++)
	{
		int u,v;
		if(T[maxind].F[i-pos]>='A' and T[maxind].F[i-pos]<='Z') 
		u = upper[T[maxind].F[i-pos]-'A'];
		else
		u = lower[T[maxind].F[i-pos]-'a'];

		if(s[i]>='A' and s[i]<='Z')
		v = upper[s[i]-'A'];
		else
		v = lower[s[i]-'a'];

		//cout<<"difference is "<<u<<" "<<v<<endl;
		tot+=abs(u-v);
	}
	//cout<<"returning "<<tot<<endl;
	return tot;
	
}


void do_reform(int pos)
{
	for(int i=pos;i<pos+maxl;i++)
	{
		if(s[i]!=T[maxind].F[i-pos])
		{
			int u;
			if(T[maxind].F[i-pos]>='A' and T[maxind].F[i-pos]<='Z') 
			u = upper[T[maxind].F[i-pos]-'A'];
			else
			u = lower[T[maxind].F[i-pos]-'a'];
			temp_moves.push_back(mp(1,mp(i+1,u)));
		}
	}
	
}

int main(){
  fast;
  int n,m,a,x,r;
  cin>>n>>m>>a>>x>>r;
  cin>>s;
  cursize = s.size();

  T.clear();
  moves.clear();

  for(int i=0;i<26;i++)
  {
  	lower[i]=i+1;
  	upper[i]=27+i;
  }
	
  for(int i=0;i<m;i++)
  {
  	int c;
  	cin>>t;
  	cin>>c;
  	T.push_back(mp(t,c));
  	if(c>=maxp and t.size()<=cursize)
  	{
  		maxind=i;
  		maxl=t.size();
  		maxp=c;
  	}
  }

  for(int i=0;i<a;i++)
  {
  	int c;
  	cin>>t;
  	cin>>c;
  }

  ll total=0;
  double cur=0;
  ll sub=0;
  int add =0;

  int refill=x;
  int startpos=0;
  while(startpos<n)
  {
  	cur=-1000000.0;
  	sub=0;
  	add=0;
  	temp_moves.clear();
  	for(int j=0;j<T.size();j++)
  	{
  		maxl=T[j].F.size();
  		maxind=j;
  	
  		if(maxl>=0 and maxl<=n-startpos)
  		{
  			double val=1.0*reform(startpos);
  			if(val==0 and (1.0*T[j].S)>=cur)
  			{
  				temp_moves.clear();
  				do_reform(startpos);
  				sub=val;
  				add=maxl;
  				cur=(1.0*T[j].S);
  			}
  			else if(x-val>=r and (1.0*T[j].S)/sqrt(1+val)>=cur)
  			{
  				temp_moves.clear();
  				do_reform(startpos);
  				sub=val;
  				add=maxl;
  				cur=(1.0*T[j].S)/sqrt(1+val);
  			}
  		}
  	}

  	for(int j=0;j<temp_moves.size();j++)
  	moves.push_back(temp_moves[j]);
  	
  	x=x-sub;
  	startpos=startpos+add;
  	if(add==0)
  	startpos++;
  }
  	
  

  	int lim=moves.size();
  	lim=100000-lim;
  	if(x>=r and lim>0 and 2*cursize<1000000)
  	moves.push_back(mp(3,mp(1,cursize)));
 

  cout<<moves.size()<<endl;
  for(int i=0;i<moves.size();i++)
  {

  	if(moves[i].F==1)
  	{
  		char ch;
  		if(moves[i].S.S>26)
  		ch='A'+moves[i].S.S-27;
  		else
  		ch='a'+moves[i].S.S-1;
  		 
  		cout<<1<<" "<<moves[i].S.F<<" "<<ch<<endl;
  	}
  	else
  		cout<<3<<" "<<moves[i].S.F<<" "<<moves[i].S.S<<endl;
  }
  return 0;
}