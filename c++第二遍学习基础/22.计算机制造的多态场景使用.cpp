//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
////cpu������
//class AbstractCpu {
//public:
//	virtual void MakeComputer() = 0;
//	//virtual ~AbstractCpu() = 0;
//};
//
////videocard������
//class AbstractVideoCard {
//public:
//	virtual void MakeComputer() = 0;
//	//virtual ~AbstractVideoCard() = 0;
//
//};
//
////memory������
//class AbstractMemory {
//public:
//	virtual void MakeComputer() = 0;
//	//virtual ~AbstractMemory() = 0;
//
//};
//
////inter��cpu��
//class InterCpu:public AbstractCpu {
//public:
//	virtual void MakeComputer() {
//		cout << "��������Inter��cpu��" << endl;
//	}
//};
////inter��VideoCard��
//
//class InterVideoCard :public AbstractVideoCard {
//public:
//	virtual void MakeComputer() {
//		cout << "��������Inter���Կ���" << endl;
//	}
//};
////inter��memory��
//
//class InterMemory :public AbstractMemory {
//public:
//	virtual void MakeComputer() {
//		cout << "��������Inter���ڴ棡" << endl;
//	}
//};
//
////amd��cpu��
//class AmdCpu :public AbstractCpu {
//public:
//	virtual void MakeComputer() {
//		cout << "��������Amd��cpu��" << endl;
//	}
//};
////Amd��VideoCard��
//
//class AmdVideoCard :public AbstractVideoCard {
//public:
//	virtual void MakeComputer() {
//		cout << "��������Amd���Կ���" << endl;
//	}
//};
////Amd��memory��
//
//class AmdMemory :public AbstractMemory {
//public:
//	virtual void MakeComputer() {
//		cout << "��������Amd���ڴ棡" << endl;
//	}
//};
//
////������Եĺ���
//void Make_Computer(AbstractCpu* a,AbstractVideoCard* b,AbstractMemory* c) {
//	a->MakeComputer();
//	b->MakeComputer();
//	c->MakeComputer();
//	delete a, b, c;
//}
//
//void test01() {
//	Make_Computer(new InterCpu, new InterVideoCard, new InterMemory);
//	Make_Computer(new AmdCpu, new AmdVideoCard, new AmdMemory);
//
//}
//
//int main() {
//
//	test01();
//
//	return 0;
//}