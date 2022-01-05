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

    void solution1(vector<vector<int>> &vec, int currCol,vector<vector<int>> &ans){
        int n= vec.size();
        if(currCol>=n){
            cout<<"ans:"<<endl;
            vec::print_2d(vec);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(vec,row,currCol)){
                vec[row][currCol]=1;
                solution1(vec,currCol+1,ans);
                vec[row][currCol]=0;
            }
        }
    }

}

namespace palindromPartition{

    bool isPalindrome(string S,int start, int end){
        if(start == end) return true;
        while(start <= end){
            if(S[start] != S[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void getAns(string str,int curr, vector<vector<string>> &ans, vector<string> &temp){
        int n=str.size();
        if(curr >= n){
            ans.push_back(temp);
            return;
        }
        for(int i=curr;i<n;i++){
            if(isPalindrome(str,curr,i)){
                temp.push_back(str.substr(curr,i-curr+1));
                getAns(str,curr+1,ans,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> palindromPartition(string str){
        vector<vector<string>> ans;
        vector<string> temp;
        getAns(str,0,ans,temp);
    }
}


// SDE sheet problems
/**
 * 1. leetcode 37: soduku solver
 * 2. GFG : subset M-coloring problem (graph)
 */
