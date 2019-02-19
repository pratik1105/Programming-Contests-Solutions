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
const int N = 1e6+10; 

struct Line {
	ll k, b;

	Line() : k(), b() {}
	Line(ll _k, ll _b) : k(_k), b(_b) {}

	ll getVal(ll x) {
		return k * x + b;
	}
};

const ll C = (ll)1e9 + 3;

struct Hull {
	vector<Line> lines;
	vector<ll> bnd;

	Hull() : lines(), bnd() {}

	void addLine(Line L) {
		while(!lines.empty()) {
			if (L.getVal(bnd.back()) >= lines.back().getVal(bnd.back())) {
				lines.pop_back();
				bnd.pop_back();
			} else break;
		}
		if (lines.empty()) {
			bnd.push_back(-C);
			lines.push_back(L);
		} else {
			ll l = bnd.back(), r = C + 1;
			while(r - l > 1) {
				ll x = l + (r - l) / 2;
				if (L.getVal(x) >= lines.back().getVal(x))
					r = x;
				else
					l = x;
			}
			if (l < C) {
				bnd.push_back(r);
				lines.push_back(L);
			}
		}
	}

	ll getVal(ll x) {
		int p = upper_bound(bnd.begin(), bnd.end(), x) - bnd.begin() - 1;
		return lines[p].getVal(x);
	}
};

struct rect
{
	ll x,y,a;
};

rect r[N];
bool comp(rect a, rect b)
{
	return a.x < b.x;
}

int main(){
  fast;
  int n;
  scanf("%d",&n);

  for(int i=0;i<n;i++)
  scanf("%lld%lld%lld", &r[i].x, &r[i].y, &r[i].a);
  //cin>>r[i].x>>r[i].y>>r[i].a;
  
  ll ans=0;
  sort(r,r+n,comp);

  Hull hull = Hull();
  hull.addLine(Line(0,0));

  for(int i=0;i<n;i++)
  {
  	ll temp = hull.getVal(-r[i].y) + r[i].x*r[i].y - r[i].a;
  	ans=max(ans,temp);
  	hull.addLine(Line(r[i].x,temp));
  }

  printf("%lld\n", ans);
  //cout<<ans<<endl;

  return 0;
}