#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX	100//�������Ľ����

/*******************
�����
ע�⣺������岿�ֵ������������͵�ʱ�򣬲�����һ�·�������
ʹ��ӳ���ϵ����ʹ����0Ԫ�ض�ӦA��������岿�ִ����µĽṹ�塣
********************/
typedef struct TreeNode
{
	int data;//������
	struct TreeNode* next;//ָ����
}TreeNode;

//������
void CreateTree(TreeNode* tree,int* size)
{
	int i;
	int node,next;//��ǰ�����������亢�ӽ�������
	int treeSize;
	TreeNode* pNode=NULL;
	TreeNode* pPrev=NULL;
    printf("�����������\n");
    scanf("%d",&treeSize);
    *size=treeSize;
    printf("����������%d������Ȩֵ\n",treeSize);
    for(i=0;i<treeSize;++i)
    {
    	scanf("%d",&tree[i].data);
    }
    printf("����������ź���ֱ�Ӻ����ţ�-1 -1������\n");
    while(1)
    {
    	scanf("%d%d",&node,&next);
    	if(node==-1 || next==-1)break;
		pNode=tree[node].next;
		pPrev=&tree[node];
		while(pNode)//�ҵ�����β������β������½��
		{
			pPrev=pNode;
			pNode=pNode->next;
		}
		//�����½��
		pNode=(TreeNode*)malloc(sizeof(TreeNode));
		pNode->data=next;
		pNode->next=NULL;
		
		pPrev->next=pNode;
    }
}
//���ʽ��ĺ���
void Visit(int data)
{
	printf("%d ",data);
}
int mark[MAX_VERTEX];//���ĳ���Ƿ񱻷���
//��������������ݹ��ã�
void DFS(TreeNode* tree,int startVertex,void Visit(int data))
{
	TreeNode* pNode=NULL;
	Visit(tree[startVertex].data);//���ʸý��
	mark[startVertex]=1;//���ý����Ϊ�ѷ���
	pNode=tree[startVertex].next;//������һ�����ӵĵ�ַ
	while(pNode)
	{
		if(mark[pNode->data]==0)
			DFS(tree,pNode->data,Visit);
		pNode=pNode->next;
	}
}
//�����������
void DFSTree(TreeNode* tree,int size,void Visit(int data))
{
	int i;
	memset(mark,0,sizeof(mark));
	for(i=0;i<size;++i)
	{
		if(mark[i]==0)//���û�з����������
			DFS(tree,i,Visit);
	}
}
//������
void DestroyTree(TreeNode* tree,int treeSize)
{
	int i;
	TreeNode* pNode=NULL;
	TreeNode* pTemp=NULL;
	for(i=0;i<treeSize;++i)
	{
		pNode=tree[i].next;
		while(pNode)
		{
			pTemp=pNode;
			pNode=pNode->next;
			free(pTemp);
		}
	}
}
int main()
{
	TreeNode tree[MAX_VERTEX];//���岿��
	int treeSize;
	memset(tree,0,sizeof(tree));
	CreateTree(tree,&treeSize);
	DFSTree(tree,treeSize,Visit);
	printf("\n");
	DestroyTree(tree,treeSize);
    return 0;
}
