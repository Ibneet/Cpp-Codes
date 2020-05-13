#include <bits/stdc++.h>
using namespace std;

void bfs(int**edges,int V,queue <int> Q,bool visited[],vector<int> &vec){
    if(Q.empty()){
        sort(vec.begin(),vec.end());
        vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++){
            cout<<*it<<" ";
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                cout<<endl;
                vec.clear();
                Q.push(i);
                visited[i]=true;
                bfs(edges,V,Q,visited,vec);
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
        vec.push_back(currentV);
        Q.pop();
        bfs(edges,V,Q,visited,vec);
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
    vector<int> vec;
    bfs(edges,V,Q,visited,vec);
    for(int i=0;i<V;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}














