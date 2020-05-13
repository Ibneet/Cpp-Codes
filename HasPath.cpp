#include <iostream>
#include <queue>
using namespace std;

bool bfs(int**edges,int V,queue <int> Q,bool visited[],int end){
    if(Q.empty()){
        return false;
    }
    int currentV = Q.front();
    for(int i=0;i<V;i++){
        if(edges[currentV][i] == 1&&visited[i] == false){
            if(i==end){
                return true;
            }else{
                Q.push(i);
                visited[i] = true;
            }
        }
    }
    Q.pop();
    bool ans=bfs(edges,V,Q,visited,end);
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
    int start,end;
    cin>>start>>end;
    bool visited[V];
    for(int i=1;i<V;i++){
        visited[i] = false;
    }
    visited[start] = true;
    queue <int> Q;
    Q.push(start);
    if(bfs(edges,V,Q,visited,end)){
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














