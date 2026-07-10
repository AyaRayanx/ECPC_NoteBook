```

const int N = 2e5 + 5,LG = 20;     
ll a[N], st[N][LG + 1], Log[N];

ll merge(ll x, ll y) {
    return min(x, y);          // change to max/gcd/...
}

void preCalc() {
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i / 2] + 1;
}

void build() {
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            st[i][k] = merge(
                st[i][k - 1],
                st[i + (1 << (k - 1))][k - 1]
            );
        }
    }
}

// O(1)
// Works for min, max, gcd ...
ll query(int l, int r) {
    int k = Log[r - l + 1];
    return merge(
        st[l][k],
        st[r - (1 << k) + 1][k]
    );
}

// O(log n)
// Works for any associative operation
ll queryLog(int l, int r) {
    ll ans = 0;              
    bool first = true;

    for (int k = LG; k >= 0; k--) {
        if (l + (1 << k) - 1 <= r) {
            if (first) {
                ans = st[l][k];
                first = false;
            } else {
                ans = merge(ans, st[l][k]);
            }
            l += 1 << k;
        }
    }
    return ans;
}


```