#include<stdio.h>
#include<stdlib.h>
typedef struct _list
{
	int data;
	struct _list* next;
}List,*PList;
int main()
{
	int n,m,i;
	List lst;//ͷ���
	PList p1,p2;
	scanf("%d%d",&n,&m);
	lst.next=NULL;
	p2=&lst;
	for(i=1;i<=n;++i)//��ʼ������
	{
		p1=(PList)malloc(sizeof(List));
		p1->data=i;
		p2->next=p1;
		p2=p1;
	}
	p2->next=lst.next;
	p2=&lst;
	p1=lst.next;
	i=0;
	while(p1!=p2)
	{
		++i;
		if(i==m)//������m���򽫸ý��ɾ����
		{
			i=0;
			p2->next=p1->next;
			free(p1);
			p1=p2->next;
		}
		else
		{
			p2=p1;		
			p1=p2->next;
		}
	}
	printf("%d",p1->data);
	return 0;
}
