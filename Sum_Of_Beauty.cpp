QUESTION : Given a string S, return the sum of beauty of all its substrings.
The beauty of a string is defined as the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of string "aaac" is 3 - 1 = 2.;

Input:
S = "aaac"
Output:
3
Explanation: The substrings with non - zero beauty are ["aaac","aac"] where beauty of "aaac" is 2 and beauty of "aac" is 1.;

Input:
S = "geeksforgeeks"
Output:
62
Explanation: There are 91 substrings of the given strings. Like, the beauty of substring "geek" is 1. In this way the sum of beauties of all substrings are 62.;


Approach : 
Run 2 loop, Take each letter and Find the maximum and minimum words after it. Make the Difference and add it in answer in every iteration;

CODE::::::::::::::


class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        vector<int> ch(26,0); // To store the count of each letter
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                ch[s[j] - 'a']++;
                int min = INT_MAX, max = INT_MIN;
                for(int k = 0; k < 26; k++)
                {
                    if(ch[k] < min and ch[k] != 0) min = ch[k];
                    if(ch[k] > max) max = ch[k];
                }
                ans+=(max - min);
            }
            for(int y = 0; y < 26; y++) ch[y] = 0; // Making the counter vector 0 to use it in next iteration.
        }
        return ans;
    }
};
