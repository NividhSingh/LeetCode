class Solution(object):
    def pushDominoes(self, dominoes):
        dominoes = list(dominoes)  # Convert to a list for mutability
        """
        :type dominoes: str
        :rtype: str
        """
        lastValue = "L"
        lastIndex = -1
        for i in range(len(dominoes)):
            if dominoes[i] == ".":
                continue
            else:
                if dominoes[i] == "L":
                    if lastValue == "L":
                        for j in range(lastIndex+1, i+1):
                            dominoes[j] = "L"
                    if lastValue == "R":
                        for j in range((int)((i-lastIndex-1)/2)):
                            dominoes[lastIndex+1+j] = "R"
                        offset = (int)((i-lastIndex-1)/2) + (1 if (i - lastIndex - 1) % 2 == 1 else 0)
                        # if c%2 == 1:
                        #     dominoes[lastIndex+1+(int)((fallen[i+1]-fallen[i]-1)/2)] = "."
                        for j in range((int)((i-lastIndex-1)/2)):
                            dominoes[lastIndex+1+j+offset] = "L"
                else: # Falling Right
                    if lastValue == "R":
                        for j in range(lastIndex+1, i+1):
                            dominoes[j] = "R"
                lastValue = dominoes[i]
                lastIndex = i
        if lastValue == "R":
            for i in range(lastIndex+1, len(dominoes)):
                dominoes[i] = "R"
        return ''.join(dominoes)  # Convert back to string

