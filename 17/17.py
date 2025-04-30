class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        l = self.next_letters(digits)
        if len(l) == 1:
            return []
        else:
            return l
        
    def next_letters(self, digits):
        if len(digits) == 0:
            return [""]
        retList = []
        newList = []
        if digits[0] == "2":
            newList = ["a", "b", "c"]
        elif digits[0] == "3":
            newList = ["d", "e", "f"]
        elif digits[0] == "4":
            newList = ["g", "h", "i"]
        elif digits[0] == "5":
            newList = ["j", "k", "l"]
        elif digits[0] == "6":
            newList = ["m", "n", "o"]
        elif digits[0] == "7":
            newList = ["p", "q", "r", "s"]
        elif digits[0] == "8":
            newList = ["t", "u", "v"]
        elif digits[0] == "9":
            newList = ["w", "x", "y", "z"]


        for suffix in self.next_letters(digits[1:]):
            for letter in newList:
                retList.append(letter + suffix)

        return retList
