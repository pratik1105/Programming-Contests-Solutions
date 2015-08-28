#include<bits/stdc++.h>
using namespace std;
int n,m;
vector< pair<int,int> > v;
vector<int>edges[100010];
set<int> s[100010];
int col[100010];
int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		int color;
		cin>>color;
		col[i]=color;
		v.push_back(make_pair(color,i));
	}
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(v[a-1].first!=v[b-1].first)
		{
		   edges[a].push_back(b);
		   edges[b].push_back(a);
	    }
	}
	
	sort(v.begin(),v.end());
	
	int maxi=0;
	int val=v[0].first;
	
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(j<n-1 && v[j].first==v[j+1].first)
		{
			j++;
		}
		
		for(int k=i;k<=j;k++)
		{
			for(int l=0;l<edges[v[k].second].size();l++)
			{
				s[v[k].first].insert(col[edges[v[k].second][l]]);
			}
		}
		i=j;
		
		if(s[v[j].first].size()>maxi)
		{maxi=s[v[j].first].size();
		 val=v[j].first;
	    }
		
		
	}
	
	cout<<val;
	return 0;
}
