#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
//�������������ĸ�����
const int direction[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
const char map[4]={'N','S','W','E'};
//�Թ����
typedef struct Maze_
{
    int r;//��
    int c;//��
    bool bVisit;//�Ƿ���ʹ�
    char data;//�������
    char dir;//������㣬���ý��ķ���
    struct Maze_ *pParent;//�����
} Maze;
Maze maze[100][101];
int row;//��
int col;//��
//�����������
bool bfs(int sr,int sc,int er,int ec)
{
    queue<Maze *> qe;
    qe.push(&maze[sr][sc]);
    maze[sr][sc].bVisit=true;
    while(!qe.empty())
    {
        Maze *pM=qe.front();
        qe.pop();
        if(pM->r == er && pM->c == ec)//�����յ�
        {
            return true;
        }
        //������Χ4����
        int r,c;
        for(int i=0;i<4;++i)
        {
        	//������Χ�ĸ����λ��
            r=pM->r + direction[i][0];
            c=pM->c + direction[i][1];
            if(r>=0 && r<row && c>=0 && c<col)//�ж��Ƿ�Խ��
            {
                if(maze[r][c].data=='.' && !maze[r][c].bVisit)//�ж��Ƿ����
                {
                    maze[r][c].bVisit=true;//���Ϊ�Է���
                    maze[r][c].pParent=pM;//��¼���ڵ�
                    maze[r][c].dir=map[i];//��¼����
                    qe.push(&maze[r][c]);//�����
                }
            }
        }
    }
    return false;
}
int main()
{
    char input[101];
    int startr=0,startc=0;
    int endr=0,endc=0;
    while(scanf("%d%d",&row,&col)!=EOF)
    {
        getchar();
        for(int i=0; i<row; ++i)
        {
            gets(input);
            for(int j=0;j<col;++j)
            {
                maze[i][j].data=input[j];
                maze[i][j].bVisit=false;
                maze[i][j].r=i;
                maze[i][j].c=j;
                maze[i][j].pParent=NULL;
                if(input[j] == 'S')//���
                {
                    startr=i;
                    startc=j;
                }
                else if(input[j] == 'E')//�յ�
                {
                    endr=i;
                    endc=j;
                    maze[i][j].data='.';
                }
            }
        }
        if(!bfs(startr,startc,endr,endc))
        {
            puts("Can't eat it!");//�޷�����
        }
        else
        {
        	//��ô��յ㵽����·��,����ջ
            stack<char> st;
            Maze *pM=&maze[endr][endc];
            while(pM != NULL)
            {
                st.push(pM->dir);
                pM=pM->pParent;
            }
            st.pop();//ȥ����һ����ķ���
            //ת��Ϊ����㵽�յ��·��
            int i=0;
            while(!st.empty())
            {
                input[i++]=st.top();
                st.pop();
            }
            input[i]=0;
            puts(input);
        }
    }
    return 0;
}
