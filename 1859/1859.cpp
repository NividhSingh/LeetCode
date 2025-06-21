class Solution(object):
    def sortSentence(self, s):
        """
        :type s: str
        :rtype: str
        """
        arr = s.split(" ")
        arrNew = [""] * len(arr)

        for a in arr:
            i = int(a[-1])
            a = a[:-1]
            arrNew[i - 1] = a
        return " ".join(arrNew)
