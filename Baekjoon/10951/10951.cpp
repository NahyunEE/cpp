#include <iostream>

int main() {

	int a;
	int b;

	while (std::cin >> a >> b) { // c++�� eof�� �������� �ʴ´�.
		// ��ſ� std::cin�� ���ϳ��� �ٴٸ��� false�� ����Ѵ�.
		std::cout << a + b << '\n';
	}

	return 0;


}