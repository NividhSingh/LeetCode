class Solution(object):

    def convert(self, num):
        Ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        TenOnes = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        Tens = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        hundreds = num / 100
        num -= hundreds * 100
        output = ""
        if hundreds > 0:
            output += Ones[hundreds] + " Hundred "
        if (num >= 20):
            output += Tens[num / 10-2] + " "
            if num % 10 > 0:
                output += Ones[num % 10] + " "
        elif (num >= 10):
            output += TenOnes[num - 10] + " "
        else:
            output += Ones[num] + " "
        
        return output

    
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """

        if num == 0:
            return "Zero"

        billions = num / 1000000000
        millions = (num % 1000000000) / 1000000
        thousands = (num % 1000000) / 1000
        normal = num % 1000

        output = ""

        if billions > 0:
            output += self.convert(billions) + "Billion "
        if millions > 0:
            output += self.convert(millions) + "Million "
        if thousands > 0:
            output += self.convert(thousands) + "Thousand "
        if normal > 0:
            output += self.convert(normal)

        return output.strip().replace("  ", " ")
        
