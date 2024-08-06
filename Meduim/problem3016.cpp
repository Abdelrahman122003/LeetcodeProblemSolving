class Solution {
public:
    int minimumPushes(string word) {
        // make freq array for characters 
        vector<int>letters(26, 0);
            for(auto k : word)
                    letters[k-'a']++;
        // Sort in descending order from greatest to smallest frequency
        sort(letters.rbegin(), letters.rend());
         // Why this sort?
        // For example, to make the character with the greatest frequency require only one key press:
        // The first 8 characters with the greatest frequency need only one press (i.e., from the first push of the button, the selected character appears on your mobile).
        // The second 8 characters require a second press (i.e., from the second push of the button, the selected character appears on your mobile), and so on...
        int i = 1, ans = 0;
        for(; i <= 3;i++)
                for(int j = (i-1)*8; j < i*8;j++)
                        ans += letters[j] * i;
        ans += (letters[24] + letters[25]) * i;
            return ans;
    }
};