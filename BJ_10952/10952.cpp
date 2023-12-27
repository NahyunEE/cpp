#include <iostream>

int main() {

	int a;
	int b;

	do {
		std::cin >> a >> b;
		if ((a == 0) && (b == 0)) {
			break;
		}

		std::cout << a + b << '\n';
	} while ((a != 0) || (b != 0));

	return 0;


}