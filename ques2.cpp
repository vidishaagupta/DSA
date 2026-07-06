
//Fizz Buzz
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                ans.push_back("FizzBuzz");
            }else if(i%3==0){
                ans.push_back("Fizz");
            }else if(i%5==0){
                ans.push_back("Buzz");
            }else{
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};

//To Lower Case
class Solution {
public:
    string toLowerCase(string s) {
        for(char &ch: s){
            ch=tolower(ch);
        }
        return s;
    }
};

//Defanging an IP Address
class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                ans+="[.]";
            }else{
                ans+=address[i];
            }
        }
        return ans;
    }
};


//Concatenation of Array
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

//Richest Customer Wealth
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n =accounts.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<accounts[i].size();j++){
                sum+=accounts[i][j];
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};

//Shuffle the Array
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        vector<int>ans;
        while(i<n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};

//Find the Highest Altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxi = 0;

        for(int i = 0; i < gain.size(); i++) {

            sum += gain[i];

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};


// Kids With the Greatest Number of Candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> ans;

        int maxi = 0;

        for(int i = 0; i < candies.size(); i++) {
            maxi = max(maxi, candies[i]);
        }

        for(int i = 0; i < candies.size(); i++) {

            if(candies[i] + extraCandies >= maxi) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};


//Build Array from Permutation
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
        
    }
};


// Final Value of Variable After Performing Operations
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(operations[i][1]=='+'){
                x++;
            }else{
                x--;
            }
        }
        return x;
    }
};


//Count the Digits That Divide a Number
class Solution {
public:
    int countDigits(int num) {
        int temp=num;
        int c=0;
        while(num>0){
            int digit=num%10;
            if(temp%digit==0){
                c++;
            }
            num/=10;
        }
        return c;
    }
};