#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void merge(int array[], int left, int mid, int right)
{
    int leftSize = mid - left+1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for(int i=0; i<leftSize; i++){
        leftArr[i] = array[left+i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = array[mid+1+i];
    }

    int i=0;
    int j=0;
    int k = left;

    while(i<leftSize && j<rightSize){
        if(leftArr[i] < rightArr[j]){
            array[k] = leftArr[i];
            i++;
        }
        else{
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i<leftSize)
    {
        array[k] = leftArr[i];
        i++;
        k++;
    }
    while (j<rightSize)
    {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(int array[], int begin, int end){
    if(begin >= end){
        return;
    }

    int mid = begin + (end - begin)/2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);

    merge(array, begin, mid, end);
}

int main(){
    int A[10] = {12, 43, 23, 54, 65, 0, 24, 34, 45, 99};
    int n = 10; //the array size

    mergeSort(A, 0, 9);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << ' ';
    }

    return 0;
}
