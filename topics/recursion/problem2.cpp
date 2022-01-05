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
                getAns(str,i+1,ans,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> palindromPartition(string str){
        vector<vector<string>> ans;
        vector<string> temp;
        getAns(str,0,ans,temp);
        return ans;
    }
}

namespace rateInMaze{

    vector<vector<int>> visited;
    vector<string> ans;
    string path="";

    void getAns(vector<vector<int>> &maze,int n,int row, int col){
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        // left
        if(col > 0 && visited[row][col-1] == 0 && maze[row][col-1] == 1){
            path += "L";
            visited[row][col]=1;
            getAns(maze,n,row,col-1);
            path = path.substr(0,path.size()-1);
            visited[row][col]=0;
        }
        // right
        if(col < n-1 && visited[row][col+1] == 0 && maze[row][col+1] == 1){
            path += "R";
            visited[row][col] = 1;
            getAns(maze,n,row,col+1);
            path = path.substr(0,path.size()-1);
            visited[row][col]=0;
        }
        // up
        if(row > 0 && visited[row-1][col] == 0 && maze[row-1][col] == 1){
            path += "U";
            visited[row][col] = 1;
            getAns(maze,n,row-1,col);
            path = path.substr(0,path.size()-1);
            visited[row][col]=0;
        }
        //down
        if(row < n-1 && visited[row+1][col] == 0 && maze[row+1][col] == 1){
            path += "D";
            visited[row][col] = 1;
            getAns(maze,n,row+1,col);
            path = path.substr(0,path.size()-1);
            visited[row][col]=0;
        }
    }

    vector<string> solution(vector<vector<int>> maze,int n){
        visited.resize(n,vector<int>(n,0));
        getAns(maze,n,0,0);
        return ans;
    }
}



// SDE sheet problems
/**
 * 1. leetcode 37: soduku solver
 * 2. GFG : subset M-coloring problem (graph)
 * 3. leetcode 60: kth permutation
 */
