#include <iostream>
#include <vector>
#include "../utils/utils.cpp"
using namespace std;

namespace nQueens{
    bool isSafe(vector<vector<int>> &vec, int row,int col){
        int n=vec.size();
        // copy original row and column
        int rowCopy=row, colCopy=col;
        // check upper left diagonal
        while(row>=0 && col>=0){
            if(vec[row][col] == 1) return false;
            row--;
            col--;
        }

        row = rowCopy;
        col = colCopy;
        // check lower left diagonal
        while(row<n && col >= 0){
            if(vec[row][col] == 1) return false;
            row++;
            col--;
        }

        row = rowCopy;
        col = colCopy;
        // check curr row in left
        while(col>=0){
            if(vec[row][col] == 1) return false;
            col--;
        }
        return true;
    }

    void Nqueens(vector<vector<int>> &vec, int currCol,vector<vector<int>> &ans){
        int n= vec.size();
        if(currCol>=n){
            cout<<"ans:"<<endl;
            printVecto_2d(vec);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(vec,row,currCol)){
                vec[row][currCol]=1;
                Nqueens(vec,currCol+1,ans);
                vec[row][currCol]=0;
            }
        }
    }

}
