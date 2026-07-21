class DSU
{
private:
    vector<int> size, parent;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int getPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = getPar(parent[node]);
    }

    void unite(int u, int v)
    {
        int pu = getPar(u);
        int pv = getPar(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv])
            swap(pu, pv);

        parent[pu] = pv;
        size[pv] += size[pu];
    }
    int siz(int n)
    {
        int p = getPar(n);
        return size[p];
    }
};
----------------------------------------------------------------------------------------------------
private:
    vector<int>parent, rank, sz;
    int comp = 0, maxi = 0;
    stack < pair<int, pair<int, int>>>history;
    stack<int>checkpoint;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        sz.assign(n + 1, 1);
        comp = n;
        maxi = 1;
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find_root(int node) {
        if (node == parent[node]) return node;
        return find_root(parent[node]);
    }

    int union_by_rank(int u, int v) {
        int root_u = find_root(u), root_v = find_root(v);
        if (root_u == root_v) return comp;
        comp--;
        if (rank[root_u] > rank[root_v]) {
            history.push({ 0, {root_v, parent[root_v]} });
            parent[root_v] = root_u;
        }
        else {
            history.push({ 0, {root_u, parent[root_u]} });
            parent[root_u] = root_v;
            if (rank[root_u] == rank[root_v]) {
                history.push({ 1, {root_v, rank[root_v]} });
                rank[root_v]++;
            }
        }
        return comp;
    }

    int union_by_size(int u, int v) {
        int root_u = find_root(u), root_v = find_root(v);
        if (root_u == root_v) return comp;
        comp--;
        if (sz[root_u] < sz[root_v]) {
            history.push({ 0, {root_u, parent[root_u]} });
            history.push({ 2, {root_v, sz[root_v]} });
            parent[root_u] = root_v;
            sz[root_v] += sz[root_u];
        }
        else {
            history.push({ 0, {root_v, parent[root_v]} });
            history.push({ 2, {root_u, sz[root_u]} });
            parent[root_v] = root_u;
            sz[root_u] += sz[root_v];
        }
        maxi = max({ maxi, sz[root_v], sz[root_u] });
        return comp;
    }

    void presist() {
        checkpoint.push(history.size());
    }

    int rollback() {
        if (checkpoint.empty()) return comp;
        int check = checkpoint.top();
        checkpoint.pop();
        while (history.size() > check) {
            int type = history.top().first, node = history.top().second.first, last_val = history.top().second.second;
            history.pop();
            if (type == 0) { // parent
                if (parent[node] != node) {
                    comp++;
                }
                parent[node] = last_val;
               
            }
            else if (type == 1) { // rank
                rank[node] = last_val;
            }
            else{ // size
                sz[node] = last_val;
            }
        }
        return comp;
    }

    int unite(int u, int v) {
        return union_by_size(u, v);
    }

    bool are_connected(int u, int v) {
        return find_root(u) == find_root(v);
    }

    int mx_comp() {
        int k = maxi;
        return maxi;
    }

    int get_size(int u) {
        return sz[find_root(u)];
    }

};

pair<int, vector<pair<int, int>>> MST(vector < pair<int, pair<int, int>>> edges, int n) {
    sort(edges.begin(), edges.end());
    vector<pair<int, int>>mst_edges;
    int total = 0;
    DSU d(n);
    for (auto& it : edges) {
        int cost = it.first, u = it.second.first, v = it.second.second;
        if (!d.are_connected(u, v)) {
            d.unite(u, v);
            mst_edges.push_back({ u, v });
            total += cost;
        }
    }
    return { total, mst_edges };
}
