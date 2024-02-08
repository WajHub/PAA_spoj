#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printNumber(vector<int> &digits, int size){
    bool first = false;
    for(int i=0;i<size;i++){
        if(digits[i]!=0)
            first = true;
        if(first){
            if(digits[i]>9)
                cout << (char)(digits[i]-10+'A');
            else
                cout << digits[i];
        }
    }
    if(!first)
        cout << 0;
    cout << endl;
}

void multiply(vector<int> &digits,int multiplier, int newBase, int size){
    if(multiplier==1)
        return;
    int carry = 0;
    for(int i=size-1;i>=0;i--){
        digits[i] = digits[i]*multiplier + carry;
        carry = digits[i]/newBase;
        digits[i] = digits[i]%newBase;
    }
}
void addNumber(vector<int> &digits, int number, int newBase, int size){
    if (number==0)
        return;
    int carry = 0;
    digits[size-1] += number;
    carry = digits[size-1]/newBase;
    digits[size-1] = digits[size-1]%newBase;
    while(carry>0){
        size--;
        digits[size-1] += carry;
        carry = digits[size-1]/newBase;
        digits[size-1] = digits[size-1]%newBase;
    }
}

void converse(vector<int> &digits, int base, int newBase, int size){
    vector<int> newDigits(size*4,0);
    for(int i=0;i<digits.size();i++){
        multiply(newDigits, base,newBase, size*4);
        addNumber(newDigits, digits[i], newBase, size*4);
    }
    printNumber(newDigits, size*4);
}

int main() {
    vector<int> digits;
    string number;
    int base, newBase, n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> number;
        cin >> base;
        cin >> newBase;
        digits.resize(number.size());
        for(int j=0;j<number.size();j++){
            if(number[j]>'9')
                digits[j] = number[j]-'A'+10;
            else
                digits[j] = number[j]-'0';
        }
        converse(digits, base, newBase, number.size());
    }
    return 0;
}
