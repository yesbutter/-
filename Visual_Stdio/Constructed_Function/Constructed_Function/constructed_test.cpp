
#include<iostream>
using namespace std;

class Father
{
public:
	int ID = -1;

	Father()
	{
		ID = 0;
		cout << "我是父类无参的构造函数" << endl;
	}

	Father(int ID)
	{
		
			this->ID = ID;
			cout << "我是父类有参的构造函数" << endl;
		
	}
	Father(const Father &father)//需要传来一个引用
	{
		ID = father.ID;
		cout << "我是父类拷贝构造方法" << endl;
	}
	~Father()
	{
		cout << ID<<":我是父类析构函数" << endl;
		cout << "-------------------我是华丽的分割线--------------------" << endl;
	}
	Father& operator=(Father &father)
	{
		this->ID = 9999;
		cout << "我是运算符=重载" << endl;
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
			cout << "我是子类无参的构造函数" << endl;
		}
		else
		{
			this->ID = ID;
			cout << "我是子类有参的构造函数" << endl;
		}
	}
	Child(const Child &child)//默认调用无参数的父类构造函数
	{
		ID = child.ID;	
		cout << "我是子类的拷贝构造函数" << endl;
	}
	~Child()
	{
		cout <<ID<< ":我是子类的析构函数" << endl;
	}
};

void RolePlay()
{
	Father father1(1);
	cout << "-------------------我是华丽的分割线--------------------" << endl;
	Father father2(father1);
	father2.ID = 2;
	cout << "-------------------我是华丽的分割线--------------------" << endl;
	Father father3 = father1;
	cout << "Father3ID:" << father3.ID << endl;
	father3.ID = 3;
	cout << "-------------------我是华丽的分割线--------------------" << endl;
	Father father4;
	cout << "Father4ID:" << father4.ID << endl;
	father4 = father1;
	cout << "Father4ID:" << father4.ID << endl;
	father4.ID = 4;
	cout << "-------------------我是华丽的分割线--------------------" << endl;

	Child child1(11);
	cout << "-------------------我是华丽的分割线--------------------" << endl;
	Child child2(child1);
	child2.ID = 12;
	cout << "-------------------我是华丽的分割线--------------------" << endl;
	Child child3 = child1;
	cout << "Child3ID:" << child3.ID << endl;
	child3.ID = 13;
	cout << "-------------------我是华丽的分割线--------------------" << endl;
	Child child4;
	cout << "Child4ID:" << child4.ID << endl;
	child4 = child1;
	cout << "Child4ID:" << child4.ID << endl;
	child4 .ID= 14;
	cout << "-------------------我是华丽的分割线--------------------" << endl;

}
int main()
{
	RolePlay();
	system("pause");
	return 0;
}
