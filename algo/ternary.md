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

      
