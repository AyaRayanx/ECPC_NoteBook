```
const int N = 2e5 + 5;

vector<int> adj[N];
int tin[N], tout[N], flat[N];
int value[N];
int timer = 0;

void dfs(int u, int p) {
    tin[u] = ++timer;
    flat[timer] = value[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }

    tout[u] = timer;
}
// flat[i] hase the new value 
// call  it dfs(root,0);
```