#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeExtraSpaces(const string& str) {
    string result;
    bool spacebool = false;

    for (char ch : str) {
        if (isspace(ch)) {
            if (!result.empty() && !spacebool) {
                result += ' ';
            }
            spacebool = true;
        }
        else {
            result += ch;
            spacebool = false;
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
