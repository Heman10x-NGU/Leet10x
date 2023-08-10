class CustomStack {
public:
    vector<int> st;
    int n;
    CustomStack(int maxSize) {
        this->n=maxSize;
    }
    
    void push(int x) {
        if(st.size()>=n){
          return;
        }
        st.push_back(x);
    }
    
    int pop() {
        if(st.size()>0){
          int x=st.back();
          st.pop_back();
          return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int l=st.size();
        for(int i=0;i<min(k,l);i++){
          st[i]+=val;
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