//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Cuba {
//public:
//	void Set_L(int l) { m_L = l; }//���ó�
//	int Get_L() { return m_L; }//��ȡ��
//	void Set_W(int w) { m_W = w; }//���ÿ�
//	int Get_W() { return m_W; }//��ȡ��
//	void Set_H(int h) { m_H = h; }//���ø�
//	int Get_H() { return m_H; }//��ȡ��
//	int CalculateArea() { return m_L * m_H * 2 + m_L * m_W * 2 + m_W * m_H * 2; }//�������
//	int CalculateVolume() { return m_L * m_H * m_W; }//�������
//	//�ж������������Ƿ����
//	bool Is_Same(Cuba c2) {
//		if (this->m_H == c2.m_H && this->m_L == c2.m_L && this->m_W == c2.m_W) return true;
//		else return false;
//	}
//private:
//	//����˽������
//	int m_L;//��
//	int m_W;//��
//	int m_H;//��
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
//	cout << "c1����������Ϊ��" << c1.CalculateArea() << endl;
//	cout << "c1����������Ϊ��" << c1.CalculateVolume() << endl;
//	Cuba c2;
//	c2.Set_L(10);
//	c2.Set_W(10);
//	c2.Set_H(10);
//	if (Is_Same(c1, c2)) cout << "��������������ȵģ�" << endl;
//	else cout << "�����������ǲ���ȵģ�" << endl;
//	if (c1.Is_Same(c2)) cout << "��������������ȵģ�" << endl;
//	else cout << "�����������ǲ���ȵģ�" << endl;
//	return 0;
//}