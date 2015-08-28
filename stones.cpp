#include<bits/stdc++.h>
using namespace std;

#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

char arr1[110];
char arr2[110];

map<char,int> m;
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int count=0;
		scanf("%s",arr1);
		scanf("%s",arr2);
		m.clear();
		
		for(i=0;i<strlen(arr1);i++)
		{
			m[arr1[i]]++;
		}
		
		for(i=0;i<strlen(arr2);i++)
		{
			if(m[arr2[i]]>0)
			count++;
		}
		
		cout<<count<<endl;
	}
	return 0;
}
