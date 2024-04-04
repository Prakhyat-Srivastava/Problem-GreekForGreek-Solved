#User function Template for python3

class Solution:
    def sumSubstrings(self, s: str) -> int:
        total_sum = 0
        mod = 10**9 + 7
        n = len(s)
        mul = 1
        for i in range(n - 1, -1, -1):
            total_sum += ((int(s[i]) * mul * (i + 1)) % mod)
            total_sum %= mod
            mul = (mul * 10 + 1) % mod
        return total_sum



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

import sys
sys.setrecursionlimit(10**6)

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = str(input())
        ob=Solution()
        print(ob.sumSubstrings(s))
# } Driver Code Ends