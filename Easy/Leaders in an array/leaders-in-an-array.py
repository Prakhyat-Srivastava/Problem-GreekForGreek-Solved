class Solution:
    #Back-end complete function Template for Python 3
    
    #Function to find the leaders in the array.
    def leaders(self, A, N):
        # Initialize the rightmost element as leader
        leader = A[N-1]
        # Initialize the list of leaders with the rightmost element
        leaders = [leader]
        
        # Traverse the array from right to left
        for i in range(N-2, -1, -1):
            # If the current element is greater than the current leader
            if A[i] >= leader:
                # Update the leader
                leader = A[i]
                # Add the new leader to the list of leaders
                leaders.append(leader)
        
        # Reverse the list of leaders to maintain the original order
        leaders = leaders[::-1]
        
        return leaders


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


    
def main():
    
    T=int(input())
    
    while(T>0):
        
        
        N=int(input())
        
        A=[int(x) for x in input().strip().split()]
        obj = Solution()
        
        A=obj.leaders(A,N)
        
        for i in A:
            print(i,end=" ")
        print()
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends