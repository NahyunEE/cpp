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
			// �뷮 �ø���
			capacity_ = capacity_ * 2;

			// �޸� ���� �Ҵ�
			T* new_data = new T[capacity_];

			// ���� ������ ����
			std::copy(data_, data_ + size_, new_data);

			// ���� �޸� ����
			delete[] data_;

			// ���� ������ ��ü
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
		std::cout << "��ü ����" << std::endl;
	}
	
	Student(){}

	Student(const Student& s) {
		std::cout << "��������� ����";

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
	//	//Student na1 = na; //�����Ͽ���
	//}
	//catch (std::exception& e) {
	//	std::cout << "unique_ptr�δ� ��ü�� ������ �� �����ϴ�."<<std::endl;
	//}

	std::shared_ptr<Student> song = std::make_shared<Student>("songhyun", 19);
	song->studentInfo();

	std::shared_ptr<Student> sing = song;

	sing->studentInfo();

	std::shared_ptr<Student> sang;

	sang = std::move(song);
	
	sang->studentInfo();



	//weak ptr




	//share ptr : ������� ���� ����� �ϼ̴µ� ���� �𸣰���


}