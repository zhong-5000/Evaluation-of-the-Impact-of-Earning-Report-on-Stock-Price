//
//  Bloomberg.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#include "Bloomberg.hpp"
#include <iostream>
using namespace std;

// 初始化Stock对象中的release_date, EPS, EstEPS等属性
void Bloomberg(map<string, Stock> &StockMap, string csv)
{
    vector<string> data;  // 方法同libcurl.cpp中的ReadYahoo函数（提取文件中的子字符串）
    string STRING;
    ifstream infile;
    infile.open(csv);
    
    int count=0;
    while(!infile.eof()) {
        getline(infile, STRING);
        data.push_back(STRING);
        count++;
    }
    infile.close();
    
    for(int i=0; i<count; ++i) {  // 提取每行中逗号分隔的子串赋值给Stock
        vector<string> temp;
        string s=data[i];
        
        istringstream ss( s );
        while(!ss.eof()) {
            string x;
            getline(ss, x, ',');
            temp.push_back(x);
        }
        
        StockMap[temp[0]].release_date=temp[1];
        StockMap[temp[0]].EPS=atof( temp[2].c_str() );
        StockMap[temp[0]].EstEPS=atof( temp[3].c_str() );
    }
    
}


// 初始化Stock对象中的spy属性，即对应股价日期内的SP500的指数
void SP500(map<string, Stock> &StockMap, string csv)
{
    ifstream infile;
    infile.open(csv);
    vector<double> sp;
    string STRING;
    
    while (!infile.eof()) {
        getline(infile, STRING);
        sp.push_back(stof( STRING.c_str() ));
    }
    
    for(map<string, Stock>::iterator it=StockMap.begin(); it!=StockMap.end(); ++it) {
        it->second.spy=sp;
    }
    
    infile.close();
}







