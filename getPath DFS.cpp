#include <bits/stdc++.h>
using namespace std;

void getPath(int**edges,int V,stack<int> s,bool visited[],int v2){
    int flag = 0;
    if(s.empty()){
        return;
    }
    int currentV = s.top();
    if(currentV == v2){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        return;
    }else{
        for(int i=0;i<V;i++){
            if(edges[currentV][i]==1&&visited[i]==false){
                s.push(i);
                flag=1;
                visited[i]=true;
                getPath(edges,V,s,visited,v2);
                return;
            }
        }
    }
    if(flag==0){
        s.pop();
        getPath(edges,V,s,visited,v2);
    }
}

int main(){
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
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    visited[v1] = true;
    stack<int> s;
    s.push(v1);
    getPath(edges,V,s,visited,v2);
    for(int i=0;i<V;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}















