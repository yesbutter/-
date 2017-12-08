#include <bits/stdc++.h>

using namespace std;
typedef struct TREE
{
    int data;
    struct TREE *lchild,*rchild;
    TREE(int _data=-1)
    {
        data=_data;
        lchild=NULL;
        rchild=NULL;
    }
} Tnode,*Ttree;
Ttree creat_Tree(Ttree root,int data)
{
    if(root==NULL)
        root=new TREE(data);
    else
    {
        if(data<root->data)
            root->lchild=creat_Tree(root->lchild,data);
        if(data>root->data)
            root->rchild=creat_Tree(root->rchild,data);
    }
    return root;
}
bool is_oneTree(Ttree root,Ttree root2)
{
    if(root==NULL&&root2==NULL)
        return true;
    if(root2!=NULL&&root!=NULL)
    {
        if(root->data==root2->data)
        {
            if(is_oneTree(root->lchild,root2->lchild)&&is_oneTree(root->rchild,root2->rchild))
            return true;
        }
    }
    return false;
}
int main()
{
    int n,l,i,data;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        cin>>l;
        Ttree root=NULL;
        for(i=0; i<n; i++)
        {
            cin>>data;
            root=creat_Tree(root,data);
        }
        while(l--)
        {
            Ttree root2=NULL;
            for(i=0; i<n; i++)
            {
                cin>>data;
                root2=creat_Tree(root2,data);
            }
            if(is_oneTree(root,root2))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}

