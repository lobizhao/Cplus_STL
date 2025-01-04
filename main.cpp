#include <iostream>
#include "my_stack.h"

int main() {
    my_stack<int> intStack;
    intStack.push(1);
    intStack.push(9);
    intStack.push(9);
    intStack.push(3);
    intStack.top();
    intStack.pop();
    intStack.isEmpty();
    intStack.size();
    return 0;
}
