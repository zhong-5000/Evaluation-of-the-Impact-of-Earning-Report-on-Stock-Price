//
//  libcurl.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//



// curl tutorial: https://curl.haxx.se/libcurl/c/libcurl-tutorial.html
#include "libcurl.hpp"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include <iterator>
using namespace std;


// Callback function, tell libcurl to pass all data to this function
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}


// Use libcurl to download stock info from Yahoo Finance into txt
void DownYahoo(string Ticker)
{
    CURL *curl;  // Create pointer of curl operation
    FILE *fp;   // File pointer to create file that store data
    curl_global_init(CURL_GLOBAL_ALL); // Initalize all curl internal sub modules
    CURLcode res;   // // Indiactor that can be used to judge if opening url success or not
    
    string surl="http://ichart.yahoo.com/table.csv?s="+Ticker+"&a=10&b=1&c=2014&d=05&e=1&f=2015&g=d&ignore=.csv";
    const char *url=(char*)surl.c_str();    // Transfer string into C style for CURL parameter use
    const char outfilename[FILENAME_MAX]="/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/temp.csv";   // Name of file to store data from Yahoo
    
    curl=curl_easy_init();
    if(curl) {
        fp=fopen(outfilename, "wb");
        
        // Set URL to transfer, url参数要求是C语言下的字符串指针
        curl_easy_setopt(curl, CURLOPT_URL, url);
        
        // Tell libcurl to pass data to write_data,instead of getting it passed to stdout
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        
        // Pass data from write_data function to your file
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        // Actual transfer, returns a code informs you if it succeeded
        res = curl_easy_perform(curl);
        
        fclose(fp);
    }
    
    if ( res == CURLE_OK)   // Succeeded in transfer data
    {
        curl_easy_cleanup(curl);  // End the libcurl easy handle, the opposite of the curl_easy_init()
        curl_global_cleanup();  // Cleanup the resources curl_global_init call initialized
    }
    
}


// Read stock info from txt to Stock Class
Stock ReadYahoo(string Ticker)
{
    vector<string> data;    // To store all strings from txt
    string STRING;
    ifstream infile;
    infile.open("/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/temp.csv");
    
    // Read stock info from txt to memory
    int count=0;    // how many lines in txt
    while (!infile.eof()) {  // To get all your lines
        getline(infile, STRING);  // Save the line in STRING
        data.push_back(STRING);
        count++;
    }
    infile.close();
    //remove("/Users/wuqianzhong/Desktop/Financial Copmuting Final Project/temp.csv");
    
    
    // Split the data and input them into 2 vectors
    vector<string> StockDate;
    vector<double> StockPrice;
    
    for(int i=1; i<count-1; ++i) {  // data[0]是“Date,Open,High...”, 文件中最后一行是空行，都不用处理
        vector<string> temp;  // 用来存放data中每行字符串用逗号分隔后的子串
        string s=data[i];
        istringstream ss(s);  // input string stream 类似于 ifstream
        while(!ss.eof()) {  // 把每行拆分成子串，提取Date和Adj两个子串
            string x;   // 用来存放子字符串
            getline(ss, x, ',');  // 以逗号作分隔符读入到x中
            temp.push_back(x);
        }
        
        long n=temp.size();
        StockDate.push_back(temp[0]);   // temp中保存的第一个子串为日期
        StockPrice.push_back(atof( temp[n-1].c_str() ));  // 最后一个子串为Adj, atof把C下的字符串转成double
    }
    
    Stock S;
    S.ticker=Ticker;
    S.price_date=StockDate;
    S.price=StockPrice;
    
    return S;
    
}


// Generate stock map to store all stock info
map<string, Stock> libcrl(vector<string> Ticker)
{
    map<string, Stock> StockMap;
    for(vector<string>::iterator it=Ticker.begin(); it!=Ticker.end(); it++) {
        DownYahoo(*it);
        Stock S=ReadYahoo(*it);
        StockMap.insert(pair<string, Stock>(*it, S));
    }
    
    return StockMap;
}

/*******检验map是否正确
 vector<string> Ticker={"AAPL","GOOG"};
 map<string, Stock> StockMap=libcrl(Ticker);
 map<string, Stock>::iterator it=StockMap.begin();
 long n = it->second.price.size();
 for(int i=0; i<n; ++i) {
 cout << it->second.price_date[i] << " " << it->second.price[i] << endl;
 }
 */

