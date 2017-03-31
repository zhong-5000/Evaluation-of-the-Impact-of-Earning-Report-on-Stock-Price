//
//  main.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#include <iostream>
#include "libcurl.hpp"
#include "GetTicker.hpp"
#include "Bloomberg.hpp"
#include "Industry.hpp"
#include "Stock.hpp"
#include "gnuplot.hpp"
using namespace std;

void Operation(map<string, Matrix>& CAAR, string TickerTXT, string IndustryCSV, string Industry);

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start=clock();
    
    // 3个industry分3次运行
    map<string, Matrix> CAAR;
    Operation(CAAR, "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/HealthcareTicker.txt", "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/Healthcare.csv", "Healthcare");
    plot(CAAR);
    
    
    /*
     Operation(CAAR, "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/FinancialTicker.txt", "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/Financial.csv", "Financial");
     
     
     Operation(CAAR, "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/ITTicker.txt", "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/IT.csv", "IT");

    */
    
    
     /*******检验三个industry的CAAR数据是否在map中保存好
    for(map<string, Matrix>::iterator it=CAAR.begin(); it!=CAAR.end(); ++it) {
        cout << it->first << endl;
        for(int i=0; i<3; ++i) {
            cout << "Group : " << i+1 << endl;
    
            for (int j=0; j<61; j++) {
                cout << "day" << j+1 << " " << it->second[i][j] << endl;
            }
            cout << endl;
        }
    }
    */
     
    end =clock();
    cout << "run time: " << double(end-start)/CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}



void Operation(map<string, Matrix>& CAAR, string tickertxt, string IndustryCSV, string industry) {
    
    //1.Read ticker txt, to become vector
    vector<string> Ticker=GetTicker(tickertxt);
    
    //2.Use libcurl to download and initialize stock info(StockPrice, StockDate, Ticker )
    map<string, Stock> StockMap=libcrl(Ticker);

    //3.Update the stock info(EPS, EstEPS, release_date, spy) using csv from bloomberg
    Bloomberg(StockMap, IndustryCSV);
    SP500(StockMap, "/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/zwq Project/SP500 Index.csv");
    
    
    
    //4.Calculate group and abnormal return(AR)
    for (map<string, Stock>::iterator it=StockMap.begin(); it!=StockMap.end(); ++it) {
        it->second.SetGroup();
        it->second.CalAR();
    }
    
    //5.Calculate AAR and CAAR calculation
    map<string, Matrix> AAR;
    Industry I;
    I.SumAR(StockMap, Ticker);
    I.CalcAAR();
    I.CalcCAAR();
    AAR.insert(pair<string, Matrix>(industry, I.AAR));
    CAAR.insert(pair<string, Matrix>(industry, I.CAAR));
}




