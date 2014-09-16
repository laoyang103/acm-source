#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTEX	100//定义最大的结点数

/*******************
树结点
注意：如果主体部分的数据域不是整型的时候，不能用一下方法。需
使用映射关系（如使数组0元素对应A）或给主体部分创建新的结构体。
********************/
typedef struct TreeNode
{
	int data;//数据域
	struct TreeNode* next;//指针域
}TreeNode;

//创建树
void CreateTree(TreeNode* tree,int* size)
{
	int i;
	int node,next;//当前结点的索引和其孩子结点的索引
	int treeSize;
	TreeNode* pNode=NULL;
	TreeNode* pPrev=NULL;
    printf("请输入结点个数\n");
    scanf("%d",&treeSize);
    *size=treeSize;
    printf("请依次输入%d个结点的权值\n",treeSize);
    for(i=0;i<treeSize;++i)
    {
    	scanf("%d",&tree[i].data);
    }
    printf("请输入结点序号和其直接后继序号（-1 -1结束）\n");
    while(1)
    {
    	scanf("%d%d",&node,&next);
    	if(node==-1 || next==-1)break;
		pNode=tree[node].next;
		pPrev=&tree[node];
		while(pNode)//找到链表尾部，向尾部添加新结点
		{
			pPrev=pNode;
			pNode=pNode->next;
		}
		//创建新结点
		pNode=(TreeNode*)malloc(sizeof(TreeNode));
		pNode->data=next;
		pNode->next=NULL;
		
		pPrev->next=pNode;
    }
}
//访问结点的函数
void Visit(int data)
{
	printf("%d ",data);
}
int mark[MAX_VERTEX];//标记某点是否被访问
//深度优先搜索（递归用）
void DFS(TreeNode* tree,int startVertex,void Visit(int data))
{
	TreeNode* pNode=NULL;
	Visit(tree[startVertex].data);//访问该结点
	mark[startVertex]=1;//将该结点标记为已访问
	pNode=tree[startVertex].next;//获得其第一个孩子的地址
	while(pNode)
	{
		if(mark[pNode->data]==0)
			DFS(tree,pNode->data,Visit);
		pNode=pNode->next;
	}
}
//深度优先搜索
void DFSTree(TreeNode* tree,int size,void Visit(int data))
{
	int i;
	memset(mark,0,sizeof(mark));
	for(i=0;i<size;++i)
	{
		if(mark[i]==0)//如果没有访问则访问它
			DFS(tree,i,Visit);
	}
}
//销毁树
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
	TreeNode tree[MAX_VERTEX];//主体部分
	int treeSize;
	memset(tree,0,sizeof(tree));
	CreateTree(tree,&treeSize);
	DFSTree(tree,treeSize,Visit);
	printf("\n");
	DestroyTree(tree,treeSize);
    return 0;
}
