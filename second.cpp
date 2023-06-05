#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (arr[j] > arr[j + 1]) {
               // Обмен элементов
               int temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
           }
       }
   }
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   } //вывод отсортированного массива
}

int main() {
   double time_spent = 0.0;
   clock_t begin = clock();
   int n;
   cout << "Enter Array size: ";
   cin >> n;
   int* a = new int[n];
   srand(time(0));
   for (int i = 0; i < n; i++)
       a[i] = 1 + rand() % 100;
   cout << "Array: ";
   for (int i = 0; i < n; i++) cout<<a[i]<<" ";
   cout << "\nSorted Array: ";
   bubbleSort(a, n);
   cout << "\n";
   clock_t end = clock();
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
   cout << "Array size: " << n << "\nTime spent: "<<time_spent << " seconds\n";
}
