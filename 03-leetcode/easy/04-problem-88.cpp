#include<iostream>
using namespace std;


void merge(int arr1[], int m, int arr2[],int n ) {
    int i = m-1, j = n-1, k = m+n-1;

    while ( i>=0 && j>=0 ) {
        if( arr1[i] > arr2[j] ) {
            arr1[k] = arr1[i];
            i--;

        } else {
            arr1[k] = arr2[j];
            j--;
        }

        k--;
    }

    while ( j>= 0 ) {
        arr1[k] = arr2[j];
        j--, k--;    }
}


int main () {

    int nums1[] = { 1,2,3,0,0,0};
    int nums2[] = { 2,5,6 };

    merge(nums1, 3, nums2, 3);

    for ( int i = 0; i<6; i++ ) {
        cout<<nums1[i]<<" ";

    }

    return 0;
}