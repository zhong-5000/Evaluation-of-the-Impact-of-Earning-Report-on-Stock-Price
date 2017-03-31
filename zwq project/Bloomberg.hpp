//
//  Bloomberg.hpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#ifndef Bloomberg_hpp
#define Bloomberg_hpp

#include <stdio.h>
#include "Stock.hpp"
#include <map>
#include <fstream>
#include <sstream>


//****************************************
//把从Bloomberg中下载下来的信息加到Stock对象中去
//****************************************


// 初始化Stock对象中的release_date, EPS, EstEPS等属性
void Bloomberg(map<string, Stock> &StockMap, string csv);

// 初始化Stock对象中的spy属性，即对应股价日期内的SP500的指数
void SP500(map<string, Stock> &StockMap, string csv);

#endif /* Bloomberg_hpp */
