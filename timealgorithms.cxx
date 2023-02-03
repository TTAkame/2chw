#include "insertionsort.h"
#include "mergesort.h"
//#include "QuickSort.h"

#include "mergesort.h"
#include "quicksort.h"
#include<fstream>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include"json.hpp"
#include<ctime>

int main(int argc, char** argv) {

	std::ifstream file(argv[1]);
	nlohmann::json data = nlohmann::json::parse(file);


	std::cout<< "Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess"<< std::endl;

	for(auto it = data.begin(); it != std::prev(data.end()); ++it){
		
		int memaccess = 0;
		int comparison = 0;

		std::vector<int> insort = it.value().get<std::vector<int>>();
		std::cout<<it.key();

clock_t start = clock();

		InsertionSort(&insort,memaccess,comparison);

clock_t end = clock();
double elatime1 = 10000.0*(end - start)/CLOCKS_PER_SEC;
		std::cout<<','<<elatime1<<','<<comparison<<','<<memaccess;

		memaccess = 0;
		comparison = 0;

		std::vector<int> mesort = it.value().get<std::vector<int>>();

start = clock();

		MergeSort(&mesort,memaccess,comparison);


end = clock();
double elatime2=10000.0*(end-start)/CLOCKS_PER_SEC;
	std::cout<<','<<elatime2<<','<<comparison<<','<<memaccess;
		

		memaccess=0;
		comparison=0;
		std::vector<int> qksort = it.value().get<std::vector<int>>();

start = clock();

		QuickSort(&qksort,memaccess,comparison);
		
end = clock();
double elatime3= 10000.0*(end-start)/CLOCKS_PER_SEC;
	std::cout<<','<<elatime1<<','<<comparison<<','<<memaccess<<std::endl;


	
}




	return 0;
}
