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
    
