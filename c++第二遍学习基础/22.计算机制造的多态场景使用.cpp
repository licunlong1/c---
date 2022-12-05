//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
////cpu抽象类
//class AbstractCpu {
//public:
//	virtual void MakeComputer() = 0;
//	//virtual ~AbstractCpu() = 0;
//};
//
////videocard抽象类
//class AbstractVideoCard {
//public:
//	virtual void MakeComputer() = 0;
//	//virtual ~AbstractVideoCard() = 0;
//
//};
//
////memory抽象类
//class AbstractMemory {
//public:
//	virtual void MakeComputer() = 0;
//	//virtual ~AbstractMemory() = 0;
//
//};
//
////inter的cpu类
//class InterCpu:public AbstractCpu {
//public:
//	virtual void MakeComputer() {
//		cout << "正在制造Inter的cpu！" << endl;
//	}
//};
////inter的VideoCard类
//
//class InterVideoCard :public AbstractVideoCard {
//public:
//	virtual void MakeComputer() {
//		cout << "正在制造Inter的显卡！" << endl;
//	}
//};
////inter的memory类
//
//class InterMemory :public AbstractMemory {
//public:
//	virtual void MakeComputer() {
//		cout << "正在制造Inter的内存！" << endl;
//	}
//};
//
////amd的cpu类
//class AmdCpu :public AbstractCpu {
//public:
//	virtual void MakeComputer() {
//		cout << "正在制造Amd的cpu！" << endl;
//	}
//};
////Amd的VideoCard类
//
//class AmdVideoCard :public AbstractVideoCard {
//public:
//	virtual void MakeComputer() {
//		cout << "正在制造Amd的显卡！" << endl;
//	}
//};
////Amd的memory类
//
//class AmdMemory :public AbstractMemory {
//public:
//	virtual void MakeComputer() {
//		cout << "正在制造Amd的内存！" << endl;
//	}
//};
//
////制造电脑的函数
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