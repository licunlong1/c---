
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>
#include<queue>
using namespace std;


template<class T>
class AVLTree;

template<class T>
//���Ľڵ�
class TreeNode {

	friend class AVLTree<T>;

private:
	//Ĭ�Ϲ��캯��
	TreeNode() :height(1), fre(1), LChild(NULL), RChild(NULL), Parent(NULL) {}

	//�����ڵ�  �вι��캯��
	TreeNode(T data1) :data(data1), height(1), fre(1), LChild(NULL), RChild(NULL), Parent(NULL) {}

	//������ָ��
	TreeNode<T>* LChild;
	TreeNode<T>* RChild;
	TreeNode<T>* Parent;

	//����
	T data;

	//��¼��ǰ�ڵ�Ϊ���ĸ߶�
	int height;

	//��¼��ǰ�ڵ�ֵ���ֵĴ��� Ƶ��
	unsigned int fre;

	//��¼��ӡ�����ζ�����
	int rank;
};

template<class T>
class AVLTree {
private:
	//���ڵ�
	TreeNode<T>* root;

	//��ȡ��ǰ�ڵ����ĸ߶�
	int Get_Height(TreeNode<T>* root);

	//�Ƚ����ĸ߶�
	int Com_AVLTree_H(int height_1, int height_2);

	//ƽ�����������������
	void Tree_In_Order(const TreeNode<T>* root);

	//����ɾ�����ĺ�̽ڵ�
	TreeNode<T>* Find_Back_Node(const TreeNode<T>* root);

	//avl������ڵ�
	void Insert_Pir(TreeNode<T>*& root, const T& data);

	//����ֵ���ڽڵ�
	TreeNode<T>* Find_Pir(TreeNode<T>*& root, const T& data);

	//ɾ��ֵ���ڵĽڵ�
	void Erase_Pir(TreeNode<T>*& root, const T& data);

	//���µ���ÿ���ڵ����ĸ߶�  �൱�ں������
	void Adjust_Tree_H(TreeNode<T>*& root);

	//��ӡ��
	void Print_AVLTree(TreeNode<T>* root);

	//ƽ�����������������  �ʺϴ�ӡ������״
	void Tree_In_Order1(TreeNode<T>*& root);

	//��Ҫ�����Ľڵ�ƽ��������-2��2 ��4����� �������ڵ��ƽ��������2ʱ ˵��������  �Һ��ӵ�ƽ������Ϊ1 �������������  ����
	void AVLTree_Left_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1);

	//��Ҫ�����Ľڵ�ƽ��������-2��2 ��4����� �������ڵ��ƽ��������-2ʱ ˵��������  �Һ��ӵ�ƽ������Ϊ-1 �������������  ����
	void AVLTree_Right_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1);


	//��Ҫ�����Ľڵ�ƽ��������-2��2 ��4����� �������ڵ��ƽ��������2ʱ ˵��������  �Һ��ӵ�ƽ������Ϊ-1 ������������� ��Ҫ��ת�ӽڵ�
	//��Ҫ�����Ľڵ�ƽ��������-2��2 ��4����� �������ڵ��ƽ��������-2ʱ ˵��������  �Һ��ӵ�ƽ������Ϊ1 �������������


	//��ת ������ת
	void AVLTree_Rotate(TreeNode<T>*& root, TreeNode<T>*& parent1);

	//�ж��Ƿ���ƽ�������
	bool Is_Balanced_Binary_Tree_Pir(TreeNode<T>* root);

public:
	//���Ĺ��캯��
	AVLTree() :root(NULL) {}

	//avl������ڵ�
	void insert(const T& data);

	//����ֵ���ڽڵ�
	TreeNode<T>* find(const T& data);

	//ɾ��ֵ���ڵĽڵ�
	void erase(const T& data);

	//��ӡ��
	void show_AVLTree();

	//��ӡ����
	void print_AVLTree();

	//�ж��Ƿ���ƽ�������
	bool is_balancedbinarytree();

};
//���ڽӿ�

//��ȡ���ĸ߶�
template<class T>
int AVLTree<T>::Get_Height(TreeNode<T>* root) {
	if (!root) return 0;
	return root->height;
}

//һ��ʹ�ñȽ����������ĸ߶�������ƽ������
template<class T>
int AVLTree<T>::Com_AVLTree_H(int height_1, int height_2) {
	return height_1 - height_2;//��������ȥ��������ƽ������
}

//�������
template<class T>
void AVLTree<T>::Tree_In_Order(const TreeNode<T>* root) {
	if (!root) return;
	Tree_In_Order(root->LChild);
	cout << root->data << " ";
	Tree_In_Order(root->RChild);
}

//���Һ�̽ڵ�
template<class T>
TreeNode<T>* AVLTree<T>::Find_Back_Node(const TreeNode<T>* root) {
	TreeNode<T>* right = root->RChild;
	TreeNode<T>* parent = NULL;
	//���ҵ�ǰ�ڵ�ĺ�̽ڵ�  ��ǰ�ڵ��������Сֵ�Ľڵ�
	while (right) {
		parent = right;
		right = right->LChild;
	}
	return parent;
}


//����ʹ���˵ݹ� ȷʵ������һ������  ������������
//template<class T>
//TreeNode<T>*& AVLTree<T>::Insert_Pir(TreeNode<T>*& root, const T& data) {
//	//����ʹ���������������ķ���ֵ ���ǿ����ò���Ľڵ����ӵ�����
//	if (!root) {
//		TreeNode<T>* newnode = new TreeNode<T>(data);
//		root = newnode;
//		//����ڵ�ɹ� �������ĵ���
//		cout << "����ڵ�ɹ�" << endl;
//		
//		return root;
//	}
//	else {
//		if (data > root->data) {
//			Insert_Pir(root->RChild, data)->Parent = root;
//		}
//		else if (data < root->data) {
//			Insert_Pir(root->LChild, data)->Parent = root;
//		}
//		else ++root->fre;//�������ڵ����ĳ���ڵ��ֵ �������ĳ��ֵ�Ƶ�ʼ�1
//		//��ǰ���ĸ߶Ⱦ����������������߶ȼ�������ĸ߶�1
//		//int lefth = Get_Height(root->LChild);
//		//int righth = Get_Height(root->RChild);
//		//root->height = lefth > righth ? lefth + 1 : righth + 1;
//		root->height = max(Get_Height(root->LChild), Get_Height(root->RChild)) + 1;
//	}
//	TreeNode<T>* parent = root->Parent;
//	//TreeNode<T>* cur = root->Parent;
//
//	while (parent != NULL) {
//		if (Com_AVLTree_H(Get_Height(parent->RChild), Get_Height(parent->LChild)) == 2) {
//			if (Com_AVLTree_H(Get_Height(parent->RChild->RChild), Get_Height(parent->RChild->LChild)) == 1) {
//				if (Com_AVLTree_H(Get_Height(parent->RChild->RChild), Get_Height(parent->RChild->LChild)) == -1) {
//					AVLTree_Right_Rotate(parent);
//				}
//				AVLTree_Left_Rotate(parent);
//			}
//		}
//		if (Com_AVLTree_H(Get_Height(parent->RChild), Get_Height(parent->LChild)) == -2) {
//			if (Com_AVLTree_H(Get_Height(parent->LChild->RChild), Get_Height(parent->LChild->LChild)) == -1) {
//				if (Com_AVLTree_H(Get_Height(parent->LChild->RChild), Get_Height(parent->LChild->LChild)) == 1) {
//					AVLTree_Left_Rotate(parent);
//				}
//				AVLTree_Right_Rotate(parent);
//			}
//		}
//		//���ϵ���
//		parent = parent->Parent;
//	}
//}



//ѭ���Ĳ���
template<class T>
void AVLTree<T>::Insert_Pir(TreeNode<T>*& root, const T& data) {
	//����ʹ���������������ķ���ֵ ���ǿ����ò���Ľڵ����ӵ�����

	TreeNode<T>* newnode = new TreeNode<T>(data);
	TreeNode<T>* cur = root;
	TreeNode<T>* parent = NULL;
	if (!root) {
		root = newnode;
		//����ڵ�ɹ� �������ĵ���
		cout << "����ڵ�ɹ�" << endl;
		return;
	}
	else {
		//�ҵ�����ڵ�ĸ��ڵ�
		while (cur) {
			if (data > cur->data) {
				parent = cur;
				cur = cur->RChild;
			}
			else if (data < cur->data) {
				parent = cur;
				cur = cur->LChild;
			}
			else {
				//�������ڵ����ĳ���ڵ��ֵ �������ĳ��ֵ�Ƶ�ʼ�1

				++root->fre;
				return;
			}
		}
		cur = newnode;
		//����ڵ���parent��data���Ƚ�
		if (data > parent->data) {
			parent->RChild = cur;
			cur->Parent = parent;
		}
		else if (data < parent->data) {
			parent->LChild = cur;
			cur->Parent = parent;
		}
		//��ǰ���ĸ߶Ⱦ����������������߶ȼ�������ĸ߶�1
		//int lefth = Get_Height(root->LChild);
		//int righth = Get_Height(root->RChild);
		//root->height = lefth > righth ? lefth + 1 : righth + 1;
		//���µ������ĸ߶�
		Adjust_Tree_H(root);
	}
	//TreeNode<T>* parent = root->Parent;
	//TreeNode<T>* cur = root->Parent;
	//���������ĸ߶�֮�� �ж��Ƿ���Ҫ������ת
	AVLTree_Rotate(root, parent);

}

//���ҽڵ�
template<class T>
TreeNode<T>* AVLTree<T>::Find_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) return NULL;
	else {
		TreeNode<T>* cur = root;
		TreeNode<T>* cur1 = NULL;
		if (data > cur->data) {
			//ȥ��������
			return Find_Pir(cur->RChild, data);
		}
		else if (data < cur->data) {
			//ȥ��������
			return Find_Pir(cur->LChild, data);
		}
		else {
			// �ҵ��� ����
			return root;
		}
	}
}


//ɾ���ڵ���Щ���� ���Խ����Ż� ����ɲο������
template<class T>
void AVLTree<T>::Erase_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) {
		cout << "��ǰƽ����Ϊ�գ��޷��ٴ�ɾ����" << endl;
		return;
	}
	//���ҵ���Ҫɾ��ͬ�����ݵĽڵ�
	TreeNode<T>* select = find(data);

	//���Һ�̽ڵ� ��������������Сֵ�Ľڵ�  �滻�ڵ�
	TreeNode<T>* backnode = Find_Back_Node(select);
	

	if (select == NULL) {
		cout << "��Ҫɾ���Ľڵ㲻���� ���������룡" << endl;
		return;
	} 
	//��¼���ҽڵ�ĸ��׽ڵ�
	TreeNode<T>* parent = select->Parent;

	//�滻�ڵ�ĸ��ڵ�
	TreeNode<T>* backnodeparent = NULL;

	//������е���  ��Ϊɾ���Ŀ�����Ҷ�ӽڵ� ��̽ڵ�ΪNULL �޺�̽ڵ� ������ȻҲû�к�̽ڵ�ĸ��� ������ת����ʱ��Ҫ�õ���̽ڵ�  ������Ҫ�ж�
	if(backnode) backnodeparent = backnode->Parent;
	//����ɾ���Ľڵ���Ҷ�ӽڵ�
	if (select->LChild == NULL && select->RChild == NULL) {
		//�ж�ɾ�����Ƿ��Ǹ��ڵ�
		if (parent == NULL) {
			root = NULL;
		}
		else {
			select == parent->LChild ? parent->LChild = NULL : parent->RChild = NULL;
		}
	}
	//����ɾ���Ľڵ�ֻ��һ������
	else if (select->LChild == NULL || select->RChild == NULL) {
		//���ɾ�����Ǹ��ڵ� �Ҹ��ڵ�ֻ��һ������
		//��¼һ�º��ӵĽڵ�
		TreeNode<T>* child = select->RChild == NULL ? select->LChild : select->RChild;
		if (parent == NULL) {
			root = (select->LChild != NULL ? select->LChild : select->RChild);
			root->Parent = NULL;
		}
		else {
			select == parent->LChild ? parent->LChild = child : parent->RChild = child;
			//�������ӽڵ�ĸ��� ָ��ɾ���ڵ�ĸ���
			if (child) {
				child->Parent = parent;

			}
		}
	}
	//����ɾ���Ľڵ����������� �ֶ������
	else {
		////���Һ�̽ڵ� ��������������Сֵ�Ľڵ�  �滻�ڵ�
		//TreeNode<T>* backnode = Find_Back_Node(select);
		////�滻�ڵ�ĸ��ڵ�
		//TreeNode<T>* backnodeparent = backnode->Parent;
		////�ж�ɾ�����Ƿ��Ǹ�
		//if (parent == NULL) {
		//	//�ٴ��ж��滻�ڵ� �Ƿ��ǵ�ǰɾ���Ľڵ��������
		//	root = backnode;
		//	if (backnode == select->RChild) {
		//		backnode->Parent = parent;
		//		backnode->LChild = select->LChild;
		//		select->LChild->Parent = backnode;
		//	}
		//	else {
		//		//�滻�ڵ㲻��ɾ���ڵ�������� ��������� �滻�ڵ����Һ��Ӻ����Һ���
		//		TreeNode<T>* child = backnode->RChild;
		//		backnodeparent->LChild = child;
		//		backnode->Parent = select->Parent;
		//		backnode->LChild = select->LChild;
		//		backnode->RChild = select->RChild;
		//		select->LChild->Parent = backnode;
		//		select->RChild->Parent = backnode;
		//	}
		//}
		////ɾ���Ĳ��Ǹ��ڵ�
		//else {
		//	//�ٴ��ж��滻�ڵ� �Ƿ��ǵ�ǰɾ���Ľڵ��������
		//	if (backnode == select->RChild) {
		//		backnode->Parent = parent;
		//		backnode->LChild = select->LChild;
		//		select->LChild->Parent = backnode;
		//		parent->LChild == select ? parent->LChild = backnode : parent->RChild = backnode;
		//	}
		//	else {
		//		//�滻�ڵ㲻��ɾ���ڵ�������� ��������� �滻�ڵ����Һ��Ӻ����Һ���
		//		TreeNode<T>* child = backnode->RChild;
		//		backnodeparent->LChild = child;
		//		backnode->Parent = parent;
		//		backnode->LChild = select->LChild;
		//		backnode->RChild = select->RChild;
		//		select->LChild->Parent = backnode;
		//		select->RChild->Parent = backnode;
		//		parent->LChild == select ? parent->LChild = backnode : parent->RChild = backnode;

		//	}
		//}
		
		
		//��¼�滻�ڵ���Һ���  �����Ƿ�Ϊ��
		TreeNode<T>* child = NULL;
		if (backnode) child = backnode->RChild;

		//�ж�ɾ�����Ƿ��Ǹ�
		if (parent == NULL) {
			//�ٴ��ж��滻�ڵ� �Ƿ��ǵ�ǰɾ���Ľڵ��������
			root = backnode;
		}
		//ɾ���Ĳ��Ǹ��ڵ�
		else {
			//�ٴ��ж��滻�ڵ� �Ƿ��ǵ�ǰɾ���Ľڵ��������
			if (backnode == select->RChild) {
				parent->LChild == select ? parent->LChild = backnode : parent->RChild = backnode;
			}
			else {
				//�滻�ڵ㲻��ɾ���ڵ�������� ��������� �滻�ڵ����Һ��Ӻ����Һ���
				backnodeparent->LChild = child;
				parent->LChild == select ? parent->LChild = backnode : parent->RChild = backnode;

			}
		}
		if (backnode == select->RChild) {
			backnode->Parent = parent;
			backnode->LChild = select->LChild;
			select->LChild->Parent = backnode;
		}
		else {
			//�滻�ڵ㲻��ɾ���ڵ�������� ��������� �滻�ڵ����Һ��Ӻ����Һ���
			backnodeparent->LChild = child;
			backnode->Parent = select->Parent;
			backnode->LChild = select->LChild;
			backnode->RChild = select->RChild;
			select->LChild->Parent = backnode;
			select->RChild->Parent = backnode;
			if (child)
				child->Parent = backnodeparent;
		}
	}
	//���µ����������ĸ߶�
	Adjust_Tree_H(root);


	//���ɾ�����Ǹ��ڵ�Ļ�  ��Ҫ������ ��̽ڵ㸸��Ϊ������
	if (parent == NULL) AVLTree_Rotate(root, backnodeparent);
	else {
		AVLTree_Rotate(root, parent);
	} 
	if(backnodeparent==select) 
		AVLTree_Rotate(root, backnode);

	//AVLTree_Rotate(root, parent);
	delete select;

}


//����ڵ� ɾ���ڵ� ����Ҫ����ÿ���ڵ�ĸ߶����½��е���  ����������е���
template<class T>
void AVLTree<T>::Adjust_Tree_H(TreeNode<T>*& root) {
	if (!root) return;
	//�Ӹ�����ʼ���� Ҳ���Ǻ������
	Adjust_Tree_H(root->LChild);
	Adjust_Tree_H(root->RChild);
	root->height = max(Get_Height(root->LChild), Get_Height(root->RChild)) + 1;
}

//��ӡ��״
template<class T>
void AVLTree<T>::Print_AVLTree(TreeNode<T>* root) {
	int xx = 0;      //�������ǰ��xx���ó�0
	Tree_In_Order1(root);     //�������
	printf("\n\nTree:\n\n");
	if (!xx) printf("");
	queue<TreeNode<T>*> q;
	if (root) q.push(root);
	while (!q.empty()) {//�������
		int k = q.size(), p = 0;
		while (k--) {   //һ�δ�ӡһ��Ľڵ㣬k��ʾһ��Ľڵ�
			root = q.front();
			q.pop();
			if (root->LChild) q.push(root->LChild);
			if (root->RChild) q.push(root->RChild);
			string str = "";
			while (p < root->rank) {
				str += " ";   //�ڽڵ��x����ǰ��ӡ�ո�
				p++;
			}
			p += to_string(root->data).size();
			printf("%s%d", str.c_str(), root->data);
		}
		printf("\n\n");
	}
}


//������������ֻ����������������״��ӡ
int xx = 0;
template<class T>
void AVLTree<T>::Tree_In_Order1(TreeNode<T>*& root) {
	if (root == NULL) return;
	Tree_In_Order1(root->LChild);
	root->rank = xx;
	xx += to_string(root->data).size();
	Tree_In_Order1(root->RChild);
}

//�Ե�ǰ�ڵ� parent1��������
template<class T>
void AVLTree<T>::AVLTree_Left_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1) {
	TreeNode<T>* right = parent1->RChild;
	TreeNode<T>* left = right->LChild;
	TreeNode<T>* parent = parent1->Parent;
	TreeNode<T>* cur = parent1;

	//˵�����Ǹ��ڵ�
	if (parent == NULL) {
		root = right;
		right->Parent = NULL;

	}
	else {
		right->Parent = parent;
		parent1 == parent->LChild ? parent->LChild = right : parent->RChild = right;

	}
	cur->Parent = right;
	cur->RChild = left;
	right->LChild = cur;
	if (left) {
		left->Parent = cur;
	}
	
}


//�Ե�ǰ�ڵ� parent1��������
template<class T>
void AVLTree<T>::AVLTree_Right_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1) {
	TreeNode<T>* left = parent1->LChild;
	TreeNode<T>* right = left->RChild;
	TreeNode<T>* parent = parent1->Parent;
	TreeNode<T>* cur = parent1;

	//˵�����Ǹ��ڵ�
	if (parent == NULL) {
		root = left;
		left->Parent = NULL;

	}
	else {
		left->Parent = parent;
		parent1 == parent->LChild ? parent->LChild = left : parent->RChild = left;


	}
	cur->Parent = left;
	cur->LChild = right;
	left->RChild = cur;
	if(right)
		right->Parent = cur;
}


//���ĵ��� ѭ������
template<class T>
void AVLTree<T> ::AVLTree_Rotate(TreeNode<T>*& root, TreeNode<T>*& parent) {
	while (parent != NULL) {
		//��ǰ�ڵ����������߶Ȳ�Ϊ2��ʱ����е��� 2˵������������  ��Ҫ����
		if (Com_AVLTree_H(Get_Height(parent->RChild), Get_Height(parent->LChild)) == 2) {
			//��ǰ�ڵ�������������������߶Ȳ�Ϊ-1��ʱ����е��� ˵����ǰ�ڵ������������������߶Ȳ�Ϊ-1  ��߸�  ��Ҫ���������ٽ�������
			if (Com_AVLTree_H(Get_Height(parent->RChild->RChild), Get_Height(parent->RChild->LChild)) == -1) {
				AVLTree_Right_Rotate(root, parent->RChild);
			}
			AVLTree_Left_Rotate(root, parent);
			Adjust_Tree_H(root);
		}
		//��ǰ�ڵ�߶Ȳ�Ϊ-2��ʱ����е��� -2˵������������  ��Ҫ����
		if (Com_AVLTree_H(Get_Height(parent->RChild), Get_Height(parent->LChild)) == -2) {
			//��ǰ�ڵ�������������������߶Ȳ�Ϊ1��ʱ����е��� ˵����ǰ�ڵ������������������߶Ȳ�Ϊ1  �ұ߸�  ��Ҫ���������ٽ�������
			if (Com_AVLTree_H(Get_Height(parent->LChild->RChild), Get_Height(parent->LChild->LChild)) == 1) {
				AVLTree_Left_Rotate(root, parent->LChild);
			}
			AVLTree_Right_Rotate(root, parent);
			//��תһ��֮�����µ���ÿ���ڵ��¼�ĸ߶�
			Adjust_Tree_H(root);
		}
		//���ϵ���
		parent = parent->Parent;

	}
}


//�ж��Ƿ���ƽ�������
template<class T>
bool AVLTree<T>::Is_Balanced_Binary_Tree_Pir(TreeNode<T>* root) {
	if (!root) return true;

	return abs(Get_Height(root->LChild) - Get_Height(root->RChild)) < 2
		&& Is_Balanced_Binary_Tree_Pir(root->LChild) 
		&& Is_Balanced_Binary_Tree_Pir(root->RChild);
}


//����ӿ�


template<class T>
TreeNode<T>* AVLTree<T>::find(const T& data) {
	return Find_Pir(root, data);
}


template<class T>
void AVLTree<T>::insert(const T& data) {
	Insert_Pir(root, data);
}

template<class T>
void AVLTree<T>::erase(const T& data) {
	Erase_Pir(root, data);
}

template<class T>
void AVLTree<T>::show_AVLTree() {
	Tree_In_Order(root);
	
	//�������ĸ߶�
	//cout << root->height << endl;
	//cout << root->LChild->height << endl;
	//cout << root->RChild->height << endl;
	//cout << root->RChild->RChild->RChild->RChild->fre << endl;//���Ե������ֳ��ֵ�Ƶ��
}


template<class T>
void AVLTree<T>::print_AVLTree() {
	Print_AVLTree(root);
}


template<class T>
bool AVLTree<T>::is_balancedbinarytree(){
	return Is_Balanced_Binary_Tree_Pir(root);
}