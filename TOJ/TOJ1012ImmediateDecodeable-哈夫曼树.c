#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct tree//�����������
{
    struct tree* left;//����
    struct tree* right;//�Һ���
}HfTree,*LHfTree;
char arr[1024];//����������ִ�
int len;//�ִ��ĳ���
void Destroy(LHfTree* lh)//�ͷŹ�������
{
    if(*lh==NULL)
        return;
    else
    {
        Destroy(&(*lh)->left);
        Destroy(&(*lh)->right);
        free(*lh);
        *lh=NULL;
    }
}
int Insert(LHfTree* lh,int i)//����������в�����
{
    LHfTree node=NULL;
    if((*lh)==NULL)//�����ǰ���Ϊ�գ��򴴽��ý�㡣
    {
        node=(LHfTree)malloc(sizeof(HfTree));
        node->left=node->right=NULL;
        *lh=node;
    }
    else if((*lh)->left==NULL && (*lh)->right==NULL)//Ҷ�ӽ��
        return 0;//˵���Ѿ�����һ����룬���ý��������������ӵĻ��ͻ�����ظ���·����
    if(i>=len)//�ַ����Ѿ��������
        return 1;
    if(arr[i]=='0')//����ַ�Ϊ0����������������
        return Insert(&((*lh)->left),i+1);
    else if(arr[i]=='1')//�����Һ���
        return Insert(&((*lh)->right),i+1);
    else return 1;//���������δ�á�
}
int main()
{
    int number=1;//��¼����
    int mark=1;//����Ƿ����,1-�У�0-����
    LHfTree head=(LHfTree)malloc(sizeof(HfTree));//��������ͷ���
	head->left=head->right=NULL;
    while(scanf("%s",arr)!=EOF)
    {
        len=strlen(arr);
        if(strcmp(arr,"9")==0)
        {
            if(mark)
                printf("Set %d is immediately decodable\n",number);
            else
                printf("Set %d is not immediately decodable\n",number);
            number++;
			mark=1;
            Destroy(&(head->left));
            Destroy(&(head->right));
        }
        else if(mark)
        {//���ǵ������ļ���ԣ�����0���ַ����⴦��
            if(arr[0]=='0')
                mark=Insert(&head->left,1);
            else if(arr[0]=='1')
                mark=Insert(&head->right,1);
        }
    }
    return 0;
}
