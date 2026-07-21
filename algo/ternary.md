ternary

int l = 0, r = 1e9;
    while (r - l > 2)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (calc(m1) > calc(m2))
            l = m1;
        else
            r = m2;
    }

    int ans = 1e18;
    for (int i = l; i <= r; i++)
        ans = min(ans, calc(i));

      <<<<<-------------------------------------------------------------------------------------------------------->>>>>

vector<int> a, b;
 
void rec(int i, int sum, int nn, bool f)
{
    if (i == nn)
    {
        if (f)
            a.push_back(sum);
        else
            b.push_back(sum);
        return;
    }
 
    rec(i + 1, (sum + v[i]) % m, nn, f);
    rec(i + 1, sum, nn, f);
}
main
  rec(0, 0, n / 2, 1);
    rec(n / 2, 0, n, 0);
