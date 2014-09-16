#include<stdio.h>
#include<stdlib.h>
int maxLength;
typedef struct BiTree
{
	int data;
	int count;
	struct BiTree* left;
	struct BiTree* right;
}BiTree;
void Insert(BiTree** tree,int data)
{
	BiTree* p=*tree;
	if(p)
	{
		if(data==p->data)
		{
			++p->count;
			if(maxLength<p->count)
				maxLength=p->count;
			return;
		}
		else if(data<p->data)
			Insert(&(p->left),data);
		else Insert(&(p->right),data);
	}
	else
	{
		p=(BiTree*)malloc(sizeof(BiTree));
		p->left=p->right=NULL;
		p->data=data;
		p->count=1;
		*tree=p;
	}
}
void Destroy(BiTree* tree)
{
	if(tree)
	{
		if(tree->left==NULL && tree->right==NULL)
		{
			free(tree);
			tree=NULL;
		}
		else
		{
			Destroy(tree->left);
			Destroy(tree->right);
		}
	}
}
int main()
{
	int testCount,i;
	int input,inputLength;
	BiTree* tree=NULL;
	scanf("%d",&testCount);
	while(testCount--)
	{
		maxLength=0;
		scanf("%d",&inputLength);
		for(i=0;i<inputLength;++i)
		{
			scanf("%d",&input);
			Insert(&tree,input);
		}
		printf("%d\n",maxLength);
		Destroy(tree);
	}
	return 0;
}
