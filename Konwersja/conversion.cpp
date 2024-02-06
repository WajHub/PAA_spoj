#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int divideNumber(string &numberToDivide, int base, int divider){
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


    string number2 = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    cout<<conversionToNewSystem(number2,36,9)<<endl;

    // string numbers [1000];
    // int base [1000];    //aktualna podstawa 3liczby
    // int newBase[1000];  //nowa podstawa
    // int n;              //ilosc liczb
    // cin >> n;
    // for(int i=0;i<n;i++){
    //     cin >> numbers[i];
    //     cin >> base[i];
    //     cin >> newBase[i];
    // }
    // string decimalNumber = "";
    // for(int i=0;i<n;i++){
    //     decimalNumber = conversionToDecimal(numbers[i],base[i]);
    //     cout<<conversionToNewSystem(decimalNumber,newBase[i])<<endl;
    // }


    return 0;
}
