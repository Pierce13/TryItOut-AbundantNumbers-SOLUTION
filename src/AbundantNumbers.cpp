#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string abundantNum(){
    string testResult;
    stringstream ss_input;
    stringstream ss_result;
    int numInput = 0;
    int numSum = 0;
    string result;
    
    while(true){
        cout << "Enter a number (-1 to quit): ";
        cin >> numInput;

        if(numInput == -1){
            break;
        }

        for(int i = 1; i < numInput; i++){
            if(numInput % i == 0){
                numSum += i;
            }
        }

        if(numSum < numInput){
            result = "a deficient number";
        }else if(numSum == numInput){
            result = "a perfect number";
        }else{
            result = "an abundant number";
        }
        numSum = 0;

        cout << numInput << " is " << result << endl; 
        //For testing purposes. Please leave in the program
        ss_input << numInput;
        ss_result << result;
        testResult += ss_input.str() + " is " + ss_result.str() + " ";
        ss_input.str(""); // Clear the stringstream after use
        ss_input.clear(); // Clear any error flags
        ss_result.str("");
        ss_result.clear();

    }
     
    return testResult;
}

#ifndef TESTING
int main(){
    abundantNum();
    return 0;
}
#endif
