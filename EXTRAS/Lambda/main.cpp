#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>        // std::array
#include <memory>


#include <numeric>
#include <future>

bool negative(int n) { return n < 0; }

int negate(int & n) { return n*-1; }
/*
int main() {
	std::array<int, 7> foo = { 0, 1, -1, 3, -3, 5, -5 };
	std::transform(foo.begin(), foo.end(), foo.begin(), negate);
	
	std::shared_ptr<int> p_i = std::shared_ptr<int>(new int [100]);


	for (auto o : foo)
		std::cout << o << " ";

	getchar();
}
*/

/*
int main() {
	std::array<int, 7> foo = { 0, 1, -1, 3, -3, 5, -5 };
	std::transform(foo.begin(), foo.end(), foo.begin(), [](int x){return x*=-1; });

	std::shared_ptr<int> p_i = std::shared_ptr<int>(new int[100]);


	for (auto o : foo)
		std::cout << o << " ";

	getchar();
}
*/
return 0 

int main() {
	std::vector<int> some_list;
	const int multiplier = 2;
	int total = 0;
	for (int i = 0; i<5; i++) some_list.push_back(i);

	std::for_each(begin(some_list), end(some_list), [&total, multiplier](int x) {total += x*multiplier;} );

	std::cout << "total = " << total;

	getchar();

}
