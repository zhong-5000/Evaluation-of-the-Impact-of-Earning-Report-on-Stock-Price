//
//  Matrix.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 24/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#include "Matrix.hpp"

// 用于计算SumAR,定义vector<double>变量间加法
vector<double> operator+(const vector<double>& v1, const vector<double>& v2)
{
    vector<double> v3(v1.size());
    
    for (int i=0; i<v1.size(); ++i) {
        v3[i]=v1[i]+v2[i];
    }
    
    return v3;
}


// 用于计算AAR,把vector<double>中的每个元素除以a
vector<double> operator/(const vector<double>& v1, const int a)
{
    vector<double> v2(v1.size());
    
    for (int i=0; i<v1.size(); ++i) {
        v2[i]=v1[i]/a;
    }
    
    return v2;
}


// Calculate cumulative return
vector<double> cum(const vector<double> &v1)
{
    vector<double> v2=v1;

    for (int i=1; i<v1.size(); ++i) {
        v2[i]=v2[i-1]+v1[i];
    }
    
    return v2;
}





