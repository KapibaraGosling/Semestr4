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
T input_container(){
	T t;
	typename T::value_type val;
	while(std::cin>>val){
		t.push_back(val);
	}
	std::cin.clear();
	return t;
}

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
	std::cout<<"Введите элементы вектора:\n";
    std::vector<int> vec = input_container<std::vector<int>>();
	std::cout<<"Введите элементы дека:\n";
    std::deque<int> deq = input_container<std::deque<int>>();
    std::cout<<"Введите элементы списка:\n";
    std::list<int> lst = input_container<std::list<int>>();

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
