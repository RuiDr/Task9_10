#pragma once

#include <vector>
using namespace std;
class MyPoint
{
public:
	// 标志
	int flag;
	// 索引
	int index;
	// 坐标
	float _x, _y, _z;
	// 存储三角面片的信息
	vector<int>listfacet;

	~MyPoint();
	void addFacet(int i)
	{
		listfacet.push_back(i);
	}
	void getIndex(int index)
	{
		this->index = index;
	}
	MyPoint(float _x, float _y, float _z)
	{
		this->_x = _x;
		this->_y = _y;
		this->_z = _z;
	}
	MyPoint(int index, float _x, float _y, float _z)
	{
		this->index = index;
		this->_x = _x;
		this->_y = _y;
		this->_z = _z;
	}
	MyPoint()
	{}
	// 重载
	bool operator<(const MyPoint& b)const
	{
		//return false;
		return (_x < b._x) || (_x == b._x) && (_y < b._y) || (_x == b._x && _y == b._y && _z < b._z);
		//return true;
		// 相等比较 
	}
	bool isEque(MyPoint point)
	{
		if (point._x == _x && point._y == _y && point._z == _z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

