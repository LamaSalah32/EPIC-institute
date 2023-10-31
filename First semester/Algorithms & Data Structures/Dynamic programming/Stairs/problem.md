**problem statement:**

We are standing initially on floor 0, We can climb to the next floor or skip one floor, Each floor has either a penalty or a reward written on it. We need to get to the final step with as much money as possible.

---

**plan:**

1. **_what do you consider a states of dynamic?_**

   dp[i] - max result for the ith floor

2. **_what value of dp do you know?_**

   dp[0] = 0

   dp[1] = a[1]

3. **_what is the order in which dp is counted?_**

   from lower floor to the higher one

4. **_which formula is used to calculate the dp?_**

   dp[i] = max(dp[i-1], dp[i-2]) + a[i]

5. **_what is the answer to our problem?_**

   dp[n-1]
