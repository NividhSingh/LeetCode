class Solution(object):
    def maximum69Number(self, num):
        """
        :type num: int
        :rtype: int
        """
        num_list = list(str(num))  # convert to list for mutability
        
        for i in range(len(num_list)):
            if num_list[i] == '6':
                num_list[i] = '9'  # change the first 6 to 9
                break  # only change the first occurrence
                
        return int(''.join(num_list))  # join back into string, then int
