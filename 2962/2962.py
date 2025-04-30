class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        indecies = []
        maxInt = max(nums)
        for i in range(len(nums)):
            if (nums[i] == maxInt):
                indecies.append(i)

        combs = 0
        for i in range(len(indecies) - k+1):
            if (i == 0):
                combs += (indecies[i]+1) * (len(nums)-indecies[i+k-1])
            else:
                combs += (indecies[i]-indecies[i-1]) * (len(nums)-indecies[i+k-1])
        return combs
