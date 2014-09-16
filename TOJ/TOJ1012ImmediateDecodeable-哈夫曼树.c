#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct tree//哈夫曼树结点
{
    struct tree* left;//左孩子
    struct tree* right;//右孩子
}HfTree,*LHfTree;
char arr[1024];//存贮输入的字串
int len;//字串的长度
void Destroy(LHfTree* lh)//释放哈夫曼树
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
int Insert(LHfTree* lh,int i)//向哈夫曼树中插入结点
{
    LHfTree node=NULL;
    if((*lh)==NULL)//如果当前结点为空，则创建该结点。
    {
        node=(LHfTree)malloc(sizeof(HfTree));
        node->left=node->right=NULL;
        *lh=node;
    }
    else if((*lh)->left==NULL && (*lh)->right==NULL)//叶子结点
        return 0;//说明已经存在一组编码，到该结点结束。如果再添加的话就会出现重复的路径。
    if(i>=len)//字符串已经插入完毕
        return 1;
    if(arr[i]=='0')//如果字符为0，则给结点增加左孩子
        return Insert(&((*lh)->left),i+1);
    else if(arr[i]=='1')//增加右孩子
        return Insert(&((*lh)->right),i+1);
    else return 1;//其他情况，未用。
}
int main()
{
    int number=1;//记录组数
    int mark=1;//标记是否可行,1-行，0-不行
    LHfTree head=(LHfTree)malloc(sizeof(HfTree));//哈夫曼树头结点
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
        {//考虑到函数的简便性，将第0个字符特殊处理。
            if(arr[0]=='0')
                mark=Insert(&head->left,1);
            else if(arr[0]=='1')
                mark=Insert(&head->right,1);
        }
    }
    return 0;
}
