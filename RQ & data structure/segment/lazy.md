
struct Node
{
    int val, lazy;
    bool islazy;
    Node()
    {
        val = 0;
        lazy = 0;
        islazy = 0;
    }
    Node(int x)
    {
        val = x;
        lazy = 0;
        islazy = 0;
    }
    void update(int x, int lx, int rx)
    {
        val = x * (rx - lx);
        lazy = x;
        islazy = 1;
    }
};

struct SegTree
{

    int tree_size;
    vector<Node> segdata;

    SegTree(int n)
    {
        tree_size = 1;
        while (tree_size < n)
            tree_size *= 2;
        segdata.assign(2 * tree_size, Node());
    }

    Node marge(Node &li, Node &ri) // Do not change in (ri || li) only in ans
    {
        Node ans = Node();
        ans.val = li.val + ri.val;
        return ans;
    }

    void init(vector<int> &arr, int ni, int lx, int rx)
    {

        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                segdata[ni] = Node(arr[lx]);
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);
        segdata[ni] = marge(segdata[2 * ni + 1], segdata[2 * ni + 2]);
    }
    void init(vector<int> &arr)
    {
        init(arr, 0, 0, tree_size);
    }
    void propagate(int ni, int lx, int rx)
    {
        if (rx - lx == 1 || !segdata[ni].islazy)
        {
            return;
        }
        int mid = (lx + rx) / 2;
        segdata[2 * ni + 1].update(segdata[ni].lazy, lx, mid);
        segdata[2 * ni + 2].update(segdata[ni].lazy, mid, rx);
        segdata[ni].lazy = 0;
        segdata[ni].islazy = 0;
    }

    void update(int l, int r, int val, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            segdata[ni].update(val, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        update(l, r, val, 2 * ni + 1, lx, mid);
        update(l, r, val, 2 * ni + 2, mid, rx);
        segdata[ni] = marge(segdata[2 * ni + 1], segdata[2 * ni + 2]);
    }
    void updata(int l, int r, int val)
    {
        update(l, r, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= l && rx <= r)
            return segdata[ni];
        if (lx >= r || rx <= l)
            return Node();

        int mid = (lx + rx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return marge(lf, ri);
    }
    Node get(int l, int r)
    {
        return get(l, r, 0, 0, tree_size);
    }
};
