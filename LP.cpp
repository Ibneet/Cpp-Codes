#include<iostream>
using namespace std;
#define NMAX 51

int solve(int n,char cake[NMAX][NMAX],int**visited,int i,int j){
    int ans=0;
    visited[i][j] = 1;
    if(cake[i+1][j]=='1' && visited[i+1][j]==0 && i+1<n){
        ans+=solve(n,cake,visited,i+1,j);
    }
    if(cake[i][j+1]=='1' && visited[i][j+1]==0 && j+1<n){
        ans+=solve(n,cake,visited,i,j+1);
    }
    if(cake[i-1][j]=='1' && visited[i-1][j]==0 && i-1>=0){
        ans+=solve(n,cake,visited,i-1,j);
    }
    if(cake[i][j-1]=='1' && visited[i][j-1]==0 && j-1>=0){
        ans+=solve(n,cake,visited,i,j-1);
    }
    return ans+1;
}

int solve(int n,char cake[NMAX][NMAX]){
    int max=0;
    int ans;
    int**visited = new int*[n];
    for(int i=0;i<n;i++){
        visited[i] = new int[n];
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]=='1' && visited[i][j]==0){
                ans = solve(n,cake,visited,i,j);
                if(ans>max){
                    max = ans;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    char cake[NMAX][NMAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cake[i][j];
        }
    }
    int ans = solve(n,cake);
    cout<<ans<<endl;
    return 0;
}
