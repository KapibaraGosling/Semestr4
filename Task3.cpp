/*Даны векторы V1 и V2 с различным количеством элементов. 
Найти все числа (с учетом повторений), которые входят в один из исходных 
векторов и отсутствуют в другом, и вывести их в порядке убывания; 
при этом если, например, некоторое число входит в один из векторов 3 раза, 
а в другой 5 раз, то его надо вывести 2 раза. 
Использовать алгоритм set_symmetric_difference для двух вспомогательных мультимножеств 
и итератора ptout_iterator. Чтобы обеспечить вывод чисел в нужном порядке, 
при создании множеств и в алгоритме использовать функциональный объект greater.  */

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

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
	std::cout<<"Введите элементы первого вектора через пробел\n";
    std::vector<int> vec1 = input_vector();
    std::cout<<"Введите элементы второго вектора через пробел\n";
	std::vector<int> vec2 = input_vector();

	std::multiset <int, std::greater<int>> mulset1(vec1.begin(), vec1.end());
	std::multiset <int, std::greater<int>> mulset2(vec2.begin(), vec2.end());

	std::cout<< "Результат выполнения программы:\n";
	std::set_symmetric_difference(
		mulset1.begin(), mulset1.end(),
		mulset2.begin(), mulset2.end(),
		std::ostream_iterator<int>(std::cout, " "),
		std::greater<int>());
	std::cout << std::endl;
	return 0;

}
