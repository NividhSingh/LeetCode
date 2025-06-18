class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        for i in range(len(s)):
            for j in range(i, len(s)+1):
                if (s[i:j] == s[j:i:-1]):
                    count += 1

        return count
