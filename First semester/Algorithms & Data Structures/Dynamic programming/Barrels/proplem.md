**problem statement:** 

We have three types of barrels - A(safe), B(dangerous), C(very dangerous). We need to put n barrels in a column, We can't put a C barrel on another C barrel.

How many ways are there to put the barrels in?

**EX:**

‘ACBC’ IS A GOOD WAY BUT, ‘ACCA‘ IS NOT

---

**plan:**

SOL 1 (bad)

1. ***what do you consider a states of dynamic?***
    
    dp[i][type] - the number of ways 
    
2. ***what value of dp do you know?***
    
    0: the  first type 
    
    1: the second type 
    
    2: the third type 
    
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1
    
3. ***what is the order in which dp is counted?***
    
    We need to count from 1 to n barrels
    
4. ***which formula is used to calculate the dp?***
    
    **in case j = 0 or j = 1:**
    
    dp[i][j] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2]
    
    **int case j = 2:**
    
    dp[i][j] = dp[i-1][0] + dp[i-1][1]
    
5. ***what is the answer to our problem?***
    
    dp[n][0] + dp[n][1] + dp[n][2]

----

SOL 2
1. ***what do you consider a states of dynamic?***
    
    dp[i] - Number of variants of i barrels arrangement
    
2. ***what value of dp do you know?***
    
    dp[0] = 1 
    
    dp[1] = 3
    
3. ***what is the order in which dp is counted?***
    
    We need to count from 1 to n barrels
    
4. ***which formula is used to calculate the dp?***
    
    dp[i] = 2 * dp[i - 1] +  2 * dp[i - 2]
    
5. ***what is the answer to our problem?***
    
    dp[n]