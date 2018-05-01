#include<iostream>
#include<string>
using namespace std;

bool judge(string tmp)
{
	bool vomel = false, many = true, p = true;
	int cnta = 0, cntb = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u')
		{
			vomel = true;
			cnta++;
			cntb = 0;
			if (cnta == 3)
				many = false;
		}
		else
		{
			cntb++;
			cnta = 0;
			if (cntb == 3)
				many = false;
		}
		if (i != 0 && tmp[i] == tmp[i - 1] && (tmp[i] != 'e' && tmp[i] != 'o'))
			p = false;
	}
	return vomel && many&&p;
}
int main()
{
	string tmp;
	while (getline(cin, tmp))
	{
		if ("end" == tmp)
			break;
		if(judge(tmp))
			printf("<%s> is acceptable.\n", tmp.c_str());
		else
			printf("<%s> is not acceptable.\n", tmp.c_str());
	}
	system("pause");
	return 0;
}