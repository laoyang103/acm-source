/*
ע���˳�����Դ�����ϣ����������޸ġ�
*/
#include <stdio.h>
#include <stdlib.h>

/*
a+b*(c-d)-e/f
*/

typedef struct BinaryTree{/*���ṹ*/
    struct BinaryTree* leftchild;
    char data;
    struct BinaryTree* rightchild;
}BinaryTree;

//���ʽ��
void Visit(BinaryTree *p)
{
	printf("%c",p->data);
}
//����������Ƕ�̬�����ģ��򽫸ú���ָ���Դ���������Զ����������ͷš�
void Destroy(BinaryTree *p)
{
	free(p);
}

void InOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p));//�������
void PreOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p));//�������
void PostOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p));//�������
void LevelOrderTranverse(BinaryTree *p,void Visit(BinaryTree* p));//��α���


void main()
{
    struct BinaryTree* p;
    struct BinaryTree a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;   /*����a+b*(c-d)-e/fģ�Ϳ�ʼ*/
    p=&a1; /*������ַ��¼*/
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
    a11.rightchild=NULL;  /*�������*/
    printf("InOrder:\n");
    InOrderTraverse(p,Visit);  /*�����������*/
    printf("\n\nPreOrder:\n");
    PreOrderTraverse(p,Visit);  /*�����������*/
    printf("\n\nPostOrder:\n");
    PostOrderTraverse(p,Visit);  /*���к������*/
    printf("\n\nLevelOrder:\n");
    LevelOrderTranverse(p,Visit);
}

void PreOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p))
{
    if(p!=NULL)
    {
        Visit(p);//���ʸ����
        PreOrderTraverse(p->leftchild,Visit);//�������������
        PreOrderTraverse(p->rightchild,Visit);//�������������
    }
}

void InOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p))
{
    if(p!=NULL)
    {
        InOrderTraverse(p->leftchild,Visit);//�������������
        Visit(p);//���ʸ����
        InOrderTraverse(p->rightchild,Visit);//�������������
    }
}

void PostOrderTraverse(BinaryTree *p,void Visit(BinaryTree* p))
{
    if(p!=NULL)
    {
        PostOrderTraverse(p->leftchild,Visit);//�������������
        PostOrderTraverse(p->rightchild,Visit);//�������������
        Visit(p);//���ʸ����
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
			//����
			p=stack[front];
			front=(front+1)%stackSize;
			Visit(p);
			//�������Һ������
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
