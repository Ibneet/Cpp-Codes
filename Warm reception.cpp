/*There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.
She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.*/

/*Input Format :
First line contains the number of customers that will come. Second line contains N space-separated integers which represent the arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.*/

/*8
307 2007 1736 2314 2101 1719 435 2214
400 2100 1800 2359 2200 1800 500 2300*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main() {
    // Write your code here
    int n;
    int chairs=1;
    int people=1;
    cin>>n;
    vector<pair<int,int> > time;
    int at[n];
    int bt[n];
    for(int i=0;i<n;i++){
       cin>>at[i];
    }
    for(int i=0;i<n;i++){
       cin>>bt[i];
    }
    for(int i=0;i<n;i++){
        time.push_back(make_pair(at[i],bt[i]));
    }
    sort(time.begin(),time.end());
    for(int i=0;i<n;i++){
        cout<<time[i].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<time[i].second<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        people=1;
        for(int j=i-1;j>-1;j--){
            if(time[i].first<time[j].second){
                people=people+1;
            }
        }
        if(people>chairs){
            chairs=chairs+1;
        }
    }
    cout<<chairs<<endl;
    return 0;
}
