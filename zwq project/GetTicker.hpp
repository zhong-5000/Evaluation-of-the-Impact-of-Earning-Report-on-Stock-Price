//
//  ticker.hpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#ifndef ticker_hpp
#define ticker_hpp

#include <stdio.h>
#include <fstream>
#include "Stock.hpp"
using namespace std;

// Read tickers from txt file into vector
vector<string> GetTicker(string txt);


#endif /* ticker_hpp */
