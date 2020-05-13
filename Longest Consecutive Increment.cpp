/*You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.*/
/*Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 */
/*Sample Input 2 :
7
3 7 2 1 9 8 1*/
/*Sample Input 3 :
7
15 24 23 12 19 11 16*/

#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]=-1;
    }
    for(int i=0;i<n;i++){
        if(m[arr[i]]==-1){
            m[arr[i]]=i;
        }
    }
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<n;i++){
        arr1.push_back(arr[i]);
    }
    sort(arr,arr+n);
    arr2.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            arr2.push_back(arr[i]);
        }
    }
    int count=1;
    vector<int> ans;
    multimap<int,int> rec;
    for(int i=0;i<n;i++){
        if(arr2[i+1]==arr2[i]+1){
            count=count+1;
        }else{
            rec.insert(make_pair(count,i-count+1));
            count=1;
        }
    }
    multimap<int,int> :: iterator it;
    it = rec.end();
    --it;
    int k=it->first;
    int b=m[arr2[it->second]];
    int start = arr1[b];
    while(it->first==k&&it!=rec.begin()){
        it--;
        if(b>m[arr2[it->second]]&&it->first==k){
            b=m[arr2[it->second]];
            start=arr1[b];
        }
    }
    if(it->first<k){
        it++;
    }
    auto itr=find(arr2.begin(),arr2.end(),start);
    int ind=distance(arr2.begin(),itr);
    int till=ind+it->first;
    for(int i=ind;i<till;i++){
        ans.push_back(arr2[i]);
    }
    return ans;
}

int main()
{
    int size;
    cin>>size;
    vector<int> ans;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    ans=longestConsecutiveIncreasingSequence(arr,size);
    vector<int> :: iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}

