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
const int N = 1e3+10; 

string s;
int arr[N][N];
ll values[N][N];
int farthest[4][N][N];
ii S[5*N];
vector<ii> obs;
map<char,ll> dir;

int main()
{
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	obs.clear();
  	ll ans=0;
  	int l,n;
  	cin>>l>>n;

  	FOR(i,1,n)
  	FOR(j,1,n)
  	values[i][j]=l;

  	cin>>s;
  	dir['R']=0;
  	dir['L']=1;
  	dir['U']=2;
  	dir['D']=3;

  	int cur=1;
  	ll val=0;

  	if(s[0]=='R' or s[0]=='U')
  		val=1;
  	else
  		val=-1;

  	S[1]=mp(dir[s[0]],val);
  	
  	FOR(i,1,sz(s)-1)
  	{
  		if(s[i]==s[i-1])
  		{
  			if(s[i]=='R' or s[i]=='U')
  				val++;
  			else
  				val--;

  			S[cur]=mp(dir[s[i]],val);
  		}
  		else
  		{
  			cur++;
  			val=0;

			if(s[i]=='R' or s[i]=='U')
  				val++;
  			else
  				val--;

  			S[cur]=mp(dir[s[i]],val);	  			
  		}
  	}

  	int ones=0,zeros=0;

  	FOR(i,1,n)
  	FOR(j,1,n)
  	{
  		char ch;
  		cin>>ch;
  		if(ch=='.')
  			arr[i][j]=1,ones++;
  		else
  			{
  				arr[i][j]=0,zeros++;
  				obs.pb(mp(i,j));
  			}
  	}

  	if(zeros>100000)
  	{
  	FOR(i,1,n)
  	{	
  		farthest[0][i][n]=n;
  		NFOR(j,n-1,1)
  		{
  			if(arr[i][j+1]==0)
  				farthest[0][i][j]=j;
  			else
  				farthest[0][i][j]=farthest[0][i][j+1];

  			//cout<<i<<" "<<j<<" "<<farthest[0][i][j]<<endl;
  		}	
  	}

  	FOR(i,1,n)
  	{
  		farthest[1][i][1]=1;
  		FOR(j,2,n)
  		{
  			if(arr[i][j-1]==0)
  				farthest[1][i][j]=j;
  			else
  				farthest[1][i][j]=farthest[1][i][j-1];

  			//cout<<i<<" "<<j<<" "<<farthest[1][i][j]<<endl;
  		}	
  	}

  	FOR(j,1,n)
  	{
  		farthest[2][1][j]=1;
  		FOR(i,2,n)
  		{
  			if(arr[i-1][j]==0)
  				farthest[2][i][j]=i;
  			else
  				farthest[2][i][j]=farthest[2][i-1][j];
  			
  			//cout<<i<<" "<<j<<" "<<farthest[2][i][j]<<endl;
  		}	
  	}

  	FOR(j,1,n)
  	{
  		farthest[3][n][j]=n;
  		NFOR(i,n-1,1)
  		{
  			if(arr[i+1][j]==0)
  				farthest[3][i][j]=i;
  			else
  				farthest[3][i][j]=farthest[3][i+1][j];

  			//cout<<i<<" "<<j<<" "<<farthest[3][i][j]<<endl;
  		}	
  	}


  	FOR(i,1,n)
  	FOR(j,1,n)
  	{
  		ll val=0;
  		if(arr[i][j]==1)
  		{
  			int posx=i,posy=j;
  			FOR(k,1,cur)
  			{
  				if(S[k].F==0)
  				{
  					if(farthest[0][posx][posy]>=posy+S[k].S)
  					{
  						val+=S[k].S;
  						posy+=S[k].S;
  					}
  					else
  					{
  						val+=farthest[0][posx][posy]-posy;
  						break;
  					}
  				}

  				else if(S[k].F==1)
  				{
  					if(farthest[1][posx][posy]<=posy+S[k].S)
  					{
  						val-=S[k].S;
  						posy+=S[k].S;
  					}
  					else
  					{
  						val+=abs(farthest[1][posx][posy]-posy);
  						break;
  					}
  				}

  				else if(S[k].F==2)
  				{
  					if(farthest[2][posx][posy]<=posx-S[k].S)
  					{
  						val+=S[k].S;
  						posx-=S[k].S;
  					}
  					else
  					{
  						val+=abs(farthest[2][posx][posy]-posx);
  						break;
  					}
  				}

  				else if(S[k].F==3)
  				{
  					if(farthest[3][posx][posy]>=posx-S[k].S)
  					{
  						val-=S[k].S;
  						posx-=S[k].S;
  					}
  					else
  					{
  						val+=abs(farthest[3][posx][posy]-posx);
  						break;
  					}
  				}
  			}
  			//cout<<i<<" "<<j<<" "<<val<<endl;
  			ans=ans^val;
  		}
  	}
  	cout<<ans<<endl;
  	}
  	else
  	{
  		for(int i=0;i<n+2;i+=n+1)
  		FOR(j,0,n+1)
  		{
  			arr[i][j]=0;
  			obs.pb(mp(i,j));
  		}

  		for(int j=0;j<n+2;j+=n+1)
  		FOR(i,0,n+1)
  		{
  			arr[i][j]=0;
  			obs.pb(mp(i,j));
  		}

  		int netx=0;
  		int nety=0;
  		FOR(k,0,l-1)
  		{
  			if(s[k]=='R')
  				nety++;
  			if(s[k]=='L')
  				nety--;
  			if(s[k]=='U')
  				netx--;
  			if(s[k]=='D')
  				netx++;

  			FOR(i,0,sz(obs)-1)
  			{
  				int posx=obs[i].F;
  				int posy=obs[i].S;
  				//cout<<posx<<" "<<netx<<" "<<posy<<" "<<nety<<endl;
  				if(posx-netx>0 and posx-netx<=n and posy-nety>0 and posy-nety<=n)
  				values[posx-netx][posy-nety]=min(values[posx-netx][posy-nety],(ll)k);
  			}
  		}

  		FOR(i,1,n)
  		FOR(j,1,n)
  		{
  			if(arr[i][j]==1)
  			{
  //				cout<<i<<" "<<j<<" "<<values[i][j]<<endl;
  				ans=ans^values[i][j];
  			}
  			
  		}
  		cout<<ans<<endl;
  	}
  }
  return 0;
}