#include <iostream>
#include <vector>
#include <ios>

std::vector<int> arr;


int main() {

	std::cin.tie(NULL); //�Է°� ����� ������ �ٿ��ش�. 
	//input�� output�� ������ �ν��Ѵ�.
	std::ios_base::sync_with_stdio(false);
	//C,C++ �� �Է½�Ʈ�� ������ �����ʴ´�.



	size_t a;
	std::cin >> a;
	
	size_t num1, num2;

	for (size_t i = 0; i < a; i++) {
		std::cin >> num1 >> num2;
		arr.push_back(num1 + num2);
	}

	for (size_t j = 0; j < arr.size(); j++) {
		
		std::cout  << arr[j] << "\n";
	}
	
}