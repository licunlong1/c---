#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>


#define MAX 101   //容量
#define MYNULL -1 //标识 是否为空

template <typename T>
class List;

template <typename T>
class Node {
	friend class List<T>;

private:
	T _data; //数据
	int _next; //记录下标

	Node<T>& operator = (Node<T>& other) {
		_data = other._data;
		_next = other._next;
		return *this;
	}
};

template <typename T>
class List {
	
public:
	List();
	~List(){}

	void insert(int pos,T value);
	void erase(T& value);
	int find(T& value);

	void showList();

private:
	std::vector<Node<T>> v;
	int _size;     //链表长度
	int fail;      //尾标识  记录上一个插入的位置下标
};

template <typename T>
List<T>::List() {
	_size = 0;
	//重新指定大小
	v.resize(MAX);
	for (int i = 0; i < MAX - 1; i++) {
		v[i]._next = MYNULL;
	}
	v[MAX - 1]._next = MYNULL;//最后一个位置的_next当链表头
	fail = MYNULL;            //尾部表示 一开始等于-1
}

template <typename T>
void List<T>::insert(int pos,T value) {
	if (_size >= MAX) {
		std::cout << "capacity exceeds limit!" << std::endl;
	}
	else {
		if (pos >= 0 && pos < MAX - 1) {
			if (v[MAX - 1]._next == MYNULL) {
				v[pos]._data = value;
				v[MAX - 1]._next = pos;
			}
			else {
				v[pos]._data = value;
				v[fail]._next = pos;
			}
			fail = pos;
			_size++;
		}
		else {
			std::cout << "pos is wrongful!" << std::endl;
		}

	}
}

template <typename T>
void List<T>::erase(T& value) {

	//删除   根据输入的下标进行删除
	//
	//if (pos >= 0 && pos < MAX - 1) {
	//	//如果不是尾并且_next 为 MYNULL  那么该位置没有数据
	//	if (v[pos]._next == MYNULL && fail != pos) {
	//		std::cout << "no data at this location!" << std::endl;
	//	}
	//	else {
	//		//找到头位置
	//		int cur = MAX - 1;
	//		while (v[cur]._next != pos) {
	//			cur = v[cur]._next;
	//		}
	//		v[cur]._next = v[pos]._next;

	//		//判读是否需要更新尾标识  删除的是尾部 更新尾部指向标识
	//		if (fail == pos) {
	//			fail = cur;
	//		}
	//	}
	//}
	//else {
	//	std::cout << "pos is wrongful!" << std::endl;
	//}



	//删除   根据输入的值进行删除
	
	//找到头位置
	int cur = MAX - 1;
	int prev = cur;
	while (v[cur]._data != value && cur != fail) {
		prev = cur;
		cur = v[cur]._next;
	}
	//如果找到尾部了 那说明没有找到这个数据 提示
	if (v[cur]._data != value && cur == fail) {
		std::cout << "no find data!" << std::endl;
	}
	else {
		//判读是否需要更新尾标识  删除的是尾部 更新尾部指向标识
		if (v[fail]._data == value) {
			fail = prev;
		}
		v[prev]._next = v[cur]._next;
	}

}


template <typename T>
int List<T>::find(T& value) {
	//找到头位置
	int cur = MAX - 1;
	while (v[cur]._data != value && cur != fail) {
		cur = v[cur]._next;
	}
	//如果找到尾部了 那说明没有找到这个数据 提示
	if (v[cur]._data != value && cur == fail) {
		std::cout << "no find data!" << std::endl;
		return MYNULL;
	}
	else {
		return cur;
	}
}


template <typename T>
void List<T>::showList() {
	int cur = v[MAX - 1]._next;
	while (cur != MYNULL) {
		std::cout << v[cur]._data << " ";
		cur = v[cur]._next;
	}
	std::cout << std::endl;
}

void test01() {
	List<int> L;
	L.insert(21, 200);
	L.insert(31, 300);
	L.insert(41, 400);
	L.insert(51, 500);
	L.insert(61, 600);
	L.insert(71, 700);
	L.insert(81, 100);
	L.insert(25, 2500);


	while (1) {
		L.showList();
		int val;
		//std::cout << "请输入你要删除的位置（下标）:";
		std::cout << "请输入你要删除的值:";
		std::cin >> val;
		L.erase(val);
		L.showList();


		int val1;
		//std::cout << "请输入你要删除的位置（下标）:";
		std::cout << "请输入你要查找的值:";
		std::cin >> val1;
		if (L.find(val1) != MYNULL) {
			std::cout << " find!!! pos is :" << L.find(val1) << std::endl;
		}

		system("pause");
		system("cls");
	}


	
}

int main() {

	test01();

	return 0;
}
