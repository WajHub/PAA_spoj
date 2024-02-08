#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
const int MAX_SIZE = 4500;


void printNumber(vector<int> &digits){
    bool first = false;
    for(int i=0;i<MAX_SIZE;i++){
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

void multiply(vector<int> &digits,int multiplier, int newBase){
    if(multiplier==1)
        return;
    int carry = 0;
    for(int i=MAX_SIZE-1;i>=0;i--){
        digits[i] = digits[i]*multiplier + carry;
        carry = digits[i]/newBase;
        digits[i] = digits[i]%newBase;
    }
}
void addNumber(vector<int> &digits, int number, int newBase){
    if (number==0)
        return;
    int carry = 0;
    digits[MAX_SIZE-1] += number;
    carry = digits[MAX_SIZE-1]/newBase;
    digits[MAX_SIZE-1] = digits[MAX_SIZE-1]%newBase;
    int index = MAX_SIZE-2;
    while(carry>0){
        digits[index] += carry;
        carry = digits[index]/newBase;
        digits[index] = digits[index]%newBase;
        index--;
    }
}

void converse(vector<int> &digits,vector<int> &newDigits, int base, int newBase, int size){
    int temp = 0;
    int counter = 0;
    for(int i=0;i<size;i++){
        temp*=base;
        temp+=digits[MAX_SIZE-size+i];
        counter++;
        if(temp>1000 || i==size-1){
            multiply(newDigits, pow(base,counter),newBase);
            addNumber(newDigits, temp, newBase);
            counter = 0;
            temp = 0;
        }
        
    }
    printNumber(newDigits);
}

void clearDigits(vector<int> &digits){
    for(int i=0;i<digits.size();i++)
        digits[i] = 0;
}

int main() {
    vector<int> digits(MAX_SIZE,0);
    vector<int> newDigits(MAX_SIZE,0);

    string number;
    int base, newBase, n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> number;
        cin >> base;
        cin >> newBase;
        for(int j=MAX_SIZE-number.size();j<MAX_SIZE;j++){
            if(number[j-MAX_SIZE+number.size()]>'9')
                digits[j] = number[j-MAX_SIZE+number.size()]-'A'+10;
            else
                digits[j] = number[j-MAX_SIZE+number.size()]-'0';
        }
        converse(digits,newDigits, base, newBase, number.size());
        clearDigits(newDigits);
    }
    return 0;
}
