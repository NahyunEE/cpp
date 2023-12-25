#include <iostream>
#include <vector>
#include <string>


std::vector<int> vec;

int main() {

	int testcase;
	int right, left;
	int i=0;
	int j = 0;
	bool flag;
	std::cin >> testcase;

	for (size_t i = 0; i < testcase; i++) {
		right = 0;
		left = 0;
		j = 0;
		flag = false;
		char* a = new char;
		std::cin >> a;

		char temp;

		do {
			temp = *(a + j);

			if (j == 0 && temp == '(') {
				flag = true;
			}

			//std::cout << temp << std::endl;
			if (temp == '(') {
				++right;
			}
			else if (temp == ')') {
				++left;
			}
			else {
			//	std::cerr << "Error";
			}
			j++;
		} while (temp != '\0');


		if ((right == left) && flag) {
			vec.push_back(1);
		}
		else {
			vec.push_back(0);
		}

	}


	for (size_t k = 0; k < vec.size(); ++k) {
	
		if (vec[k]==1) {
			std::cout << "YES" << '\n';
		}
		else {
			std::cout << "NO" << '\n';
		}

	}

}