class SmallestInfiniteSet {
public:
    
    SmallestInfiniteSet() {
        for(int i = 1;i <= 1000;i++){
          s.emplace(i);
        }
    }
    int popSmallest() {
        int top = *s.begin();
        s.erase(s.begin());
        return top;
    }
    void addBack(int num){
        s.emplace(num);
    }

    private:
    set<int>s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */