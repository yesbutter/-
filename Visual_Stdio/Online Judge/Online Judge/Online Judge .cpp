#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string formats(string a)
{
	string tmp;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ' || a[i] == '\n' || a[i] == '\t');
		else
			tmp += a[i];
	}
	return tmp;
}
int judge(string a, string b)
{
	if (a == b)
		return 0;
	string tmp;
	a = formats(a);
	b = formats(b);
	if (a == b)
		return 1;
	else
		return 2;
}
int main()
{
	int T,flag;
	scanf("%d ", &T);
	vector<string> ans, user;
	string tmp,ans1,user1;
	while (T--)
	{
		ans.clear(), user.clear(),ans1="",user1="";		
		while (getline(cin, tmp))
		{
			if (tmp == "START")
				break;
		}
		while (true)
		{
			getline(cin, tmp);
			if (tmp == "END")
				break;
			ans.push_back(tmp);
		}
		while (getline(cin,tmp))
		{
			if (tmp == "START")
				break;
		}
		while (true)
		{
			getline(cin, tmp);
			if (tmp == "END")
				break;
			user.push_back(tmp);
		}
		for (int i = 0; i < ans.size(); i++) {
			ans1 += ans[i];
			ans1 += "\n";
		}
		for (int i = 0; i < user.size(); i++) {
			user1 += user[i];
			user1 += "\n";
		}
		flag = judge(ans1, user1);
		if (flag == 0)
			printf("Accepted\n");
		else if (flag == 1)
			printf("Presentation Error\n");
		else
			printf("Wrong Answer\n");
	}
	system("pause");
	return 0;
}