//
//  Industry.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 24/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#include "Industry.hpp"
#include<fstream>
#include<iostream>
#include "Matrix.hpp"
using namespace std;

void Industry::SumAR(map<string, Stock> &StockMap, vector<string> Ticker)
{
    Group[0]=0; Group[1]=0; Group[2]=0;
    vector<double> AR0(61,0); vector<double> AR1(61,0); vector<double> AR2(61,0);   // 61天
    
    for(int i=0; i<Ticker.size(); ++i) {
        Stock temp=StockMap[Ticker[i]];
        
        if(temp.group==1) {Group[0]++; AR0=AR0+temp.AR;}
        else if(temp.group==2) {Group[1]++; AR1=AR1+temp.AR;}
        else {Group[2]++; AR2=AR2+temp.AR;}
    }
    
    AAR0=AR0; AAR1=AR1; AAR2=AR2;
    
}


void Industry::CalcAAR()
{
    AAR0=AAR0/Group[0]; AAR1=AAR1/Group[1]; AAR2=AAR2/Group[2];
    AAR.push_back(AAR0); AAR.push_back(AAR1); AAR.push_back(AAR2);
}


void Industry::CalcCAAR()
{
    CAAR0=cum(AAR0); CAAR1=cum(AAR1); CAAR2=cum(AAR2);
    CAAR.push_back(CAAR0); CAAR.push_back(CAAR1); CAAR.push_back(CAAR2);
}


