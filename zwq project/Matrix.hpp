//
//  Matrix.hpp
//  zwq Project
//
//  Created by Wuqian Zhong on 24/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>
using namespace std;

typedef vector< vector<double>> Matrix;

// 用于计算SumAR,定义vector<double>变量间加法
vector<double> operator+(const vector<double>& v1, const vector<double>& v2);

// 用于计算AAR,把vector<double>中的每个元素除以a
vector<double> operator/(const vector<double>& v1, const int a);

// Calculate cumulative return
vector<double> cum(const vector<double> &v1);

#endif /* Matrix_hpp */
