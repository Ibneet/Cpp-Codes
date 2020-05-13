#include <iostream>
#include <queue>
using namespace std;

bool bfs(int**edges,int V,queue <int> Q,bool visited[]){
    bool ans=true;
    if(Q.empty()){
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                return false;
            }
        }
    }
    else{
        int currentV = Q.front();
        for(int i=0;i<V;i++){
            if(edges[currentV][i] == 1&&visited[i] == false){
                Q.push(i);
                visited[i] = true;
            }
        }
        Q.pop();
        ans=bfs(edges,V,Q,visited);
    }
    if(ans){
        return true;
    }else{
        return false;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int**edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j=0;j<V;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<E;i++){
        int s,e;
        cin>>s>>e;
        edges[s][e] = 1;
        edges[e][s] = 1;
    }
    bool visited[V];
    for(int i=1;i<V;i++){
        visited[i] = false;
    }
    visited[0] = true;
    queue <int> Q;
    Q.push(0);
    if(bfs(edges,V,Q,visited)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    for(int i=0;i<V;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}














