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

vector< pair< pair<int,int> ,int> > edges[N];
vector<int> newedges[N];
int n,m;
int par[N];
int num[N];
int last=n;
vector<int> final;
bool dfs(int s,int p,int vis)
{
	if(par[s]==vis)
	{
		//cout<<"returning false for "<<s<<endl;
		return false;
	}
	if(par[s])
	return true;

	par[s]=vis;
	
	for(int i=0;i<newedges[s].size();i++)
	{
		//cout<<"edge from "<<s<<" to "<<newedges[s][i]<<endl;
		if(dfs(newedges[s][i],s,vis)==false)
			return false;
	}

	num[s]=last;
	last--;
	par[s]=N;
	//cout<<" num for "<<s<<" is "<<num[s]<<endl;
	return true;	
}

bool check(int mid)
{
	//cout<<"checking "<<mid<<endl;
	for(int i=1;i<=n;i++)
	{
		newedges[i].clear();
		par[i]=0;
		num[i]=0;
		last=n;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			if(edges[i][j].F.S>mid)
			{
				newedges[i].push_back(edges[i][j].F.F);
			}
		}
	}


	for(int i=1;i<=n;i++)
	{
		if(par[i]==0)
		{
			if(dfs(i,0,i)==false)
			return false;
		}
	}

	return true;
}


int main(){
  fast;
  
  cin>>n>>m;
  int ans;
  final.clear();
  for(int i=1;i<=m;i++)
  {
  	int u,v,w;
  	cin>>u>>v>>w;
  	edges[u].push_back(mp(mp(v,w),i));
  }

   fill(num,0);
   int l =0;
   int r = 1000000000;

   while(r-l>1)
   {
   	 int mid =(l+r)/2;
   	 if(check(mid))
   	 {
   	 	r=mid;
   	 	//cout<<"good for "<<mid<<endl;
   	 }
     else
     {
     	l=mid;
     	//cout<<"bad for "<<mid<<endl;
     }
   }

   if(check(l))
   ans=l;
   else
   ans=r;
   
   //cout<<" ans is "<<ans<<endl;
   for(int i=1;i<=n;i++)
	{
		newedges[i].clear();
		par[i]=0;
		num[i]=0;
		last=n;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			if(edges[i][j].F.S>ans)
			newedges[i].push_back(edges[i][j].F.F);
		}
	}
   	
    for(int i=1;i<=n;i++)
	{
		if(par[i]==0)
		{
			dfs(i,0,i);
		}
	}
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<edges[i].size();j++)
    	{
    		if(edges[i][j].F.S<=ans)
    		{
    			if(num[i]==0 and num[edges[i][j].F.F]==0)
    			{
    				num[i]=last;
    				num[edges[i][j].F.F]=last+1;
    				last=last+2;
    			}

    			else if(num[i]==0 and num[edges[i][j].F.F]!=0)
    			{
    				num[i]=last;
    				last++;
    				final.push_back(edges[i][j].S);
    			}

    			else if(num[i]!=0 and num[edges[i][j].F.F]==0)
    			{
    				num[edges[i][j].F.F]=last;
    				last++;
    			}

    			else if(num[i]!=0 and num[edges[i][j].F.F]!=0)
    			{
    				if(num[edges[i][j].F.F]<num[i])
    				final.push_back(edges[i][j].S);
    			}
    		}
    	}
    }

    cout<<ans<<" "<<final.size()<<endl;
    for(int i=0;i<final.size();i++)
    cout<<final[i]<<" ";

  return 0;
}