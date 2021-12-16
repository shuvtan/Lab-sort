#include <iostream>
#include <chrono>
using namespace std;
  
// Функция сравнения элементов по дереву
void heapify(int arr[], int n, int root)
{
   int largest = root; // Наибольший элемент = корень
   int l = 2*root + 1; // left 
   int r = 2*root + 2; // right 
  
   // Если левый элемент больше корня 
   if (l < n && arr[l] > arr[largest])
   largest = l;
  
   // Если правый элемент больше корня
   if (r < n && arr[r] > arr[largest])
   largest = r;
  
   // Если наибольший элемент != корень
   if (largest != root)
      {
      //Поменять корень и наибольший элемент
      swap(arr[root], arr[largest]);
  
      // Рекурсия
      heapify(arr, n, largest);
      }
}
  
// Реализация сортировки
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i);
  
   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--)
   {
      // Move current root to end
      swap(arr[0], arr[i]);
  
      // again call max heapify on the reduced heap
      heapify(arr, i, 0);
   }
}
  
// Функция выведения массива
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  

int main()
{
   int n, heap_arr[100];
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>heap_arr[i];
	}
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
   auto start = std::chrono::high_resolution_clock::now(); //старт счётчика времени

   heapSort(heap_arr, n);
   auto end = std::chrono::high_resolution_clock::now(); //стоп счётчика времени
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   auto nsec = end - start; //подсчёт времени, затраченного на сортировку
   std::cout <<nsec.count() << " нсек." << std::endl;

   return 0;
}