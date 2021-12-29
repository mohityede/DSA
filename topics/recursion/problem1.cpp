#include <iostream>
#include <vector>
using namespace std;

// print 1 to n using recursion
void print_one2N(int num,int n){
    if(num>=n) return;
    cout<<num<<",";
    print_one2N(num+1,n);
}

// print 1 to n using backtracking
void print_one2N_back(int n){
    if(n<=1) return;
    print_one2N_back(--n);
    cout<<n<<",";
}

// print n to 1 using recursion
void print_N2One(int n){
    if(n<1) return;
    cout<<n<<",";
    print_N2One(n-1);
}

// print n to 1 using backtracking
void print_N2One_back(int n,int c){
    if(n<1) return;
    print_N2One_back(n-1,c+1);
    cout<<c<<",";
}

// sum of first N numbers (paramiterized)
void sum_para(int n,int sum=0){
    if(n==0){
        cout<<"sum_para sum is "<<sum<<endl;
        return;
    }
    sum_para(n-1,n+sum);
}

// sum of first N numbers (functional)
int sum_func(int n){
    if(n==0)
        return 0;
    return n+sum_func(n-1);
}

// is string palindrom using recursion
bool isPalindrome(string str,int i){
    int n=str.size();
    if(i >= (n-i-1)) return true;
    if(str[i] != str[n-i-1]) return false;
    return isPalindrome(str,i+1);
}

// reverse the array using recursion
void reverseArr(int *arr,int n, int l, int r){
    if(l >= r) return;
    swap(arr[l],arr[r]);
    reverseArr(arr,n,l+1,r-1);
}