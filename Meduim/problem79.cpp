class Solution {
public:
    vector<int>dx{1, -1, 0, 0};
    vector<int>dy{0, 0 , 1, -1};
    bool  checkF(int nx, int ny, vector<vector<char>>& board){
            return nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size(); 
    }
    bool dfs(int i, int j, vector<vector<char>> &board,string word,int  ptr){
           
            if(ptr == word.size())return true;
            
            if(!checkF(i, j , board) || board[i][j] == '0' || word[ptr] != board[i][j])return false;
            char temp =  board[i][j];
//             peek this char 
             board[i][j] = '0';
            for(int k = 0; k < 4;k++){
                   int nx = i + dx[k], ny = j + dy[k];
                      if(dfs(nx, ny, board, word, ptr+1))return true;
            }
//             leave this char
             board[i][j] = temp;
            return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
            for(int i = 0;i < board.size();i++){
                    for(int j = 0;j < board[0].size();j++){
// We will initiate depth-first search (DFS) from any node equal to the first character in the word
// if, during the depth-first search (DFS), a path exists that matches the word, then the word exists, and true is returned
                      if(board[i][j] == word[0])
                            if(dfs(i, j, board, word, 0))return true;
                    }
            }
            
            return false;
            
    }
};