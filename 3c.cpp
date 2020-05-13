#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int solve(int n,int m,vector<int>u,vector<int>v){
    int count = 0;
    int**edges = new int*[n];
    for(int i=1;i<=n;i++){
        edges[i] = new int[n];
        for(int j=1;j<=n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        edges[u[i]][v[i]] = 1;
        edges[v[i]][u[i]] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edges[i][j]==1){
                for(int k=1;k<=n;k++){
                    if(edges[j][k]==1){
                        if(edges[i][k]==1){
                            count+=1;
                        }
                    }
                }
            }
        }
    }
    return count/6;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>u;
    vector<int>v;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        u.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int ans = solve(n,m,u,v);
    cout<<ans<<endl;
}
 

