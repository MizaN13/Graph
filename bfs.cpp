#include <bits/stdc++.h>

using namespace std;

#define Size 1000
vector<int>graph[Size+5];
int dis[Size+5];
queue<int>Q;

void Clear()
{
    for(int i=0; i<Size; i++) {
        graph[i].clear();
    }
}

void bfs(int start)
{
    memset(dis, -1, sizeof(dis));
    dis[start] = 0;
    Q.push(start);
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for(int i=0; i<graph[curr].size() ; i++) {
            int next = graph[curr][i];
            if(dis[next] == -1) {
                dis[next] = dis[curr]+1;
                Q.push(next);
            }
        }
    }

}

int main()
{
    int q, n, m, u, v, s;
    cin >> q;
    while(q--) {
            Clear();
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin >> s;
        bfs(s);
        for(int j=1; j<=n; j++) {
            if(j==s) continue;
            if(dis[j] == -1) {
                cout << "-1" << " ";
            }
            else {
                cout << "6" << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
