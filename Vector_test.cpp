#define _CRT_SECURE_NO_WARNINGS 1

#include"Vector.hpp"

using namespace LCL;

void test01() {
	Vector<int> v;
	for (int i = 0; i < 20; i++) {
		v.push_back(i + 1);
	}
	v.show();

	Vector<int> v1;
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(2);

	v1.show();
	//std::cout << "½»»»ºó" << std::endl;
	//v.swap(v1);
	//v.show();
	//v1.show();

	//std::cout << v.at(3) << std::endl;
	//std::cout << v[4] << std::endl;
	//v1 = v;
	//v1.show();
	//std::string at = v.empty() ? "is NULL!" : "is not NULL";
	//std::cout << at << std::endl;
	//v.clear();
	//at = v.empty() ? "is NULL!" : "is not NULL";
	//std::cout << at << std::endl;

	for (Vector<int>::Iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}

	v.insert(v.begin() + 3, 20, 1);
	v.show();

	cout << *v.erase(v.begin()) << endl;
	v.show();
}


int main() {
	test01();

	return 0;
}
