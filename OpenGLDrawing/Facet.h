#pragma once

#include "MyPoint.h"
#include <iostream>
using namespace std;
class Facet
{
public:
	// 面片索引
	int index;
	int index1;
	int index2;
	int index3;
	// 体积
	double volume;
	// 面积
	double s;
	// 面片中点的数据
	MyPoint _vertex_1;
	MyPoint _vertex_2;
	MyPoint _vertex_3;
	double sum;
	vector<double>list;
	vector<int>listfacet;
	vector<MyPoint>_facelist;
	void addPoint(MyPoint mypoint)
	{
		_facelist.push_back(mypoint);
	}
	void addFacet(int index)
	{
		listfacet.push_back(index);
	}
	~Facet();
	Facet()
	{}
	bool operator<(const Facet& _b) const
	{
		if (_b.index < index)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void  getVolume()
	{
		MyPoint p0 = this->_vertex_1;
		MyPoint p1 = this->_vertex_2;
		MyPoint p2 = this->_vertex_3;
		double v1 = p2._x*p1._y*p0._z;

		double v2 = p1._x*p2._y*p0._z;

		double v3 = p2._x*p0._y*p1._z;

		double v4 = p0._x*p2._y*p1._z;

		double v5 = p1._x*p0._y*p2._z;

		double v6 = p0._x*p1._y*p2._z;

		this->volume = (1.0 / 6.0)*(-v1 + v2 + v3 - v4 - v5 + v6);
	}
	// 求方向量
	void getNormal()
	{
		MyPoint p0 = this->_vertex_1;
		MyPoint p1 = this->_vertex_2;
		MyPoint p2 = this->_vertex_3;
		double v1x = p1._x - p0._x;
		double v1y = p1._y - p0._y;
		double v1z = p1._z - p0._z;
		double v2x = p2._x - p1._x;
		double v2y = p2._y - p1._y;
		double v2z = p2._z - p1._z;
		double x = v1y * v2z - v1z * v2y;
		double y = v1z * v2x - v1x * v2z;
		double z = v1x * v2y - v1y * v2x;
		double len = sqrt(x*x + y * y + z * z);
		if (len == 0)
		{

		}
		else {
			list.push_back(x / len);
			list.push_back(y / len);
			list.push_back(z / len);
		}
	}
	// 求面积
	void getS()
	{
		MyPoint p0 = this->_vertex_1;
		MyPoint p1 = this->_vertex_2;
		MyPoint p2 = this->_vertex_3;

		double l1 = sqrt((p0._x - p1._x)*(p0._x - p1._x) + ((p0._y - p1._y)*(p0._y - p1._y)) + ((p0._z - p1._z)*(p0._z - p1._z)));

		double l2 = sqrt((p0._x - p2._x)*(p0._x - p2._x) + ((p0._y - p2._y)*(p0._y - p2._y)) + ((p0._z - p2._z)*(p0._z - p2._z)));


		double l3 = sqrt((p2._x - p1._x)*(p2._x - p1._x) + ((p2._y - p1._y)*(p2._y - p1._y)) + ((p2._z - p1._z)*(p2._z - p1._z)));

		double c = 1.0 / 2.0*(l1 + l2 + l3);

		this->s = sqrt(c*(c - l1)*(c - l2)*(c - l3));

	}
	void toString()
	{
		cout << "x= " << _vertex_1.index << " y= " << _vertex_2.index << " z= " << _vertex_3.index << endl;
	}
};

