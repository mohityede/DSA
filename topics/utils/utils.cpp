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

void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}