#include<bits/stdc++.h>
#define MAXNODE 1024

using namespace std;

typedef struct TREE
{
    int data;
    struct TREE *lchild,*rchild;
}Tnode,*Tree_Link;
void init_tree(Tree_Link *root);//��ʼ��������
void creat_tree(Tree_Link *root);//����������
void pre_order(Tree_Link root);//��������ݹ�ʵ��
void pre_order_stack(Tree_Link root);//���������ջʵ��
void mid_order(Tree_Link root);//��������ݹ�ʵ��
void mid_order_stack(Tree_Link root);//���������ջʵ��
void pos_order(Tree_Link root);//��������ݹ�ʵ��
void pos_order(Tree_Link root);//���������ջʵ��
void display_leaf(Tree_Link root);//�ݹ����Ҷ�ӽڵ�
void clean_tree(Tree_Link root);//����һ�Ŷ�����
void clean_left_tree(Tree_Link root);//ɾ��������
void clean_right_tree(Tree_Link root);//ɾ��������
void insert_leftnode(Tree_Link root,int data);//��ڵ����
void insert_rightnode(Tree_Link root,int data);//�ҽڵ����
Tree_Link search_data(Tree_Link root,int data);//���ҽ��
int Tree_Height(Tree_Link root);//��������ĸ߶�
int Tree_Leafcount(Tree_Link root);//��Ҷ�ӽ��ĸ���
int Tree_Allcount(Tree_Link root);//�����н��ĸ���


void init_tree(Tree_Link *root)
{
    *root=NULL;
    printf("BINGO!");
}

void creat_tree(Tree_Link *root)
{
    int data;
    cin>>data;
    *root = (Tree_Link)malloc(sizeof(Tnode));
    (*root)->data=data;
    (*root)->lchild=NULL;
    (*root)->rchild=NULL;
}

void pre_order(Tree_Link root)
{
    if(root==NULL)return ;
    printf("%d\n",root->data);
    return pre_order(root->lchild);
    return pre_order(root->rchild);
}

void pre_order_stack(Tree_Link root)
{
    printf("�������,�ǵݹ�ʵ�֣�");
    Tree_Link stacks[MAXNODE],p;
    int top=-1;
    if(root==NULL)return ;
    p=root;
    while(!(p==NULL&&top==-1))
    {
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            stacks[++top]=p;
            p=p->lchild;
        }
        if(top<0)return ;
        p=stacks[top--];
        p=p->rchild;
    }
}


void mid_order(Tree_Link root)
{
    if(root==NULL)return ;
    return mid_order(root->lchild);
    printf("%d\n",root->data);
    return mid_order(root->rchild);
}

void mid_order_stack(Tree_Link root)
{
    printf("�������,�ǵݹ�ʵ�֣�");
    Tree_Link stacks[MAXNODE],p;
    int top=-1;
    if(root==NULL)return ;
    p=root;
    while(!(p==NULL&&top==-1))
    {
        while(p!=NULL)
        {
            stacks[++top]=p;
            p=p->lchild;
        }
        printf("%d\n",p->data);
        if(top<0)return ;
        p=stacks[top--];
        p=p->rchild;
    }
}

void pos_order(Tree_Link root)
{
    if(root==NULL)return ;
    return pre_order(root->lchild);
    return pre_order(root->rchild);
    printf("%d\n",root->data);
}

void mid_order_stack(Tree_Link root)
{
    printf("�������,�ǵݹ�ʵ�֣�");
    Tree_Link stacks[MAXNODE],p;
    int top=-1;
    if(root==NULL)return ;
    p=root;
    while(!(p==NULL&&top==-1))
    {
        while(p!=NULL)
        {
            stacks[++top]=p;
            p=p->lchild;
        }
        if(top<0)return ;
        p=stacks[top--];
        p=p->rchild;
        printf("%d\n",p->data);
    }
}

void display_leaf(Tree_Link root)
{
    if(root==NULL)return ;
    if(root->lchild==NULL&&root->rchild==NULL)
        printf("%-3d",root->data);
    display_leaf(root->lchild);
    display_leaf(root->rchild);
}

void clean_tree(Tree_Link *root)
{
    Tree_Link pl,pr;
    if(*root==NULL)
        return ;
    pl=(*root)->lchild;
    pr=(*root)->rchild;
    (*root)->lchild=NULL;//������ΪʲôҪ�ÿ�
    (*root)->rchild=NULL;//������ΪʲôҪ�ÿ�
    free((*root));
    *root=NULL;//Ϊʲô��Ҫ�ÿ�
    clean_tree(&pl);
    clean_tree(&pr);
}

void clean_left_tree(Tree_Link root)
{
    if(root==NULL)return ;
    clean_tree(&root->lchild);
    root->lchild=NULL;
}


void clean_right_tree(Tree_Link root)
{
    if(root==NULL)return ;
    clean_tree(&root->rchild);
    root->rchild=NULL;
}


void insert_leftnode(Tree_Link root,int data)
{
    if(root==NULL)return ;
    Tree_Link p,newnode;
    p=root->lchild;
    newnode=(Tree_Link)malloc(sizeof(Tnode));
    newnode->data=data;
    newnode->lchild=p;
    newnode->rchild=NULL;
    root->lchild=newnode;
}

void insert_rightnode(Tree_Link root,int data)
{
    if(root==NULL)return ;
    Tree_Link p,newnode;
    p=root->rchild;
    newnode=(Tree_Link)malloc(sizeof(Tnode));
    newnode->data=data;
    newnode->rchild=p;
    newnode->lchild=NULL;
    root->lchild=newnode;
}


Tree_Link search_data(Tree_Link root,int data)
{
    if(root==NULL)
        return NULL;
    if(root->data==data)
        return root;
    return search_data(root->lchild,data);
    return search_data(root->rchild,data);
}

int Tree_Height(Tree_Link root)
{
    int l_Height,r_Height;
    if(root==NULL)
        return 0;
    l_Height=Tree_Height(root->lchild);
    r_Height=Tree_Height(root->rchild);
    return (l_Height>r_Height)?(1+l_Height):(1+r_Height);
}

int Tree_Leafcount(Tree_Link root)
{
    if(root==NULL)return 0;
    if(root->lchild==NULL&&root->rchild==NULL)
        return 1;
    return Tree_Leafcount(root->lchild)+Tree_Leafcount(root->rchild);
}

int Tree_Allcount(Tree_Link root)
{
    if(root==NULL)return 0;
    return Tree_Allcount(root->lchild)+Tree_Allcount(root->rchild)+1;
}
int main()
{
    cout<<"Hello Tree"<<endl;
}
