#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
//定义上下左右四个方向
const int direction[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
const char map[4]={'N','S','W','E'};
//迷宫结点
typedef struct Maze_
{
    int r;//行
    int c;//列
    bool bVisit;//是否访问过
    char data;//结点数据
    char dir;//父级结点，到该结点的方向
    struct Maze_ *pParent;//父结点
} Maze;
Maze maze[100][101];
int row;//行
int col;//列
//广度优先搜索
bool bfs(int sr,int sc,int er,int ec)
{
    queue<Maze *> qe;
    qe.push(&maze[sr][sc]);
    maze[sr][sc].bVisit=true;
    while(!qe.empty())
    {
        Maze *pM=qe.front();
        qe.pop();
        if(pM->r == er && pM->c == ec)//到达终点
        {
            return true;
        }
        //遍历周围4个点
        int r,c;
        for(int i=0;i<4;++i)
        {
        	//计算周围四个点的位置
            r=pM->r + direction[i][0];
            c=pM->c + direction[i][1];
            if(r>=0 && r<row && c>=0 && c<col)//判断是否越界
            {
                if(maze[r][c].data=='.' && !maze[r][c].bVisit)//判断是否可走
                {
                    maze[r][c].bVisit=true;//标记为以访问
                    maze[r][c].pParent=pM;//记录父节点
                    maze[r][c].dir=map[i];//记录方向
                    qe.push(&maze[r][c]);//入队列
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
                if(input[j] == 'S')//起点
                {
                    startr=i;
                    startc=j;
                }
                else if(input[j] == 'E')//终点
                {
                    endr=i;
                    endc=j;
                    maze[i][j].data='.';
                }
            }
        }
        if(!bfs(startr,startc,endr,endc))
        {
            puts("Can't eat it!");//无法到达
        }
        else
        {
        	//获得从终点到起点的路径,并入栈
            stack<char> st;
            Maze *pM=&maze[endr][endc];
            while(pM != NULL)
            {
                st.push(pM->dir);
                pM=pM->pParent;
            }
            st.pop();//去掉第一个点的方向
            //转换为从起点到终点的路径
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
