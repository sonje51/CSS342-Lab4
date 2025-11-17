#include <iostream>
using namespace std;

// Start with Stack [1,2,3,2,1] and determine if it is a palindrome only using stacks

/*
method()
    {
        create a new stack
        use size to find where the middle should be
        if odd, then there will be an odd one out in the middle
        if even, then each value needs to have a match
        for(int i = size/2; i > 0; i--) {
            place top of stack into the new stack
            Use pop to get rid 
        }
    }
*/

bool isPalindrome(const stack<int> s) {
    scopy = s;
    int val;
    while(!scopy.isEmpty()) {
        val = scopy.top();
        scopy.pop();
        list.push(val);
    }
    return list==s;
}

int main()
{
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(1);
    cout << isPalindrome(myStack) << endl;
    return 0;
}