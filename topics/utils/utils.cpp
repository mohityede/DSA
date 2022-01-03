#include <iostream>
#include <vector>
using namespace std;

namespace vec{
    void print(vector<int> vec){
        int n= vec.size();
        for(int i=0;i<n;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

    void print_2d(vector<vector<int>> vec){
        int n=vec.size();
        int m=vec[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void print_str(vector<string> vec){
        int n= vec.size();
        for(int i=0;i<n;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
}

namespace array{
    void print(int *arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}