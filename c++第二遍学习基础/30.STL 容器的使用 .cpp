//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<deque>//双向数组 可以头插删 尾插删 插入速度比vertor快 访问速度比较慢
//#include<vector>//单向数组 头插效率比较低  尾插删 访问速度挺快
//#include<list>//内层是双向链表
//#include<algorithm>//标准算法
//#include<map>//键值对的形式  heapmap表
//#include<stack>//栈的数据结构  first int last out   filo  取栈顶top  删除栈顶数据pop push
//#include<set>//集合 集合中不能有相同的元素 multiset可以有相同的元素
//#include<queue>//队列 先进先出  first int first out fifo 取队头队尾 front back  push pop
//using namespace std;
//
////STL  stand template library  标准模板库
////STL 的六大组件  容器 算法 迭代器 仿函数 适配器 网络配置器
////1.序列式容器  物理上是连续存储的一块空间  数组 vector deque stack queue
////2.非序列数容器 物理上不是连续存储的 逻辑上是线性空间（数组也是线性） list map set （multi）
////1.质变算法  实际意义就是改变容器的数据称为质变算法  比如 copy replace pop
////2.非质变算法 实际意义就是不改变容器的数据称为非质变算法  比如find find_if for_each
////迭代器用的比较多的  双向迭代器 随机迭代器
//
//
//
//
////创建类
//class Person {
//public:
//	Person(string name, int age) :m_Name(name), m_Age(age) {
//
//	}
//
//	string m_Name;
//	int m_Age;
//
//};
////打印人属性的函数
//void PrintPerson(vector<Person> p) {
//	//自动类型推导访问
//	for (auto p1 : p) {
//		cout <<"姓名："<< p1.m_Name <<"\n年龄："<< p1.m_Age << endl;
//	}
//}
////打印人属性的函数  迭代器
//void PrintPerson1(vector<Person> p) {
//	//迭代器访问
//	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++) {
//		cout << "姓名：" << it->m_Name << "\n年龄：" << it->m_Age << endl;
//
//	}
//}
////测试vector存内置数据类型
//void test01() {
//	vector<Person> v1;
//	Person p1("猪八戒", 999);
//	Person p2("唐曾", 999);
//	Person p3("孙悟空", 999);
//	Person p4("玉皇大帝", 999);
//	Person p5("小玉米", 999);
//
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//	v1.push_back(p4);
//	v1.push_back(p5);
//	PrintPerson(v1);
//	//PrintPerson1(v1);
//
//}
//
//
////测试容器嵌套容器
//void test02() {
//	vector<vector<int>> v;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 1);
//		v3.push_back(i + 2);
//		v4.push_back(i + 3);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	for (auto i : v) {
//		for (auto j : i) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//}
//
////测试string容器
//void test03() {
//	string str1;
//	str1 = "abcdefghde";
//	cout << str1 << endl;
//	str1 += str1;
//	cout << str1 << endl;
//	string str2;
//
//	str2.assign(10, 'w');
//	cout << str2 << endl;
//
//	string str3(str2);
//	cout << str3 << endl;
//	string str4;
//	str4.assign(str2.begin(), str2.end());
//	cout << str4 << endl;
//
//	int pos = str1.find("de");
//	cout << pos << endl;
//	int pos1 = str1.rfind("de");
//	cout << pos1 << endl;
//
//
//	str4.replace(str4.begin() + 1, str4.begin() + 4, "abcedf");
//	cout << str4 << endl;
//
//	str4[str4.rfind('w')] = 'a';
//	cout << str4 << endl;
//	for (string::reverse_iterator it = str4.rbegin(); it != str4.rend(); it++) {
//		cout << *it << endl;
//		
//	}
//	for (size_t i = 0; i < str4.size(); i++) {
//		cout << str4.at(i) << " ";
//	}
//
//	cout << str1.substr(4) << endl;
//}
//
////vector的测试  front back的数据也是可以取出来的  v.at(i)   swap 可以交换两个vector
//void test04() {
//
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i + 10);
//	}
//	if (!v.empty()) {
//		cout << "v不为空" << endl;
//		cout << "v的容量为：" << v.capacity() << endl;
//		cout << "v的大小为：" << v.size() << endl;
//	}
//
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//
//	v.push_back(1);
//	cout << "v的容量为：" << v.capacity() << endl;
//	cout << "v的大小为：" << v.size() << endl;
//
//	//计算v2容器存储了10万个数据 开辟空间开辟了多少次
//	vector<int> v2;
//	vector<int> v3;
//	v3.reserve(100000);
//	int count = 0;
//	int* p = NULL;
//	for (int i = 0; i < 100000; i++) {
//		v2.push_back(i);
//		if (p != &v2[0]) {
//			count++;
//			p = &v2[0];
//		}
//	}
//	cout << "v2容器存储了10万个数据 开辟了" << count << "次内存！" << endl;
//
//	count = 0;
//	for (int i = 0; i < 100000; i++) {
//		v3.push_back(i);
//		if (p != &v3[0]) {
//			count++;
//			p = &v3[0];
//		}
//	}
//	cout << "v3容器存储了10万个数据 开辟了" << count << "次内存！" << endl;
//
//
//	v3.resize(10);
//	cout << "v3的容量为：" << v3.capacity() << endl;
//	cout << "v3的大小为：" << v3.size() << endl;
//	vector<int>(v3).swap(v3);
//	cout << "\nv3的容量为：" << v3.capacity() << endl;
//	cout << "v3的大小为：" << v3.size() << endl;
//
//	v3.resize(20, 100);
//	for (auto i : v3) cout << i << " ";
//}
//
////deque和vector应用的方法基本一样  deque多了一个头插头删 效率比较高 头尾指针维护着
////deque中没有容量的概念 插入一个开辟一个 基本就是这样
//bool compare(int val) {
//	return val < 9;
//}
//
//void my_print(int val) {
//	cout << val << " ";
//}
//void test05() {
//
//	deque<int> d1;
//	int count = 0;
//	int* p = NULL;
//	for (int i = 0; i < 20; i++) {
//		d1.push_front(i);
//		if (p != &d1[0]) {
//			count++;
//			p = &d1[0];
//		}
//	}
//	//头插 这里输出20  就是循环次数的输出 说明开辟空间开辟了N次 但是头插确实很方便
//	cout << count << endl;
//
//	for (int i = 0; i < 20; i++)cout << d1.at(i) << " ";
//	cout << endl;
//
//	d1.insert(find(d1.begin(), d1.end(), 9), 10);
//	for (int i = 0; i < 21; i++)cout << d1.at(i) << " ";
//	cout << endl;
//
//	//find_if需要自己手动写入谓词 也就是函数的指针 compare
//	deque<int>::iterator it = find_if(d1.begin(), d1.end(), compare);
//	for_each(it, d1.end(), my_print);
//}
//
//int main() {
//	//test01();
//
//	//test02();
//
//	//test03();
//
//	//test04();
//
//	test05();
//	return 0;
//}
////#include<vector>
////#include<iostream>
////#include<memory>
////using namespace std;
//////观察者
////class Observer
////{
////public:
////	Observer(void  (*doA)()) :doAction(doA) {}
////	void (*doAction)();//函数指针
////};
////
//////被观察主体
////class Subject
////{
////	vector<Observer> observers;
////public:
////	void attach(Observer observer)
////	{
////		observers.push_back(observer);
////	}
////	void notifyAllObservers()
////	{
////		for (auto it = observers.begin(); it != observers.end(); it++)
////		{
////			it->doAction();
////		}
////	}
////};
////
////int main()
////{
////	Subject sj;
////	sj.attach(Observer([] {static int state = 0; state++; cout << "匿名类1当前状态为" << state << endl; }));//匿名函数
////	sj.attach(Observer([] {static int state = 2; state++; cout << "匿名类2当前状态为" << state << endl; }));
////	sj.notifyAllObservers();
////}
