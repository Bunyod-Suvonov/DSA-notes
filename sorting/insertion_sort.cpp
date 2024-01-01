#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int A[10] = {12, 43, 23, 54, 65, 0, 24, 34, 45, 99};
    int n = 10; //the array size

    // insertion sort
    for(int i=1; i<10; i++){
        int key = A[i];
        int j = i-1;
        while (j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;  
    }
    //
    
    for(int i=0; i<n; i++){
        cout << A[i] << ' ';
    }
}
