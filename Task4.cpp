/*Дано целое число K и вектор V, содержащий целые числа. 
Используя алгоритм transform и стандартный объект-функцию minus со связывателем bind, 
преобразовать исходный вектор, уменьшив значения всех его элементов на величину K. */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

std::vector<int> input_vector(){
	std::vector<int> vec;
	int val;
	while (std::cin >> val){
		vec.push_back(val);
	}
	std::cin.clear();
	return vec;
}


int main(){
	std::cout<<"Введите элементы вектора через пробел\n";
    std::vector<int> V = input_vector();
	if(V.empty()){
		throw std::invalid_argument("Ошибка: пустой вектор.");
	}
	int K;
	std::cout<<"Введите число K\n";
	std::cin >> K;
	auto substract = std::bind(std::minus<int>(), std::placeholders::_1,K);
	std::transform(V.begin(),V.end(), V.begin(), substract);
	std::cout<<"Итоговый результат:\n";

	for(auto x:V){
		std::cout << x << " ";
	}
	return 0;
}
