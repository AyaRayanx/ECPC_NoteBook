struct Node
{
    int mn;

    Node()
    {
        mn = 1e16;
    }
    Node(int x)
    {
        mn = x;
    }
    void change(int x)
    {
        mn = x;
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
        ans.mn = min(li.mn, ri.mn);
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

    void set(int idx, int val, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            segdata[ni].change(val);
            return;
        }
        int mid = (lx + rx) / 2;

        if (idx < mid)
            set(idx, val, ni * 2 + 1, lx, mid);
        else
            set(idx, val, ni * 2 + 2, mid, rx);

        segdata[ni] = marge(segdata[ni * 2 + 1], segdata[ni * 2 + 2]);
    }
    void set(int idx, int val)
    {
        set(idx, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx)
    {

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
void solve()
{
    int n;cin >> n; 
    vector<int> v(n);
    cin(v);
    SegTree st = SegTree(n);
    st.init(v);
}
