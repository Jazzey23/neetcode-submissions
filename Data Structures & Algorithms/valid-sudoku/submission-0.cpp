class Solution {

private:

    unordered_set<int> col[9];
    unordered_set<int> row[9];
    unordered_set<int> box[9];



public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int cRow;
        int cCol;
         int num;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                //check col and row
                if(isdigit(board[i][j])){
                    num = board[i][j] - '0';
                }else{
                    continue;
                }
                

                int box_index = (i / 3) * 3 + (j / 3);

                if(col[j].count(num) == 0 && row[i].count(num) == 0 && box[box_index].count(num) == 0){
                    col[j].insert(num);
                    row[i].insert(num);
                    box[box_index].insert(num);
                   
                }else{
                    cout << num << endl;
                    cout << i << j << endl;

                    return false;
                }

                

            }
        }
        return true;
    }


    
};
