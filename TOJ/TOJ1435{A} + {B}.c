#include <stdio.h>
#include <stdlib.h>
//二叉树结点
typedef struct BiTree_
{
	int data;
	struct BiTree_ *left,*right;
}BiTree,*PBiTree;

BiTree memoryPool;//内存池
int firstNumber;//判断是否是第一个输出的数

PBiTree mallocBiNode()//动态分配结点
{
	PBiTree p=memoryPool.left;
	if(p!=NULL)//从内存池中取出一个结点
	{
		memoryPool.left=p->left;
	}
	else//当内存池中无结点时，向系统申请新的结点
	{
		p=(PBiTree)malloc(sizeof(BiTree));
	}
	p->left=p->right=NULL;//赋初值
	return p;
}
void freeTree(PBiTree tree)//将所有结点移入内存池
{
	if(tree != NULL)
	{
		freeTree(tree->left);//将结点左子树移入内存池
		freeTree(tree->right);//将结点右子树移入内存池
		tree->right=NULL;
		tree->left=memoryPool.left;
		memoryPool.left=tree;//将结点移入内存池
		tree=NULL;
	}
}
void destroy()//销毁内存池
{
	PBiTree p=memoryPool.left;
	PBiTree q=NULL;
	while(p != NULL)
	{
		q=p;
		p=p->left;
		free(q);
	}
	memoryPool.left=NULL;
}
void insert(PBiTree *pt,int data)//插入结点
{
	PBiTree p=*pt;
	if(p == NULL)
	{
		p=mallocBiNode();
		p->data=data;
		*pt=p;
	}
	else
	{
		if(data < p->data)insert(&(p->left),data);
		else if(data > p->data)insert(&(p->right),data);
	}
}
void LDR(PBiTree tree)//中序遍历二叉树
{
	if(tree != NULL)
	{
		LDR(tree->left);
		if(firstNumber==1)
		{
			printf("%d",tree->data);
			firstNumber=0;
		}
		else
		{
			printf(" %d",tree->data);
		}
		LDR(tree->right);
	}
}
int main()
{
	PBiTree root=NULL;//二叉树根结点
	int na,nb;//集合A、B的元素个数
	int i;
	int data;
	while(scanf("%d%d",&na,&nb)==2)
	{
		for(i=0;i<na+nb;++i)
		{
			scanf("%d",&data);
			insert(&root,data);
		}
		if(root != NULL)
		{
			firstNumber=1;
			LDR(root);
		}
		printf("\n");
		freeTree(root);
		root=NULL;
	}
	destroy();//销毁内存池
	return 0;
}
