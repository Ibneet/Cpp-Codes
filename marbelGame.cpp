// At CodingNinjas, we love to play with marbles. We have many marble games, but the most popular 
// one is “Target Marbles”. Now, our marbles are unique. Each marble has a number on it.
// In Target Marbles, the player is given a number in the starting and this number is called target.
// The player is also given N number of marbles to play with. Now, player has to arrange the 
// marbles in a specific way such that sum of the values of at least one of the continuous subset
// of the arrangement is equal to given target.
// Now, NinjaCoder came to play this game and made an arrangement of marbles. The judges of the 
// game need your help. You have to determine if NinjaCoder has won it or not.

#include<iostream>
#include<string>
using namespace std;
int main() {
    int n;
    int target;
    int start;
    int stop;
    bool targetFound = false;
    cin>>n;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            if(arr[j]<=target){
                sum = sum+arr[j];
                if(sum==target){
                    targetFound = true;
                    stop = j;
                    break;
                }else{
                    targetFound = false;
                }
            }else{
                break;
            }
        }
        start = i;
        if(targetFound == true){
            break;
        }
    }
    string result;
    if(targetFound == true){
        cout<<"true"<<endl;
        for(int i=start;i<=stop;i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}