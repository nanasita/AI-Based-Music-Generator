#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomNumbers(int count, int minVal, int maxVal) {
    vector<int> numbers;
    for (int i = 0; i < count; i++) {
        numbers.push_back(rand() % (maxVal - minVal + 1) + minVal);
    }
    return numbers;
}

vector<int> fibonacci(int n) {
    vector<int> sequence = {0, 1};
    for (int i = 2; i < n; i++) {
        sequence.push_back(sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string reverseString(const string &str) {
    return string(str.rbegin(), str.rend());
}

int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

double calculateMean(const vector<int> &arr) {
    return accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}

double calculateMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int mid = arr.size() / 2;
    return arr.size() % 2 ? arr[mid] : (arr[mid - 1] + arr[mid]) / 2.0;
}

bool isPalindrome(const string &str) {
    return str == string(str.rbegin(), str.rend());
}

template<typename T>
void printVector(const vector<T> &vec) {
    for (const auto &val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    vector<int> numbers = generateRandomNumbers(10, 1, 100);
    cout << "Random Numbers: ";
    printVector(numbers);
    
    vector<int> fibSeq = fibonacci(10);
    cout << "Fibonacci Sequence: ";
    printVector(fibSeq);
    
    cout << "Is 17 Prime? " << (isPrime(17) ? "Yes" : "No") << endl;
    cout << "Reversed String (Hello): " << reverseString("Hello") << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Mean: " << calculateMean(numbers) << endl;
    cout << "Median: " << calculateMedian(numbers) << endl;
    cout << "Is 'racecar' a palindrome? " << (isPalindrome("racecar") ? "Yes" : "No") << endl;
    
    return 0;
}
