#include<iostream>
using namespace std;
int n;
int diagonalSum(int n,int**arr){
    int sum = 0;
    int j = 0;
    for(int i=0;i<n;i++){
        sum = sum+arr[i][i];
    }
    for(int i=n-1;i>=0;i--){
        sum = sum+arr[j++][i];
    }
    if(n%2 != 0){
        sum = sum-arr[(n-1)/2][(n-1)/2];
    }
    return sum;
}
int borderSum(int n,int**arr){
    int sum = 0;
    for(int i=0;i<n-1;i++){
        sum = sum+arr[0][i+1]+arr[i+1][0]+arr[i+1][n-1]+arr[n-1][i+1];
    }
    sum = sum-(arr[0][n-1]+arr[n-1][0]+2*arr[n-1][n-1]);
    return sum;
}
int main(){
    int sum = 0;
    cin>>n;
    int**arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    sum = diagonalSum(n,arr);
    sum = sum+borderSum(n,arr);
    cout<<sum<<endl;
	return 0;
}
