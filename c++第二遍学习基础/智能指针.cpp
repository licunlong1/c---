#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<memory>

#include"mshared_pointer.h"
using namespace std;

template <class _Ty>
class My_auto_ptr {

	_Ty* _My_ptr;
public:
	My_auto_ptr(_Ty* t = NULL)
		: _My_ptr(t) 
	{}
	~My_auto_ptr() {
		if (_My_ptr) {
			delete _My_ptr;
		}
	}
	_Ty* get() const {
		return _My_ptr;
	}

    _Ty* operator->() {
		return _My_ptr;
	}

	_Ty& operator*() {
		return *_My_ptr;
	}

	void reset(_Ty* ptr) {
		delete _My_ptr;
		_My_ptr = ptr;
	}

	_Ty* release() {
		_Ty* temp = _My_ptr;
		_My_ptr = NULL;
		return temp;
	}

	void swap(My_auto_ptr<_Ty>& _Other) {
		std::swap(this->_My_ptr, _Other._My_ptr);
	}

};


class Int {
	int _value;
public:
	Int(int i = 0)
		:_value(i) {
		cout << "Create Int!" << endl;
	}
	~Int() {
		cout << "Destory Int!" << endl;
	}

	void PrintInfo() {
		cout << _value << endl;
	}

	void Set_value(int num) {
		_value = num;
	}



};

void func1(std::unique_ptr<int> p1) {
	cout << *p1 << endl;
}

void func2(std::unique_ptr<int> &p1) {
	cout << *p1 << endl;
}

int main() {

	shared_ptr<int> i_s_ptr1 = make_shared<int>(20);

	shared_ptr<int> i_s_ptr2 = i_s_ptr1;
	shared_ptr<int> i_s_ptr3 = i_s_ptr1;

	cout << "i_s_ptr1 use count : " << i_s_ptr1.use_count() << endl;
	cout << "i_s_ptr2 use count : " << i_s_ptr2.use_count() << endl;
	cout << "i_s_ptr3 use count : " << i_s_ptr3.use_count() << endl;
	std::cout << *i_s_ptr1 << "  " << *i_s_ptr2 << "  " << *i_s_ptr3 << "  " << endl;

	i_s_ptr1.reset();
	cout << "i_s_ptr1 use count : " << i_s_ptr1.use_count() << endl;
	cout << "i_s_ptr2 use count : " << i_s_ptr2.use_count() << endl;
	cout << "i_s_ptr3 use count : " << i_s_ptr3.use_count() << endl;

	//My_auto_ptr<Int> p1(new Int(10));
	//p1->PrintInfo();
	//(*p1).Set_value(200);
	//p1->PrintInfo();

	//My_auto_ptr<Int> p2(new Int(10));

	//p2->PrintInfo();
	//p2.reset(new Int(100));
	//p2->PrintInfo();

	//Int* p = p2.release(); //这里的p2已经是NULL了

	////p2->PrintInfo();  error
	//p->PrintInfo();

	//p1.swap(p2);//  交换之后  p1为空  p2不为空
	//p2->PrintInfo();
	////p1->PrintInfo();//error
	
	//std::unique_ptr<int> i_u_p1(new int(100));

	//std::unique_ptr<int> i_u_p2 = make_unique<int>(10);

	//std::cout << *i_u_p1 << endl;
	//std::cout << *i_u_p2 << endl;

	//std::cout << i_u_p1.get() << endl;
	//std::cout << &i_u_p1<< endl;

	//func1(std::move(i_u_p1));//独占指针传入函数的时候一定要用move 

	//func2(i_u_p2);//独占指针传入函数的时候一定要用move 

	//lcl::shared_ptr<int> s_p1(new int(10));

	//lcl::shared_ptr<int> s_p2(s_p1);
	//lcl::shared_ptr<int> s_p3(s_p1);

	//lcl::shared_ptr<int> s_p4(new int(10));


	//cout << "s_p1 use count:" << s_p1.use_count() << endl;
	//cout << "s_p2 use count:" << s_p2.use_count() << endl;
	//cout << "s_p3 use count:" << s_p3.use_count() << endl;
	//cout << "s_p4 use count:" << s_p4.use_count() << endl;

	////s_p1 = NULL;

	//s_p1 = s_p4;

	//cout << "s_p1 use count:" << s_p1.use_count() << endl;
	//cout << "s_p2 use count:" << s_p2.use_count() << endl;
	//cout << "s_p3 use count:" << s_p3.use_count() << endl;
	//cout << "s_p4 use count:" << s_p4.use_count() << endl;




	Mshared_ptr<int> s_p1(new int(10));

	Mshared_ptr<int> s_p2(s_p1);
	Mshared_ptr<int> s_p3(s_p1);
	Mshared_ptr<int> s_p4(s_p1);


	//cout << "s_p1 use count:" << s_p1.use_count() << endl;
	//cout << "s_p2 use count:" << s_p2.use_count() << endl;
	//cout << "s_p3 use count:" << s_p3.use_count() << endl;
	//cout << "s_p4 use count:" << s_p4.use_count() << endl;

	////s_p1 = NULL;
	//std::cout << "--------------------------------------" << endl;
	////s_p1 = s_p4;
	////s_p2 = s_p4;
	////s_p3 = s_p4;

	//cout << "s_p1 use count:" << s_p1.use_count() << endl;
	//cout << "s_p2 use count:" << s_p2.use_count() << endl;
	//cout << "s_p3 use count:" << s_p3.use_count() << endl;
	//cout << "s_p4 use count:" << s_p4.use_count() << endl;
	//std::cout << "--------------------------------------" << endl;
	s_p3.reset();
	s_p4.reset();
	//std::cout << *s_p1 << "  " << *s_p2 << "  " << *s_p3 << "  " << *s_p4 << endl;

	cout << "s_p1 use count:" << s_p1.use_count() << endl;
	cout << "s_p2 use count:" << s_p2.use_count() << endl;
	cout << "s_p3 use count:" << s_p3.use_count() << endl;
	cout << "s_p4 use count:" << s_p4.use_count() << endl;

	if (s_p1) {
		cout << "s_p1 is not null" << endl;
	}
	cout << s_p1[0] << endl;

	cout << "------------------li------" << endl;
	return 0;
}




//lambda表达式的运用

//int main() {
//
//	int a = 10, b = 20;
//
//	auto Swap = [&]()->void {
//		int temp = a;
//		a = b;
//		b = temp;
//	};
//
//	Swap();
//	cout << a <<"  " <<  b << endl;
//
//	int a1 = 100, b1 = 200;
//
//	auto Swap1 = [=]()mutable->void {
//		int temp = a1;
//		a1 = b1;
//		b1 = temp;
//	};
//
//	Swap1();
//	cout << a1 << "  " << b1 << endl;
//
//	return 0;
//}
