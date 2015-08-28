#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int len1,len2,len3,i,j,dec1=1000000,temp,dec2=1000000;
	char str1[100001];
	char str2[100001];
	char str3[100001];
	
	int pos1[27];
	int pos2[27];
	int pos3[27];
	
	cin>>str1;
	cin>>str2;
	cin>>str3;
	
	len1=strlen(str1);
	len2=strlen(str2);
	len3=strlen(str3);
	
	for(i=0;i<len1;i++)
	{
		pos1[str1[i]-'a'+1]++;
	}
	
	for(i=0;i<len2;i++)
	{
		pos2[str2[i]-'a'+1]++;
	}
	
	for(i=0;i<len3;i++)
	{
		pos3[str3[i]-'a'+1]++;
	}
	
    
	for(i=0;i<len2;i++)
	{
		temp=pos1[str2[i]-'a'+1]/pos2[str2[i]-'a'+1];
		if(temp<dec1)
		dec1=temp;
	}
	
	
	if(strcmp(str2,str3))
	{
	
		for(i=0;i<len3;i++)
		{
	    temp=pos1[str3[i]-'a'+1]/pos3[str3[i]-'a'+1];
		if(temp<dec2)
		dec2=temp;	
	    }
		
		
		if(dec1>dec2)
		{
			for(i=0;i<len2;i++)
			{
				pos1[str2[i]-'a'+1]-=dec1;
			}
			
			for(i=0;i<len2*dec1;i++)
			{
				str1[i]=str2[i%len2];
			}
			
			cout<<str1<<endl;
		for(i=0;i<len3;i++)
		{
	    temp=pos1[str3[i]-'a'+1]/pos3[str3[i]-'a'+1];
		if(temp<dec2)
		dec2=temp;	
	    }
	    
	    if(dec2>0)
	    {
	    	for(i=0;i<len3;i++)
			{
				pos1[str3[i]-'a'+1]-=dec2;
			}
			
			for(i=len2*dec1;i<len2*dec1+len3*dec2;i++)
			{
				str1[i]=str3[i%len3];
			}
		}
		

		else
		i=len2*dec1;
		
		
		for(j=0;j<len1 && i<len1;j++)
		{
			while(pos1[str1[j]-'a'+1]>0)
			{
				str1[i]=str1[j];
				i++;
				pos1[str1[j]]--;
			}
		}
		
		}
		
		else
		{
				for(i=0;i<len3;i++)
			{
				pos1[str3[i]-'a'+1]-=dec2;
			}
			
			for(i=0;i<len3*dec1;i++)
			{
				str1[i]=str3[i%len3];
			}
			
		for(i=0;i<len2;i++)
		{
	    temp=pos1[str2[i]-'a'+1]/pos2[str2[i]-'a'+1];
		if(temp<dec1)
		dec1=temp;	
	    }
	    
	    if(dec1>0)
	    {
	    	for(i=0;i<len2;i++)
			{
				pos1[str2[i]-'a'+1]-=dec1;
			}
			
			for(i=len3*dec2;i<len3*dec2+len2*dec1;i++)
			{
				str1[i]=str2[i%len2];
			}
		}
		
		else
		i=len3*dec2;
		
		for(j=0;j<len1 && i<len1;j++)
		{
			while(pos1[str1[j]-'a'+1]>0)
			{
				str1[i]=str1[j];
				i++;
				pos1[str1[j]]--;
			}
		}
		}
	}
	else
	{
		for(i=0;i<len2;i++)
			{
				pos1[str2[i]-'a'+1]-=dec1;
			}
			
			for(i=0;i<len2*dec1;i++)
			{
				str1[i]=str2[i%len2];
			}
			
			for(j=0;j<len1 && i<len2;i++)
		{
			while(pos1[str1[j]-'a'+1]>0)
			{
				str1[i]=str1[j];
				i++;
				pos1[str1[j]]--;
			}
		}
	
	}
	
	cout<<str1;
	return 0;
}
