#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
class Solution {
public:
    ll count1=0;
    vector<int> temp;
    void merge(vector<int>& nums,int l,int mid,int r)
    {
        int i=l;
        //find first i for which nums[i]>nums[j]
        //since halves are sorted, every other i will be > that particular nums[j] too
        for(int j=mid+1;j<=r;j++)
        {
            while(i<=mid && nums[i]<=nums[j]) i++;
            count1+=(mid-i+1);
        }
        i=l;
        int j=mid+1;
        int k=l;
        while(i<=mid && j<=r)
        {
            if(nums[i]<=nums[j]) temp[k++]=nums[i++];
            else temp[k++]=nums[j++];
        }
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=r) temp[k++]=nums[j++];
        for(int k=l;k<=r;k++) nums[k]=temp[k];
    }
    void mergeSort(vector<int>& nums,int l,int r)
    {
        if(l<r)
        {
            int mid=l+(r-l)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }
    bool isIdealPermutation(vector<int>& nums) {
        //for each j(>i) we need number of elements >nums[j]
        //so total-number of elements <nums[j]
        //ordered_set<pair<ll,int>> st;
        int n=nums.size();
        ll count2=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                count2++;
            }
        }
        /*for(int i=0;i<n;i++)
        {
            count1+=(st.size()-st.order_of_key({nums[i],INT_MAX}));
            st.insert({nums[i],i});
        }*/
        temp.resize(n);
        mergeSort(nums,0,n-1);
        return count1==count2;
    }
};