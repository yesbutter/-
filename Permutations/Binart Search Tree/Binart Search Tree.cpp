#include<iostream>
#include<string.h>

using namespace std;

typedef struct TREE
{
	char data;
	struct TREE *lchild=NULL, *rchild=NULL;
} Tnode,*Tlinknode;

Tlinknode insert_tree(Tlinknode root, char c)
{
	if (root == NULL)
	{
		root = new Tnode;
		root->data = c;
	}
	else
	{
		if (root->data > c) root->lchild=insert_tree(root->lchild, c);
		else root->rchild=insert_tree(root->rchild, c);
	}
	return root;
}

Tlinknode creat_tree(Tlinknode root,char *str)
{
	if (root == NULL)
	{
		root = new Tnode;
		root->data= str[0];
		root->lchild = root->rchild = NULL;
	}
	for (int i = 1; i < strlen(str); i++)
	{
		root=insert_tree(root, str[i]);
	}
	
	return root;
}

bool is_onetree(Tlinknode root1, Tlinknode root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->data == root2->data)
		{
			if (is_onetree(root1->lchild, root2->lchild) && is_onetree(root1->rchild, root2->rchild))
				return true;
		}
	}
	return false;
}

int main()
{
	int n;
	char str1[11], str2[11];
	while (1)
	{
		cin>>n;
		if (n == 0)break;
		cin >> str1;
		Tlinknode root1=NULL , root2;
		root1=creat_tree(root1, str1);
		for (int i = 1; i <= n; i++)
		{
			cin >> str2;
			root2 = NULL;
			root2=creat_tree(root2, str2);
			if (is_onetree(root1,root2))cout << "YES"<<endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
