class Solution {
public:

    int compareVersion(string version1, string version2) {
           int j = 0,k = 0;
            // int mx = max(version1.size(), version2.size());
            while(j < version1.size() || k < version2.size()){
                   int x = 0, y = 0;
                   while(j < version1.size() && version1[j] != '.')
                           x = x*10 + (version1[j] - '0'), j++;
                    if(j+1 < version1.size())j++;
                     while(k < version2.size() && version2[k] != '.')
                           y = y*10 + (version2[k] - '0'), k++;
                    if(k+1 < version2.size())k++;
                  if(x > y)
                          return 1;
                    else if(x < y)
                            return -1;
           }
            return 0;
    }
};
