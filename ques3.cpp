//Rotate image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//Matrix Diagonal Sum
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=mat[i][i];
    
            if(i!=n-i-1){
                s+=mat[i][n-i-1];
            }
        }
        return s;
    }

};

//Transpose Matrix
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i]=matrix[i][j];
            }
        }
        return ans;
    }
};

//Flipping an Image
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++){
            reverse(image[i].begin(), image[i].end());

            for(int j=0;j<n;j++){
                image[i][j]=1-image[i][j];
            }
        }
        return image;
    }
};

//Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int n=matrix.size();
        int m=matrix[0].size();

        int h=n*m-1;

        while(l<=h){
            int mid=(l+h)/2;
            int r=mid/m;
            int c=mid%m;

            if(matrix[r][c]==target){
                return true;
            }else if(matrix[r][c]<target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
    }
};

//Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0=0;
                    }
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<m;j++) matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }
    }
};

//Swap nodes in pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        dummy->next=head;

        while(prev->next!=NULL && prev->next->next!=NULL){
            ListNode* first=prev->next;
            ListNode* sec=prev->next->next;

            first->next=sec->next;
            sec->next=first;
            prev->next=sec;

            prev=first;
        }
        return dummy->next;
    }
};

//Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* del=slow->next;
        slow->next=slow->next->next;
        delete del;
        return head;
    }
};

//Reorder list
class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;


        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* curr = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while(curr != NULL){

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }


        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL){

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

//Spiral matrix
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;

        List<Integer> ans=new ArrayList<>();

        int top=0, left=0;
        int right=m-1, bott=n-1;

        while(top<=bott && left<=right){
            for(int i=left;i<=right;i++){
                ans.add(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bott;i++){
                ans.add(matrix[i][right]);
            }
            right--;

            if(top<=bott){
                for(int i=right;i>=left;i--){
                    ans.add(matrix[bott][i]);
                }
                bott--;
            }

            if(left<=right){
                for(int i=bott;i>=top;i--){
                    ans.add(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;

    }
}

//Evaluate Reverse Polish Notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string it:tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int a=s.top();
                s.pop();

                int b=s.top();
                s.pop();

                if(it=="+"){
                    s.push(a+b);
                }
                if(it=="-"){
                    s.push(b-a);
                }
                if(it=="*"){
                    s.push(a*b);
                }
                if(it=="/"){
                    s.push(b/a);
                }
            }else{
                s.push(stoi(it));
            }
        }
        return s.top();
    }
};

//Min Stack
class MinStack {
public:
    stack<long long> st;
    stack<long long> mn;

    MinStack() {
        
    }
    
    void push(long long value) {
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

