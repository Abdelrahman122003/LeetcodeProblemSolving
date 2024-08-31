class Solution {
public:
    string countOfAtoms(string formula) {
        // Stack to hold atom counts for nested groups in the formula
        stack<unordered_map<string, int>> groupStack;
        // Push an empty map to initialize the stack
        groupStack.push(unordered_map<string, int>());
        
        int currentIndex = 0;   // Current position in the formula string
        int formulaLength = formula.size(); // Length of the formula

        while (currentIndex < formulaLength) {
            // If an opening bracket '(' is encountered, push a new empty map for the new group
            if (formula[currentIndex] == '(') {
                groupStack.push(unordered_map<string, int>());
                currentIndex++;
            }
            // If a closing bracket ')' is encountered
            else if (formula[currentIndex] == ')') {
                currentIndex++;
                // Read the multiplier following the closing bracket (if any)
                // Like (H2O)34   ==> 34 is a muliplier                  
                string multiplierString = "";
                while (currentIndex < formulaLength && isdigit(formula[currentIndex])) {
                    multiplierString += formula[currentIndex];
                    currentIndex++;
                }
                int multiplier = (multiplierString == "") ? 1 : stoi(multiplierString); // Default multiplier is 1
                // Pop the top map from the stack (current group of atoms within parentheses)
                unordered_map<string, int> currentGroup = groupStack.top();
                groupStack.pop();
                // Multiply the count of each atom in the current group by the multiplier and merge with the previous group
                for (auto [atom, count] : currentGroup) {
                    groupStack.top()[atom] += count * multiplier;
                }
            }
            // If an atom is encountered
            else {
                string atomName = ""; // Variable to hold the new atom name
                string countString = ""; // Variable to hold the atom count
                // Extract the atom name (starts with uppercase, may include lowercase letters)
                atomName += formula[currentIndex++]; // Add first character (always uppercase)
                while (currentIndex < formulaLength && islower(formula[currentIndex])) {
                    atomName += formula[currentIndex++];
                }
                // Extract the count for the atom (if any)
                while (currentIndex < formulaLength && isdigit(formula[currentIndex])) {
                    countString += formula[currentIndex++];
                }
                int atomCount = (countString == "") ? 1 : stoi(countString); // Default count is 1 if not specified
                // Add atom and count to the current group
                groupStack.top()[atomName] += atomCount;
            }
        }
        // Convert the final atom counts to a sorted map for output
        map<string, int> sortedAtoms(groupStack.top().begin(), groupStack.top().end());
        string result = ""; // String to hold the final result

        // Construct the result string in lexicographical order
        for (auto [atom, count] : sortedAtoms) {
            result += atom; // Add atom name
            if (count > 1) { // Add count only if greater than 1
                result += to_string(count);
            }
        }
        return result;
    }
};
