#include <iostream>
#include <cstring>
using namespace std;


class String {
public:
	String()
		:data(nullptr),
		size(0),
		capacity(0)
	{
		/*data = nullptr;//в указатели записывают нулевой указатель
		size = 0;
		capacity = 0;*/
		cout << this << " Ля-ля тополя\n";
	}
	explicit String(int i):String(){
		capacity = i;
		data = new char[i] {};
		//size = 0;
	}
	String(const char *str) {
		size = ::strlen(str) + 1;
		capacity = size;
		data = new char[size] {};
		::memcpy(data, str, size);
	}
	String(const String &other) {
		size = other.size;
		capacity = other.capacity;
		data = new char[other.size] {};
		::memcpy(data, other.data, size);
		cout << this << " Ля-ля тополя копия\n";
	}
	const String &operator=(const String &other) {
		if (capacity >= other.size) {
			for (int i = 0; i < size; i++){
				data[i] = '\0';
			}
		}
		else {
			if (data) {
				delete[] data;
			}
			data = new char[other.size + 1];
			capacity = other.size + 1;
		}
		size = other.size;
		::memcpy(data, other.data, size);
		//процесс копирования
		return *this;
	}
	~String() {
		if (data) {
			delete[]data;
		}
		cout << this << " Пичалька(\n";
	}

	void setString(const char *str) {
		(*this) = String(str);
	}

	friend String operator+(String a, String b);
private:
	char *data;
	int size;
	int capacity;
};
String operator+(String a, String b) {
	String result(a.size + b.size);
	::memcpy(result.data, a.data, a.size);
	::memcpy(result.data + a.size, b.data, b.size);
	result.size = a.size + b.size;
	return result;
}
void F00(String obj){}//Вызов кон-ра при создании аргументов

int main() {
	setlocale(LC_ALL, "Russian");
	String a;
	String b(5);
	a = b = static_cast<String>(8);
	String();//Анонимный обьект
	auto point = new String; //Base * point = new Base; Для выделения памяти под обьект
	F00(static_cast<String>(8));
	delete point;
	double r;
	r = (1 / double(6));
	double e;
	e = r = 5.6;
	


	return 0;
}