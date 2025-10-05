#include "hello.h"

#include <iostream>

using namespace std;

void myproject::sayHello(){
    cout << "Hello, World!" << endl;

    cout << "Write the name to continue or 'exit' to end the program" << endl;

    string input;

    cin >> input;

    while (input != "exit"){
        cout << "Hello, " << input << "!" << endl;

        cout << "Write the name to continue or 'exit' to end the program" << endl;

        cin >> input;
    }
}