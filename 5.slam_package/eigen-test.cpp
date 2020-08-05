#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
	MatrixXf a(4, 1);//必须要进行初始化
	a = MatrixXf::Zero(4, 1);//初始化为0
	cout << "初始化为0" << endl << a << endl;
	a = MatrixXf::Ones(4, 1);//初始化为1，矩阵大小与初始化相关，因为是动态矩阵
	cout << "初始化为1" << endl << a << endl;
	a.setZero();//矩阵置零
	a << 1, 2, 3, 4;//手动赋值
	MatrixXf b(1, 4);
	b.setRandom();//随机生成一个矩阵
	MatrixXf c(3, 3);
	c.setIdentity();
	cout << "置单位矩阵：" << endl << c << endl;
	c.setRandom();
	MatrixXf d = c;
	d = d.inverse();
	cout << "矩阵c：" << endl << c << endl;
	cout << "矩阵a：" << endl << a << endl;
	cout << "矩阵b：" << b << endl;
	cout << "访问a(0)：" << endl << a(0) << endl;
	cout << "矩阵相乘：" << endl << a*b << endl;
	cout << "矩阵数乘：" << endl << 2 * a << endl;
	cout << "矩阵c求逆d：" << endl << d << endl;
	cout << "逆矩阵回乘：" << endl << d*c << endl;
	cout << "逆矩阵d转置：" << endl << d.transpose() << endl;
	Vector3d v(1, 2, 3);
	Vector3d w(1, 0, 0);
	cout << "向量相加：" << endl << v + w << endl;
	return 0;
}
