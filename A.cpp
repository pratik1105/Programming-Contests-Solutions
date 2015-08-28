#include<bits/stdc++.h>
using namespace std;

#define take(n) scanf("%d",&n)
#define loop(i,a,b) for(i=a;i<b;i++)

int main()
{
	int n;
	take(n);
	int min1,min2,min3,max1,max2,max3,f,s,t;
	take(min1);
	take(max1);
	take(min2);
	take(max2);
	take(min3);
	take(max3);
	
	f=min(max1,n-(min2+min3));
	n=n-f;
	s=min(max2,n-min3);
	t=n-s;
	
	cout<<f<<" "<<s<<" "<<t;
	return 0;
}
