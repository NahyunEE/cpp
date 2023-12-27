#include <iostream>
#include <vector>
#include <ios>




struct num {
	int a;
	int b;
	int sum;
};
std::vector<num> arr;
int main() {

	std::cin.tie(NULL); //입력과 출력의 연결을 줄여준다. 
	//input과 output을 별도로 인식한다.
	std::ios_base::sync_with_stdio(false);
	//C,C++ 간 입력스트림 통일을 하지않는다.



	size_t a;
	std::cin >> a;

	size_t num1, num2;

	struct num _num;

	for (size_t i = 0; i < a; ++i) {
		
		int _a, _b;
		std::cin >> _a >> _b;
		_num.sum = _a + _b;
		_num.a = _a;
		_num.b = _b;
		arr.push_back(_num);
	}

	for (size_t j = 0; j < arr.size(); ++j) {
		std::cout << "Case #" << (j + 1) << ": " << arr[j].a << " + " << arr[j].b << " = " << arr[j].sum << '\n';
	}

}