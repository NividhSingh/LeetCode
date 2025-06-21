class Solution {
public:
    string interpret(string command) {
        string output = "";
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                output += 'G';
            }
            else  if (command[i+1] == ')') {
                output += 'o';
                i++;
            }
            else {
                output += "al";
                i++;
                i++;
                i++;
            }
        }
        return output;
    }
};
