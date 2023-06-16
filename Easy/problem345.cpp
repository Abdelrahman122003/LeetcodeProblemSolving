class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        map<char, bool>vowels {{'a', 1}, {'e', 1},
        {'i', 1},
        {'o', 1},
        {'u', 1}
        ,{'A', 1}, {'E', 1},
        {'I', 1},
        {'O', 1},
        {'U', 1}};
        while(left < right){
          if(!vowels[s[left]])left++;
          if(!vowels[s[right]])right--;
          if(vowels[s[left]] && vowels[s[right]]){
            swap(s[left], s[right]);
            left++;right--;
          }
        }
        return s;
    }
};