// qp link: https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-possible-subsets/1?page=1&company=Google&sortBy=latest
/*
Given an array arr[], return the sum of the XOR of all elements for every possible subset of the array. Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

Note: The answer is guaranteed to fit within a 32-bit integer.
*/

// Aproach 1 is simply to generate all the possible subsets which are 2^n in number where n is the number of elements in an array, using backtracking and recursion and then all of their xor into ans. Check the code: -


// User function template for C++
class Solution {
public:
    int add(vector<int> &bit) {
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            if (bit[i] == 1) {
                sum += (1 << i);  // Faster than pow(2, i)
            }
        }
        return sum;
    }

    void Xor(int n, vector<int> &bit) {
        int p = 0;
        while (n) {
            bit[p] ^= (n & 1);  // Directly XORing each bit
            n >>= 1;
            p++;
        }
    }

    void solve(int idx, vector<int> &bit, int n, vector<int> &arr, int &sum) {
        if (idx == n) return;
        
        for (int i = idx; i < n; i++) {
            Xor(arr[i], bit);
            sum += add(bit);
            solve(i + 1, bit, n, arr, sum);
            Xor(arr[i], bit);  // Backtracking (undoing XOR)
        }
    }

    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> bit(32, 0);
        int sum = 0;
        solve(0, bit, n, arr, sum);
        return sum;
    }
};
// tc=o(2^n) hence will not work for larger n (>20)
// to optimize this we need to work with a little math. Xor of same numbers is 0 and different number (0^1=1). So if a particular bit is set, then it will contribute to half of the subsets. Understand more about the problem : https://www.youtube.com/watch?v=LI7YR-bwNYY&t=700s
// check code:-

// User function template for C++
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        vector<int> bit(32,0);
        
        for(int i=0; i<n; i++){
            int temp=arr[i];
            int p=0;
            
            while(temp){
                bit[p]=(bit[p] | (temp & 1));
                
                p++;
                temp>>=1;
            }
        }
        
        int sum=0;
        
        for(int i=0; i<32; i++){
            sum+=(bit[i])*(1<<i)*(1<<(n-1));
        }
        
        return sum;
    }
};
