//
//  gnuplot.cpp
//  zwq Project
//
//  Created by Wuqian Zhong on 24/01/2017.
//  Copyright © 2017 Wuqian Zhong. All rights reserved.
//



// Install gnuplot on Mac with Macports: http://blog.sina.com.cn/s/blog_731c054101017s5v.html

#include "gnuplot.hpp"

void plot(map<string, Matrix> CAAR)
{
    FILE *pipe, *fp; // pipe可理解为指向terminal的指针
    
    //创建一个通道，执行一个shell以运行命令来开启一个进程，相当于在terminal中进入gnuplot
    pipe=popen("/opt/local/bin/gnuplot","w");
    
    // 创建一个存放三个Group CAAR数据的临时文件，用于之后gnuplot画图时使用
    char* tempData=(char*)("/Users/wuqianzhong/Desktop/NYU/Financial Computing/zwq Project/CAARData.dat");
    fp=fopen(tempData, "w");
    
    if(pipe) {  // 如果成功进入该目录下的gnuplot
        printf("gnuplot found...\n");
        fprintf(pipe, "set title \"Healthcare Sector\"\n");  // 设置输出图片的title
        fprintf(pipe, "set xlabel \"release day\"\n");  // 设置输出图片的xlabel
        fprintf(pipe, "set ylabel \"CAAR\"\n");  // 设置输出图片的ylabel
        fprintf(pipe, "set xrange [-30:30]\n");  // 设置输出图片的日期范围
        fprintf(pipe, "set xtic 3\n");   // 设置输出图片的x增量
        
        // 往tempData.dat文件中写入三个Group 的61天CAAR数据
        for (int i=0; i<61; i++) {
            fprintf(fp, "%d %lf %f %f\n", i-30 ,CAAR["Healthcare"][0][i],
                                                CAAR["Healthcare"][1][i],CAAR["Healthcare"][2][i]);
        }
        fclose(fp);
        
        // 相当于在terminal中调用gnuplot, 画出三个Group 的61天CAAR
        fprintf(pipe, "plot \"%s\" using 1:2 lw 3 with lines title \"Group1: miss\",\"%s\" using 1:3 lw 3 with lines title \"Group2: meet\",\"%s\" using 1:4 lw 3 with lines title \"Group3: beat\",\n",tempData,tempData,tempData);
        
    }
    else {printf("gnuplot not found...\n");}
    
    pclose(pipe);
    
}





//******************gnuplot用法示例**************************
/*
void plot()
{
    FILE *pipe; // 可理解为指向terminal
    
    //创建一个通道，执行一个shell以运行命令来开启一个进程，相当于在terminal中进入gnuplot
    pipe=popen("/opt/local/bin/gnuplot","w");
    
    if(pipe) {  // 如果成功进入该目录下的gnuplot
        printf("gnuplot found...\n");
        fprintf(pipe, "plot sin(x)\n");   // 相当于往terminal中输命令plot sin(x)
    }
    else {printf("gnuplot not found...\n");}
    
    pclose(pipe);
    
}
*/
