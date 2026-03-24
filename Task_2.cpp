/*Даны вектор V, дек D и список L. Каждый исходный контейнер содержит
 не менее двух элементов, количество элементов является четным. 
 Поменять значения двух средних элементов каждого из исходных контейнеров. 
 Использовать алгоритм swap (не путать его с одноименной функцией-членом контейнера). */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <algorithm>

template <typename T>
void print_container(const std::string& name, const T& container){
	std::cout << "\n" << name << ": ";
	for (auto c: container) std::cout << c << " ";
}

template <typename T>
void swap_middle (T& container){
	auto iterMid1 = std::next(container.begin(), container.size()/2-1);
	auto iterMid2 = std::next(iterMid1);
	std::swap(*iterMid1, *iterMid2);
}

int main(){
    std::vector<int> vec = {10, 20, 30, 40, 50, 60};

    std::deque<int> deq = {1, 2, 3, 4, 5, 6};

    std::list<int> lst = {100, 200, 300, 400, 500, 600, 777, 800};

	std::cout << "\nИсходные данные\n";

	print_container("Vector", vec);
	print_container("Dequeue", deq);
	print_container("List", lst);

	swap_middle(vec);
	swap_middle(deq);
	swap_middle(lst);

	std::cout << "\n\nОбработанные данные\n";

	print_container("Vector", vec);
	print_container("Dequeue", deq);
	print_container("List", lst);
	std::cout << std::endl;
	return 0;	
}
