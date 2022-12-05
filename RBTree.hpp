
#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<ctime>
using namespace std;

//树节点的颜色  枚举
enum COLOR {
	RED = 0,//0
	BLACK = 1 ,//1
};

template<class T>
class RBTree;

//树的节点
template<class T>
class TreeNode {

	friend class RBTree<T>;//设置RBTree类是TreeNode类的朋友  可以访问TreeNode类的私有成员
private:

	//默认构造函数
	TreeNode() :color(BLACK), fre(1), LChild(NULL), RChild(NULL), Parent(NULL) {}

	//创建节点  有参构造函数
	TreeNode(T data1) :data(data1), color(RED), fre(1), LChild(NULL), RChild(NULL), Parent(NULL),rank(0) {}

	//二叉树指针
	TreeNode<T>* LChild;
	TreeNode<T>* RChild;
	TreeNode<T>* Parent;

	//数据
	T data;

	//记录当前节点的颜色
	COLOR color;

	//记录当前节点值出现的次数 频率
	unsigned int fre;

	//记录打印的树形二叉树
	int rank;
};

//红黑树
template<class T>
class RBTree {
private:
	//根节点
	TreeNode<T>* root;

	//获取当前节点的颜色
	COLOR Get_Color(TreeNode<T>* root);

	//设置节点的颜色
	void Set_Color(TreeNode<T>* root,COLOR color);

	//获取父亲节点
	TreeNode<T>* Get_Parent(TreeNode<T>* root);

	//获取左孩子节点
	TreeNode<T>* Get_Left(TreeNode<T>* root);

	//获取右孩子节点
	TreeNode<T>* Get_Right(TreeNode<T>* root);

	//红黑树树的中序遍历
	void Tree_In_Order(const TreeNode<T>* root);

	//查找删除数的后继节点
	TreeNode<T>* Find_Back_Node(const TreeNode<T>* root);

	//RB树插入节点
	void Insert_Pir(TreeNode<T>*& root, const T& data);

	//查找值所在节点
	TreeNode<T>* Find_Pir(TreeNode<T>*& root, const T& data);

	//删除值所在的节点
	void Erase_Pir(TreeNode<T>*& root, const T& data);

	//调整红黑树
	void Adjust_TreeColor_erase(TreeNode<T>* select);

	//重新调整每个节点的颜色  
	void Adjust_TreeColor_insert(TreeNode<T>*& root);

	//打印树
	void Print_RBTree(TreeNode<T>* root);

	//红黑自平衡搜索树的中序遍历  适合打印树的形状
	void Tree_In_Order1(TreeNode<T>*& root);

	//左旋
	void RBTree_Left_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1);

	//右旋
	void RBTree_Right_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1);


	//AVL树中的调整
	//需要调整的节点平衡因子是-2和2 分4中情况 当调整节点的平衡因子是2时 说明右树高  右孩子的平衡因子为-1 这种情况是右左 需要旋转子节点
	//需要调整的节点平衡因子是-2和2 分4中情况 当调整节点的平衡因子是-2时 说明右树高  右孩子的平衡因子为1 这种情况是左右
	
	
	
public:
	//树的构造函数
	RBTree() :root(NULL) {}

	//RB树插入节点
	void insert(const T& data);

	//查找值所在节点
	TreeNode<T>* find(const T& data);

	//删除值所在的节点
	void erase(const T& data);

	//打印树
	void show_RBTree();

	//打印树形
	void print_RBTree();
};

//对内接口

//获取当前节点的颜色
template<class T>
COLOR RBTree<T>::Get_Color(TreeNode<T>* root) {
	return root == NULL ? BLACK : root->color;
}

//设置当前节点的颜色
template<class T>
void RBTree<T>::Set_Color(TreeNode<T>* root, COLOR color) {
	if(root != NULL) root->color = color;
}

//获取当前节点的父节点
template<class T>
TreeNode<T>* RBTree<T>::Get_Parent(TreeNode<T>* root) {
	return root == NULL ? NULL : root->Parent;
}

//获取当前节点的左孩子
template<class T>
TreeNode<T>* RBTree<T>::Get_Left(TreeNode<T>* root) {
	return root == NULL ? NULL : root->LChild;

}

//获取当前节点的右孩子
template<class T>
TreeNode<T>* RBTree<T>::Get_Right(TreeNode<T>* root) {
	return root == NULL ? NULL : root->RChild;

}

//中序遍历
template<class T>
void RBTree<T>::Tree_In_Order(const TreeNode<T>* root) {
	if (!root) return;
	Tree_In_Order(root->LChild);
	cout << root->data << " ";
	Tree_In_Order(root->RChild);
}

//查找后继节点
template<class T>
TreeNode<T>* RBTree<T>::Find_Back_Node(const TreeNode<T>* root) {
	TreeNode<T>* right = root->RChild;
	while (right->LChild) {
		right = right->LChild;
	}
	return right;
}


//循环的插入
template<class T>
void RBTree<T>::Insert_Pir(TreeNode<T>*& root, const T& data) {
	//这里使用了引用做函数的返回值 就是可以让插入的节点连接到父亲

	TreeNode<T>* newnode = new TreeNode<T>(data);
	TreeNode<T>* cur = root;
	TreeNode<T>* parent = NULL;
	if (!root) {
		newnode->color = BLACK;
		root = newnode;
		//插入节点成功 进行树的调整
		cout << "插入节点成功" << endl;
		return;
	}
	else {
		//找到插入节点的父节点
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
				//如果插入节点等于某个节点的值 就让他的出现的频率加1

				++root->fre;
				return;
			}
		}
		cur = newnode;
		//插入节点与parent的data作比较
		if (data > parent->data) {
			parent->RChild = cur;
			cur->Parent = parent;
		}
		else if (data < parent->data) {
			parent->LChild = cur;
			cur->Parent = parent;
		}

		//重新调整树的颜色
		Adjust_TreeColor_insert(cur);
	}
	//TreeNode<T>* parent = root->Parent;
	//TreeNode<T>* cur = root->Parent;

}



//对红黑树的性质进行调整  插入时候的调整
//1.红黑树每个节点都是红色和黑色   2.根节点必须是黑色  3.空节点是黑色    4.红色节点的叶子节点必须是黑色 也就是不能有相连的两个红色节点  5.每个路径上黑色节点个数一样
template<class T>
void RBTree<T>::Adjust_TreeColor_insert(TreeNode<T>*& cur) {
	//分多中情况
	if (cur == root) return;
	//通过2 3 4树的转换 可以分析  3 4树才需要调整
	//3树插入的时候分6中情况 2种情况不需要调整 4种需要  而4树中都需要调整 只不过是叔父节点有无两种情况
	//当前节点不是跟节点 当前节点不为空  父节点的颜色是红色才需要调整  父节点颜色是黑色的话  插入的是红色节点不用调整
	while (cur && cur != root && Get_Color(Get_Parent(cur)) == RED) {
		//当前节点的父亲节点是爷爷的右孩子
		if (Get_Parent(cur) == Get_Right(Get_Parent(Get_Parent(cur)))) {
	
			//叔叔节点颜色是红色
			if (Get_Color(Get_Left(Get_Parent(Get_Parent(cur)))) == RED) {
				//变色
				Set_Color(Get_Parent(cur), BLACK);//父节点变成黑色
				Set_Color(Get_Left(Get_Parent(Get_Parent(cur))), BLACK);//父节点是右孩子 那么叔父节点就是左孩子  叔父节点变成黑色
				Set_Color(Get_Parent(Get_Parent(cur)), RED);//爷爷变成红色
				//递归处理
				cur = Get_Parent(Get_Parent(cur));

			}
			//叔叔节点是黑色  也就是空节点
			else {
				//当前节点是父节点的左孩子的话  需要先将父亲右旋 再进行变色 让后对爷爷左旋
				if (cur == Get_Parent(cur)->LChild) {
					cur = Get_Parent(cur);
					RBTree_Right_Rotate(root, cur);
				}
				Set_Color(Get_Parent(cur), BLACK);
				Set_Color(Get_Parent(Get_Parent(cur)), RED);
				RBTree_Left_Rotate(root, Get_Parent(Get_Parent(cur)));
			}
			
		}
		//当前节点的父亲是爷爷的左孩子
		else {
			
			//叔叔节点为红色
			if (Get_Color(Get_Right(Get_Parent(Get_Parent(cur)))) == RED) {
				//变色
				Set_Color(Get_Parent(cur), BLACK);
				Set_Color(Get_Right(Get_Parent(Get_Parent(cur))), BLACK);
				Set_Color(Get_Parent(Get_Parent(cur)), RED);
				//递归调整
				cur = Get_Parent(Get_Parent(cur));

			}
			//当前节点叔叔节点为黑色  NULL
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
	//设置根节点的颜色
	root->color = BLACK;
}

//查找节点
template<class T>
TreeNode<T>* RBTree<T>::Find_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) return NULL;
	else {
		TreeNode<T>* cur = root;
		TreeNode<T>* cur1 = NULL;
		if (data > cur->data) {
			//去右子树找
			cur1 = Find_Pir(cur->RChild, data);
		}
		else if (data < cur->data) {
			//去左子树找
			cur1 = Find_Pir(cur->LChild, data);

		}
		else {
			// 找到了 返回
			return root;
		}
	}
}


//template<class T>
//void RBTree<T>::Erase_OneChild(TreeNode<T>*& root, TreeNode<T>*& select) {
//	//父亲节点
//	TreeNode<T>* parent = select->Parent;
//
//	//删除的节点是叶子结点
//	if (Get_Left(select) == NULL && Get_Right(select) == NULL) {
//		//如果删除的是根节点
//		if (parent == NULL) {
//			root = NULL;
//		}
//		else {
//			select == parent->LChild ? parent->LChild = NULL : parent->RChild = NULL;
//		}
//		delete select;
//	}//删除的节点有一个孩子节点
//	else if (Get_Left(select) == NULL || Get_Right(select) == NULL) {
//		//找到孩子节点
//		TreeNode<T>* child = select->LChild == NULL ? select->RChild : select->LChild;
//		select->data = child->data;
//		select->LChild == child ? select->LChild = NULL : select->RChild = NULL;
//		delete child;
//	}
//}

//删除节点
template<class T>
void RBTree<T>::Erase_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) return;
	//查找删除的节点
	TreeNode<T>* select = Find_Pir(root, data);
	if (!select) {
		cout << "该数据的节点不存在！" << endl;
		return;
	}

	//删除的节点有两个孩子节点
	if (Get_Left(select) != NULL && Get_Right(select) != NULL) {
		//后继节点  替代节点
		TreeNode<T>* backnode = Find_Back_Node(select);

		select->data = backnode->data;

		//将删除的节点变成后继节点
		select = backnode;
	}

	//删除的节点有一个孩子节点
	if (Get_Left(select) != NULL || Get_Right(select) != NULL) {

		//找到孩子节点
		TreeNode<T>* child = select->LChild == NULL ? select->RChild : select->LChild;
		//如果删除的是根节点
		if (select == root) {
			root = child;
			child->Parent = NULL;
		}
		else {
			//孩子与父节点的指向关系
			if (Get_Parent(select)->LChild == select) {
				Get_Parent(select)->LChild = child;
			}
			else {
				Get_Parent(select)->RChild = child;
			}
			child->Parent = Get_Parent(select);
		}
		if (select->color == BLACK) {
			//调整红黑树
			Adjust_TreeColor_erase(child);
		}

	}
	else if (select == root) {
		root = NULL;
	}
	//删除的节点是叶子结点
	else {
		if (select->color == BLACK) {
			//调整红黑树
			Adjust_TreeColor_erase(select);
		}
		select == Get_Parent(select)->LChild ? Get_Parent(select)->LChild = NULL : Get_Parent(select)->RChild = NULL;
	}
	delete select;

}

//删除节点是黑色时候对红黑树的调整
template<class T>
void RBTree<T>::Adjust_TreeColor_erase(TreeNode<T>* select) {
	if (!select) return;
	//如果当前节点是黑色才需要调整
	while (select != root && select->color == BLACK) {
		//1.判断父节点  如果当前节点是父节点的左孩子
		if (select == Get_Parent(select)->LChild) {
			//找出兄弟节点
			TreeNode<T>* brother = Get_Parent(select)->RChild;
			//判断兄弟节点是否是真的兄弟节点  看兄弟节点是否是红色
			if (brother->color == RED) {
				//如果兄弟是红色  那么久对兄弟和父亲进行变色 让后左旋
				Set_Color(brother, BLACK);
				Set_Color(Get_Parent(select), RED);
				RBTree_Left_Rotate(root, Get_Parent(select));
				//让兄弟变为父节点的右节点
				brother = Get_Parent(select)->RChild;
			}
			//兄弟节点不借出  当兄弟节点的两个孩子都是黑色的话  说明是叶子节点  不可借出
			if (Get_Color(Get_Left(brother)) == BLACK && Get_Color(Get_Right(brother)) == BLACK) {
				//没有孩子 借不出 那么久吧兄弟的颜色变为红色
				Set_Color(brother, RED);
				//进行循环处理
				select = Get_Parent(select);

			}//兄弟节点借出
			else {
				//来到这里说明兄弟节点有一个孩子  兄弟节点的有左孩子
				if (Get_Color(Get_Left(brother)) == RED) {
					RBTree_Right_Rotate(root, brother);
					//brother = Get_Parent(brother);
					Set_Color(brother, RED);
					Set_Color(Get_Parent(brother), BLACK);
					//调整兄弟节点
					brother = Get_Parent(select)->RChild;
				}
				//变色
				Set_Color(brother, Get_Color(Get_Parent(select)));
				Set_Color(Get_Parent(select), BLACK);
				Set_Color(Get_Right(brother), BLACK);
				//对父节点进行一个左旋
				RBTree_Left_Rotate(root, Get_Parent(select));
				break;
			}

		}
		else {
			//找出兄弟节点
			TreeNode<T>* brother = Get_Parent(select)->LChild;
			//判断兄弟节点是否是真的兄弟节点  看兄弟节点是否是红色
			if (brother->color == RED) {
				//如果兄弟是红色  那么久对兄弟和父亲进行变色 让后右旋
				Set_Color(brother, BLACK);
				Set_Color(Get_Parent(select), RED);
				RBTree_Right_Rotate(root, Get_Parent(select));
				//让兄弟变为父节点的左节点
				brother = Get_Parent(select)->LChild;
			}
			//兄弟节点不借出  当兄弟节点的两个孩子都是黑色的话  说明是叶子节点  不可借出
			if (Get_Color(Get_Left(brother)) == BLACK && Get_Color(Get_Right(brother)) == BLACK) {
				//没有孩子 借不出 那么久吧兄弟的颜色变为红色
				Set_Color(brother, RED);
				//进行循环处理
				select = Get_Parent(select);

			}//兄弟节点借出
			else {
				//来到这里说明兄弟节点有一个孩子  兄弟节点的有左孩子
				if (Get_Color(Get_Right(brother)) == RED) {
					//对兄弟节点进行左旋 把兄弟节点变成红色 兄弟节点的父节点变成黑色 找到旋转之后调整节点的兄弟节点
					RBTree_Left_Rotate(root, brother);
					//brother = Get_Parent(brother);
					Set_Color(brother, RED);
					Set_Color(Get_Parent(brother), BLACK);
					brother = Get_Parent(select)->LChild;
				}
				//变色
				Set_Color(brother, Get_Color(Get_Parent(select)));
				Set_Color(Get_Parent(select), BLACK);
				Set_Color(Get_Left(brother), BLACK);
				//对父节点进行一个右旋 
				RBTree_Right_Rotate(root, Get_Parent(select));
				break;
			}
		}
	}
	// 循环进行  如果当前节点是红色 那么直接变色就行  也有可能循环到根节点
	Set_Color(select, BLACK);

}



//根据中序遍历打印树状
template<class T>
void RBTree<T>::Print_RBTree(TreeNode<T>* root) {
	int xx = 0;      //中序遍历前把xx设置成0
	Tree_In_Order1(root);     //中序遍历
	printf("\n\nTree:\n\n");
	if (!xx) printf("");
	queue<TreeNode<T>*> q;
	if (root) q.push(root);
	while (!q.empty()) {//层序遍历
		int k = q.size(), p = 0;
		while (k--) {   //一次打印一层的节点，k表示一层的节点
			root = q.front();
			q.pop();
			if (root->LChild) q.push(root->LChild);
			if (root->RChild) q.push(root->RChild);
			string str = "";
			while (p < root->rank) {
				str += "   ";   //在节点的x坐标前打印空格
				p++;
			}
			p += to_string(root->data).size();
			printf("%s%d", str.c_str(), root->data);
			cout << ":"<<root->color;
		}
		printf("\n\n");
	}
}

//这里的中序只做记录 不做打印
int xx = 0;
template<class T>
void RBTree<T>::Tree_In_Order1(TreeNode<T>*& root) {
	//这里的中序遍历只是配合上面的树的形状打印
	if (root == NULL) return;
	Tree_In_Order1(root->LChild);
	root->rank = xx;
	xx += to_string(root->data).size();
	Tree_In_Order1(root->RChild);
}

//对parent1节点进行左旋
template<class T>
void RBTree<T>::RBTree_Left_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1) {
	TreeNode<T>* right = parent1->RChild;
	TreeNode<T>* left = right->LChild;
	TreeNode<T>* parent = parent1->Parent;
	TreeNode<T>* cur = parent1;

	//说明他是根节点
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

//对parent1节点进行右旋
template<class T>
void RBTree<T>::RBTree_Right_Rotate(TreeNode<T>*& root, TreeNode<T>* parent1) {
	TreeNode<T>* left = parent1->LChild;
	TreeNode<T>* right = left->RChild;
	TreeNode<T>* parent = parent1->Parent;
	TreeNode<T>* cur = parent1;

	//说明他是根节点
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


//对外接口


//查找
template<class T>
TreeNode<T>* RBTree<T>::find(const T& data) {
	return Find_Pir(root, data);
}

//插入
template<class T>
void RBTree<T>::insert(const T& data) {
	Insert_Pir(root, data);
}

//删除
template<class T>
void RBTree<T>::erase(const T& data) {
	Erase_Pir(root, data);
}

//展示树
template<class T>
void RBTree<T>::show_RBTree() {
	Print_RBTree(root);
	//测试树的颜色
	//cout << root->height << endl;
	//cout << root->LChild->height << endl;
	//cout << root->RChild->height << endl;
	//cout << root->RChild->RChild->RChild->RChild->fre << endl;//测试单个数字出现的频率
}

//打印树形
template<class T>
void RBTree<T>::print_RBTree() {
	Tree_In_Order(root);
}

