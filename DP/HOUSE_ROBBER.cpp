// ***********************************************
// // recursion and memo:
// ***********************************************
// class Solution {
// public:
// int t[101];
// int slove(vector<int>& nums,int i, int n){
//     if(i>n) return 0;
//     if(t[i]!=-1) return t[i];
//     int steal = nums[i] + slove(nums,i+2,n);
//     int skip = slove(nums,i+1,n);
//     return t[i]=max(steal,skip);
// }
//     int rob(vector<int>& nums) {
//         int n= nums.size();
//         memset(t,-1,sizeof(t));
//         if(n==0) return 0;
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         int steal= slove(nums, 0, n-2);
//           memset(t,-1,sizeof(t));
//         int skip= slove(nums,1,n-1);
//         return max(steal,skip);
//     }
// };
// ***********************************************
// with bottom up
// ***********************************************
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0)
//             return 0;
//         if (n == 1)
//             return nums[0];
//         if (n == 2)
//             return max(nums[0], nums[1]);
//         vector<int> t(n + 1, 0);
//         //    case1 (chose 1st house) 0 to n-1
//         t[0] = 0;
//         for (int i = 1; i <= n - 1; i++) {
//             int skip = t[i - 1];
//             int steal = nums[i - 1] + ((i - 2) >= 0 ? t[i - 2] : 0);
//             t[i] = max(skip, steal);
//         }
//         int res1 = t[n - 1];
//         t.clear();
//         // case2 skip 1st house:
//         t[0] = 0;
//         t[1] = 0;
//         for (int i = 2; i <= n; i++) {
//             int skip = t[i - 1];
//             int steal = nums[i - 1] + ((i - 2) >= 0 ? t[i - 2] : 0);
//             t[i] = max(skip, steal);
//         }
//         int res2 = t[n];
//         return max(res1, res2);
//     }
// };
//***********************************************
// constant time:
// ***********************************************
class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    int prevprev=0;
    int prev=nums[0];
    for(int i=2;i<=n;i++){
        int skip = prev;
        int steal = nums[i-1] + prevprev;
        int temp = max(skip,steal);
        prevprev= prev;
        prev = temp;
    }      
    return prev;
    }
};