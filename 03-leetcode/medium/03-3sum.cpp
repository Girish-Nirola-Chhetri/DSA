#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    for ( int i = 0; i<n-2; i++ ) {
        if( i > 0 && nums[i] == nums[i-1] ) continue;
        int l = i+1;
        int r = n-1;

        while ( l<r ) {
            int sum = nums[i] + nums[l] + nums[r];
            if( sum == 0 ) {
                result.push_back({nums[i], nums[l], nums[r]});

                // skip duplicates
                while ( l<r && nums[l] == nums[l+1] ) i++;
                while( l<r && nums[r] == nums[ r-1 ]) r--;

                l++, r--;

            }else if( sum > 0 ) {
                r--;

            }else {
                l++;
            }
        }
        
    }

    return result;
}

int main () {

    vector<int> nums = {-1, 0, 1,2, -1};
    vector<vector<int>> res = threeSum( nums );

    int n = res.size();
    int m = res[0].size();

    for ( int i = 0; i<n; i++ ) {
        for ( int j = 0; j<m; j++ ) {
            cout<< res[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}