class Solution {
public:
    vector<int> findNSE(vector<int>& v) {
        int n = v.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] > v[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findPSE(vector<int>& v) {
        int n = v.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }

        return total;
    }
};