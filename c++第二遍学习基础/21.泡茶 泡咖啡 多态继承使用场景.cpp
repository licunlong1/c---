//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
//class AbstractDrinking {
//public:
//	void Boil_Witer(){
//		cout << "��ʼ��ˮ��" << endl;
//	}
//	virtual void Stock()  = 0;
//	void Up_Glass() {
//		cout << "���뱭�У�" << endl;
//	}
//	virtual void AddCondiment() = 0;
//};
//void Do_Drink1(AbstractDrinking& b);
//class Coffee :public AbstractDrinking {
//public:
//	virtual void Stock() {
//		cout << "���뿧�ȣ�" << endl;
//	}
//	void operator()(Coffee* abc) {
//		Do_Drink1(*abc);
//		delete abc;
//	}
//	virtual void AddCondiment() {
//		cout << "�����Ǻ�ţ�̣�" << endl;
//	}
//};
//class Tea :public AbstractDrinking {
//public:
//	virtual void Stock() {
//		cout << "���������裡" << endl;
//	}
//	virtual void AddCondiment() {
//		cout << "�������ʣ�" << endl;
//	}
//};
////ʹ�ø�������ý�������Ķ�����ʵ�ֶ�̬
//void Do_Drink1(AbstractDrinking& b) {
//	b.Boil_Witer();
//	b.Stock();
//	b.Up_Glass();
//	b.AddCondiment();
//}
////ʹ�ø����ָ����ʹ�ö�̬ ʹ���꼴��ɾ�� �ͷ� ��ֹ�ڴ�й¶
//void Do_Drink2(AbstractDrinking* b) {
//	b->Boil_Witer();
//	b->Stock();
//	b->Up_Glass();
//	b->AddCondiment();
//	delete b;
//}
//void test01() {
//	AbstractDrinking* b = new Coffee;
//	Do_Drink1(*b);
//	delete b;
//	cout << "----------------------" << endl;
//	b = new Tea;
//	Do_Drink1(*b);
//	delete b;
//}
//void test02() {
//	Do_Drink2(new Coffee);
//	cout << "----------------------" << endl;
//	Do_Drink2(new Tea);
//}
////ʹ�÷º������е���  ��̫��Ӧ
//void test03() {
//	Coffee* c = new Coffee;
//	Coffee()(c);
//}
//
//void test04(int*& a) {
//	cout << *a << endl;
//}
//int main() { 
//
//	//test01();
//
//	test02();
//
//	//test03();
//
//	//int* a = new int(10);
//	//test04(a);//�������ݵĻ��ǿ��Դ���ָ������� �����βο�����ָ������������
//
//	test04(new int(10));//���� �ǲ����Ե�  ��Ϊ ���������˵��ǲ�û���ñ������� ���Բ���ָ�����ý���
//
//	return 0;
//}