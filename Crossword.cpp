/*CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA*/

#include<iostream>
using namespace std;
#define N 10

void resetVertical(int x,int y,string grid[],string currentWord,int helperVertical[]){
    int n = currentWord.length();
    for (int i = 0; i < N; i++) {
        if(helperVertical[i]==true){
            grid[i][y]='-';
        }
    }
}
void resetHorizontal(int x,int y,string grid[],string currentWord,int helperHorizontal[]){
    int n = currentWord.length();
    
    for (int i = 0; i < N; i++) {
        if(helperHorizontal[i]==true){
            grid[x][i]='-';
        }
    }
}
void setVertical(int x,int y,string grid[],string currentWord,int helperVertical[]){
    int n = currentWord.length();
    for (int i = 0; i < n; i++) {
        if(grid[x+i][y]=='-'){
            helperVertical[x+i]=1;
        }
        grid[x+i][y]=currentWord[i];
    }
}
void setHorizontal(int x,int y,string grid[],string currentWord,int helperHorizontal[]){
    int n = currentWord.length();
    for (int i = 0; i < n; i++) {
         if(grid[x][y+i]=='-'){
            helperHorizontal[y+i]=1;
        }
        grid[x][y+i]=currentWord[i];
    }
}
bool checkHorizontal(int x,int y,string grid[],string currentWord){
    int n = currentWord.length();
    for (int i = 0; i < n; i++) {
        if (grid[x][y + i] != '-' && grid[x][y + i] != currentWord[i]) {
            return false;
        }
    }
  
    return true;;
}
bool checkVertical(int x, int y,string grid[],string currentWord)
{
    int n = currentWord.length();
    for (int i = 0; i < n; i++) {
        if (grid[x + i][y] != '-' && grid[x + i][y] != currentWord[i]) {
            return false;
        }
    }
    return true;
}

bool solveCrossword(string grid[],vector<string> names,int index){
    if(index>=names.size()){
        return true;
    }
        string word=names[index];
        int n=N-word.length();
        for(int i=0;i<N;i++){
            for(int j=0;j<=n;j++){
                if(checkVertical(j,i,grid,word)){
                    int helperVertical[10]={0};
                    setVertical(j,i,grid,word,helperVertical);
                    if(solveCrossword(grid,names,index+1)){
                        return true;
                    }
                    resetVertical(j,i,grid,word,helperVertical);
                }
            
                if(checkHorizontal(i,j,grid,word)){
                    int helperHorizontal[10]={0};
                    setHorizontal(i,j,grid,word,helperHorizontal);
                    if(solveCrossword(grid,names,index+1)){
                        return true;
                    }
                   
                    resetHorizontal(i,j,grid,word,helperHorizontal);
                }
            }
        }
    
    return false;
    
}

int main() {
    
    // Write your code here
    string grid[N];
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        grid[i]=s;
    }
    string words;
    cin>>words;
    words=words+';';
    vector<string> names;
    string word="";
    for(auto x:words){
        if(x==';'){
            names.push_back(word);
            word="";
        }else{
            word=word+x;
        }
    }
    solveCrossword(grid,names,0);
    for(int i=0;i<N;i++){
           cout<<grid[i]<<endl;
        }
        cout<<endl;
}

