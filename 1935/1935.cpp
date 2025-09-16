class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        words = text.split()
        c = 0
        for word in words:
            g = True
            brokenLetters = list(brokenLetters)
            for i in range(len(word)):
                if word[i] in brokenLetters:
                    g = False
                    break

            if g:
                c += 1
        return c
