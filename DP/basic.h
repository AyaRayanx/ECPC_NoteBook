LIS

 int n;
    cin>>n;
    vector<int> nums(n), tails;
    cin(nums);
    for (int x : nums)
    {
        auto it = lower_bound(all(tails), x);
        if (it == tails.end())
            tails.push_back(x);
        
        else
            *it = x;
    }
    cout << (int)tails.size();
<<<<<-------------------------------------------------------------------------------------------------------->>>>>
//o(n^2)
int LIS(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}





int LCS(string &a, string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}
<<<<<-------------------------------------------------------------------------------------------------------->>>>>

dp iterative 

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n), dp(N, 0);
    cin(v);
    dp[0] = 1;
    for (auto it : v)
    {
        for (int i = it; i < N; i++)
            dp[i] = (dp[i] + dp[i - it]) %mod;
        // بجيب عدد مرات تكوين العدد X من انك تاخد اي عدد من v[i] 
    }
    cout << dp[x];
}

----------------------
		memo1[0] = 1;
    for (int x : v1)
    {
        for (int i = w; i >= x; i--)
        {
            memo1[i] = (memo1[i] + memo1[i - x]) % mod;
       // بجيب عدد مرات تكوين اي رقم من انك تاخد v[i] مره وحده بس 

        }
    }

<<<<<-------------------------------------------------------------------------------------------------------->>>>>

// knapsack 
int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[W];
}
// unbounded 
int unboundedKnapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = wt[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[W];
}
<<<<<-------------------------------------------------------------------------------------------------------->>>>>

dp digit ootimize tight

int dp[20][4];
string a;
int rec(int i, int rem, int tight)
{
 
    if (i == (int)a.size())
        return 1;
    int &ret = dp[i][rem];
    if (!tight && ~ret)
        return ret;
    ll ans = 0;
 
    int end = 9;
    if (tight)
        end = a[i] - '0';
 
    for (int j = 0; j <= end; j++)
    {
        int x = (j != 0);
        if (rem - x >= 0)
            ans += rec(i + 1, rem - x, tight && (j == end));
    }
 
    if (!tight)
        dp[i][rem] = ans;
    return ans;
}
 
void solve()
{
    int l, r;
    cin >> l >> r;
    ll ans = 0;
    a = to_string(r);
    a = string(19 - a.length(), '0') + a;
    ans += rec(0, 3, 1);
    l--;
    a = to_string(l);
    a = string(19 - a.length(), '0') + a;
 
    ans -= rec(0, 3, 1);
    cout << ans << endl;
}
 
signed main()
{
    memset(dp, -1, sizeof(dp));
    test
    solve();
    return 0;
}
<<<<<-------------------------------------------------------------------------------------------------------->>>>>
// o(n^3)
for (int m = 0; m < (1 << n); m++)
for (int s = m; s; s = (s - 1) & m)
int remaining = m ^ s;
// dp[m] = min(dp[m], dp[s] + dp[remaining]);

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
int n;
vector<vector<int>> cost;
int dp[1<<15][15];

int solve(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return cost[pos][0]; // return to start

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int nxt = 0; nxt < n; nxt++) {
        if (!(mask & (1 << nxt))) {
            ans = min(ans,
                      cost[pos][nxt] +
                      solve(mask | (1 << nxt), nxt));
        }
    }

    return dp[mask][pos] = ans;
}

//. Subset Sum DP
bool subsetSum(vector<int>& a, int target) {
    vector<vector<bool>> dp(a.size()+1, vector<bool>(target+1, false));

    for (int i = 0; i <= a.size(); i++)
        dp[i][0] = true;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i-1])
                dp[i][j] |= dp[i-1][j - a[i-1]];
        }
    }

    return dp[a.size()][target];
}
<<<<<-------------------------------------------------------------------------------------------------------->>>>>

dp sub mask grouping 

vector<long long> dp(total_masks, -1e18); 
    dp[0] = 0; // لو مفيش أرانب، السكور بصفر

    for (int mask = 1; mask < total_masks; mask++) {
        // بنطلع كل الجروبات الأصغر (submasks) من الـ mask الحالي
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            // الباقي من الأرانب اللي لسه متقسمتش في اللفة دي
            int remaining_mask = mask ^ submask;
            
            // معادلة الـ DP
            dp[mask] = max(dp[mask], cost[submask] + dp[remaining_mask]);
        }
    }

    // الإجابة النهائية هي أحسن سكور لما ناخد كل الأرانب (كل الـ bits بواحد)
    cout << dp[total_masks - 1] << "\n";
    
