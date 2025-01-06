#include <iostream>
#include "my_stack.h"

using namespace std;
int main() {
    //my_stack test
    my_stack<int> intStack;
    intStack.push(1);
    intStack.push(9);
    intStack.push(9);
    intStack.push(3);
    intStack.top();
    intStack.pop();
    intStack.size();
    intStack.isEmpty();
    my_stack<string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.emplace(3,"Ok ");
    strStack.pop();
    strStack.size();
    strStack.pop();
    strStack.isEmpty();

    //my_vector test

    return 0;
}
