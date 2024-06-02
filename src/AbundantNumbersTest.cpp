#include "AbundantNumbers.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

// Helper functions for testing
template <typename T>
bool checkTest(int testNum, int& correct, T whatItShouldBe, T whatItIs) {
    if (whatItShouldBe == whatItIs) {
        correct++;
        cout << "***TEST " << testNum << " PASSED***" << endl;
        return true;
    } else {
        cout << "***TEST " << testNum << " FAILED*** " << endl;
        cout << "   Output was " << whatItIs << endl;
        cout << "   Output should have been " << whatItShouldBe << endl;
        return false;
    }
}

// Function to test calculateCircleArea()
void testAbundantNum(int& correctTests) {
    string numInput = "12 14 28 -1\n";
    stringstream inputBuffer(numInput);
    streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    string numResult = abundantNum();

    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    // Extract the actual result from the output buffer
    stringstream ss;
    ss << numResult;
    string capturedOutput = ss.str();
    string expectedOutput = "12 is an abundant number 14 is a deficient number 28 is a perfect number ";
    checkTest(1, correctTests, expectedOutput, capturedOutput);
}

// Function to run all tests
void runAllTests() {
    int correctTests = 0;
    testAbundantNum(correctTests);
    cout << "Total tests passed: " << correctTests << " out of 1" << endl;
}

// Main function to run specific tests
int main(int argc, char* argv[]) {
    if (argc == 1) {
        runAllTests();
    } else if (argc == 2) {
        int correctTests = 0;
        int testNumber = atoi(argv[1]);

        switch (testNumber) {
            case 1:
                testAbundantNum(correctTests);
                break;
            default:
                cerr << "Invalid test number. Please enter 1" << endl;
                return 1;
        }

        cout << "Total tests passed: " << correctTests << " out of 1" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [testNumber]" << endl;
        return 1;
    }

    return 0;
}
