/*In Little Flowers Public School, there are many students with same first names. You are given a task to
find the students with same names. You will be given a string comprising of all the names of students and
you have to tell the name and count of those students having same. If all the names are unique, print -1
instead.*/

//To run this code put the following cmd in the terminal: clang++ -std=c++11 /Users/ibneetkaur/Desktop/coding/C+Cpp\ codes/namesFrequency.cpp

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main()
{
    int q=-1;
    string input;
    getline(cin,input);
    vector<string> names;
    string word="";
    input = input+" ";
    for(auto x:input){
        if(x==' '){
            names.push_back(word);
            word="";
        }else{
            word=word+x;
        }
        
    }
    map<string,int> freq;
    for(int k=0;k<names.size();k++){
        freq[names[k]]=freq[names[k]]+1;
        if(freq[names[k]]>1){
            q=1;
        }
    }
    map<string,int>::iterator it;
    if(q==-1){
        cout<<q<<endl;
    }else{
        for(it=freq.begin();it!=freq.end();it++){
            if(it->second>1){
                cout<<it->first<<" "<<it->second<<endl;
            }
        }
    }
    
    
    
    return 0;
}
