#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vec){
    int n= vec.size();
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void printVecto_2d(vector<vector<int>> vec){
    int n=vec.size();
    int m=vec[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printVector_str(vector<string> vec){
    int n= vec.size();
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}