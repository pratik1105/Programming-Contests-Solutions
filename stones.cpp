#include<iostream>

using namespace std;

int main()
{
	char arr[50];
	int n,i;
	int cur=0,next=1,count=0;
	cin>>n;
	
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    while(next<n)
    {
    	if(arr[next]==arr[cur])
    	{
    		next++;
    		count++;
		}
		else
		{
			cur=next;
			next++;
		}
	}
	
	cout<<count;
	return 0;
}
