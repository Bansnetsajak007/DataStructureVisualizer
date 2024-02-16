//just write fucking codeeeeeee
//  master java only java not script only java


#include <iostream>

using namespace std;

void printArray(int* array,  int size) {
    for(int i = 0; i < size; i++) {
        cout<<array[i]<<'\n';
    }
}

int* copyArray(int* array ,int size) {
    int* copiedArray = new int[size];
    
    for(int i = 0 ; i<size; ++i) {
        copiedArray[i] = array[i];
    }
    
    return copiedArray;
}


int main()
{
    const int size = 5;
    int array[size] = {20,45,22,12,44};

    int* destArray = copyArray(array , size);
    
    printArray(destArray, size);
    
    delete destArray;

    return 0;
}
