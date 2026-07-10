```
const long long mod = 1e9 + 7;
const int N = 2e5 + 5, lg = 20;

int n, q, m;
int anc[N][lg], level[N];
vector<vector<int>> adj;

void buildAnc(int u, int p) {

    anc[u][0] = p;

    if (u == p)
        level[u] = 0;
    else
        level[u] = level[p] + 1;

    for (int i = 1; i < lg; i++)
        anc[u][i] = anc[anc[u][i - 1]][i - 1];

    for (auto v : adj[u]) {
        if (v != p)
            buildAnc(v, u);
    }
}

// kth ancestor
int kthAnc(int u, int k) {
    for (int i = lg - 1; i >= 0; i--) {
        if ((k >> i) & 1)
            u = anc[u][i];
    }
    return u;
}

// Lowest Common Ancestor
int LCA(int u, int v) {

    if (level[u] < level[v])
        swap(u, v);

    u = kthAnc(u, level[u] - level[v]);

    if (u == v)
        return u;

    for (int i = lg - 1; i >= 0; i--) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0];
}

// distance in number of edges
int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[LCA(u, v)];
}
// if i want to flatting the tree also:
int tin[N], tout[N], timer;
void buildAnc(int u, int p) {

    tin[u] = ++timer;

    anc[u][0] = p;

    if (u == p)
        level[u] = 0;
    else
        level[u] = level[p] + 1;

    for (int i = 1; i < lg; i++)
        anc[u][i] = anc[anc[u][i - 1]][i - 1];

    for (auto v : adj[u]) {
        if (v != p)
            buildAnc(v, u);
    }

    tout[u] = timer;
}
bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}


  
```