#include <bits/stdc++.h>
using namespace std;

const int N =1000000000;
long long int A,B,C,D;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cout<<"Q "<<0<<" "<<0<<endl;
	    cin>>A;
	    cout<<"Q "<<N<<" "<<0<<endl;
	    cin>>B;
	    long long int X = N+A-B;
	    X/=2;
	    cout<<"Q "<<X<<" "<<0<<endl;
	    cin>>C;
	    cout<<"Q "<<0<<" "<<N<<endl;
	    cin>>D;
	    
	    cout<<"A "<<A-C<<" "<<C<<" "<<N-B+C<<" "<<N-D+A-C<<endl;
	    cin>>A;
	}
	return 0;
}