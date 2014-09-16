/*
注：此程序来源于网上，我稍做了修改。
*/
#include <stdio.h>
#include <stdlib.h>

/*
a+b*(c-d)-e/f
*/

typedef struct BinaryTree{/*树结构*/
    struct BinaryTree* leftchild;
    char data;
    struct BinaryTree* rightchild;
}BinaryTree;

//访问结点
void Visit(BinaryTree *p)
{
	printf("%c",p->data);
}
//如果二叉树是动态创建的，则将该函数指针以传入层层遍历对二叉树进行释放。
void Destroy(BinaryTree *p)
{
	free(p);
}

void InOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p));//中序遍历
void PreOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p));//先序遍历
void PostOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p));//后序遍历
void LevelOrderTranverse(BinaryTree *p,void Visit(BinaryTree* p));//层次遍历


void main()
{
    struct BinaryTree* p;
    struct BinaryTree a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;   /*构建a+b*(c-d)-e/f模型开始*/
    p=&a1; /*将根地址记录*/
    a1.data='-';
    a1.leftchild=&a2;
    a1.rightchild=&a3;
    a2.data='+';
    a2.leftchild=&a4;
    a2.rightchild=&a5;
    a3.data='/';
    a3.leftchild=&a6;
    a3.rightchild=&a7;
    a4.data='a';
    a4.leftchild=NULL;
    a4.rightchild=NULL;
    a5.data='*';
    a5.leftchild=&a8;
    a5.rightchild=&a9;
    a6.data='e';
    a6.leftchild=NULL;
    a6.rightchild=NULL;
    a7.data='f';
    a7.leftchild=NULL;
    a7.rightchild=NULL;
    a8.data='b';
    a8.leftchild=NULL;
    a8.rightchild=NULL;
    a9.data='-';
    a9.leftchild=&a10;
    a9.rightchild=&a11;
    a10.data='c';
    a10.leftchild=NULL;
    a10.rightchild=NULL;
    a11.data='d';
    a11.leftchild=NULL;
    a11.rightchild=NULL;  /*构建完毕*/
    printf("InOrder:\n");
    InOrderTraverse(p,Visit);  /*进行中序遍历*/
    printf("\n\nPreOrder:\n");
    PreOrderTraverse(p,Visit);  /*进行先序遍历*/
    printf("\n\nPostOrder:\n");
    PostOrderTraverse(p,Visit);  /*进行后序遍历*/
    printf("\n\nLevelOrder:\n");
    LevelOrderTranverse(p,Visit);
}

void PreOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p))
{
    if(p!=NULL)
    {
        Visit(p);//访问根结点
        PreOrderTraverse(p->leftchild,Visit);//先序遍历左子树
        PreOrderTraverse(p->rightchild,Visit);//先序遍历右子树
    }
}

void InOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p))
{
    if(p!=NULL)
    {
        InOrderTraverse(p->leftchild,Visit);//中序遍历左子树
        Visit(p);//访问根结点
        InOrderTraverse(p->rightchild,Visit);//中序遍历右子树
    }
}

void PostOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p))
{
    if(p!=NULL)
    {
        PostOrderTraverse(p->leftchild,Visit);//后序遍历左子树
        PostOrderTraverse(p->rightchild,Visit);//后序遍历右子树
        Visit(p);//访问根结点
    }
}
void LevelOrderTranverse(BinaryTree *p,void Visit(BinaryTree* p))
{
	BinaryTree* stack[100];
	int stackSize=100;
	int front=0;
	int rear=0;
	if(p!=NULL)
	{
		stack[rear++]=p;
		while(front!=rear)
		{
			//出队
			p=stack[front];
			front=(front+1)%stackSize;
			Visit(p);
			//将其左右孩子入队
			if(p->leftchild)
			{
				stack[rear]=p->leftchild;
				rear=(rear+1)%stackSize;
			}
			if(p->rightchild)
			{
				stack[rear]=p->rightchild;
				rear=(rear+1)%stackSize;
			}
		}
	}
}
