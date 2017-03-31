//
//  ticker.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#include "GetTicker.hpp"

// Read tickers from txt file into vector
vector<string> GetTicker(string txt)
{
    vector<string> Ticker;
    string STRING;
    
    ifstream infile;
    infile.open(txt);
    
    int count=0;
    while(!infile.eof()) {
        getline(infile, STRING);
        Ticker.push_back(STRING);
        count++;
    }
    
    infile.close();
    
    return Ticker;
}



