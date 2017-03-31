//
//  Industry.hpp
//  zwq Project
//
//  Created by Wuqian Zhong on 24/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#ifndef Industry_hpp
#define Industry_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include "Stock.hpp"
#include "Matrix.hpp"

class Industry {
public:
    vector<double> AAR0;
    vector<double> AAR1;
    vector<double> AAR2;
    vector<double> CAAR0;
    vector<double> CAAR1;
    vector<double> CAAR2;
    
    Matrix AAR;
    Matrix CAAR;
    int Group[3];  // The number of stock in group[i]
    
    void CalcAAR();
    void CalcCAAR();
    void SumAR(map<string, Stock> &StockMap, vector<string> Ticker);
};
#endif /* Industry_hpp */
