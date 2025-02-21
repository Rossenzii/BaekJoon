#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define RED 1
#define BLUE 2
using namespace std;

vector<int> vect[20001];
int visited[20001];
int V,E;

void BFS(int start){
    visited[start] = RED;
    queue<int> q;
    q.push(start);
    
    while(q.size()!=0){
        int now=q.front();
        q.pop();
        for(int i=0; i<vect[now].size(); i++){
            if(visited[vect[now][i]]==0){
                q.push(vect[now][i]);
                
                if(visited[now]==RED) visited[vect[now][i]]=BLUE;
                else if(visited[now]==BLUE) visited[vect[now][i]] = RED;
            }
        }
    }
}
bool check(){
    for (int i=1; i<=V;i++){
        for(int j=0; j<vect[i].size(); j++){
            if(visited[i]==visited[vect[i][j]])
                return false;
        }
    }
    return true;
}

int main()
{
    int K, u, v;
    cin >> K;

    while (K--)
    {
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            vect[u].push_back(v);
            vect[v].push_back(u);
        }

        //빠짐없이 방문하기 위해 노드 개수만큼 BFS 돌려줘야함
        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
            {
                BFS(i);
            }
        }

        //이분그래프 검사
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";

        memset(visited, 0, sizeof(visited));
        memset(vect, 0, sizeof(vect));
    }
}
