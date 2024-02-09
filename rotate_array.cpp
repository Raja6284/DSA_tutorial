#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void rotate(int arr[], int k,int n) {
        
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
        
    cout<<"Rotated aray is:"<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int k = 5;

    int n = sizeof(arr)/sizeof(arr[0]);

    rotate(arr,k,n);

    return 0;
}