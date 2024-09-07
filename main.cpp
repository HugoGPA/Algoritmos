
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;


template <typename T>
void ExchangeSort(vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
void BubbleSort(vector<T>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

template <typename T>
void SelectionSort(vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void InsertionSort(vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        T key = arr[i];
        size_t j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void Merge(vector<T>& arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    vector<T> L(n1), R(n2);

    for (size_t i = 0; i < n1; i++) L[i] = arr[left + i];
    for (size_t i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

template <typename T>
void MergeSortHelper(vector<T>& arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        MergeSortHelper(arr, left, mid);
        MergeSortHelper(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

template <typename T>
void MergeSort(vector<T>& arr) {
    MergeSortHelper(arr, 0, arr.size() - 1);
}


template <typename T>
size_t Partition(vector<T>& arr, size_t low, size_t high) {
    T pivot = arr[high];
    size_t i = low - 1;
    for (size_t j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void QuickSortHelper(vector<T>& arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = Partition(arr, low, high);
        QuickSortHelper(arr, low, pi - 1);
        QuickSortHelper(arr, pi + 1, high);
    }
}

template <typename T>
void QuickSort(vector<T>& arr) {
    QuickSortHelper(arr, 0, arr.size() - 1);
}


template <typename T>
int busqSecuencial(const vector<T>& arr, T valor) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1;
}


template <typename T>
int busqBinaria(const vector<T>& arr, T valor) {
    size_t inicio = 0;
    size_t fin = arr.size() - 1;

    while (inicio <= fin) {
        size_t mitad = inicio + (fin - inicio) / 2;
        if (arr[mitad] == valor) {
            return mitad;
        } else if (arr[mitad] < valor) {
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }

    return -1;
}


int main() {
    vector<int> numeros;
    int n, num, opcion, busqueda;

    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    cout << "Ingrese los números: \n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        numeros.push_back(num);
    }

    cout << "Seleccione el método de ordenamiento:\n";
    cout << "1. ExchangeSort\n";
    cout << "2. BubbleSort\n";
    cout << "3. SelectionSort\n";
    cout << "4. InsertionSort\n";
    cout << "5. MergeSort\n";
    cout << "6. QuickSort\n";
    cin >> opcion;

    switch (opcion) {
        case 1: ExchangeSort(numeros); break;
        case 2: BubbleSort(numeros); break;
        case 3: SelectionSort(numeros); break;
        case 4: InsertionSort(numeros); break;
        case 5: MergeSort(numeros); break;
        case 6: QuickSort(numeros); break;
        default: cout << "Opción inválida"; return 1;
    }

    cout << "Números ordenados: ";
    for (int i : numeros) {
        cout << i << " ";
    }
    cout << endl;

    
    cout << "¿Cuántas búsquedas desea realizar? ";
    int cantidadBusquedas;
    cin >> cantidadBusquedas;

    for (int i = 0; i < cantidadBusquedas; i++) {
        cout << "Ingrese el número a buscar: ";
        cin >> busqueda;

        int resultadoSecuencial = busqSecuencial(numeros, busqueda);
        int resultadoBinario = busqBinaria(numeros, busqueda);

        cout << "Resultado búsqueda secuencial: " << resultadoSecuencial << endl;
        cout << "Resultado búsqueda binaria: " << resultadoBinario << endl;
    }

    return 0;
}
