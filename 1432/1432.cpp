class Solution(object):
    def maxDiff(self, num):
        """
        :type num: int
        :rtype: int
        """
        s1 = str(num)
        s2 = str(num)
        if (s1[0] != '1'):
            s1 = int(s1.replace(s1[0], '1'))
        else:
            for i in range(1, len(s1)):
                if (s1[i] != '0' and s1[i] != '1'):
                    s1 = int(s1.replace(s1[i], '0'))
                    break
        for i in range(len(s2)):
            if (s2[i] != '9'):
                s2 = int(s2.replace(s2[i], '9'))
                break
        print(s1)
        print(s2)
        return int(s2) - int(s1)
        
