# Q link->https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans=0
        mod=1000000007
        for i in range(1,n+1):
            b=bin(i)[2:]
            ans=(ans*2**len(b))%mod
            ans=(ans+i)%mod
        return ans    
            
        
