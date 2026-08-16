class CustomStack {
public:
    vector<int>v;
    stack<int>st;
    int p;
    int size;
    CustomStack(int maxSize) {
        vector<int>arr(maxSize);
        p=0;
        size=0;
        v=arr;
    }
    
    void push(int x) {
        if(size==v.size())return;
        v[p]=x;
        p++;
        size++;
    }
    
    int pop() {
        if(size==0)return -1;
        size--;
        p--;
        return v[p];
    }
    
    void increment(int k, int val) {
        for(int i=p-1;i>=0;i--){
            st.push(v[i]);
            
        }
        for(int i=1;i<=p;i++){
            if(i<=k){
                v[i-1]=(st.top()+val);
                st.pop();
            }
            else{
                v[i-1]=(st.top());
                st.pop();
            } 
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