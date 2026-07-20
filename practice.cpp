//The Tallest Magic Tower
class Solution {
public:
    int findMaxHeight(vector<int>& heights) {
        int n=heights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]);
        }
        return maxi;
    }
};

//Balance of the Binary Archive
class Solution {
public:
    int solve(vector<int>& arr) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int N=arr.size();
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] == 0)
                sum += -1;
            else
                sum += 1;

            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};

//Mystic Merchants and the Golden Ledger
class Solution {
public:
    bool hasSubarraySum(vector<int>& energy, int target) {
        int n = energy.size();

        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += energy[right];

            while (sum > target && left <= right) {
                sum -= energy[left];
                left++;
            }

            if (sum == target)
                return true;
        }

        return false;

    }
};

//Ferris Wheel
class Solution {
public:
    int solve(int n, int x, vector<int>& p) {
        sort(p.begin(), p.end());

        int i = 0;
        int j = n - 1;
        int gondolas = 0;

        while (i <= j) {
            if (p[i] + p[j] <= x) {
                i++;
                j--;
            } else {
                j--;
            }
            gondolas++;
        }

        return gondolas;
    }
};

//The Perfect Duo for the Summer Contest
class Solution {
public:
    bool hasPairWithSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                return true;
            }else if(nums[l]+nums[r]<target){
                l++;
            }else{
                r--;
            }
        }
        return false;

    }
};

//The Grand Total of Sub-Regions
class Solution {
public:
    long long totalSubarraySum(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*arr[i]*(i+1)*(n-i);
        }
        return ans;
    }
};

//The Future Price Predictor
class Solution {
public:
    vector<int> getSuffixMinimums(vector<int>& prices) {
       int n = prices.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(prices[i], suffixMin[i + 1]);
        }

        return suffixMin;
    }
};

//Twin Array Common Elements
class Solution {
public:
    vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m) {
        int l=0;
        int r=0;
        vector<int> ans;
        while(l<n && r<m){
            if(A[l]==B[r]){
                ans.push_back(A[l]);
                l++;
                r++;
            }else if(A[l]<B[r]){
                l++;
            }else{
                r++;
            }
        }
        return ans;
    }
};

//Remove Duplicates from Sorted List
class Solution {
public:

    ListNode* removeDuplicates(
        ListNode* head
    ) {
        ListNode* t=head;
        while(t!=NULL && t->next!=NULL){
            if(t->val == t->next->val){
                t->next=t->next->next;
            }else{
                t=t->next;
            }
        }
        return head;

    }
};
