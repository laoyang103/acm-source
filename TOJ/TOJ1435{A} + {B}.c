#include <stdio.h>
#include <stdlib.h>
//���������
typedef struct BiTree_
{
	int data;
	struct BiTree_ *left,*right;
}BiTree,*PBiTree;

BiTree memoryPool;//�ڴ��
int firstNumber;//�ж��Ƿ��ǵ�һ���������

PBiTree mallocBiNode()//��̬������
{
	PBiTree p=memoryPool.left;
	if(p!=NULL)//���ڴ����ȡ��һ�����
	{
		memoryPool.left=p->left;
	}
	else//���ڴ�����޽��ʱ����ϵͳ�����µĽ��
	{
		p=(PBiTree)malloc(sizeof(BiTree));
	}
	p->left=p->right=NULL;//����ֵ
	return p;
}
void freeTree(PBiTree tree)//�����н�������ڴ��
{
	if(tree != NULL)
	{
		freeTree(tree->left);//����������������ڴ��
		freeTree(tree->right);//����������������ڴ��
		tree->right=NULL;
		tree->left=memoryPool.left;
		memoryPool.left=tree;//����������ڴ��
		tree=NULL;
	}
}
void destroy()//�����ڴ��
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
void insert(PBiTree *pt,int data)//������
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
void LDR(PBiTree tree)//�������������
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
	PBiTree root=NULL;//�����������
	int na,nb;//����A��B��Ԫ�ظ���
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
	destroy();//�����ڴ��
	return 0;
}
