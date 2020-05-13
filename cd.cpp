#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 50+5;

bool idx[MAXN][MAXN] = {false};


bool dfs(char board[][MAXN],int i, int j, int t) {
  if (idx[i][j] == true) return true;
  idx[i][j] = true;
    if (board[i][j] == board[i-1][j] && t!=2){
        if (dfs(board,i-1,j,1)){
            return true;
        }
    }
    if (board[i][j] == board[i+1][j] && t!=1){
        if (dfs(board,i+1,j,2)){
            return true;
        }
    }
    if (board[i][j] == board[i][j-1] && t!=4){
        if (dfs(board,i,j-1,3)){
           return true;
        }
    }
    if (board[i][j] == board[i][j+1] && t!=3){
        if (dfs(board,i,j+1,4)){
            return true;
        }
    }
  return false;
}

int solve(char board[][MAXN],int n,int m){
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!idx[i][j])
          if (dfs(board,i, j, 0)) {
              return 1;
          }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    char board[MAXN][MAXN];
    memset(board, 0, sizeof(board));
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    cout << solve(board,n,m) << endl;
    return 0;
}

