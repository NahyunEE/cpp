#include <iostream>

int main() {

	size_t i = 0;
	std::cin >> i;

	char tmp;

	for (size_t f = 1; f <= i; f++) {

		for (size_t j = 1; j <= i; j++) {
			
			if (j <= i-f) {
				std::cout << ' ';
			}
			else {
				std::cout << "*";
			}
		}
		std::cout << '\n';


	}

}