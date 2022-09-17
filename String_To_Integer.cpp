
===========================================================================================================================================================
QUESTION : Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
===========================================================================================================================================================
  
  Input:
str = 123
Output: 123
--------------------------------------------  
  Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
---------------------------------------------
 Approach For Solve this problem is : 

1) Create a Function which return true if that string data is >= 0 and <= 9
2) Inside our main atoi function :

  2.1) Get the string size and store it inside n;
  2.2) Declare res = 0 to convert the string into integer and store in it.
    
  2.3) Declare variable --> sign; [If in starting, - sign is found then it will becomes -ve, otherwise it is +1; we will multiply this to our res
       to onvert the number in negetive if str[0] == '-';
                                   
  2.3) Start a loop FOR i < n; i++ :
                                   
     i) If str[i] is not a number then return -1;
     ii) res = res*10 + (str[i] - '0'); ---> This will extract the numbers from string and continuously converting and adding them in res.
                                   
3) Return sign * res --> If our sign becomes -1 in 2.3 step; then main ans will becomes negetive. Otherwise it remains positive.                                   
  


##### CODE BELOW #####




class Solution{
  public:
    bool isNumericChar(char x) {
        return (x >= '0' && x <= '9')? true: false;
    }
    
    int atoi(string str)
    {
    	int n=str.size();
        if (str == "")
           return 0;
      
        int res = 0;  
        int sign = 1;  
        int i = 0; 
      
     
        if (str[0] == '-')
        {
            sign = -1; // Converting sign into negetive if - is found at the starting point.
            i++;  
        }
      
       
        for (; i<n; i++)
        {
            if (isNumericChar(str[i]) == false)
                return -1; 
            res = res*10 + (str[i] - '0');
        }
      
        // Return result with sign
        
        return sign*res;
    }
};
