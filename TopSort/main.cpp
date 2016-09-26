/**
输入：
1
5 10
3 5
1 4
2 5
1 2
3 4
1 4
2 3
1 5
3 5
1 2
*/
#include <iostream>
#include <string.h>
#include <climits>

using namespace std;

class ListDG
{
private:
    // 邻接表中表对应的链表的顶点
    class ENode
    {
        int ivex;           // 该边所指向的顶点的位置
        ENode *nextEdge;    // 指向下一条弧的指针
        friend class ListDG;
    };

    // 邻接表中表的顶点
    class VNode
    {
        int data;          // 顶点信息
        ENode *firstEdge;   // 指向第一条依附该顶点的弧
        friend class ListDG;
    };

private: // 私有成员
    int mVexNum;             // 图的顶点的数目
    int mEdgNum;             // 图的边的数目
    VNode *mVexs;            // 图的顶点数组
public:
    ListDG();
    void print();
    void topsort();
};

ListDG::ListDG()//邻接表建表函数，n代表定点数，m代表边数
{
    cin>>mVexNum>>mEdgNum;
    mVexs = new VNode[mVexNum+1];
    for(int i=1; i<=mVexNum; i++)
    {
        mVexs[i].data = i;
        mVexs[i].firstEdge = nullptr;
    }

    for(int i=0; i<mEdgNum; i++)
    {
        int u,v;
        cin>>u>>v;
        ENode* node = mVexs[u].firstEdge;
        while(node!=nullptr)
        {
            node = node->nextEdge;
        }
        ENode* p=new ENode;
        p->ivex=v;
        p->nextEdge = mVexs[u].firstEdge;
        mVexs[u].firstEdge = p;
    }
}

void ListDG::print()//邻接表打印函数
{
    ENode* node;
    for(int i=1; i<=mVexNum; i++)
    {
        node=mVexs[i].firstEdge;
        while(node!=nullptr)
        {
            cout<<node->ivex<<' ';
            node = node->nextEdge;
        }
        cout<<endl;
    }
}

void ListDG::topsort()
{
    int* indegree = new int[mVexNum+1];
    bool* visited = new bool[mVexNum+1];
    memset(indegree,0,sizeof(int)*(mVexNum+1));
    ENode *p;
    for(int i=1; i<=mVexNum; i++)
    {
        p=mVexs[i].firstEdge;
        while(p!=nullptr)
        {
            indegree[p->ivex]++;
            p=p->nextEdge;
        }
        visited[i] = false;
    }
    int count = mVexNum;
    while(count>0)
    {
        for(int i=1; i<=mVexNum; i++)
        {
            if(indegree[i]==0)
            {
                cout<<i<<' ';
                visited[i] = true;
                count--;
                for(p=mVexs[i].firstEdge; p!=nullptr; p=p->nextEdge)
                {
                    int k=p->ivex;
                    indegree[k]--;
                }
            }
        }
    }
    cout<<endl;
    delete[] indegree;
}

int main()
{
    int num;
    cin>>num;
    for(int k=0; k<num; k++)
    {
        ListDG* dg = new ListDG();
        dg->topsort();
    }
    return 0;
}
