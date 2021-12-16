#include <iostream> //время на сортировку пузырьком
#include <chrono>
using namespace std; 

int main(){
	int n, a[100];
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	auto start = std::chrono::high_resolution_clock::now(); //старт счётчика времени
	for (int i=0; i<n; i++){
		for (int j=0; j<n-1; j++){
			if (a[j]>a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}

		}
	}
	auto end = std::chrono::high_resolution_clock::now(); //стоп счётчика времени


	for (int i=0; i<n; i++){
		cout<< a[i]<< ' ';
	}
	cout<< ' ' <<endl;
	auto nsec = end - start; //подсчёт времени, затраченного на сортировку
    std::cout << nsec.count() << " нсек." << std::endl;


	return 0; 
}