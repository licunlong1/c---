#include<iostream>
#include<ctime>
#include<string>
#include<stack>
using namespace std;

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Swap(int& p, int& p1) {
	int temp = p;
	p = p1;
	p1 = temp;
}

//插入排序        O(N*N)
void InsertSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		int j = i - 1;
		while (temp > a[j] && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

//希尔排序  插入版本的升级  时间复杂度 为 O(N*logN)
void ShellSort(int* a, int n) {
	int group = n;
	while (group > 1) {
		group /= 2;//每次需要跳的大小 每次循环都比上次少一倍
		for (int i = 0; i < n - group; i++) {
			int j = i;
			int temp = a[j + group];
			//while (j >= 0) {
			//	if (a[j] < temp) {
			//		a[j + group] = a[j];
			//		j -= group;
			//		//1 2 3 4 5 6 7 8
			//		//1-----1-----1     第一次group为一半
			//		//  1-----1-----1
			//		//    1-----1
			//		//2---2---2---2     第二次
			//		//3 3 3 3 3 3 3 3   第三次
			//	}
			//	else
			//		break;
			//}
			while (a[j] < temp && j >= 0) {
				a[j + group] = a[j];
				j -= group;
			}
			a[j + group] = temp;
		}
	}
}

//选择排序    就是从区间选取数字 把最大的值和最小的值分别放到最后和初始位置
void SelectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (a[i] > a[maxi]) maxi = i;
			if (a[i] < a[mini]) mini = i;
		}
		Swap(a[end], a[mini]);
		if (maxi == end) maxi = mini;
		Swap(a[begin], a[maxi]);
		begin++;
		end--;
	} 
}

//堆排序需要向下调整算法，向下调整算法是看做一个满二叉树  左树和友树满足大堆小堆他就可以调整跟（左孩子和右孩子）
void JustDown(int* a, int root, int n) {
	//把数组看成二叉树  逻辑结构 实际还是数组  父子关系如下
	// leftchild = parend*2+1     rightchile = parent*2+2   parent=( child-1 ) / 2 下标关系
	int parent = root;
	int child = parent * 2 + 1; //左孩子
	while (child < n) {
		//小堆  降序的话要建小堆
		if (child + 1 < n && a[child + 1] < a[child]) {
			child += 1;
		}
		if (a[child] < a[parent]) {
			Swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
		
	} 
}

//堆排序
void HeapSort(int* a, int n) {
	//建堆的过程
	for (int i = (n - 2) / 2; i >= 0; i--) {
		JustDown(a, i, n);
	}
	int end = n - 1;
	while (end > 0) {
		Swap(a[end], a[0]);
		JustDown(a, 0, end);
		--end;
	}
}

//冒泡排序
void BubbleSort(int* a, int n) {
	
	for (int i = 0; i < n - 1; i++) 
		for (int j = 0; j < n - i - 1; j++) 
			if (a[j + 1] > a[j]) 
				Swap(a[j + 1], a[j]);

}

//快排需要使用到三数取中
int select_midnum(int  *arr,int left,int right)   //三个数取中
{
	int mid = (left + right) / 2;
	if (arr[left] < arr[mid])
	{
		if (arr[right] > arr[mid])
		{
			return mid;
		}
		else if (arr[right]<arr[mid] && arr[right]>arr[left])
		{
			return right;
		}
		else 
			return left;
	}
	else 
	{
		if (arr[right] < arr[mid])
		{
			return mid;
		}
		else if (arr[right] > arr[mid] && arr[right] < arr[left])
		{
			return right;
		}
		else
			return left;
	}
}

//挖坑法
int Quick1(int* a, int begin, int end) {
	int key = a[begin], pivot = begin;
	while (begin < end) {
		while (begin < end && a[end] <= key) {
			end--;
		}
		a[pivot] = a[end];
		pivot = end;
		while (begin < end && a[begin] >= key) {
			begin++;
		}
		a[pivot] = a[begin];
		pivot = begin;
	}
	a[pivot] = key;
	return pivot;
}

//双向指针交换法
int Quick2(int* a, int begin, int end) {
	int key = begin;
	while (begin < end){
		while (begin < end && a[end] <= a[key]) {
			end--;
		}
		while (begin < end && a[begin] >= a[key]) {
			begin++;
		}
		Swap(a[begin], a[end]);
	}
	Swap(a[end], a[key]);
	return end;
}

//前后指针法
int Quick3(int* a, int begin, int end) {
	int prev = begin;
	int cur = prev + 1;
	while (cur <= end) {
		if (a[cur] > a[begin]) {
			++prev;
			Swap(a[prev], a[cur]);
		}
		cur++;
	}
	Swap(a[prev], a[begin]);
	return prev;
}

//快速排序
void QuickSort(int* a, int left, int right) {
	if (left >= right) return;
	int begin = left, end = right;
	int mid = select_midnum(a, begin, end);
	//cout << a[mid] << endl;
	Swap(a[mid], a[begin]);
	//第一个数做key
	//int pivot = Quick1(a, begin, end);
	int pivot = Quick2(a, begin, end);
	//int pivot = Quick3(a, begin, end);

	//分成了新的区间 左边和右边 left-pivot-1  pivot pivot+1-right
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);

}

//归并排序   合并有序数组
void _MergeSort(int* a, int left, int right, int* temp) {

	if (left >= right) return;
	//中间数值的下标
	int midnum = (left + right) / 2;
	_MergeSort(a, left, midnum, temp);
	_MergeSort(a, midnum + 1, right, temp);

	int begin1 = left, end1 = midnum;
	int begin2 = midnum + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] > a[begin2]) {
			temp[index++] = a[begin1++];
		}
		else {
			temp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1) {
		temp[index++] = a[begin1++];
	}
	while (begin2 <= end2) {
		temp[index++] = a[begin2++];
	}
	for (int i = left; i <= right; i++) {
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int n) {
	//徐开辟新的数组
	int* temp = new int[n];
	_MergeSort(a, 0, n - 1, temp);
	delete[]a;
}


//快速排序的非递归
void QuickSortNoR(int* a, int n) {
	stack<int> st;
	st.push(n - 1);
	st.push(0);
	while (!st.empty()) {
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		int pos = Quick1(a, left, right);
		if (left < right) {
			st.push(right);
			st.push(pos + 1);
			st.push(pos - 1);
			st.push(left);
		}
	}
}

//归并排序的非递归
void MergeSortNoR(int* a, int n) {
	int* temp = new int[n];
	int gap = 1;
	while (gap < n) {

		for (int i = 0; i < n - gap; i += 2 * gap) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = begin2 + gap - 1;
			int index = begin1;
			//如果左区间的右边大于n了 那就不要合并了
			if (end1 >= n) {
				break;
			}
			if (end2 >= n) {
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2) {
				if (a[begin1] > a[begin2]) {
					temp[index++] = a[begin1++];
				}
				else {
					temp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1) {
				temp[index++] = a[begin1++];
			}
			while (begin2 <= end2) {
				temp[index++] = a[begin2++];
			}
			for (int j = i; j <= end2; j++) {
				a[j] = temp[j];
			}
		}
		//for (int i = 0; i < n; i++) {
		//	a[i] = temp[i];
		//}
		gap *= 2;
	}
}

//计数排序    只能使用于整形  其他类型的不可以 比较具有局限性
void CountSort(int* a, int n) {
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++) {
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	//cout << max << "   " << min << endl;
	int newsize = max - min + 1;
	int* temp = new int[newsize];
	if (temp == NULL && newsize < 0) return;
	memset(temp, 0, sizeof(int) * newsize);
	for (int i = 0; i < n; i++) {
		temp[a[i] - min]++;
	}
	//PrintArray(temp, newsize);
	int j = 0;
	for (int i = 0; i < newsize; i++) {
		while (temp[i]--) {
			a[j++] = i + min;
		}
	}
	delete[]temp;
}


void testInsertSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(a[0]);
	//cout << sz;
	InsertSort(a, sz);
	PrintArray(a, sz);
}

void testShellSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);

	ShellSort(a, sz);
	PrintArray(a, sz);
}

void testSelectSort() {
	int a[]= { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);

	SelectSort(a, sz);
	PrintArray(a, sz);
}

void testHeapSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);

	HeapSort(a, sz);
	PrintArray(a, sz);
}

void testBubbleSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);
	BubbleSort(a, sz);
	PrintArray(a, sz);
}

void testQuickSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);

	QuickSort(a, 0, sz - 1);
	//QuickSortNoR(a, sz);
	PrintArray(a, sz);
}


void testMergeSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);
	//MergeSort(a, sz);
	MergeSortNoR(a, sz);
	PrintArray(a, sz);

}

void testCountSort() {
	int a[] = { 48,39,24,76,83,92,12,19,2,10,15 };
	int sz = sizeof(a) / sizeof(int);

	CountSort(a, sz);
	PrintArray(a, sz);
}

void testSortSpeed() {
	srand((unsigned int)time(NULL));
	int N = 100000;
	int* a1 = new int[N];
	int* a2 = new int[N];
	int* a3 = new int[N];
	int* a4 = new int[N];
	int* a5 = new int[N];
	int* a6 = new int[N];
	int* a7 = new int[N];
	int* a8 = new int[N];
	for (int i = 0; i < N; i++) {
		a1[i] = rand();
		//a1[i] = 100;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//BubbleSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N - 1);
	int end6 = clock();

	int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();

	int begin8 = clock();
	CountSort(a8, N);
	int end8 = clock();

	cout << "InsertSort = " << end1 - begin1 << endl;
	cout << "ShellSort = " << end2 - begin2 << endl;
	cout << "SelectSort = " << end3 - begin3 << endl;
	cout << "HeapSort = " << end4 - begin4 << endl;
	cout << "BubbleSort = " << end5 - begin5 << endl;
	cout << "QuickSort = " << end6 - begin6 << endl;
	cout << "MergeSort = " << end7 - begin7 << endl;
	cout << "CountSort = " << end8 - begin8 << endl;

}

int main() {

	//testSortSpeed();
	//testInsertSort();  //插入排序  N*N
	testShellSort();   //希尔排序  N*logN
	//testSelectSort();  //选择排序  N*N
	//testHeapSort();    //堆排序
	//testBubbleSort();  //冒泡排序
	//testQuickSort();   //快速排序
	//testMergeSort();   //归并排序
	//testCountSort();   //计数排序

	system("pause");
	return 0;
}