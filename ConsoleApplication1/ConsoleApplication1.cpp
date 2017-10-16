/******************************************************************************

Copyright (C),2007-2016, LonBon Technologies Co. Ltd. All Rights Reserved.

******************************************************************************
Version       : 1.0
Author        : 肖兴宇
Created       : 2017/10/16
Description   :ffmpeg环境搭建
History       :
1.Date        :
Author      :
Modification:
******************************************************************************/
#include "stdafx.h"
#include <stdio.h>  
#include "sdl2/sdl.h"
//#include "sdl2/sdl_main.h"
#define __STDC_CONSTANT_MACROS  

#ifdef _WIN32  
//Windows  
extern "C"
{
#include "libavcodec/avcodec.h"  
#include "libavformat/avformat.h"  
#include "libavfilter/avfilter.h"  
};
#else  
//Linux...  
#ifdef __cplusplus  
extern "C"
{
#endif  
#include <libavcodec/avcodec.h>  
#include <libavformat/avformat.h>  
#include <libavfilter/avfilter.h>  
#ifdef __cplusplus  
};
#endif  
#endif  


int main(int argc, char* argv[])
{
	av_register_all();//ffmpeg初始化
	printf("%s\n", avcodec_configuration());//输出ffmpeg编码信息
	SDL_Init(SDL_INIT_EVERYTHING);
	auto win=SDL_CreateWindow("helloworld",0,0,500,500,SDL_WINDOW_SHOWN);//创建窗口
	auto  render= SDL_CreateRenderer(win,-1, SDL_RENDERER_SOFTWARE);//创建渲染器
	SDL_SetRenderDrawColor(render, 0, 255, 0, 255);//渲染绿色
	SDL_RenderClear(render);
	SDL_RenderPresent(render);//渲染
	SDL_Delay(2000);
	SDL_Quit();
    return 0;
}

