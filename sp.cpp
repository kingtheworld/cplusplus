#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

string boolToString(bool value) {
    return value ? "TRUE" : "FALSE";
}

unordered_map<char, bool> parseValueString(const string& value) {
    unordered_map<char, bool> ans;
    string s1;
    int j = 0;

    for (int i = 0; i < value.length(); i++) {
        char c = value[i];
        if (isalpha(c)) {
            s1 += c;
        } else if (c == '0' || c == '1') {
            bool s2 = (c == '1');
            ans[s1[j]] = s2;
            j++;
            s1.clear();
        } else if (c == ' ') {
            continue;
        }
    }

    if (!s1.empty()) {
        ans[s1[0]] = false;
    }

    return ans;
}

string LogicPostfixPrefixCalculator(string input, string value) {
    unordered_map<char, bool> ans = parseValueString(value);
    stack<bool> s;

    size_t index = 0;  // Current position in the input string

    while (index < input.size()) {
        char c = input[index];
        if (isalpha(c)) {
            if (ans.find(c) != ans.end()) {
                s.push(ans.at(c));
            }
        } else {
            if (c == '&') {
                bool operand2 = s.top();
                s.pop();
                bool operand1 = s.top();
                s.pop();
                s.push(operand1 && operand2);
            } else if (c == '|') {
                bool operand2 = s.top();
                s.pop();
                bool operand1 = s.top();
                s.pop();
                s.push(operand1 || operand2);
            } else if (c == '-') {
                bool operand2 = s.top();
                s.pop();
                bool operand1 = s.top();
                s.pop();
                s.push(!operand1 || operand2);
            } else if (c == '~') {
                bool operand = s.top();
                s.pop();
                s.push(!operand);
            } else if (c == '<') {
                if (index + 1 < input.size() && input[index + 1] == '-') {
                    index++;  // Skip the next character '-'
                    bool operand2 = s.top();
                    s.pop();
                    bool operand1 = s.top();
                    s.pop();
                    s.push((operand1 && operand2) || (!operand1 && !operand2));
                }
            }
        }
        index++;  // Move to the next character in the input string
    }
    bool result = s.top();
    return boolToString(result);
}


int main() {
    string expression = "&|p~qr";
    string value = "t w z p q y x 1 0 1 0 0 1 1";

     unordered_map<char, bool> variableValues = parseValueString(value);

    cout << "Variable Values:\n";
    for (const auto& entry : variableValues) {
        cout << entry.first << ": " << (entry.second ? "TRUE" : "FALSE") << endl;
    }
    //string result = LogicPostfixPrefixCalculator(expression, value);
   // cout << "Result: " << result << endl;

    return 0;
}
