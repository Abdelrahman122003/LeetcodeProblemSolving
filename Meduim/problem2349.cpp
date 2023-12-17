class NumberContainers {
public:
    // mapping betwwen index, number
    unordered_map<int, int>inNum;
    // mapping between number, thier indices 
    unordered_map<int, set<int>>numIndices;
    NumberContainers() {
          ios_base::sync_with_stdio(false); 
          cin.tie(nullptr);                 
          cout.tie(nullptr);
    }
    void change(int index, int number) {
        if(!inNum[index])
            inNum[index] = number;
        else{
          // delete old number
          if(numIndices[inNum[index]].size() == 1)
            numIndices.erase(inNum[index]);
          else
             numIndices[inNum[index]].erase(index);
          inNum[index] = number;
        }
        numIndices[number].insert(index);
    }
    
    int find(int number) {
        return numIndices[number].empty()? -1 : *numIndices[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */