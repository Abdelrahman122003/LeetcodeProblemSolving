class Solution {
public:
        
//         Time complexity : nlog(n)
    map<int, int>m;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
            if(hand.size() % groupSize)
                    return false;
            for(auto k : hand)
                    m[k]++;
            while(m.size() >= groupSize){
                   int v = m.begin()->first;//8
                    for(int i = 0;i < groupSize;i++){
                         if(!m[v+i])
                                    return false;
                            else 
                            {
                                    if(m[v+i] <= 1)
                                            m.erase(v+i);
                                   else 
                                         m[v+i]--;
                            }
                    }
            }
            return m.empty()? true: false;
    }
};

