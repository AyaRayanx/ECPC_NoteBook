// Next Element :
    vector<int> next(n+2, 0);
    stack<int> st;
    for (int i = 1; i <= n+1; i++) {
        while (!st.empty() && v[i] > v[st.top()]) {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
