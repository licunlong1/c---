#define _CRT_SECURE_NO_WARNINGS 1
#include"balancedbinarytree.hpp"

void test01() {
	AVLTree<int> tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);

	tree.insert(1);
	tree.insert(12);
	tree.insert(120);
	tree.insert(112);
	tree.insert(128);
	tree.insert(129);
	//tree.insert(129); tree.insert(129); tree.insert(129); tree.insert(129);
	tree.show_AVLTree();
	TreeNode<int>* cur = tree.find(129);
	if (cur) {
		cout << "�ҵ���" << endl;
	}
	int temp;
	while (true) {
		tree.print_AVLTree();
		cout << "��������Ҫɾ���ڵ��ʶ��ֵ��";
		cin >> temp;
		tree.erase(temp);
		//tree.show_AVLTree();
		cout << endl;
		xx = 0;
		system("pause");
	}

}

void test02() {
	AVLTree<int> tree;
	int temp;
	int begin1 = clock();
	for (int i = 0; i < 100; i++) {
		tree.insert(i+1);

	}
	int end1 = clock();
	cout << end1 - begin1 << endl;
	if (tree.is_balancedbinarytree()) {
		cout << "��ƽ����" << endl;
	}


	//while (true) {
	//	tree.print_AVLTree();
	//	//���������������
	//	tree.show_AVLTree();

	//	cout << "��������Ҫɾ���ڵ��ʶ��ֵ��";
	//	cin >> temp;
	//	tree.erase(temp);
	//	//tree.show_AVLTree();
	//	cout << endl;
	//	xx = 0;
	//	system("pause");
	//}
}


int main() {
	test01();
	//test02();


	return 0;
}