#include<iostream>
using namespace std;
bool compare(string a,string b)
{
	bool flag=true;
	if(a.size()>b.size())
	return(!flag);
	else if(b.size()>a.size())
	return(flag);
	else
	{
		for(int i=0;i<a.size();i++)
		if(a[i]<b[i])
		return(!flag);
		else if(a[i]>b[i])
		return(flag);
	}
}
int main()
{
	int n;
	string m;
	cin>>n;
	string str[1000];
	for(int i=0;i<n;i++)
	cin>>str[i];
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(compare(str[j],str[j-1]))
			{
				m=str[j];str[j]=str[j-1];str[j-1]=m;
			}
		}
	}
	for(int i=0;i<n;i++)
	cout<<str[i]<<endl;
	return 0;
}
