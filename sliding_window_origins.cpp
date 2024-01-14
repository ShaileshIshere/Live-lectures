#include<iostream>
#include<string.h>
#include<queue>
#include<deque>

using namespace std;

string first_non_repeating(string &str) {
	string ans = "";
	queue<char> q;
    int freq[26] = {0};
    for(int i=0; i<str.length(); ++i) {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);
        
        // answer find karo
        while(!q.empty()) {
            char front_character = q.front();
            if(freq[front_character - 'a'] > 1) {
                // ye answer nhi h
                q.pop();
            }
            else {
                // ye (== 1) wala answer h yehi answer h
                ans += front_character;
                break;
            }
        }
        
        // ager koi bhi character esa nhi h jo single time aya h
        if(q.empty()) {
            ans += "#";
        }
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return ans;
}

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;

        int start = 0;
        for(int i=0; i<gas.size(); ++i) {
            balance += gas[i] - cost[i];
            if(balance < 0) {
                deficit += abs(balance);
                start = i+1;
                balance = 0;
            }
        }
        if(balance - deficit >= 0) {
            return start;
        }
        else {
            return -1;
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // first window ko process krlo
        for(int i=0; i<k; ++i) {
            int element = nums[i];

            // deque ke andar chote elements ko remove krdo
            while(!dq.empty() && element > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // remaining window ko process karlo
        for(int i=k; i<nums.size(); ++i) {
            // ans store krlo
            ans.push_back(nums[dq.front()]);

            // removal
            // ->out of range step
            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }

            // ->chote elements ko remove krdo
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // last window ka ans store krlo
        ans.push_back(nums[dq.front()]);
        return ans;
    }

int main() {

    // first non repeating characters
    // string str = "abcdbacef";
    // first_non_repeating(str);

    // int test_case;
    // cin >> test_case;
    // while(test_case--) {
    //     string str;
    //     cin >> str;
    //     string ans = first_non_repeating(str);
    //     cout << "first non repeating elements are : " << ans << endl;
    // }

    // gas wala question
    // int n;
    // cout << "mention the size of all gases and cost here :-" << endl;
    // cin >> n;
    // vector<int>gas;
    // vector<int>cost;
    // cout << "here mention gas :" << endl;
    // for(int i=0; i<n; i++) {
    //     int x;
    //     cin >> x;
    //     gas.push_back(x);
    // }
    // cout << "here mention cost :" << endl;
    // for(int i=0; i<n; ++i) {
    //     int x;
    //     cin >> x;
    //     cost.push_back(x);
    // }
    // cout << canCompleteCircuit(gas, cost) << " -> this is the point where all traversal is possible" << endl;

    // sliding window maximum
    // int k, n;
    // cout << "enter the size of window : ";
    // cin >> k;
    // cout << "enter the size of vector : ";
    // cin >> n;
    // cout << "enter the array :-" << endl;
    // vector<int> nums(n);
    // for(int i=0; i<n; ++i) {
    //     cin >> nums[i];
    // }
    // vector<int> ans = maxSlidingWindow(nums, k);
    // for(int i=0; i<ans.size(); ++i) {
    //     cout << ans[i] << " "; 
    // }
    // cout << endl;



    return 0;
}