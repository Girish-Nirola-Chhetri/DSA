#include<iostream>
#include<deque>
#include<vector>
using namespace std;


int sum( vector<int> arr, int k ) {
    deque<int> max;
    deque<int> min;

    int n = arr.size();
    int sum = 0;

    for( int i = 0; i<k; i++ ) {
        // pop alememnts that are smaller than curr  fornt of queue in max for current window
        while( !max.empty() && arr[max.back()] <= arr[i] ) 
            max.pop_back();

        while( !min.empty() && arr[min.back()] >= arr[i]) 
            min.pop_back();

        // push current element index
        max.push_back( i );
        min.push_back( i );
    }

    sum+= arr[max.front()] + arr[min.front()];

    // process rest of the window
    for( int i = k; i<n; i++ ) {
        while( !max.empty() && i - max.front() >=k  )
            max.pop_front();

        while( !min.empty() && i - min.front() >= k )
            min.pop_front();

        // add current elemet 
        while( !max.empty() && arr[max.back()] <= arr[i]) 
            max.pop_back();

        while( !min.empty() && arr[min.back()] >= arr[i]) 
            min.pop_back();

        min.push_back(i);
        max.push_back(i);

        sum+= arr[max.front()] + arr[min.front()];
    }

    return sum;
}


int main () {

    vector<int> arr = { 2, 5, -1, 7, -3, -1, -2 };
    int k = 4;

    int ans = sum( arr, k );
    cout<< "sum is: "<< ans<<endl;

    return 0;
}