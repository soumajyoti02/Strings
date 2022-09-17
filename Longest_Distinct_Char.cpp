QUESTION : Given a string S, find length of the longest substring with all distinct characters. 
  
Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.

S = "aaa"
Output: 1
Explanation: "a" is the longest substring 
with all distinct characters.

  
APPROACH : 
i) Try using a 2 pointer approach. Move the right pointer till you get a repeating character.
  Then, move the left character till you skip the first occurrence of that repeated character.
  
ii) Store the starting index i.e. 0 in a variable i and onGoing index value in j;
iii) Then make a counter variable k and increment it untill a repetitive value is found,.
iv) When such a element is found whose count is > 1; then start moving the i th index untill that repetative element is removed From where it 1st appears.
  
  
  
### CODE BELOW ###
  
  
  
int longestSubstrDistinctChars (string S)
{
    // your code here
    int i = 0, k = 0;
    int j = 0;
    int n = S.size();
    unordered_set<char> st;
    while((i < n) and (j < n))
    {
        if(st.count(S[i]) == 0)
        {
            st.insert(S[i]);
            if(k < st.size()) // If new k is greater than previous then store this new k
            {
                k = st.size();
            }
            i++;
        }
        else
        {
            st.erase(S[j]);
            j++;
        }
    }
    return k;
}
