
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
//树的节点
class TreeNode {

	friend class AVLTree<T>;

private:
	//默认构造函数
	TreeNode() :height(1), fre(1), LChild(NULL), RChild(NULL), Parent(NULL) {}

	//创建节点  有参构造函数
	TreeNode(T data1) :data(data1), height(1), fre(1), LChild(NULL), RChild(NULL), Parent(NULL) {}

	//二叉树指针
	TreeNode<T>* LChild;
	TreeNode<T>* RChild;
	TreeNode<T>* Parent;

	//数据
	T data;

	//记录当前节点为树的高度
	int height;

	//记录当前节点值出现的次数 频率
	unsigned int fre;

	//记录打印的树形二叉树
	int rank;
};

template<class T>
class AVLTree {
private:
	//根节点
	TreeNode<T>* root;

	//获取当前节点树的高度
	int Get_Height(TreeNode<T>* root);

	//比较树的高度
	int Com_AVLTree_H(int height_1, int height_2);

	//平衡搜索树的中序遍历
	void Tree_In_Order(const TreeNode<T>* root);

	//查找删除数的后继节点
	TreeNode<T>* Find_Back_Node(const TreeNode<T>* root);

	//avl树插入节点
	void Insert_Pir(TreeNode<T>*& root, const T& data);

	//查找值所在节点
	TreeNode<T>* Find_Pir(TreeNode<T>*& root, const T& data);

	//删除值所在的节点
	void Erase_Pir(TreeNode<T>*& root, const T& data);

	//重新调整每个节点树的高度  相当于后序遍历
	void Adjust_Tree_H(TreeNode<T>*& root);

	//打印树
	void Print_AVLTree(TreeNode<T>* root);

	//平衡搜索树的中序遍历  适合打印树的形状
	void Tree_In_Order1(TreeNode<T>*& root);

	//需要调整的节点平衡因子是-2和2 分4中情况 当调整节点的平衡因子是2时 说明右树高  右孩子的平衡因子为1 这种情况是右右  左旋
	void AVLTree_Left_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1);

	//需要调整的节点平衡因子是-2和2 分4中情况 当调整节点的平衡因子是-2时 说明右树高  右孩子的平衡因子为-1 这种情况是左左  右旋
	void AVLTree_Right_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1);


	//需要调整的节点平衡因子是-2和2 分4中情况 当调整节点的平衡因子是2时 说明右树高  右孩子的平衡因子为-1 这种情况是右左 需要旋转子节点
	//需要调整的节点平衡因子是-2和2 分4中情况 当调整节点的平衡因子是-2时 说明右树高  右孩子的平衡因子为1 这种情况是左右


	//旋转 整体旋转
	void AVLTree_Rotate(TreeNode<T>*& root, TreeNode<T>*& parent1);

	//判断是否是平衡二叉树
	bool Is_Balanced_Binary_Tree_Pir(TreeNode<T>* root);

public:
	//树的构造函数
	AVLTree() :root(NULL) {}

	//avl树插入节点
	void insert(const T& data);

	//查找值所在节点
	TreeNode<T>* find(const T& data);

	//删除值所在的节点
	void erase(const T& data);

	//打印树
	void show_AVLTree();

	//打印树形
	void print_AVLTree();

	//判断是否是平衡二叉树
	bool is_balancedbinarytree();

};
//对内接口

//获取树的高度
template<class T>
int AVLTree<T>::Get_Height(TreeNode<T>* root) {
	if (!root) return 0;
	return root->height;
}

//一般使用比较两个子树的高度来产生平衡因子
template<class T>
int AVLTree<T>::Com_AVLTree_H(int height_1, int height_2) {
	return height_1 - height_2;//右子树减去左子树的平衡因子
}

//中序遍历
template<class T>
void AVLTree<T>::Tree_In_Order(const TreeNode<T>* root) {
	if (!root) return;
	Tree_In_Order(root->LChild);
	cout << root->data << " ";
	Tree_In_Order(root->RChild);
}

//查找后继节点
template<class T>
TreeNode<T>* AVLTree<T>::Find_Back_Node(const TreeNode<T>* root) {
	TreeNode<T>* right = root->RChild;
	TreeNode<T>* parent = NULL;
	//查找当前节点的后继节点  当前节点的右树最小值的节点
	while (right) {
		parent = right;
		right = right->LChild;
	}
	return parent;
}


//插入使用了递归 确实出现了一点问题  下面修正过来
//template<class T>
//TreeNode<T>*& AVLTree<T>::Insert_Pir(TreeNode<T>*& root, const T& data) {
//	//这里使用了引用做函数的返回值 就是可以让插入的节点连接到父亲
//	if (!root) {
//		TreeNode<T>* newnode = new TreeNode<T>(data);
//		root = newnode;
//		//插入节点成功 进行树的调整
//		cout << "插入节点成功" << endl;
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
//		else ++root->fre;//如果插入节点等于某个节点的值 就让他的出现的频率加1
//		//当前树的高度就是左树右树的最大高度加上自身的高度1
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
//		//向上调整
//		parent = parent->Parent;
//	}
//}



//循环的插入
template<class T>
void AVLTree<T>::Insert_Pir(TreeNode<T>*& root, const T& data) {
	//这里使用了引用做函数的返回值 就是可以让插入的节点连接到父亲

	TreeNode<T>* newnode = new TreeNode<T>(data);
	TreeNode<T>* cur = root;
	TreeNode<T>* parent = NULL;
	if (!root) {
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
		//当前树的高度就是左树右树的最大高度加上自身的高度1
		//int lefth = Get_Height(root->LChild);
		//int righth = Get_Height(root->RChild);
		//root->height = lefth > righth ? lefth + 1 : righth + 1;
		//重新调整树的高度
		Adjust_Tree_H(root);
	}
	//TreeNode<T>* parent = root->Parent;
	//TreeNode<T>* cur = root->Parent;
	//调整好树的高度之后 判断是否需要进行旋转
	AVLTree_Rotate(root, parent);

}

//查找节点
template<class T>
TreeNode<T>* AVLTree<T>::Find_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) return NULL;
	else {
		TreeNode<T>* cur = root;
		TreeNode<T>* cur1 = NULL;
		if (data > cur->data) {
			//去右子树找
			return Find_Pir(cur->RChild, data);
		}
		else if (data < cur->data) {
			//去左子树找
			return Find_Pir(cur->LChild, data);
		}
		else {
			// 找到了 返回
			return root;
		}
	}
}


//删除节点有些反锁 可以进行优化 具体可参考红黑树
template<class T>
void AVLTree<T>::Erase_Pir(TreeNode<T>*& root, const T& data) {
	if (!root) {
		cout << "当前平衡树为空，无法再次删除！" << endl;
		return;
	}
	//先找到需要删除同等数据的节点
	TreeNode<T>* select = find(data);

	//先找后继节点 就是右子树的最小值的节点  替换节点
	TreeNode<T>* backnode = Find_Back_Node(select);
	

	if (select == NULL) {
		cout << "你要删除的节点不存在 请重新输入！" << endl;
		return;
	} 
	//记录查找节点的父亲节点
	TreeNode<T>* parent = select->Parent;

	//替换节点的父节点
	TreeNode<T>* backnodeparent = NULL;

	//这里进行调整  因为删除的可能是叶子节点 后继节点为NULL 无后继节点 理所当然也没有后继节点的父亲 后面旋转调整时需要用到后继节点  所以需要判断
	if(backnode) backnodeparent = backnode->Parent;
	//假如删除的节点是叶子节点
	if (select->LChild == NULL && select->RChild == NULL) {
		//判断删除的是否是根节点
		if (parent == NULL) {
			root = NULL;
		}
		else {
			select == parent->LChild ? parent->LChild = NULL : parent->RChild = NULL;
		}
	}
	//假如删除的节点只有一个孩子
	else if (select->LChild == NULL || select->RChild == NULL) {
		//如果删除的是根节点 且根节点只有一个子树
		//记录一下孩子的节点
		TreeNode<T>* child = select->RChild == NULL ? select->LChild : select->RChild;
		if (parent == NULL) {
			root = (select->LChild != NULL ? select->LChild : select->RChild);
			root->Parent = NULL;
		}
		else {
			select == parent->LChild ? parent->LChild = child : parent->RChild = child;
			//调整孩子节点的父亲 指向删除节点的父亲
			if (child) {
				child->Parent = parent;

			}
		}
	}
	//假如删除的节点有两个孩子 分多中情况
	else {
		////先找后继节点 就是右子树的最小值的节点  替换节点
		//TreeNode<T>* backnode = Find_Back_Node(select);
		////替换节点的父节点
		//TreeNode<T>* backnodeparent = backnode->Parent;
		////判断删除的是否是根
		//if (parent == NULL) {
		//	//再次判断替换节点 是否是当前删除的节点的右子树
		//	root = backnode;
		//	if (backnode == select->RChild) {
		//		backnode->Parent = parent;
		//		backnode->LChild = select->LChild;
		//		select->LChild->Parent = backnode;
		//	}
		//	else {
		//		//替换节点不是删除节点的右子树 分两种情况 替换节点有右孩子和无右孩子
		//		TreeNode<T>* child = backnode->RChild;
		//		backnodeparent->LChild = child;
		//		backnode->Parent = select->Parent;
		//		backnode->LChild = select->LChild;
		//		backnode->RChild = select->RChild;
		//		select->LChild->Parent = backnode;
		//		select->RChild->Parent = backnode;
		//	}
		//}
		////删除的不是根节点
		//else {
		//	//再次判断替换节点 是否是当前删除的节点的右子树
		//	if (backnode == select->RChild) {
		//		backnode->Parent = parent;
		//		backnode->LChild = select->LChild;
		//		select->LChild->Parent = backnode;
		//		parent->LChild == select ? parent->LChild = backnode : parent->RChild = backnode;
		//	}
		//	else {
		//		//替换节点不是删除节点的右子树 分两种情况 替换节点有右孩子和无右孩子
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
		
		
		//记录替换节点的右孩子  不管是否为空
		TreeNode<T>* child = NULL;
		if (backnode) child = backnode->RChild;

		//判断删除的是否是根
		if (parent == NULL) {
			//再次判断替换节点 是否是当前删除的节点的右子树
			root = backnode;
		}
		//删除的不是根节点
		else {
			//再次判断替换节点 是否是当前删除的节点的右子树
			if (backnode == select->RChild) {
				parent->LChild == select ? parent->LChild = backnode : parent->RChild = backnode;
			}
			else {
				//替换节点不是删除节点的右子树 分两种情况 替换节点有右孩子和无右孩子
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
			//替换节点不是删除节点的右子树 分两种情况 替换节点有右孩子和无右孩子
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
	//重新调整整个树的高度
	Adjust_Tree_H(root);


	//如果删除的是跟节点的话  需要调整以 后继节点父亲为根的树
	if (parent == NULL) AVLTree_Rotate(root, backnodeparent);
	else {
		AVLTree_Rotate(root, parent);
	} 
	if(backnodeparent==select) 
		AVLTree_Rotate(root, backnode);

	//AVLTree_Rotate(root, parent);
	delete select;

}


//插入节点 删除节点 都需要对树每个节点的高度重新进行调整  后序遍历进行调整
template<class T>
void AVLTree<T>::Adjust_Tree_H(TreeNode<T>*& root) {
	if (!root) return;
	//从根部开始调整 也就是后序遍历
	Adjust_Tree_H(root->LChild);
	Adjust_Tree_H(root->RChild);
	root->height = max(Get_Height(root->LChild), Get_Height(root->RChild)) + 1;
}

//打印树状
template<class T>
void AVLTree<T>::Print_AVLTree(TreeNode<T>* root) {
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
				str += " ";   //在节点的x坐标前打印空格
				p++;
			}
			p += to_string(root->data).size();
			printf("%s%d", str.c_str(), root->data);
		}
		printf("\n\n");
	}
}


//这里的中序遍历只是配合上面的树的形状打印
int xx = 0;
template<class T>
void AVLTree<T>::Tree_In_Order1(TreeNode<T>*& root) {
	if (root == NULL) return;
	Tree_In_Order1(root->LChild);
	root->rank = xx;
	xx += to_string(root->data).size();
	Tree_In_Order1(root->RChild);
}

//对当前节点 parent1进行右旋
template<class T>
void AVLTree<T>::AVLTree_Left_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1) {
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


//对当前节点 parent1进行右旋
template<class T>
void AVLTree<T>::AVLTree_Right_Rotate(TreeNode<T>*& root,TreeNode<T>*& parent1) {
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
	if(right)
		right->Parent = cur;
}


//树的调整 循环进行
template<class T>
void AVLTree<T> ::AVLTree_Rotate(TreeNode<T>*& root, TreeNode<T>*& parent) {
	while (parent != NULL) {
		//当前节点左右子树高度差为2的时候进行调整 2说明是右子树高  需要左旋
		if (Com_AVLTree_H(Get_Height(parent->RChild), Get_Height(parent->LChild)) == 2) {
			//当前节点的左右子树的右子树高度差为-1的时候进行调整 说明当前节点右子树的左右子树高度差为-1  左边高  需要进行右旋再进行左旋
			if (Com_AVLTree_H(Get_Height(parent->RChild->RChild), Get_Height(parent->RChild->LChild)) == -1) {
				AVLTree_Right_Rotate(root, parent->RChild);
			}
			AVLTree_Left_Rotate(root, parent);
			Adjust_Tree_H(root);
		}
		//当前节点高度差为-2的时候进行调整 -2说明是左子树高  需要右旋
		if (Com_AVLTree_H(Get_Height(parent->RChild), Get_Height(parent->LChild)) == -2) {
			//当前节点的左右子树的左子树高度差为1的时候进行调整 说明当前节点左子树的左右子树高度差为1  右边高  需要进行左旋再进行右旋
			if (Com_AVLTree_H(Get_Height(parent->LChild->RChild), Get_Height(parent->LChild->LChild)) == 1) {
				AVLTree_Left_Rotate(root, parent->LChild);
			}
			AVLTree_Right_Rotate(root, parent);
			//旋转一次之后重新调整每个节点记录的高度
			Adjust_Tree_H(root);
		}
		//向上调整
		parent = parent->Parent;

	}
}


//判断是否是平衡二叉树
template<class T>
bool AVLTree<T>::Is_Balanced_Binary_Tree_Pir(TreeNode<T>* root) {
	if (!root) return true;

	return abs(Get_Height(root->LChild) - Get_Height(root->RChild)) < 2
		&& Is_Balanced_Binary_Tree_Pir(root->LChild) 
		&& Is_Balanced_Binary_Tree_Pir(root->RChild);
}


//对外接口


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
	
	//测试树的高度
	//cout << root->height << endl;
	//cout << root->LChild->height << endl;
	//cout << root->RChild->height << endl;
	//cout << root->RChild->RChild->RChild->RChild->fre << endl;//测试单个数字出现的频率
}


template<class T>
void AVLTree<T>::print_AVLTree() {
	Print_AVLTree(root);
}


template<class T>
bool AVLTree<T>::is_balancedbinarytree(){
	return Is_Balanced_Binary_Tree_Pir(root);
}