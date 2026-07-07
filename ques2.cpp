
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


//Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        int count = 0;

        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        while(i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

//Make Array Zero by Subtracting Equal Amounts
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                st.insert(nums[i]);
            }
        }

        return st.size();
    }
};


//Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]) != st.end()){
                return true;
            }
            st.insert(nums[i]);
        }

        return false;
    }
};

//Difference Between Element Sum and Digit Sum of an Array
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;

        for(int num : nums){
            elementSum += num;

            while(num > 0){
                digitSum += num % 10;
                num /= 10;
            }
        }

        return abs(elementSum - digitSum);
    }
};


//Number of Good Pairs
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;

        for(int num : nums){
            count += mp[num];
            mp[num]++;
        }

        return count;
    }
};


//Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int c=0;
        int el;

        for(int i=0;i<n;i++){
            if(c==0){
                c++;
                el=nums[i];
            }else if(nums[i]==el){
                c++;
            }else{
                c--;
            }
        }
        return el;
    }
};


//Palindrome Number
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0 || (x%10==0 &&x!=0)){
            return false;
        }

        int rev=0;
        while(x>rev){
            int d=x%10;
            rev=rev*10+d;
            x/=10;
        }
        return (x==rev || x==rev/10);

    }
}


//Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;

        for(string op : operations){

            if(op == "+"){
                int n = scores.size();
                scores.push_back(scores[n-1] + scores[n-2]);
            }
            else if(op == "D"){
                scores.push_back(2 * scores.back());
            }
            else if(op == "C"){
                scores.pop_back();
            }
            else{
                scores.push_back(stoi(op));
            }
        }

        int sum = 0;
        for(int x : scores){
            sum += x;
        }

        return sum;
    }
};


//Crawler Log Folder
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(string log : logs){
            if(log == "../"){
                if(depth > 0)
                    depth--;
            }
            else if(log == "./"){
                continue;
            }
            else{
                depth++;
            }
        }

        return depth;
    }
};



//Convert the Temperature
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double k=celsius+273.15;
        double f=celsius*1.80+32.00;
        ans.push_back(k);
        ans.push_back(f);
        return ans;
    }
};


//Smallest Even Multiple
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0) return n;
        return 2*n;
    }
};


//Jewels and Stones
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;

        for(char ch : jewels){
            st.insert(ch);
        }

        int count = 0;

        for(char ch : stones){
            if(st.find(ch) != st.end()){
                count++;
            }
        }

        return count;
    }
};


//Unique Morse Code Words
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..",
            "--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-",
            "-.--","--.."
        };

        unordered_set<string> st;

        for(string word : words){
            string code = "";

            for(char ch : word){
                code += morse[ch - 'a'];
            }

            st.insert(code);
        }

        return st.size();
    }
};


//First Unique Character in a String
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
        }

        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};


//Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int freq[26]={0};

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            freq[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};


// Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            while(l < r && !isalnum(s[l])){
                l++;
            }

            while(l < r && !isalnum(s[r])){
                r--;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }

            l++;
            r--;

        }
        return true;
    }
};










   
