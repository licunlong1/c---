#define _CRT_SECURE_NO_WARNINGS 1
#include"redblacktree.hpp"

void test01() {
	RBTree<int> tree;
	//tree.insert(1);
	//tree.insert(2);
	//tree.insert(3);
	


	int temp;
	while (1) {
		tree.print_RBTree();
		tree.show_RBTree();
		cout << "请输入你要插入节点的数据：" << endl;
		cin >> temp;
		tree.insert(temp);
		system("pause");
		xx = 0;
	}
}

void test02() {
	RBTree<int> tree;
	//tree.insert(1);
	//tree.insert(2);
	//tree.insert(3);
	int begin1 = clock();

	for (int i = 0; i < 10; i++) {
		tree.insert(i + 1);
	}

	int end1 = clock();
	cout << end1 - begin1 << endl;
	int temp;
	while (1) {
		tree.print_RBTree();
		tree.show_RBTree();
		cout << "请输入你要删除节点的数据：" << endl;
		cin >> temp;
		tree.erase(temp);
		system("pause");
		xx = 0;
	}
}

int main() {
	//test01();
	test02();
	return 0;
}