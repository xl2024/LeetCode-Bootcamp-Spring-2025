class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, row0 = 1;
        for(int i = 0; i < matrix.size(); i++)
            if(matrix[i][0] == 0)
                col0 = 0;
        for(int i = 0; i < matrix[0].size(); i++)
            if(matrix[0][i] == 0)
                row0 = 0;
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if(col0 == 0)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        if(row0 == 0)
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
    }
};