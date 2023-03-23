#include <iostream>
using namespace std;

int main() {
    string inputString;
    cout << "Enter your full name: ";
    getline(cin, inputString);
    cout << "Your full name is: " << inputString << endl;
    return 0;
}
