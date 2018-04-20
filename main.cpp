#include <bits/stdc++.h>

using namespace std;

#define SIZE 1010

vector<int>graph[SIZE+5];
int vis[SIZE+5], s[SIZE+5], dis[SIZE+5];

void CLEAR()
{
    for(int i=0; i<SIZE; i++) {
        graph[i].clear();
    }
}

int dfs(int curr)
{
    //memset(vis, 0, sizeof(vis));
    vis[curr]=1;
    dis[curr]++;
    for(int i=0; i<graph[curr].size(); i++) {
        int next = graph[curr][i];
        if(!vis[next]) {
            dfs(next);
        }
    }
}


int main()
{
    int tCase, t=1, K, N, M, p, u, v;
    cin >> tCase;
    while(tCase--) {
        CLEAR();
        memset(dis, 0, sizeof(dis));
        cin >> K >> N >> M;
        for(int i=1; i<=K; i++) {
            cin >> s[i];
            //r[s[i]]++;
        }
        for(int j=1; j<=M; j++) {
            cin >> u >> v;
            graph[u].push_back(v);
        }
        for(int i=1; i<=K; i++) {
            memset(vis, 0, sizeof(vis));
            dfs(s[i]);
        }
        int cnt=0;
        for(int i=1; i<=N; i++) {
            if(dis[i]>=K) {
                cnt++;
            }
        }
        cout << "Case " << t++ << ": "  << cnt << endl;
    }
    return 0;
}
