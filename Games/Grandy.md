// dp win lose 
int dp[18][18];
bool rec(int x, int y)
{
    int &ret = dp[x][y];
    if (~ret)
        return ret;
    bool f = false;

    if (x - 2 >= 1 && y + 1 <= 15)
    {
        if (rec(x - 2, y + 1) == 0)
            f = true;
    }
    if (x - 2 >= 1 && y - 1 >= 1)
    {
        if (rec(x - 2, y - 1) == 0)
            f = true;
    }
    if (x + 1 <= 15 && y - 2 >= 1)
    {
        if (rec(x + 1, y - 2) == 0)
            f = true;
    }
    if (x - 1 >= 1 && y - 2 >= 1)
    {
        if (rec(x - 1, y - 2) == 0)
            f = true;
    }

    // Grundy 
    int calcGrundy1(int n) {
  if (n == 0)
    return 0;

  int &ret = grundy[n];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  for (int i = 1; i <= 3; i++)
    if (n >= i)
      sub_nimbers.insert(calcGrundy1(n - i));

  return ret = calcMex(sub_nimbers);
}

int calcGrundy2(int n) {
  if (n == 0)
    return 0;

  int &ret = grundy[n];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;
  int moves[3] = { 2, 3, 6 };

  for (int i = 0; i < 3; i++)
    sub_nimbers.insert(calcGrundy2(n / moves[i]));

  return ret = calcMex(sub_nimbers);
}

///////

int grundy2[120][120];

bool valid(int v) {
  return v >= 0 && v < 8;
}

int calcGrundyChess(int r, int c) {
  int &ret = grundy2[r][c];
  if (ret != -1)
    return ret;

  unordered_set<int> sub_nimbers;

  const int DIR = 4;
  int dr[DIR] = { 1, -1, -2, -2 };
  int dc[DIR] = { -2, -2, 1, -1 };

  for (int d = 0; d < 4; ++d) {
    if (valid(r + dr[d]) && valid(c + dc[d]))
      sub_nimbers.insert(calcGrundyChess(r + dr[d], c + dc[d]));
  }
  return ret = calcMex(sub_nimbers);
}

    return ret = f;
}
