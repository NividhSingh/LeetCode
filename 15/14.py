class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        i = 0
        while(i < len(strs[0])):
            c = strs[0][i]
            for j in range(len(strs)):
                if (i >= len(strs[j])):
                    return strs[0][:i]
                if (c != strs[j][i]) :
                    return strs[0][:i]
            i += 1
        return strs[0][:i]
