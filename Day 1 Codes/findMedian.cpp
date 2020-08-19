class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > min;
    priority_queue<int> max;
    int i;
    double output;
    /** initialize your data structure here. */
    MedianFinder() {
        i = 0;
        output = 0;
    }
    
    void addNum(int num) {
        if(i % 2 != 0) {
            min.push(num);
            if(max.top() < min.top()) {
                output =  (max.top() + min.top()) / 2.0;
            } else {
                int temp = max.top();
                max.pop();
                max.push(min.top());
                min.pop();
                min.push(temp);
                output = (max.top() + min.top()) / 2.0;
            }
        } else {
            max.push(num);
            if(min.empty()) {
               output = max.top();
            } else if(max.top() < min.top()){
                output = max.top();
            } else {
                int temp = max.top();
                max.pop();
                max.push(min.top());
                min.pop();
                min.push(temp);
                output = max.top();
            }
        }
        i++;
    }
    
    double findMedian() {
        return output;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
