// count freqency of number in range L,R
map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        mp[v[i]].push_back(i);
auto it1 = lower_bound(all(mp[g]), l);
auto it2 = upper_bound(all(mp[g]), r -1);
int cnt = it2 - it1;
