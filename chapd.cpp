#include<iostream>
#include<math.h>
using namespace std;

bool prime[1000000001]={true};
#define big 1000000000
int primes[1000000];

void sieve()
{
	prime[1]=false;
	int i=3,j;
	if(prime[i]==true && i<=sqrt(big))
	{
		for(j=i;j<=big;j=j+i)
		prime[j]=false;
		
		i=i+1;
	}

    j=1;
	for(i=1;i<=big;i++)
	{
		if(prime[i]==true)
		{
		primes[j]=i;
		j++;
	    }
	}
}


int main()
{
	int t,i;
	long long int a,b,prod;
	cin>>t;
	
	sieve();
	
	for(i=1;i<1000000;i++)
	cout<<primes[i]<<endl;
	
	/*while(t--)
	{
		prod=1;
		cin>>a>>b;
		
		/*for(i=1;i<b;i++)
		{
			if(b%primes[i]==0)
			{
				prod=prod*primes[i];  
		    }
		    
		}
		
		
		
		if(a%prod==0)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		
	}*/
	return 0;
}
