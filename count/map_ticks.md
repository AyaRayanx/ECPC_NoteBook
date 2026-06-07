Subarray Sum Divisible by K

void Subarray_Sum_Divisible_by_K()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	cin(v);
	
	map<int, int> mp;
	mp[0] = 1;
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		sum = ((sum +v[i])%k+k)%k;
		ans += mp[sum ];
		mp[sum ]++;
	}
	cout << ans;
}

<<<<<-------------------------------------------------------------------------------------------------------->>>>>
