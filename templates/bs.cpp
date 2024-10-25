#include <bits/stdc++.h>

using namespace std;

int bs(int target, const vector<int> &nums){
    int l=0, r=nums.size()-1, m;
    while(l<=r){
        m=(l+r)/2;
        if(nums[m]<target) l=m+1;
        else if(nums[m]>target) r=m-1;
        else if(nums[m]==target) return m;
    }

    return -1;
}

int main(){

    return 0;
}
