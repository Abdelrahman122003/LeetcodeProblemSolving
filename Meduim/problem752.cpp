class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
            set<string>vis;
            for(auto k : deadends)
            {
                    vis.insert(k);
                    if(k == "0000")
                            return -1;
            }
        vis.insert("0000");
        queue<string>q;
            q.push("0000");
            int l = 0;
           while(!q.empty()){
                   int size = q.size();
                   while(size--){
                          string top = q.front();
                           if(top == target)
                                   return l;
                           q.pop();
//                            get all combinations for every string
//                            0000
//                            first digit -, +  0-> 9, 0 -> 1
                           for(int i = 0;i < 4;i++){
                                  string str = "";
                                  str = top;
                                   // minus 1 form this digit 
                                 if(str[i] == '0')
                                         str[i] = '9';
                                  else
                                          str[i]--;
                                   // Check if the digit has been visited and if it does not exist in the list of deadends.
                                   if(!vis.count(str))
                                           vis.insert(str), q.push(str);
                                   str = top;
                                    // plus 1 to this digit 
                                   if(str[i] == '9')
                                           str[i] = '0';
                                   else
                                           str[i]++;
                                 // Check if the digit has been visited and if it does not exist in the list of deadends.
                                    if(!vis.count(str))
                                           vis.insert(str), q.push(str);
                           }
                   }
                   l++;
           }
            return -1;
    }
};
// Explanation : 
//                                   0000  ---> root 
//               0              0              0            0
//             +/ \-          +/ \-          +/ \-        +/ \-
//           1000  9000     0100 0900      0010 0090    0001 0009
// each node create 8 nodes.



