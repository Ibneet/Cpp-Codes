/*In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.*/
/*Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99*/

#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;
using namespace std;
int main()
{
    int n,sum,k=1;
    cin>>n;
    multimap<int,string,greater<int> > list;
    string names[n];
    int marks[3];
    for(int i=0;i<n;i++){
        cin>>names[i];
        sum=0;
        for(int j=0;j<3;j++){
            cin>>marks[j];
            sum=sum+marks[j];
        }
        list.insert(make_pair(sum,names[i]));
    }
    multimap<int,string> :: iterator it;
    for(it=list.begin();it!=list.end();it++){
        cout<<k<<" "<<it->second<<" "<<it->first<<endl;
        k++;
    }
    return 0;
}
