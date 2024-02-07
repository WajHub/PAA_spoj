#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Result {
    int length;
    vector<int> placeX;
    vector<int> placeY;
};

//dynamiczna funkcja
//Funkcja insirpujaca: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
//Jest to dokladnie ta sama funkcja, ktora omawialem szczegolowo w zadaniu Proof_A
// string y bedzie naszymi wierszami, a string x bedzie naszymi kolumnami
void longestSubsequence(Result &result, string strX, string strY, int lengthX, int lengthY){
    // Inicjalizacja wektora dwuwymiarowego
    vector<vector<int> > arr(lengthY+1, vector<int>(lengthX+1));
    for(int y=0;y<lengthY+1;y++){
        for(int x=0;x<lengthX+1;x++){
            if(y==0||x==0) arr[y][x]=0;
            else if(strX[x-1]==strY[y-1]) arr[y][x]=arr[y-1][x-1]+1;
            else arr[y][x]=max(arr[y-1][x],arr[y][x-1]);
        }
    }
    //odczytujemy nasz wynik, odczytywanie wyniku rowniez omawaialem w zadaniu Proof_A
    result.length = arr[lengthY][lengthX];
    int temp = result.length;
    if(temp>0){
        result.placeX.resize(result.length);
        result.placeY.resize(result.length);

        int indexX = lengthX;
        int indexY = lengthY;
        while(indexX > 0 && indexY > 0){
            if(arr[indexY][indexX] != arr[indexY][indexX-1]){
                result.placeX[temp-1] = indexX;
                result.placeY[temp-1] = indexY;
                temp--;
                indexY--;
            }
            indexX--;
        }
    }

}
void clearResult(Result &result){
    result.length = 0;
    result.placeX.clear();
    result.placeY.clear();
}

int main() {
    int n = 0;
    cin >> n;
    Result result;

    for(int i = 0; i < n; i++) {
        int lengthX = 0;
        int lengthY = 0;
        cin>>lengthX;
        string x (lengthX, '0');
        cin>>x;

        cin>>lengthY;
        string y (lengthY, '0');
        cin>>y;

        longestSubsequence(result, x, y, lengthX, lengthY);

        cout<<"case "<<i+1;
        if(result.length > 0){
            cout<<" Y"<<endl;
            cout<<result.length<<endl;
             //Odczytanie znakow 
            for(int i = 0; i < result.length; i++) cout<<x[result.placeX[i]-1]<<" " <<result.placeX[i]<<" "<<result.placeY[i]<<endl;
        }
        else cout<<" N"<<endl;
        clearResult(result);
        
    }
    return 0;
}
