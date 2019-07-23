// 模型类，用于存放每一个模型的基本信息
#pragma once
#include<map>
#include"Facet.h"
#include"MyPoint.h"
#include<gl/GLUT.H>
#include<iostream>
#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include <ctime>
#include<algorithm>
#include <set>
#include <ctime>
#include <iostream>
#include<list>
using namespace std;
class Model
{
public:
	// 模型的面片数据
	map<int, Facet>modelFacet;
	// 模型的点类数据,去重后的数据
	map<int, MyPoint>modelPoint;
	Model();
	~Model();
	void addPoint(MyPoint point, int index)
	{
		modelPoint.insert(pair<int, MyPoint>(index, point));
	}
	void addFacet(int index, Facet facet)
	{
		modelFacet.insert(pair<int, Facet>(index, facet));

	}
};

