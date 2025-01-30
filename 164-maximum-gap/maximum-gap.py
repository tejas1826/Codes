class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # RADIX SORT
        n,exp = len(nums),1
        sortarr = [0]*n
    
        
        # Constraint: 1<=nums[i]<=10^9
        for _ in range(9):
            b = [0]*10 #Base 10
            
            # Counting Sort
            for i in range(n):
                b[(nums[i]//exp)%10] += 1
            
            for i in range(1,10):
                b[i]+=b[i-1]
            
            #Shift the values
            for i in range(9,0,-1):
                if b[i-1]==0:
                    b[i] = 0
                else:b[i]=b[i-1]
            b[0] = 0

            #Place each element in right place according to their digits
            for i in range(n):
                idx = (nums[i]//exp)%10
                sortarr[b[idx]] = nums[i]
                b[idx]+=1

            nums = list(sortarr)
            exp*=10
  
        res = 0
        for i in range(1,n):
            res = max(res,nums[i]-nums[i-1])
        return res