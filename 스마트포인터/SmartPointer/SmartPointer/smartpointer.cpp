#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include <exception>
#include <cstdint>

template<typename T>
class MyVector {
public:
	MyVector()
		: data_(nullptr),
		capacity_(3),
		size_(0)
	{
		data_ = new T[capacity_];
	}

	~MyVector() {
		delete[] data_;
	}

	void push_back(const T& data) {
		if (size_ >= capacity_) {
			// 용량 늘리기
			capacity_ = capacity_ * 2;

			// 메모리 새로 할당
			T* new_data = new T[capacity_];

			// 기존 데이터 복사
			std::copy(data_, data_ + size_, new_data);

			// 기존 메모리 해제
			delete[] data_;

			// 기존 포인터 대체
			data_ = new_data;
		}

		data_[size_] = data;
		size_ += 1;
	}

private:
	T* data_;
	std::size_t capacity_;
	std::size_t size_;
};



class Student {
private:
	int _age;
	char *_name;
public:
	Student(char* name, int age) {
		this->_age = age;
		_name = new char[20];
		strcpy(_name, name);
		std::cout << "객체 생성" << std::endl;
	}
	
	Student(){}

	Student(const Student& s) {
		std::cout << "복사생성자 생성";

		delete[] _name;

		_name = new char[20];

		_name = s._name;
		_age = s._age;


	}

	void studentInfo() {
		std::cout << "name is " << this->_name << ", " << "age is " << this->_age << std::endl;
	}

};


int main() {
	char name[20] = "nahyun";
	int age = 26;

	//unique ptr
	std::unique_ptr<Student> na = std::make_unique<Student>(name, age);
	na->studentInfo();
	
	

	//try {
	//	//Student na1 = na; //컴파일에러
	//}
	//catch (std::exception& e) {
	//	std::cout << "unique_ptr로는 객체를 복사할 수 없습니다."<<std::endl;
	//}

	std::shared_ptr<Student> song = std::make_shared<Student>("songhyun", 19);
	song->studentInfo();

	std::shared_ptr<Student> sing = song;

	sing->studentInfo();

	std::shared_ptr<Student> sang;

	sang = std::move(song);
	
	sang->studentInfo();



	//weak ptr




	//share ptr : 쓰레드랑 같이 쓰라고 하셨는데 뭔지 모르겠음


}