class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        output = ""
        l = 0
        n = 0
        p = 0
        for i in range(len(s)):
            if s[i] == '(':
                p += 1
            elif s[i] == ')':
                p -= 1
            if p == 0:
                output += s[l + 1:i]
                l = i + 1
        return output
      
