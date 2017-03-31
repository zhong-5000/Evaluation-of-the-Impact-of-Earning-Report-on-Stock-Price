//
//  Stock.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 23/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//

#include "Stock.hpp"
#include <iostream>
#include <iterator>

void Stock::SetGroup()
{
    double ratio=(EPS-EstEPS)/EstEPS;
    
    if(ratio<-0.0104) group=1; // miss
    else if(ratio >0.0885) group=3; // beat
    else group=2; // meet
}

// Calculate Abnormal return 30 days before and after the release date
void Stock::CalAR()
{
    int release=0;
    for (int i=0; i<price_date.size(); ++i) {
        if(release_date==price_date[i]) {release=i; break;}
    }
    
    for(int j=release+30; j>release-31; --j) {  // 按从Yahoo finance下载的Excel中的顺序，j+1表示j的前一天
        double ar=(price[j]-price[j+1])/price[j+1] - (spy[j]-spy[j+1])/spy[j+1];
        AR.push_back(ar);
    }
    
}




