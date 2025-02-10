#include<bits/stdc++.h>
using namespace std;
 static bool comp(pair<int,int>&a , pair<int,int>&b){
    return a.second <b.second; //inc. order...
 }
 // how many you remove then find like ....then maxium no u can watch movies..
// int slove(vector<pair<int,int>>&movies , int n){
//      sort(movies.begin(),movies.end(),comp);
//     int count = 0;
//     int prevstart = movies[0].first;
//     int prevend = movies[0].second;

//     for(int i=1;i<n;i++){
//         int currstart = movies[i].first;
//         int currend = movies[i].second;
//         if(prevend > currstart){
//           count ++;
//         }
//         else {
//         prevstart = currstart;
//         prevend = currend;
//         }
//     }
//     return count;

// this maximum no movies u can watch .......................................
int slove(vector<pair<int,int>>&movies , int n){
     sort(movies.begin(),movies.end(),comp);
     vector<int>si;
    int count = 1;
    si.push_back(movies[0].second+1);
    int  prevstart = movies[0].first;
    int prevend = movies[0].second;

    for(int i=1;i<n;i++){
        int currstart = movies[i].first;
        int currend = movies[i].second;
        if(prevend <= currstart){
          count ++;  
          si.push_back(movies[i].second);
         prevstart = currstart;
        prevend = currend;
        }
        
    }
    cout<<count;
    for(auto i : si){
        cout<<i;
    }

}
int main(){

    int n;
    cin>>n;
        vector<pair<int,int>>movies(n);
    for(int i=0;i<n;i++){
        cin>>movies[i].first>>movies[i].second;
    }
    slove(movies,n);
    return 0;
}