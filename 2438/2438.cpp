#include <iostream>

int main() {
	size_t a;

	std::cin >> a;

	for (size_t i = 1; i < a+1; ++i) {
		for (size_t j = 0; j < i; ++j) {
			std::cout << "*";
		}
		std::cout << '\n';
	}

	return 0;
}