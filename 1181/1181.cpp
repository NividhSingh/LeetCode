class Solution(object):
    def beforeAndAfterPuzzles(self, phrases):
        """
        :type phrases: List[str]
        :rtype: List[str]
        """
        phrases_split = []
        phrases_dict = {}
        for i, phrase in enumerate(phrases):
            x = phrase.split()
            phrases_split.append(x)
            if (x[0] in phrases_dict.keys()):
                phrases_dict[x[0]].append(i)
            else:
                phrases_dict[x[0]] = [i]

        ans = []
        for i, phrase in enumerate(phrases_split):
            k = phrase[-1]
            if k in phrases_dict.keys():
                for j in phrases_dict[k]:
                    if j != i:
                        ans.append(phrase + phrases_split[j][1:])
        
        for i in range(len(ans)):
            ans[i] = ' '.join(ans[i])


        ans = list(set(ans))
        ans.sort()
        return ans

