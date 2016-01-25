
/*
*Checks if a word is a palindrome, returns true else false.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  bool isPalindrome = true;
  string input; // input string
  cin >> input; // read a string from terminal
  string reverse;
  reverse = string(input.rbegin(),input.rend());
  for (int  i = 0; i != input.size(); ++i){
    if(input[i] != reverse[i]){
      isPalindrome = false;
    }
  }
  if(isPalindrome){
    cout << "The word: " + input + " is a palindrome!" << endl;
  }else{
    cout << "The word: " + input + " is NOT a palindrome!" << endl;
  }
}
