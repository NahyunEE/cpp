#include <iostream>

int main() {

	int a;
	int b;

	while (std::cin >> a >> b) { // c++은 eof가 존재하지 않는다.
		// 대신에 std::cin이 파일끝에 다다르면 false를 출력한다.
		std::cout << a + b << '\n';
	}

	return 0;


}