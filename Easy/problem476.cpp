class Solution {
public:
    int binaryToDec(string str, int start) {
        int number = 0;
        for (int j = start; j < str.size(); j++) {
                if(str[j] == '1')
                        
            number = (number << 1) | (str[j] == '1');
        }
        return number;
    }

    int findComplement(int num) {
        string binaryStr = "";
        while (num) {
            binaryStr += (num & 1) ? '0' : '1';
            num >>= 1;
        }
        reverse(binaryStr.begin(), binaryStr.end());

        int i = 0;
        while (i < binaryStr.size() && binaryStr[i] == '0') {
            i++;
        }
            int number = 2;
            cout << (number << 1) << endl;
        cout << ((number << 1) | 0) << endl;
            cout << ((number << 1) | 1) << endl;

        return binaryToDec(binaryStr, i);
    }
};
