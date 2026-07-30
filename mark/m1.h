print dp

int rec(int i, int time, int j)
{

    if (time == 0)
        return 0;

    int &ret = dp[i][time][j];
    if (~ret)
        return ret;
    int ch1 = 0, ch2 = 0;

    if (i + 1 < n && time - t[i] >= 0)
        ch1 = rec(i + 1, time - t[i], 0);
    if (j < 203)
        ch2 = rec(i, time - 1, j + 1) + max(0LL, f[i] - (j * d[i]));
    return ret = max(ch1, ch2);
}

void P(int i, int time, int j)
{
    if (time == 0)
        return;

    int stay = rec(i, time - 1, j + 1) + max(0LL, f[i] - j * d[i]);
    int move = -1;

    if (i + 1 < n && time - t[i] >= 0)
        move = rec(i + 1, time - t[i], 0);

    if (stay >= move)
    {
        ans[i] += 5;
        P(i, time - 1, j + 1);
    }
    else
        P(i + 1, time - t[i], 0);
    
}


<<<<<-------------------------------------------------------------------------------------------------------->>>>>

dp mark correct has len less than n

int &ret = dp[i][mask][last + 1];
    if (~ret)
        return ret;
    ret = 0;
    if (__builtin_popcount(mask) == n )
        ret = 1; // mark it correct 

