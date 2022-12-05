//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//
//
//#define MAX 101   //����
//#define MYNULL -1 //��ʶ �Ƿ�Ϊ��
//
//template <typename T>
//class List;
//
//template <typename T>
//class Node {
//	friend class List<T>;
//
//private:
//	T _data; //����
//	int _next; //��¼�±�
//
//	Node<T>& operator = (Node<T>& other) {
//		_data = other._data;
//		_next = other._next;
//		return *this;
//	}
//};
//
//template <typename T>
//class List {
//	
//public:
//	List();
//	~List(){}
//
//	void insert(int pos,T value);
//	void erase(T& value);
//	int find(T& value);
//
//	void showList();
//
//private:
//	std::vector<Node<T>> v;
//	int _size;     //������
//	int fail;      //β��ʶ  ��¼��һ�������λ���±�
//};
//
//template <typename T>
//List<T>::List() {
//	_size = 0;
//	//����ָ����С
//	v.resize(MAX);
//	for (int i = 0; i < MAX - 1; i++) {
//		v[i]._next = MYNULL;
//	}
//	v[MAX - 1]._next = MYNULL;//���һ��λ�õ�_next������ͷ
//	fail = MYNULL;            //β����ʾ һ��ʼ����-1
//}
//
//template <typename T>
//void List<T>::insert(int pos,T value) {
//	if (_size >= MAX) {
//		std::cout << "capacity exceeds limit!" << std::endl;
//	}
//	else {
//		if (pos >= 0 && pos < MAX - 1) {
//			if (v[MAX - 1]._next == MYNULL) {
//				v[pos]._data = value;
//				v[MAX - 1]._next = pos;
//			}
//			else {
//				v[pos]._data = value;
//				v[fail]._next = pos;
//			}
//			fail = pos;
//			_size++;
//		}
//		else {
//			std::cout << "pos is wrongful!" << std::endl;
//		}
//
//	}
//}
//
//template <typename T>
//void List<T>::erase(T& value) {
//
//	//ɾ��   ����������±����ɾ��
//	//
//	//if (pos >= 0 && pos < MAX - 1) {
//	//	//�������β����_next Ϊ MYNULL  ��ô��λ��û������
//	//	if (v[pos]._next == MYNULL && fail != pos) {
//	//		std::cout << "no data at this location!" << std::endl;
//	//	}
//	//	else {
//	//		//�ҵ�ͷλ��
//	//		int cur = MAX - 1;
//	//		while (v[cur]._next != pos) {
//	//			cur = v[cur]._next;
//	//		}
//	//		v[cur]._next = v[pos]._next;
//
//	//		//�ж��Ƿ���Ҫ����β��ʶ  ɾ������β�� ����β��ָ���ʶ
//	//		if (fail == pos) {
//	//			fail = cur;
//	//		}
//	//	}
//	//}
//	//else {
//	//	std::cout << "pos is wrongful!" << std::endl;
//	//}
//
//
//
//	//ɾ��   ���������ֵ����ɾ��
//	
//	//�ҵ�ͷλ��
//	int cur = MAX - 1;
//	int prev = cur;
//	while (v[cur]._data != value && cur != fail) {
//		prev = cur;
//		cur = v[cur]._next;
//	}
//	//����ҵ�β���� ��˵��û���ҵ�������� ��ʾ
//	if (v[cur]._data != value && cur == fail) {
//		std::cout << "no find data!" << std::endl;
//	}
//	else {
//		//�ж��Ƿ���Ҫ����β��ʶ  ɾ������β�� ����β��ָ���ʶ
//		if (v[fail]._data == value) {
//			fail = prev;
//		}
//		v[prev]._next = v[cur]._next;
//	}
//
//}
//
//
//template <typename T>
//int List<T>::find(T& value) {
//	//�ҵ�ͷλ��
//	int cur = MAX - 1;
//	while (v[cur]._data != value && cur != fail) {
//		cur = v[cur]._next;
//	}
//	//����ҵ�β���� ��˵��û���ҵ�������� ��ʾ
//	if (v[cur]._data != value && cur == fail) {
//		std::cout << "no find data!" << std::endl;
//		return MYNULL;
//	}
//	else {
//		return cur;
//	}
//}
//
//
//template <typename T>
//void List<T>::showList() {
//	int cur = v[MAX - 1]._next;
//	while (cur != MYNULL) {
//		std::cout << v[cur]._data << " ";
//		cur = v[cur]._next;
//	}
//	std::cout << std::endl;
//}
//
//void test01() {
//	List<int> L;
//	L.insert(21, 200);
//	L.insert(31, 300);
//	L.insert(41, 400);
//	L.insert(51, 500);
//	L.insert(61, 600);
//	L.insert(71, 700);
//	L.insert(81, 100);
//	L.insert(25, 2500);
//
//
//	while (1) {
//		L.showList();
//		int val;
//		//std::cout << "��������Ҫɾ����λ�ã��±꣩:";
//		std::cout << "��������Ҫɾ����ֵ:";
//		std::cin >> val;
//		L.erase(val);
//		L.showList();
//
//
//		int val1;
//		//std::cout << "��������Ҫɾ����λ�ã��±꣩:";
//		std::cout << "��������Ҫ���ҵ�ֵ:";
//		std::cin >> val1;
//		if (L.find(val1) != MYNULL) {
//			std::cout << " find!!! pos is :" << L.find(val1) << std::endl;
//		}
//
//		system("pause");
//		system("cls");
//	}
//
//
//	
//}
//
//int main() {
//
//	test01();
//
//	return 0;
//}
