
#include<iostream>
using namespace std;

class Father
{
public:
	int ID = -1;

	Father()
	{
		ID = 0;
		cout << "���Ǹ����޲εĹ��캯��" << endl;
	}

	Father(int ID)
	{
		
			this->ID = ID;
			cout << "���Ǹ����вεĹ��캯��" << endl;
		
	}
	Father(const Father &father)//��Ҫ����һ������
	{
		ID = father.ID;
		cout << "���Ǹ��࿽�����췽��" << endl;
	}
	~Father()
	{
		cout << ID<<":���Ǹ�����������" << endl;
		cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	}
	Father& operator=(Father &father)
	{
		this->ID = 9999;
		cout << "���������=����" << endl;
		cout << "----------------------------------------------------------" << endl;
		return *this;
	}
};


class Child :public Father
{
public:
	int ID = -2;
	Child(int ID=0):Father(188)
	{
		if (ID == 0) {
			ID = 0;
			cout << "���������޲εĹ��캯��" << endl;
		}
		else
		{
			this->ID = ID;
			cout << "���������вεĹ��캯��" << endl;
		}
	}
	Child(const Child &child)//Ĭ�ϵ����޲����ĸ��๹�캯��
	{
		ID = child.ID;	
		cout << "��������Ŀ������캯��" << endl;
	}
	~Child()
	{
		cout <<ID<< ":�����������������" << endl;
	}
};

void RolePlay()
{
	Father father1(1);
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	Father father2(father1);
	father2.ID = 2;
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	Father father3 = father1;
	cout << "Father3ID:" << father3.ID << endl;
	father3.ID = 3;
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	Father father4;
	cout << "Father4ID:" << father4.ID << endl;
	father4 = father1;
	cout << "Father4ID:" << father4.ID << endl;
	father4.ID = 4;
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;

	Child child1(11);
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	Child child2(child1);
	child2.ID = 12;
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	Child child3 = child1;
	cout << "Child3ID:" << child3.ID << endl;
	child3.ID = 13;
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;
	Child child4;
	cout << "Child4ID:" << child4.ID << endl;
	child4 = child1;
	cout << "Child4ID:" << child4.ID << endl;
	child4 .ID= 14;
	cout << "-------------------���ǻ����ķָ���--------------------" << endl;

}
int main()
{
	RolePlay();
	system("pause");
	return 0;
}
