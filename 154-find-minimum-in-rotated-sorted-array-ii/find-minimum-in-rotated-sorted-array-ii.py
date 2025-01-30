class Solution:
    def findMin(self, nums: List[int]) -> int:
        res=sorted(nums)
        res1=min(res)
        return res1