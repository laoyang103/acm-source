#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Node_	//������
{
	int data;
	struct Node_ *next;
}Tree;
int treeNodeSize=sizeof(Tree);//����С
//�����в����ַ���
void insert(Tree *pt,char *str)
{
	Tree *p=NULL;
	int index=0;
	if(*str == 0)//�������
	{
		return;
	}
	else
	{
		index=*str-'a';//�����ַ����a��ƫ��ֵ
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
	if(*str == 0)//strΪ���ִ�
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
	Tree *ptree=(Tree*)malloc(treeNodeSize*26);//Ϊa��zÿ���ַ�����һ���ռ�
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
