//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Cuba {
//public:
//	void Set_L(int l) { m_L = l; }//设置长
//	int Get_L() { return m_L; }//获取长
//	void Set_W(int w) { m_W = w; }//设置宽
//	int Get_W() { return m_W; }//获取宽
//	void Set_H(int h) { m_H = h; }//设置高
//	int Get_H() { return m_H; }//获取高
//	int CalculateArea() { return m_L * m_H * 2 + m_L * m_W * 2 + m_W * m_H * 2; }//计算面积
//	int CalculateVolume() { return m_L * m_H * m_W; }//计算体积
//	//判断两个立方体是否相等
//	bool Is_Same(Cuba c2) {
//		if (this->m_H == c2.m_H && this->m_L == c2.m_L && this->m_W == c2.m_W) return true;
//		else return false;
//	}
//private:
//	//设置私有属性
//	int m_L;//长
//	int m_W;//宽
//	int m_H;//高
//};
//
//bool Is_Same(Cuba c1, Cuba c2) {
//	if (c1.Get_H() == c2.Get_H() && c1.Get_L() == c2.Get_L() && c1.Get_W() == c2.Get_W()) {
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	Cuba c1;
//	c1.Set_L(10);
//	c1.Set_W(10);
//	c1.Set_H(10);
//	cout << "c1立方体的面积为：" << c1.CalculateArea() << endl;
//	cout << "c1立方体的体积为：" << c1.CalculateVolume() << endl;
//	Cuba c2;
//	c2.Set_L(10);
//	c2.Set_W(10);
//	c2.Set_H(10);
//	if (Is_Same(c1, c2)) cout << "两个立方体是相等的！" << endl;
//	else cout << "两个立方体是不相等的！" << endl;
//	if (c1.Is_Same(c2)) cout << "两个立方体是相等的！" << endl;
//	else cout << "两个立方体是不相等的！" << endl;
//	return 0;
//}