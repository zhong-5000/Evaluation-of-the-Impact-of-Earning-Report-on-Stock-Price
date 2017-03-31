//
//  libcurl.hpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#ifndef libcurl_hpp
#define libcurl_hpp

#include <stdio.h>
#include <curl/curl.h>
#include <fstream>
#include <map>
#include "Stock.hpp"
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream); // Callback function in libcurl

// Use libcurl to download stock info from Yahoo Finance into txt
void DownYahoo(string Ticker);

// Read stock info from txt to Stock Class
Stock ReadYahoo(string Ticker);

// Generate stock map to store all stock info
map<string, Stock> libcrl(vector<string> Ticker);


#endif /* libcurl_hpp */
