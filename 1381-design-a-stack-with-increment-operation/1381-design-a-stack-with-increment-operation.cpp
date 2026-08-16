class CustomStack {
public:
    vector<int> v;
    stack<int> st;
    int p;
    int size;
    CustomStack(int maxSize) {
        vector<int> arr(maxSize);
        p = 0;
        size = 0;
        v = arr;
    }

    void push(int x) {
        if (size == v.size())
            return;
        v[p] = x;
        p++;
        size++;
    }

    int pop() {
        if (size == 0)
            return -1;
        size--;
        p--;
        return v[p];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, p); i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */