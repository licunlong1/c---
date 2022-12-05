
#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<ctime>
using namespace std;

//���ڵ����ɫ  ö��
enum COLOR {
	RED = 0,//0
	BLACK = 1 ,//1
};

template<class T>
class RBTree;

//���Ľڵ�
template<class T>
class TreeNode {

	friend class RBTree<T>;//����RBTree����TreeNode�������  ���Է���TreeNode���˽�г�Ա
private:

	//Ĭ�Ϲ��캯��
	TreeNode() :color(BLACK), fre(1), LChild(NULL), RChild(NULL), Parent(NULL) {}

	//�����ڵ�  �вι��캯��
	TreeNode(T data1) :data(data1), color(RED), fre(1), LChild(NULL), RChild(NULL), Parent(NULL),rank(0) {}

	//������ָ��
	TreeNode<T>* LChild;
	TreeNode<T>* RChild;
	TreeNode<T>* Parent;

	//����
	T data;

	//��¼��ǰ�ڵ����ɫ
	COLOR color;

	//��¼��ǰ�ڵ�ֵ���ֵĴ��� Ƶ��
	unsigned int fre;

	//��¼��ӡ�����ζ�����
	int rank;
};

//�����
template<class T>
class RBTree {
private:
	//���ڵ�
	TreeNode<T>* root;

	//��ȡ��ǰ�ڵ����ɫ
	COLOR Get_Color(TreeNode<T>* root);

	//���ýڵ����ɫ
	void Set_Color(TreeNode<T>* root,COLOR color);

	//��ȡ���׽ڵ�
	TreeNode<T>* Get_Parent(TreeNode<T>* root);

	//��ȡ���ӽڵ�
	TreeNode<T>* Get_Left(TreeNode<T>* root);

	//��ȡ�Һ��ӽڵ�
	TreeNode<T>* Get_Right(TreeNode<T>* root);

	//����������������
	void Tree_In_Order(const TreeNode<T>* root);

	//����ɾ�����ĺ�̽ڵ�
	TreeNode<T>* Find_Back_Node(const TreeNode<T>* root);

	//RB������ڵ�
	void Insert_Pir(TreeNode<T>*& root, const T& data);

	//����ֵ���ڽڵ�
	TreeNode<T>* Find_Pir(TreeNode<T>*& root, const T& data);

	//ɾ��ֵ���ڵĽڵ�
	void Erase_Pir(TreeNode<T>*& root, const T& data);

	//���������
	void Adjust_TreeColor_erase(TreeNode<T>* select);

	//���µ���ÿ���ڵ����ɫ  
	void Adjust_TreeColor_insert(TreeNode<T>*& root);

	//��ӡ��
	void Print_RBTree(TreeNode<T>* root);

	//�����ƽ�����������������  �ʺϴ�ӡ������״
	void Tree_In_Order1(TreeNode<T>*& root);

	//����
	void RBTree_Left_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1);

	//����
	void RBTree_Right_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1);


	//AVL���еĵ���
	//��Ҫ�����Ľڵ�ƽ��������-2��2 ��4����� �������ڵ��ƽ��������2ʱ ˵��������  �Һ��ӵ�ƽ������Ϊ-1 ������������� ��Ҫ��ת�ӽڵ�
	//��Ҫ�����Ľڵ�ƽ��������-2��2 ��4����� �������ڵ��ƽ��������-2ʱ ˵��������  �Һ��ӵ�ƽ������Ϊ1 �������������
	
	
	
public:
	//���Ĺ��캯��
	RBTree() :root(NULL) {}

	//RB������ڵ�
	void insert(const T& data);

	//����ֵ���ڽڵ�
	TreeNode<T>* find(const T& data);

	//ɾ��ֵ���ڵĽڵ�
	void erase(const T& data);

	//��ӡ��
	void show_RBTree();

	//��ӡ����
	void print_RBTree();
};

//���ڽӿ�

//��ȡ��ǰ�ڵ����ɫ
template<class T>
COLOR RBTree<T>::Get_Color(TreeNode<T>* root) {
	return root == NULL ? BLACK : root->color;
}

//���õ�ǰ�ڵ����ɫ
template<class T>
void RBTree<T>::Set_Color(TreeNode<T>* root, COLOR color) {
	if(root != NULL) root->color = color;
}

//��ȡ��ǰ�ڵ�ĸ��ڵ�
template<class T>
TreeNode<T>* RBTree<T>::Get_Parent(TreeNode<T>* root) {
	return root == NULL ? NULL : root->Parent;
}

//��ȡ��ǰ�ڵ������
template<class T>
TreeNode<T>* RBTree<T>::Get_Left(TreeNode<T>* root) {
	return root == NULL ? NULL : root->LChild;

}

//��ȡ��ǰ�ڵ���Һ���
template<class T>
TreeNode<T>* RBTree<T>::Get_Right(TreeNode<T>* root) {
	return root == NULL ? NULL : root->RChild;

}

//�������
template<class T>
void RBTree<T>::Tree_In_Order(const TreeNode<T>* root) {
	if (!root) return;
	Tree_In_Order(root->LChild);
	cout << root->data << " ";
	Tree_In_Order(root->RChild);
}

//���Һ�̽ڵ�
template<class T>
TreeNode<T>* RBTree<T>::Find_Back_Node(const TreeNode<T>* root) {
	TreeNode<T>* right = root->RChild;
	while (right->LChild) {
		right = right->LChild;
	}
	return right;
}


//ѭ���Ĳ���
template<class T>
void RBTree<T>::Insert_Pir(TreeNode<T>*& root, const T& data) {
	//����ʹ���������������ķ���ֵ ���ǿ����ò���Ľڵ����ӵ�����

	TreeNode<T>* newnode = new TreeNode<T>(data);
	TreeNode<T>* cur = root;
	TreeNode<T>* parent = NULL;
	if (!root) {
		newnode->color = BLACK;
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

		//���µ���������ɫ
		Adjust_TreeColor_insert(cur);
	}
	//TreeNode<T>* parent = root->Parent;
	//TreeNode<T>* cur = root->Parent;

}



//�Ժ���������ʽ��е���  ����ʱ��ĵ���
//1.�����ÿ���ڵ㶼�Ǻ�ɫ�ͺ�ɫ   2.���ڵ�����Ǻ�ɫ  3.�սڵ��Ǻ�ɫ    4.��ɫ�ڵ��Ҷ�ӽڵ�����Ǻ�ɫ Ҳ���ǲ�����������������ɫ�ڵ�  5.ÿ��·���Ϻ�ɫ�ڵ����һ��
template<class T>
void RBTree<T>::Adjust_TreeColor_insert(TreeNode<T>*& cur) {
	//�ֶ������
	if (cur == root) return;
	//ͨ��2 3 4����ת�� ���Է���  3 4������Ҫ����
	//3�������ʱ���6����� 2���������Ҫ���� 4����Ҫ  ��4���ж���Ҫ���� ֻ�������常�ڵ������������
	//��ǰ�ڵ㲻�Ǹ��ڵ� ��ǰ�ڵ㲻Ϊ��  ���ڵ����ɫ�Ǻ�ɫ����Ҫ����  ���ڵ���ɫ�Ǻ�ɫ�Ļ�  ������Ǻ�ɫ�ڵ㲻�õ���
	while (cur && cur != root && Get_Color(Get_Parent(cur)) == RED) {
		//��ǰ�ڵ�ĸ��׽ڵ���үү���Һ���
		if (Get_Parent(cur) == Get_Right(Get_Parent(Get_Parent(cur)))) {
	
			//����ڵ���ɫ�Ǻ�ɫ
			if (Get_Color(Get_Left(Get_Parent(Get_Parent(cur)))) == RED) {
				//��ɫ
				Set_Color(Get_Parent(cur), BLACK);//���ڵ��ɺ�ɫ
				Set_Color(Get_Left(Get_Parent(Get_Parent(cur))), BLACK);//���ڵ����Һ��� ��ô�常�ڵ��������  �常�ڵ��ɺ�ɫ
				Set_Color(Get_Parent(Get_Parent(cur)), RED);//үү��ɺ�ɫ
				//�ݹ鴦��
				cur = Get_Parent(Get_Parent(cur));

			}
			//����ڵ��Ǻ�ɫ  Ҳ���ǿսڵ�
			else {
				//��ǰ�ڵ��Ǹ��ڵ�����ӵĻ�  ��Ҫ�Ƚ��������� �ٽ��б�ɫ �ú��үү����
				if (cur == Get_Parent(cur)->LChild) {
					cur = Get_Parent(cur);
					RBTree_Right_Rotate(root, cur);
				}
				Set_Color(Get_Parent(cur), BLACK);
				Set_Color(Get_Parent(Get_Parent(cur)), RED);
				RBTree_Left_Rotate(root, Get_Parent(Get_Parent(cur)));
			}
			
		}
		//��ǰ�ڵ�ĸ�����үү������
		else {
			
			//����ڵ�Ϊ��ɫ
			if (Get_Color(Get_Right(Get_Parent(Get_Parent(cur)))) == RED) {
				//��ɫ
				Set_Color(Get_Parent(cur), BLACK);
				Set_Color(Get_Right(Get_Parent(Get_Parent(cur))), BLACK);
				Set_Color(Get_Parent(Get_Parent(cur)), RED);
				//�ݹ����
				cur = Get_Parent(Get_Parent(cur));

			}
			//��ǰ�ڵ�����ڵ�Ϊ��ɫ  NULL
			else {
				if (cur == Get_Parent(cur)->RChild) {
					cur = Get_Parent(cur);
					RBTree_Left_Rotate(root, cur);
				}
				Set_Color(Get_Parent(cur), BLACK);
				Set_Color(Get_Parent(Get_Parent(cur)), RED);
				RBTree_Right_Rotate(root, Get_Parent(Get_Parent(cur)));
			}
		}
	}
	//���ø��ڵ����ɫ
	root->color = BLACK;
}

//���ҽڵ�
template<class T>
TreeNode<T>* RBTree<T>::Find_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) return NULL;
	else {
		TreeNode<T>* cur = root;
		TreeNode<T>* cur1 = NULL;
		if (data > cur->data) {
			//ȥ��������
			cur1 = Find_Pir(cur->RChild, data);
		}
		else if (data < cur->data) {
			//ȥ��������
			cur1 = Find_Pir(cur->LChild, data);

		}
		else {
			// �ҵ��� ����
			return root;
		}
	}
}


//template<class T>
//void RBTree<T>::Erase_OneChild(TreeNode<T>*& root, TreeNode<T>*& select) {
//	//���׽ڵ�
//	TreeNode<T>* parent = select->Parent;
//
//	//ɾ���Ľڵ���Ҷ�ӽ��
//	if (Get_Left(select) == NULL && Get_Right(select) == NULL) {
//		//���ɾ�����Ǹ��ڵ�
//		if (parent == NULL) {
//			root = NULL;
//		}
//		else {
//			select == parent->LChild ? parent->LChild = NULL : parent->RChild = NULL;
//		}
//		delete select;
//	}//ɾ���Ľڵ���һ�����ӽڵ�
//	else if (Get_Left(select) == NULL || Get_Right(select) == NULL) {
//		//�ҵ����ӽڵ�
//		TreeNode<T>* child = select->LChild == NULL ? select->RChild : select->LChild;
//		select->data = child->data;
//		select->LChild == child ? select->LChild = NULL : select->RChild = NULL;
//		delete child;
//	}
//}

//ɾ���ڵ�
template<class T>
void RBTree<T>::Erase_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) return;
	//����ɾ���Ľڵ�
	TreeNode<T>* select = Find_Pir(root, data);
	if (!select) {
		cout << "�����ݵĽڵ㲻���ڣ�" << endl;
		return;
	}

	//ɾ���Ľڵ����������ӽڵ�
	if (Get_Left(select) != NULL && Get_Right(select) != NULL) {
		//��̽ڵ�  ����ڵ�
		TreeNode<T>* backnode = Find_Back_Node(select);

		select->data = backnode->data;

		//��ɾ���Ľڵ��ɺ�̽ڵ�
		select = backnode;
	}

	//ɾ���Ľڵ���һ�����ӽڵ�
	if (Get_Left(select) != NULL || Get_Right(select) != NULL) {

		//�ҵ����ӽڵ�
		TreeNode<T>* child = select->LChild == NULL ? select->RChild : select->LChild;
		//���ɾ�����Ǹ��ڵ�
		if (select == root) {
			root = child;
			child->Parent = NULL;
		}
		else {
			//�����븸�ڵ��ָ���ϵ
			if (Get_Parent(select)->LChild == select) {
				Get_Parent(select)->LChild = child;
			}
			else {
				Get_Parent(select)->RChild = child;
			}
			child->Parent = Get_Parent(select);
		}
		if (select->color == BLACK) {
			//���������
			Adjust_TreeColor_erase(child);
		}

	}
	else if (select == root) {
		root = NULL;
	}
	//ɾ���Ľڵ���Ҷ�ӽ��
	else {
		if (select->color == BLACK) {
			//���������
			Adjust_TreeColor_erase(select);
		}
		select == Get_Parent(select)->LChild ? Get_Parent(select)->LChild = NULL : Get_Parent(select)->RChild = NULL;
	}
	delete select;

}

//ɾ���ڵ��Ǻ�ɫʱ��Ժ�����ĵ���
template<class T>
void RBTree<T>::Adjust_TreeColor_erase(TreeNode<T>* select) {
	if (!select) return;
	//�����ǰ�ڵ��Ǻ�ɫ����Ҫ����
	while (select != root && select->color == BLACK) {
		//1.�жϸ��ڵ�  �����ǰ�ڵ��Ǹ��ڵ������
		if (select == Get_Parent(select)->LChild) {
			//�ҳ��ֵܽڵ�
			TreeNode<T>* brother = Get_Parent(select)->RChild;
			//�ж��ֵܽڵ��Ƿ�������ֵܽڵ�  ���ֵܽڵ��Ƿ��Ǻ�ɫ
			if (brother->color == RED) {
				//����ֵ��Ǻ�ɫ  ��ô�ö��ֵܺ͸��׽��б�ɫ �ú�����
				Set_Color(brother, BLACK);
				Set_Color(Get_Parent(select), RED);
				RBTree_Left_Rotate(root, Get_Parent(select));
				//���ֵܱ�Ϊ���ڵ���ҽڵ�
				brother = Get_Parent(select)->RChild;
			}
			//�ֵܽڵ㲻���  ���ֵܽڵ���������Ӷ��Ǻ�ɫ�Ļ�  ˵����Ҷ�ӽڵ�  ���ɽ��
			if (Get_Color(Get_Left(brother)) == BLACK && Get_Color(Get_Right(brother)) == BLACK) {
				//û�к��� �費�� ��ô�ð��ֵܵ���ɫ��Ϊ��ɫ
				Set_Color(brother, RED);
				//����ѭ������
				select = Get_Parent(select);

			}//�ֵܽڵ���
			else {
				//��������˵���ֵܽڵ���һ������  �ֵܽڵ��������
				if (Get_Color(Get_Left(brother)) == RED) {
					RBTree_Right_Rotate(root, brother);
					//brother = Get_Parent(brother);
					Set_Color(brother, RED);
					Set_Color(Get_Parent(brother), BLACK);
					//�����ֵܽڵ�
					brother = Get_Parent(select)->RChild;
				}
				//��ɫ
				Set_Color(brother, Get_Color(Get_Parent(select)));
				Set_Color(Get_Parent(select), BLACK);
				Set_Color(Get_Right(brother), BLACK);
				//�Ը��ڵ����һ������
				RBTree_Left_Rotate(root, Get_Parent(select));
				break;
			}

		}
		else {
			//�ҳ��ֵܽڵ�
			TreeNode<T>* brother = Get_Parent(select)->LChild;
			//�ж��ֵܽڵ��Ƿ�������ֵܽڵ�  ���ֵܽڵ��Ƿ��Ǻ�ɫ
			if (brother->color == RED) {
				//����ֵ��Ǻ�ɫ  ��ô�ö��ֵܺ͸��׽��б�ɫ �ú�����
				Set_Color(brother, BLACK);
				Set_Color(Get_Parent(select), RED);
				RBTree_Right_Rotate(root, Get_Parent(select));
				//���ֵܱ�Ϊ���ڵ����ڵ�
				brother = Get_Parent(select)->LChild;
			}
			//�ֵܽڵ㲻���  ���ֵܽڵ���������Ӷ��Ǻ�ɫ�Ļ�  ˵����Ҷ�ӽڵ�  ���ɽ��
			if (Get_Color(Get_Left(brother)) == BLACK && Get_Color(Get_Right(brother)) == BLACK) {
				//û�к��� �費�� ��ô�ð��ֵܵ���ɫ��Ϊ��ɫ
				Set_Color(brother, RED);
				//����ѭ������
				select = Get_Parent(select);

			}//�ֵܽڵ���
			else {
				//��������˵���ֵܽڵ���һ������  �ֵܽڵ��������
				if (Get_Color(Get_Right(brother)) == RED) {
					//���ֵܽڵ�������� ���ֵܽڵ��ɺ�ɫ �ֵܽڵ�ĸ��ڵ��ɺ�ɫ �ҵ���ת֮������ڵ���ֵܽڵ�
					RBTree_Left_Rotate(root, brother);
					//brother = Get_Parent(brother);
					Set_Color(brother, RED);
					Set_Color(Get_Parent(brother), BLACK);
					brother = Get_Parent(select)->LChild;
				}
				//��ɫ
				Set_Color(brother, Get_Color(Get_Parent(select)));
				Set_Color(Get_Parent(select), BLACK);
				Set_Color(Get_Left(brother), BLACK);
				//�Ը��ڵ����һ������ 
				RBTree_Right_Rotate(root, Get_Parent(select));
				break;
			}
		}
	}
	// ѭ������  �����ǰ�ڵ��Ǻ�ɫ ��ôֱ�ӱ�ɫ����  Ҳ�п���ѭ�������ڵ�
	Set_Color(select, BLACK);

}



//�������������ӡ��״
template<class T>
void RBTree<T>::Print_RBTree(TreeNode<T>* root) {
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
				str += "   ";   //�ڽڵ��x����ǰ��ӡ�ո�
				p++;
			}
			p += to_string(root->data).size();
			printf("%s%d", str.c_str(), root->data);
			cout << ":"<<root->color;
		}
		printf("\n\n");
	}
}

//���������ֻ����¼ ������ӡ
int xx = 0;
template<class T>
void RBTree<T>::Tree_In_Order1(TreeNode<T>*& root) {
	//������������ֻ����������������״��ӡ
	if (root == NULL) return;
	Tree_In_Order1(root->LChild);
	root->rank = xx;
	xx += to_string(root->data).size();
	Tree_In_Order1(root->RChild);
}

//��parent1�ڵ��������
template<class T>
void RBTree<T>::RBTree_Left_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1) {
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

//��parent1�ڵ��������
template<class T>
void RBTree<T>::RBTree_Right_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1) {
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
	if (right)
		right->Parent = cur;
}


//����ӿ�


//����
template<class T>
TreeNode<T>* RBTree<T>::find(const T& data) {
	return Find_Pir(root, data);
}

//����
template<class T>
void RBTree<T>::insert(const T& data) {
	Insert_Pir(root, data);
}

//ɾ��
template<class T>
void RBTree<T>::erase(const T& data) {
	Erase_Pir(root, data);
}

//չʾ��
template<class T>
void RBTree<T>::show_RBTree() {
	Print_RBTree(root);
	//����������ɫ
	//cout << root->height << endl;
	//cout << root->LChild->height << endl;
	//cout << root->RChild->height << endl;
	//cout << root->RChild->RChild->RChild->RChild->fre << endl;//���Ե������ֳ��ֵ�Ƶ��
}

//��ӡ����
template<class T>
void RBTree<T>::print_RBTree() {
	Tree_In_Order(root);
}

