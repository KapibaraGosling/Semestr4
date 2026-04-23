/*Дано целое число K и вектор V, содержащий целые числа. 
Используя алгоритм transform и стандартный объект-функцию minus со связывателем bind, 
преобразовать исходный вектор, уменьшив значения всех его элементов на величину K. */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>


int main(){
	std::cout<<"Введите элементы вектора через пробел\n";
    std::vector<int> V{std::istream_iterator<int>(std::cin), 
                   std::istream_iterator<int>()};
    std::cin.clear();
	if(V.empty()){
		throw std::invalid_argument("Ошибка: пустой вектор.");
	}
	int K;
	std::cout<<"Введите число K\n";
	std::cin >> K;
	auto subtract = std::bind(std::minus<int>(), std::placeholders::_1,K);
	std::transform(V.begin(),V.end(), V.begin(), subtract);
	std::cout<<"Итоговый результат:\n";

	for(auto x:V){
		std::cout << x << " ";
	}
	return 0;
}
