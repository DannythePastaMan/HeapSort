#include <iostream>

using namespace std;

void Heapify(int arr[], int n, int i) {
    int mayor = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    //Si el hijo de la izquierda es mayor que la raiz
    if(left < n && arr[left] > arr[mayor]){
        mayor = right;
    }

    //Si el hijo de la derecha es mayor que el mas grande que hayamos encontrado
    if(right < n && arr[right] > arr[mayor]){
        mayor = right;
    }

    //Si el mayor no es una raiz
    if(mayor != i){
        swap(arr[i], arr[mayor]);
        //Recursivamente heapify el sub arbol afectado
        Heapify(arr, n, mayor);
    }
}

//Funcion principal del heap sort
void HeapSort(int arr[], int n) {
    //Armar el heap (reorganizamos el arreglo)
    for (int i = n/2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }
    //Extraemos uno por uno  los elementos del heap
    for (int i  = n - 1; i >= 0 ; --i ) {
        //Movemos la raiz en la que estamos ubicados al final
        swap(arr[0], arr[i]);
        //Llamar el max heapify en el heap reducido
        Heapify(arr, i, 0);
    }

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/ sizeof(arr[0]);

    HeapSort(arr, n);

    cout<<"Sorted array is \n";
    printArray(arr, n);
}