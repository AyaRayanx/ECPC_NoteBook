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
