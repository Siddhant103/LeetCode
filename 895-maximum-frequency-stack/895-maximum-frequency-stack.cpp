class FreqStack {
    unordered_map<int, int> m;
    vector<vector<int>> v;
public:
    FreqStack() { }
    
    void push(int x) {
        m[x]++;
        if(v.size()<m[x]){
            vector<int> tempV;
            tempV.push_back(x);
            v.push_back(tempV);
        } else{
            v[m[x]-1].push_back(x);
        }
    }
    
    int pop() {
        int n=v.size();
        n--;
        int x = v[n].back();
        v[n].pop_back();
        if(v[n].size() == 0){
            v.pop_back();
        }
        m[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */