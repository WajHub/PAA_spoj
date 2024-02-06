#include <iostream>
#include <string>
using namespace std;
string addNumber(string &numberToAdd, string &number, int base){
    string result = "";
    if(numberToAdd.length()<number.length()){
        swap(numberToAdd,number);
    }
    numberToAdd = '0' + numberToAdd;
    int lengthNumberToAdd = numberToAdd.length();
    int lengthNumber = number.length();
    int difference = lengthNumberToAdd - lengthNumber;
    int indexNumberToAdd = lengthNumberToAdd-1;
    int indexNumber = lengthNumber-1;
    while(indexNumber>=0 ){
        int digit = numberToAdd[indexNumberToAdd] - '0' + number[indexNumber] - '0';
        if (digit>=base){
            numberToAdd[indexNumberToAdd-1] += 1;
            digit -= base;
        }
        indexNumberToAdd--;
        indexNumber--;
        result = to_string(digit) + result;
    }
    while(difference>0){
        int digit = numberToAdd[indexNumberToAdd] - '0';
        if (digit>=base){
            numberToAdd[indexNumberToAdd-1] += 1;
            digit -= base;
        }
        indexNumberToAdd--;
        if(digit > 0) result = to_string(digit) + result;
        else if(digit == 0) result = "0" + result;
        difference--;
    }
    if(result[0]=='0') result = result.substr(1,result.length()-1);
    return result;
}
string divideNumber(string numberToDivide, int base, int divider){
    string result = "";
    int index = 0;
    int digit = numberToDivide[index] - '0';
    while(digit<divider && numberToDivide.length()-1>index) digit = digit*base + (numberToDivide[++index] - '0');
    while(numberToDivide.length()>index){
        result += to_string(digit/divider);
        index++;
        digit = (digit%divider)*base + (numberToDivide[index] - '0');
    }
    if(result.length()==0)  result = "0";
    return result;
}
int restOfDivideNumber(string &numberToDivide, int base, int divider){
    int restResult = 0;
    string result = "";
    int index = 0;
    int digit = numberToDivide[index] - '0';
    while(digit<divider && numberToDivide.length()-1>index )digit = digit*base + (numberToDivide[++index] - '0');
    while(numberToDivide.length()>index){
        result += to_string(digit/divider);
            if(index==numberToDivide.length()-1) restResult = digit%divider;
        digit = (digit%divider)*base + (numberToDivide[++index] - '0');

    }
    if(result.length()==0)  result = "0";
    return restResult;
}
string multipliesNumber(string &numberToMultiply, int multplier){
    if(numberToMultiply == "0") return "0";
    if(multplier == 0) return "0";
    string result(numberToMultiply.length()+2,0);
    int length = numberToMultiply.length();
    int lengthResult = result.length();
    int digit = 0;
    string temp = "";
    for (int i=0;i<length;i++){
        digit = (numberToMultiply[length-i-1])-'0';
        digit = digit * multplier;
        temp = to_string(digit);
        for (int j=0;j<temp.length();j++){
            if( result[lengthResult-i-j-1] + digit%10>=10){
                result[lengthResult-i-j-2] += 1;
                result[lengthResult-i-j-1] += digit%10-10;
            }
            else result[lengthResult-i-j-1] += digit%10;
            digit = digit/10;
        }
    }
    for(int i=0;i<lengthResult;i++){
        result[i] += 48;
    }
    if(result[0]=='0' or result[0]=='\0') result = result.substr(1);
    if(result[0]=='0' or result[0]=='\0') result = result.substr(1);
    return result;
}
string conversionToDecimal(string &number, int base){
    string result = "0";
    int power = 0;
    string element="";
    for(int i=number.length()-1;i>=0;i--){
        if(number[i]>='0' && number[i]<='9'){
            element = to_string(number[i]-'0');
            for(int j=0;j<power;j++) element = multipliesNumber(element,base);
            result = addNumber(result,element,10);
        }else{
                element = to_string(number[i]-'A'+10);
            for(int j=0;j<power;j++) element = multipliesNumber(element,base);
            
            result = addNumber(result,element,10);
        }
        power++;
    }
    return result;
}
string conversionToNewSystem(string &decimalNumber,int newBase){
    if (decimalNumber == "0") return "0";
    string result = "";
    while(decimalNumber!="0"){
        int digit = restOfDivideNumber(decimalNumber,10,newBase);
        if(digit<10) result = to_string(digit) + result;
        else result = (char)(digit-10+'A') + result;
        
        decimalNumber = divideNumber(decimalNumber,10,newBase);
    }
    return result;
}
int main() {
    string numbers [1000];
    int base [1000];    
    int newBase[1000];  
    int n;              
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
        cin >> base[i];
        cin >> newBase[i];
    }
    string decimalNumber = "";
    for(int i=0;i<n;i++){
        decimalNumber = conversionToDecimal(numbers[i],base[i]);
        cout<<conversionToNewSystem(decimalNumber,newBase[i])<<endl;
    }
    return 0;
}