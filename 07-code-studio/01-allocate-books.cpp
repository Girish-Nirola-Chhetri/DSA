// the problem is the elemensnts pf an array representa the no of pages of a book.
//Allocate books to m sutdents such thet the maximum pages allocated is minimum and return this min value

#include<iostream>
using namespace std;

bool isPossibleSol( int arr[], int n, int m, int mid ) {
    int studentCount = 1;
    int pageSUm = 0;

    for ( int i = 0; i<n; i++ ) {
        if( pageSUm + arr[i] <= mid ) {
            pageSUm += arr[i];

        }else {
            studentCount++;
            if( studentCount >m || arr[i] > mid ) {
                return false;
            }
            pageSUm = arr[i];
        }
    }
    return true;
}


int allocateBooks(int arr[], int n, int m ) {
    int s=0, ans = -1, sum = 0;
    
    for ( int i = 0; i<n; i++ ) {
        sum += arr[i];
    }

    int e = sum;

    int mid = s + (e - s)/2;
    while ( s<=e ) {
        if( isPossibleSol(arr, n, m, mid )) {
            ans = mid;
            e = mid -1;

        }else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}       



int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elemnets: ";
    for( int i = 0; i<n; i++ ) {
        cin>>arr[i];
    }

    int m;
    cout<<"enter no of students: ";
    cin>>m;

    int val = allocateBooks(arr, n, m );
    cout<<"the minimum val: "<<val;

    return 0;
}