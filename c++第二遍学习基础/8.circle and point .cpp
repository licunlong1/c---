//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Point {
//public:
//	void Set_PointX(int x) { m_X = x; }//设置x
//	int Get_PointX() { return m_X; }//获取x
//	void Set_PointY(int x) { m_Y = x; }//设置y
//	int Get_PointY() { return m_Y; }//获取y
//
//private:
//
//	//点的坐标
//	int m_X;
//	int m_Y;
//};
//
//
//class Circle {
//	//友元类  友元函数
//	//friend class Point;
//public:
//	//设置圆的圆心
//	//void Set_CenterX() { m_Center.Set_PointX(0); }
//	//void Set_CenterY() { m_Center.Set_PointY(0); }
//	Circle() {
//		m_Center.Set_PointX(0);
//		m_Center.Set_PointY(0);
//	}
//	//设置圆的半径
//	void Set_CircleR(int r) { m_R = r; }
//	//获取圆的半径
//	int Get_CircleR() { return m_R; }
//	//判断点和圆的位置关系   1是园内 0是在圆上 -1是在圆外
//	string Is_InRelation(Point p1) {
//		int Distance = (p1.Get_PointX() * p1.Get_PointX()) + (p1.Get_PointY() * p1.Get_PointY());
//		//cout << Distance << endl;
//		//cout << (this->m_R * this->m_R) << endl;
//		if ((this->m_R * this->m_R) > Distance)
//			return "这个点在园内！";
//		else if ((this->m_R * this->m_R) < Distance)
//			return "这个点在园外！";
//		else return "这个点在园上！";
//	}
//
//private:
//	//圆心的坐标  假设是原点  0.0
//	Point m_Center;
//	//半径
//	int m_R = 0;
//};
//int main() {
//	Circle c1;
//	c1.Set_CircleR(10);
//	Point p1;
//	p1.Set_PointX(10);
//	p1.Set_PointY(0);
//	Point p2;
//	p2.Set_PointX(10);
//	p2.Set_PointY(19);
//
//	//if (c1.Is_Relation(p1) == 1) cout << "这个点在园内！" << endl;
//	//else if (c1.Is_Relation(p1) == -1) cout << "这个点在圆外！" << endl;
//	//else cout << "这个点在圆上！" << endl;
//
//	cout << c1.Is_InRelation(p1) << endl;
//	cout << c1.Is_InRelation(p2) << endl;
//	return 0;
//}