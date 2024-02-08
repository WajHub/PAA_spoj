#include <iostream>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;


void swap(int*bookId, int bookIndexTemp, int bookIndexTemp2,unordered_map<int, int> &booksMap) {
    int temp = bookId[bookIndexTemp];
    bookId[bookIndexTemp] = bookId[bookIndexTemp2];
    bookId[bookIndexTemp2] = temp;

    booksMap[bookId[bookIndexTemp]] = bookIndexTemp;
    booksMap[bookId[bookIndexTemp2]] = bookIndexTemp2;
}

void printBooks(int *bookId, int size) {
    for (int i = 0; i < size; i++) {
        cout << bookId[i] << " ";
    }
    cout << endl;
}

void order(deque<int> &booksSort, unordered_map<int, int> &booksMap, int *bookId, int k,int &size) {
    int bookTemp = booksSort[k-1];
    int bookIndexTemp = booksMap[bookTemp];
    swap(bookId, bookIndexTemp, size - 1, booksMap);
    booksSort.erase(booksSort.begin() + k-1);
    size--;
}

int main() {
    deque<int> booksSort;
    unordered_map<int, int> booksMap;  //ID - > indeks
    int *booksId;
    int size;
    cin >> size;
    int numberOfBooks = size;
    booksId = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> booksId[i];
        booksMap[booksId[i]] = i;
        booksSort.push_back(booksId[i]);
    }
    sort(booksSort.begin(), booksSort.end(),greater<int>());
    int *k = new int[size];
    for (int i = 0; i < size; i++) {
        cin>>k[i];
    }
    int instruction = 0;
    int counter=0;

    while(instruction<numberOfBooks){
        cin>>instruction;
        for(int i=counter;i<instruction;i++){
            order(booksSort,booksMap,booksId,k[counter],size);
            //sort(booksSort.begin(), booksSort.end(),greater<int>());
            //cout<<i<<": ";
            //printBooks(booksId, numberOfBooks);
            counter++;
        }
        
        printBooks(booksId, numberOfBooks);
    }
    delete [] booksId;
    delete [] k;
    return 0;
}

