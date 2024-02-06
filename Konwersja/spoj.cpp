#include <iostream>
#include <string>
using namespace std;

string conversionToNewSystem(string &number,int base,int newBase);
int divideNumber(string &numberToDivide, int base, int divider);

int divideNumber(string &numberToDivide, int base, int divider){
    if (numberToDivide == "0") return 0;
    int restResult = 0;
    string result = "";
    int index = 0;
    int digit;
    if(numberToDivide[index]>'9') digit = numberToDivide[index] - 'A' + 10;
    else digit = numberToDivide[index] - '0';
    while(digit<divider && numberToDivide.length()-1>index) {
        index++;
        if(numberToDivide[index]>'9') digit = digit*base + (numberToDivide[index] - 'A' + 10);
        else digit = digit*base + (numberToDivide[index] - '0');
    }
    while(numberToDivide.length()>index){
        if(digit/divider<10) result += to_string(digit/divider);
        else result += (char)(digit/divider-10+'A');
        if(index==numberToDivide.length()-1) restResult = digit%divider;
        index++;
        if (numberToDivide[index]>'9') digit = (digit%divider)*base + (numberToDivide[index] - 'A' + 10);
        else digit = (digit%divider)*base + (numberToDivide[index] - '0');
    }
    if(result.length()==0)  result = "0";
    numberToDivide = result;
    return restResult;
}
string conversionToNewSystem(string &number,int base,int newBase){
    if (number == "0") return "0";
    string result = "";
    while(number!="0"){
        int digit = divideNumber(number,base,newBase);  
        if(digit<10){
            result = to_string(digit) + result;
        }else{
            result = (char)(digit-10+'A') + result;
        }
    }
    return result;
}
int main() {
    string number;
    int base ;    
    int newBase;  
    int n;              
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> number;
        cin >> base;
        cin >> newBase;
        cout<<conversionToNewSystem(number,base,newBase)<<endl;
    }
    return 0;
}