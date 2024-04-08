class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& san) {
        int counterZ = 0, counterO = 0;
        
            for(auto k : s)
                    (k == 0)?counterZ++:counterO++;
            for(int i = 0;i < san.size() ;i++){
                    if(!san[i] && !counterZ)
                            return counterO;
                    else if(san[i] && !counterO)
                            return counterZ;
                    if(!san[i] && counterZ)
                            counterZ--;
                    else if(san[i] && counterO)
                            counterO--;
                    
            }
                   
                return 0;
         }
};