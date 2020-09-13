 #include<bits/stdc++.h>
 using namespace std;

template<typename T>
void printVec(vector<T>& vec)
{
    for(auto v: vec)
        cout<<v<<' ';
    cout<<'\n';
}

template<typename T>
void print2dVec(vector<vector<T>>& vec)
{
    for(vector<T> v: vec)
        printVec(v);
}
vector<vector<int>> threeSum(vector<int>& nums)
{
    // i am assuming it's okay to reuse only as many times as they are already repeated in input
    
    vector<vector<int>> ans;
    if(nums.size()<3)
        return ans;

    
    // O(n^3)
    // first sort it
    // sort(nums.begin(), nums.end()); // assuming altering is allowed, ow make a copy
    
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     while(i>0 && i<nums.size() && nums[i]==nums[i-1]) {i++;}
    //     for(int j = i+1; j < nums.size(); j++)
    //     {
    //         while(j>i+1 && j<nums.size() && nums[j]==nums[j-1]) {j++;}
    //         for(int k = j+1; k < nums.size(); k++)
    //         {
    //             while(k>j+1 && k<nums.size() && nums[k]==nums[k-1]) {k++;}
    //             if(i<j && j<k && k<nums.size() && nums[i]+nums[j]+nums[k]==0)
    //             {
    //                 ans.push_back(vector<int> {nums[i], nums[j], nums[k]});
    //                 cout<<i<<j<<k;
    //             }
    //         }
    //     }
    // }
    
    // O(n^2*log(n))
    map<int,int> nums_dict;
    for(auto i: nums)
        nums_dict[i] += 1

    for()
    return ans;
}


int main()
{
    vector<int> nums {0,0, 0, 0};
    vector<vector<int>> ans = threeSum(nums);
    // print2dVec<int>(ans);
    return 0;
}