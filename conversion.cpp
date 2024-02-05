#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Dodawanie dwoch liczb w stringu (liczby sa w tym samym systemie)
string addNumber(string numberToAdd, string number, int base){
    string result = "";
    //numberToAdd - liczba dluzsza (ma wiecej znakow)
    if(numberToAdd.length()<number.length()){
        swap(numberToAdd,number);
    }
    numberToAdd = '0' + numberToAdd;
    int lengthNumberToAdd = numberToAdd.length();
    int lengthNumber = number.length();
    int difference = lengthNumberToAdd - lengthNumber;
    int indexNumberToAdd = lengthNumberToAdd-1;
    int indexNumber = lengthNumber-1;
    while(indexNumber>=0){
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
        difference--;
    }

    return result;
}

//Napisana Ponizej funkcja inspirowana jest (a reczej sprawdzana czy aby na pewno dziala poprawnie) https://www.geeksforgeeks.org/divide-large-number-represented-string/ 
//
string divideNumber(string numberToDivide, int base, int divider){
    string result = "";
    int index = 0;
    int digit = numberToDivide[index] - '0';
    while(digit<divider){
        digit = digit*base + (numberToDivide[++index] - '0');
    }
    while(numberToDivide.length()>index){
        result += to_string(digit/divider);
        digit = (digit%divider)*base + (numberToDivide[++index] - '0');
    }
    return result;
}



//zamiana dowolnej liczby na system dziesietny
string conversionToDecimal(string number, int base){
    string result = "0";
    int power = 0;
    for(int i=number.length()-1;i>=0;i--){
        if(number[i]>='0' && number[i]<='9'){
            //string number = convertBigNumberToString((number[i]-'0'),base,power);

            long long element = (number[i]-'0')*pow(base,power);
            result = addNumber(result,to_string(element),10);
        }else{
            //string number = convertBigNumberToString((number[i]-'A'),base,power);

            long long element = (number[i]-'A')*pow(base,power);
            result = addNumber(result,to_string(element),10);
        }
        power++;
    }
    return result;
}

//zamiana systemu dziesietnego na dowolny
string conversionToNewSystem(string decimalNumber,int newBase){
    string result = "";
    while(decimalNumber.length()>0){
        int digit = decimalNumber[decimalNumber.length()-1] - '0';
        if(digit<10){
            result = to_string(digit) + result;
        }else{
            result = (char)(digit-10+'A') + result;
        }
        // !!! dzielenie liczby dziesietnej przez nowa podstawe
    }
    return result;
}


int main() {
    string numbers [1000];
    int base [1000];    //aktualna podstawa 3liczby
    int newBase[1000];  //nowa podstawa
    int n;              //ilosc liczb
    // cin >> n;
    // for(int i=0;i<n;i++){
    //     cin >> numbers[i];
    //     cin >> base[i];
    //     cin >> newBase[i];
    // }
    // for(int i=0;i<n;i++){
    //     cout<<conversionToNewSystem(conversionToDecimal(numbers[i],base[i]),newBase[i])<<endl;
    // }
    cout<<divideNumber("1248163264128256512",10,125)<<endl;

    

    return 0;
}
