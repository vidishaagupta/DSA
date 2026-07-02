//Jump Game 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxInd=0;
        for(int i=0;i<n;i++){
            if(maxInd<i) return false;
            maxInd=max(maxInd,i+nums[i]);
        }
        return true;                         
    }
};


//JUMP GAME 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int l=0;
        int r=0;

        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jump++;
        }
        return jump;
    }
};


//Koko Eating Bananas
class Solution {
public:
    int maximum(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    long long totalhours(vector<int>& piles,int k){
        long long t=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            t += (piles[i] + k - 1) / k;
        }
        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int high=maximum(piles);

        while(l<=high){
            long long mid=l+(high-l)/2;

            long long total=totalhours(piles,mid);
            if(total>h){
                l=mid+1;
            }else{
                high=mid-1;
            }
        }
        return l;
    }
};


//Capacity To Ship Packages Within D Days
class Solution {
public:
    int capacity(vector<int>& arr, int c){
        int day=1;
        int s=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(s+arr[i]>c){
                day++;
                s=arr[i];
            }else{
                s+=arr[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(), arr.end(),0);

        while(l<=h){
            int mid=(l+h)/2;
            if(capacity(arr,mid)<=days){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};

//Valid Parantheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='(' || it=='[' || it=='{'){
                st.push(it);
            }else{
                if(st.empty())return false;
                char ch=st.top();
                st.pop();
                if((ch=='(' && it==')') || (ch=='[' && it==']') || (ch=='{' && it=='}')){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};


//MIN STACK
class MinStack {
public:
    stack<int> st;
    stack<int> mn;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(mn.empty()){
            mn.push(value);
        }else{
            mn.push(min(value,mn.top()));
        }
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};


//Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int c=nums[0];
        int a=nums[0];

        for(int i=1;i<n;i++){
            c=max(nums[i],c+nums[i]);
            a=max(c,a);
        }
        return a;
    }
};

//LINKED LIST IMPLEMENTATION
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insertBeginning(Node* &head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void deleteBeginning(Node* &head) {
    if (head == NULL) {
        cout << "Linked List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

bool search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Linked List is empty\n";
        return;
    }

    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insertBeginning(head, 30);
    insertBeginning(head, 20);
    insertBeginning(head, 10);

    cout << "Linked List: ";
    display(head);

    if (search(head, 20))
        cout << "20 Found\n";
    else
        cout << "20 Not Found\n";

    deleteBeginning(head);

    cout << "After deleting first node: ";
    display(head);

    return 0;
}


//reverse a linked list
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};


//Middle element of Linked List
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
};


//prefix sum
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 1, 6, 3};
    int n = arr.size();

    vector<int> prefix(n);

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    cout << "Prefix Sum Array: ";

    for (int x : prefix)
        cout << x << " ";

    cout << endl;
}


//Find pivot index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }

        int leftsum=0;
        for(int i=0;i<n;i++){
            if(leftsum==t-leftsum-nums[i]){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};


//Running Sum of 1d Array
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};


//Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        int presum=0;
        int c=0;
        mpp[0]=1;

        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            c+=mpp[remove];
            mpp[presum]++;
        }
        return c;
        
    }
};


//Left and Right Sum Differences
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }
        int left=0;
        vector<int> ans;

        for(int i=0;i<n;i++){
            t-=nums[i];
            ans.push_back(abs(left-t));
            left+=nums[i];
        }
        return ans;
    }
};
