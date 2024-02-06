#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Dodawanie dwoch liczb w stringu (liczby sa w tym samym systemie)
string addNumber(string &numberToAdd, string &number, int base){
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

//Napisana Ponizej funkcja inspirowana jest (a reczej sprawdzana czy aby na pewno dziala poprawnie) https://www.geeksforgeeks.org/divide-large-number-represented-string/ 
// Zasada dzielenia liczb (string przez int) jest bardzo prosta - dzielimy tak jak pisemnie (szkolne dzielenie)
string divideNumber(string numberToDivide, int base, int divider){
    string result = "";
    int index = 0;
    int digit = numberToDivide[index] - '0';
    // szukamy najbardziej znaczacych cyfr, ktore utworza liczbe wieksza niz dzielnik
    while(digit<divider && numberToDivide.length()-1>index){
        digit = digit*base + (numberToDivide[++index] - '0');
    }
    // szkolnie dzielnie pod kreska
    while(numberToDivide.length()>index){
        // resultat dzielenia calkowitego
        result += to_string(digit/divider);
        // do dzielnej dodajemy reszte z powyzszego dzielenia i dodajemy kolejna (mniej znaczaca) cyfre z liczby
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
    // szukamy najbardziej znaczacych cyfr, ktore utworza liczbe wieksza niz dzielnik
    while(digit<divider && numberToDivide.length()-1>index ){
        digit = digit*base + (numberToDivide[++index] - '0');
    }
    // szkolnie dzielnie pod kreska
    while(numberToDivide.length()>index){
        // resultat dzielenia calkowitego
        result += to_string(digit/divider);
        // do dzielnej dodajemy reszte z powyzszego dzielenia i dodajemy kolejna (mniej znaczaca) cyfre z liczby
                if(index==numberToDivide.length()-1){
            restResult = digit%divider;
        }
        index++;
        digit = (digit%divider)*base + (numberToDivide[index] - '0');

    }
    if(result.length()==0)  result = "0";
    return restResult;
}

//Mnozenie liczb (dziesietnych) zrobimy pdobnie do dzielenia, pomnozymy pod kreska, z tym ze druga liczbe nie bedziemy mnozyc przez kazda cyfre osobno, lecz po prostu przez cala liczbe
//odpowiedniej cyfrze dodawac bedziem zera znaczace
//inspiracja: https://www.tutorialspoint.com/multiply-large-numbers-represented-as-strings-in-cplusplus
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
            else{
                result[lengthResult-i-j-1] += digit%10;
            }
            
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



//zamiana dowolnej liczby na system dziesietny
string conversionToDecimal(string &number, int base){
    string result = "0";
    int power = 0;
    string element="";
    for(int i=number.length()-1;i>=0;i--){
        if(number[i]>='0' && number[i]<='9'){
            element = to_string(number[i]-'0');
            for(int j=0;j<power;j++){
                element = multipliesNumber(element,base);
            }
            result = addNumber(result,element,10);
        }else{
                element = to_string(number[i]-'A'+10);
            for(int j=0;j<power;j++){
                element = multipliesNumber(element,base);
            }
            result = addNumber(result,element,10);
        }
        power++;
    }
    return result;
}

//zamiana systemu dziesietnego na dowolny
string conversionToNewSystem(string &decimalNumber,int newBase){
    if (decimalNumber == "0") return "0";

    string result = "";
    while(decimalNumber!="0"){
        int digit = restOfDivideNumber(decimalNumber,10,newBase);
        if(digit<10){
            result = to_string(digit) + result;
        }else{
            result = (char)(digit-10+'A') + result;
        }
        //dzielenie liczby dziesietnej przez nowa podstawe
        decimalNumber = divideNumber(decimalNumber,10,newBase);
    }
    return result;
}

string multiplyTwoNumbers(string num1, string num2) {
   if (num1 == "0" || num2 == "0") {
      return "0";
   }
   string product(num1.size() + num2.size(), 0);
   for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
            int n = (num1[i] - '0') * (num2[j] - '0') + product[i + j + 1];
            product[i + j + 1] = n % 10;
            product[i + j] += n / 10;
      }
   }
   for (int i = 0; i < product.size(); i++) {
      product[i] += '0';
   }
   if (product[0] == '0') {
      return product.substr(1);
   }
   return product;
}


int main() {
    string number = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string number2 = "35";

    auto start = std::chrono::high_resolution_clock::now();
    cout<<multipliesNumber(number,35)<<endl;
    auto end = std::chrono::high_resolution_clock::now();

    // Obliczenie czasu trwania
    std::chrono::duration<double> duration = end - start;

    // Wyświetlenie czasu trwania w sekundach
    std::cout << "Czas wykonania funkcji: " << duration.count() << " sekundy" << std::endl;

start = std::chrono::high_resolution_clock::now();
    cout<<multiplyTwoNumbers(number,number2)<<endl;
     end = std::chrono::high_resolution_clock::now();

    // Obliczenie czasu trwania
    duration = end - start;

    // Wyświetlenie czasu trwania w sekundach
    std::cout << "Czas wykonania funkcji: " << duration.count() << " sekundy" << std::endl;

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
// Rozwiazanie zawiera komentrze, lecz przez limit wielkosc rozwiazania (5000 bytes) musialem je usunac
// pelne rozwiazanie wraz z odpowiednimi komentarzami znajduje sie na moim githubie https://github.com/WajHub/PAA_spoj )