#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Node_	//链表结点
{
	int data;
	struct Node_ *next;
}Tree;
int treeNodeSize=sizeof(Tree);//结点大小
//向树中插入字符串
void insert(Tree *pt,char *str)
{
	Tree *p=NULL;
	int index=0;
	if(*str == 0)//插入完毕
	{
		return;
	}
	else
	{
		index=*str-'a';//计算字符相对a的偏移值
		if(pt[index].next==NULL)
		{
			p=(Tree*)malloc(treeNodeSize*26);
			memset(p,0,treeNodeSize*26);
			pt[index].next=p;
		}
		++pt[index].data;
		insert(pt[index].next,str+1);
	}
}
void destroy(Tree *pt)
{
	int i;
	for(i=0;i<26;++i)
	{
		if(pt[i].next != NULL)
		{
			destroy(pt[i].next);
		}
	}
	free(pt);
}
int counter(Tree *pt,char *str)
{
	int index=0;
	if(*str == 0)//str为空字串
	{
		return 0;
	}
	else if(pt == NULL)
	{
		return 0;
	}
	else
	{
		index = *str-'a';
		if(*(str+1)==0)
		{
			return pt[index].data;
		}
		else return counter(pt[index].next,str+1);
	}
}
int main()
{
	char str[128];
	Tree *ptree=(Tree*)malloc(treeNodeSize*26);//为a～z每个字符开辟一个空间
	memset(ptree,0,treeNodeSize*26);
	while(1)
	{
		gets(str);
		if(str[0]==0)break;
		insert(ptree,str);
	}
	while(gets(str) != NULL)
	{
		printf("%d\n",counter(ptree,str));
	}
	destroy(ptree );
	return 0;
}
