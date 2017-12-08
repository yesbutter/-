#include <bits/stdc++.h>

#define N 40

using namespace std;

typedef struct TREE
{
    char data;
    struct TREE *lchild,*rchild;
} Tnode,*Ttree;

int space=0;

void Create_Tree(Ttree &root,string data,int data_len)
{
    static int count=0;
    char ch;
    if(count<data_len)ch=data[count++];
    else
    {
        root=NULL;
        return ;
    }
    if(ch=='0')root=NULL;
    else
    {
       // root=(Ttree)malloc(sizeof(Tnode));
       root=new Tnode;
        root->data=ch;
        Create_Tree(root->lchild,data,data_len);
        Create_Tree(root->rchild,data,data_len);
    }
}

void Pre_Order(Ttree root)
{
    if(root==NULL)return ;

    for(int i=0;i<space;i++)
        cout<<" ";
    for(int i=space;i<N;i++)
        cout<<"-";
    cout<<":"<<root->data<<endl;
    space+=2;
    Pre_Order(root->lchild);
    Pre_Order(root->rchild);
    space-=2;
}

int main()
{
    string ch;
    cin>>ch;
    Ttree root;
    Create_Tree(root,ch,ch.length());
    Pre_Order(root);
    return 0;
}
