//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Point {
//public:
//	void Set_PointX(int x) { m_X = x; }//����x
//	int Get_PointX() { return m_X; }//��ȡx
//	void Set_PointY(int x) { m_Y = x; }//����y
//	int Get_PointY() { return m_Y; }//��ȡy
//
//private:
//
//	//�������
//	int m_X;
//	int m_Y;
//};
//
//
//class Circle {
//	//��Ԫ��  ��Ԫ����
//	//friend class Point;
//public:
//	//����Բ��Բ��
//	//void Set_CenterX() { m_Center.Set_PointX(0); }
//	//void Set_CenterY() { m_Center.Set_PointY(0); }
//	Circle() {
//		m_Center.Set_PointX(0);
//		m_Center.Set_PointY(0);
//	}
//	//����Բ�İ뾶
//	void Set_CircleR(int r) { m_R = r; }
//	//��ȡԲ�İ뾶
//	int Get_CircleR() { return m_R; }
//	//�жϵ��Բ��λ�ù�ϵ   1��԰�� 0����Բ�� -1����Բ��
//	string Is_InRelation(Point p1) {
//		int Distance = (p1.Get_PointX() * p1.Get_PointX()) + (p1.Get_PointY() * p1.Get_PointY());
//		//cout << Distance << endl;
//		//cout << (this->m_R * this->m_R) << endl;
//		if ((this->m_R * this->m_R) > Distance)
//			return "�������԰�ڣ�";
//		else if ((this->m_R * this->m_R) < Distance)
//			return "�������԰�⣡";
//		else return "�������԰�ϣ�";
//	}
//
//private:
//	//Բ�ĵ�����  ������ԭ��  0.0
//	Point m_Center;
//	//�뾶
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
//	//if (c1.Is_Relation(p1) == 1) cout << "�������԰�ڣ�" << endl;
//	//else if (c1.Is_Relation(p1) == -1) cout << "�������Բ�⣡" << endl;
//	//else cout << "�������Բ�ϣ�" << endl;
//
//	cout << c1.Is_InRelation(p1) << endl;
//	cout << c1.Is_InRelation(p2) << endl;
//	return 0;
//}