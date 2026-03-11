#include "bits/stdc++.h"
using namespace std;
#define int long long

struct Node {
    vector<pair<int,int>> next;   // 出边 (v , w)
    int a;                        // 需要的能量数量
    int ans = -1;                 // 最早解锁时间
    multiset<int> in;             // 保存最小的 a 个候选到达时间
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;

    vector<Node> node(n);

    // 小根堆，按时间排序
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    // 读取 a[i]
    for(int i=0;i<n;i++){
        cin>>node[i].a;

        // 如果需要能量为0，时间0即可解锁
        if(node[i].a==0)
            pq.push({0,i});
    }

    // 强制刷新器
    while(k--){
        int t,sc;
        cin>>t>>sc;

        while(sc--){
            int id;
            cin>>id;
            id--;

            // 在时间 t 强制解锁（等价于一个候选事件）
            pq.push({t,id});
        }
    }

    // 读边
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;

        node[u].next.push_back({v,w});
    }

    // Dijkstra过程
    while(!pq.empty()){
        auto [t,id]=pq.top();
        pq.pop();

        // 如果已经解锁过，跳过
        if(node[id].ans!=-1)
            continue;

        // 当前节点解锁
        node[id].ans=t;

        // 向外传播能量
        for(auto &edge:node[id].next){

            int v=edge.first;
            int w=edge.second;

            // a[v]==0 的节点已经在初始入队，不需要再维护
            if(node[v].a==0)
                continue;

            // 新的候选到达时间
            int arrive=t+w;

            // 插入候选时间
            node[v].in.insert(arrive);

            // 只保留最小的 a[v] 个时间
            if(node[v].in.size()>node[v].a){
                auto it=prev(node[v].in.end()); // 最大值
                node[v].in.erase(it);
            }

            /*
            当收集到 a[v] 个最小时间时
            第 a[v] 小的时间 = 当前 multiset 中最大的
            */
            if(node[v].in.size()==node[v].a && node[v].ans==-1){
                int unlock_time=*node[v].in.rbegin();
                pq.push({unlock_time,v});
            }
        }
    }

    // 输出答案
    for(int i=0;i<n;i++)
        cout<<node[i].ans<<" ";
    cout<<"\n";

    return 0;
}

