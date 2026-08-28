class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push(asteroids[i]);
            else if ((asteroids[i] > 0 && st.top() > 0) ||
                     (asteroids[i] < 0 && st.top() < 0))
                st.push(asteroids[i]);
            else if ((asteroids[i] > 0 && st.top() < 0) ||
                     (asteroids[i] < 0 && st.top() > 0)) {
                while (!st.empty() && st.top()>0 && abs(asteroids[i]) > abs(st.top()))
                    st.pop();
                if (st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
                else if (abs(asteroids[i]) == abs(st.top()))
                    st.pop();
            } else
                st.push(asteroids[i]);
        }
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};