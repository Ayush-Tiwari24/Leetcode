class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty())left.push(num);
        else{
            if(left.top()>=num){
                left.push(num);
            }
            else right.push(num);
        }
        if(abs((int)left.size()-(int)right.size())>1){
            if(left.size()<right.size()){
                left.push(right.top());
                right.pop();
            }
            else{
                right.push(left.top());
                left.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size())return (left.top()+(double)right.top())/2.0;
        else{
            if(left.size()>right.size())return left.top();
            else return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */