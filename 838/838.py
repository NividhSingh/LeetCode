class Solution(object):
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        fallen = []
        for i in range(len(dominoes)):
            if dominoes[i] != '.':
                fallen.append(i)

        if len(fallen) == 0:
            return dominoes

        output = ""
        index = 0
        while index <= fallen[0] - 1:
            if (dominoes[fallen[0]] == "L"):
                output += "L"
            else:
                output += "."
            index += 1

        for i in range(len(fallen) - 1):
            output += dominoes[fallen[i]]
            if dominoes[fallen[i]] == "L" and dominoes[fallen[i+1]] == "R":
                for _ in range(fallen[i+1] - fallen[i]-1):
                    output += "."
            elif dominoes[fallen[i]] == "L" and dominoes[fallen[i+1]] == "L":
                for _ in range(fallen[i+1] - fallen[i]-1):
                    output += "L"
            elif dominoes[fallen[i]] == "R" and dominoes[fallen[i+1]] == "R":
                for _ in range(fallen[i+1] - fallen[i]-1):
                    output += "R"
            elif dominoes[fallen[i]] == "R" and dominoes[fallen[i+1]] == "L":
                c = fallen[i+1] - fallen[i] - 1
                # subcount = c / 2 if c%2 == 0 else (c - 1) / 2
                for _ in range((int)((fallen[i+1] - fallen[i]-1)/2)):
                    output += "R"
                if c%2 == 1:
                    output += "."
                for _ in range((int)((fallen[i+1] - fallen[i]-1)/2)):
                    output += "L"
        
        output += dominoes[fallen[-1]]
        index = fallen[-1] + 1
        while index < len(dominoes):
            if (dominoes[fallen[-1]] == "R"):
                output += "R"
            else:
                output += "."
            index += 1
        
        return output
        
