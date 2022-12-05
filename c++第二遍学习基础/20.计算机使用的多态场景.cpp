//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include<iostream>
//using namespace std;
//
//class AbstractClaculate {
//public:
//	virtual int Calculate() {
//		return 0;
//	}
//	int m_num1;
//	int m_num2;
//};
//
//class AddCalculate :public AbstractClaculate {
//public:
//	AddCalculate(int num1, int num2) {
//		m_num1 = num1;
//		m_num2 = num2;
//	}
//	virtual int Calculate() override {
//		return m_num1 + m_num2;
//	}
//};
//
//class SubCalculate :public AbstractClaculate {
//public:
//	SubCalculate(int num1, int num2) {
//		m_num1 = num1;
//		m_num2 = num2;
//	}
//	virtual int Calculate() {
//		return m_num1 - m_num2;
//	}
//};
//
//class MulCalculate :public AbstractClaculate {
//public:
//	MulCalculate(int num1, int num2) {
//		m_num1 = num1;
//		m_num2 = num2;
//	}
//	virtual int Calculate() {
//		return m_num1 * m_num2;
//	}
//};
//
//void do_Calculate(AbstractClaculate*& abc) {
//	//cout << abc->m_num1 << abc->m_num2 << endl;
//	cout << abc->Calculate() << endl;
//}
//
//void test01() {
//	AbstractClaculate *abc = new AddCalculate(100,200);
//	do_Calculate(abc);
//	delete abc;
//	abc = new SubCalculate(200, 100);
//	do_Calculate(abc);
//	abc = new MulCalculate(200, 100);
//	do_Calculate(abc);
//
//}
//int main() {
//	test01();
//	
//	return 0;
//}