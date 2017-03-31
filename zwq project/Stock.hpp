//
//  Stock.hpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#ifndef Stock_hpp
#define Stock_hpp

#include <stdio.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Stock {
public:
    string ticker;
    vector<string> price_date;
    vector<double> price;
    vector<double> spy; // S&P500 index vector
    double EPS;
    double EstEPS;
    int group;
    string release_date;
    vector<double> AR; // Abnormal Return
    
    void SetGroup();
    void CalAR(); // Calculate Abnormal return 30 days before and after the release date
};


#endif /* Stock_hpp */
