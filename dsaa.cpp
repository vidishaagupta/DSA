// 2. Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};

// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

// 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr;
        stringstream ss(path);

        while (getline(ss, curr, '/')) {
            if (curr.empty() || curr == ".")
                continue;

            if (curr == "..") {
                if (!st.empty())
                    st.pop_back();
            } else {
                st.push_back(curr);
            }
        }

        string ans;

        for (string dir : st)
            ans += "/" + dir;

        return ans.empty() ? "/" : ans;
    }
};

// 76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t)
            freq[c]++;

        int left = 0;
        int count = t.size();

        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

// 84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }
};

// 134. Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int tank = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return totalGas < totalCost ? -1 : start;
    }
};

// 135. Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

// 138. Copy List with Random Pointer

/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};

// 143. Reorder List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};

// 160. Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};

// 202. Happy Number

class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

// 239. Sliding Window Maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string curr = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(k);
                stringStack.push(curr);
                curr = "";
                k = 0;
            }
            else if (ch == ']') {
                string temp = curr;
                curr = stringStack.top();
                stringStack.pop();

                int repeat = countStack.top();
                countStack.pop();

                while (repeat--)
                    curr += temp;
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};

// 406. Queue Reconstruction by Height

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> ans;

        for (auto& person : people)
            ans.insert(ans.begin() + person[1], person);

        return ans;
    }
};

// 410. Split Array Largest Sum

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int count = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num <= maxSum) {
                sum += num;
            } else {
                count++;
                sum = num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

// 527. Word Abbreviation

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        vector<string> ans(n);
        vector<int> prefix(n, 1);

        while (true) {
            unordered_map<string, vector<int>> mp;

            for (int i = 0; i < n; i++) {
                string w = words[i];
                if (w.size() <= 3) {
                    ans[i] = w;
                    continue;
                }

                if (prefix[i] >= w.size() - 2) {
                    ans[i] = w;
                } else {
                    ans[i] = w.substr(0, prefix[i]) +
                             to_string(w.size() - prefix[i] - 1) +
                             w.back();
                }

                mp[ans[i]].push_back(i);
            }

            bool unique = true;

            for (auto &it : mp) {
                if (it.second.size() > 1) {
                    unique = false;
                    for (int idx : it.second)
                        prefix[idx]++;
                }
            }

            if (unique) break;
        }

        return ans;
    }
};

// 561. Array Partition

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < nums.size(); i += 2)
            ans += nums[i];

        return ans;
    }
};

// 622. Design Circular Queue

class MyCircularQueue {
    vector<int> q;
    int front, rear, size, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

// 645. Set Mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        int duplicate = -1, missing = -1;

        for (int num : nums)
            freq[num]++;

        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 2)
                duplicate = i;
            else if (freq[i] == 0)
                missing = i;
        }

        return {duplicate, missing};
    }
};

// 763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<int> ans;

        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};

// 852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

// 948. Bag of Tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int left = 0, right = tokens.size() - 1;
        int score = 0, maxScore = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) {
                power += tokens[right--];
                score--;
            }
            else {
                break;
            }
        }

        return maxScore;
    }
};

// 950. Reveal Cards In Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        queue<int> q;
        int n = deck.size();

        for (int i = 0; i < n; i++)
            q.push(i);

        vector<int> ans(n);

        for (int card : deck) {
            int idx = q.front();
            q.pop();

            ans[idx] = card;

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};

// 1029. Two City Scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int n = costs.size() / 2;
        int ans = 0;

        for (int i = 0; i < n; i++)
            ans += costs[i][0];

        for (int i = n; i < 2 * n; i++)
            ans += costs[i][1];

        return ans;
    }
};

// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int target = k * threshold;
        int sum = 0, ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (i >= k)
                sum -= arr[i - k];

            if (i >= k - 1 && sum >= target)
                ans++;
        }

        return ans;
    }
};
