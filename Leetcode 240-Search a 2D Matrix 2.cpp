class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int total_cols,total_rows,cur_row,cur_col;
        total_rows=matrix.size();
        if (total_rows!=0) total_cols=matrix[0].size();
        if (total_rows==0 or total_cols==0) return false;
        cur_row=0;
        cur_col=total_cols-1;
        while (cur_row<total_rows and cur_col>=0 ){
            if (matrix[cur_row][cur_col]==target) return true;
            else if (matrix[cur_row][cur_col]<target) cur_row+=1;
            else if (matrix[cur_row][cur_col]>target) cur_col-=1;
        }
        return false;
            
        }

};

//faster than 97%