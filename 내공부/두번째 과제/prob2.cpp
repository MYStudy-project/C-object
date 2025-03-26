#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeExtraSpaces(const string& str) {
    string result;
    bool spaceFlag = false;

    for (char ch : str) {
        if (isspace(ch)) {
            if (!result.empty() && !spaceFlag) {
                result += ' ';
            }
            spaceFlag = true;
        }
        else {
            result += ch;
            spaceFlag = false;
        }
    }

    return result;
}

int main() {
    string input;
    while (true) {
        getline(cin, input);
        if (input == "exit") {
            cout << "종료" << endl;
            break;
        }

        string cleanedText = removeExtraSpaces(input);
        cout << "-> " << cleanedText << " : " << cleanedText.length() << endl;
    }

    return 0;
}
