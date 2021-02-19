#pragma once

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>

#pragma comment(lib, "winmm.lib")

/***** 宏定义区 ******/
#define NUM 13// 烟花种类数量宏定义
#define PI 3.1415926548

/***** 结构定义区 **********/

// 烟花结构
struct FIRE
{
	int r;// 当前爆炸半径
	int max_r;// 爆炸中心距离边缘最大半径
	int x, y;// 爆炸中心在窗口的坐标
	int cen_x, cen_y;// 爆炸中心相对图片左上角的坐标
	int width, height;// 图片的宽高
	int xy[240][240];// 储存图片像素点
	bool show;// 是否绽放
	bool draw;// 开始输出像素点
	DWORD t1, t2, dt;// 绽放速度

}Fire[NUM];

// 烟花弹结构
struct JET
{
	int x, y;// 喷射点坐标
	int hx, hy;// 最高点坐标------将赋值给 FIRE 里面的 x, y
	int height;// 烟花高度
	bool shoot;// 是否可以发射
	DWORD t1, t2, dt;// 发射速度
	IMAGE img[2];// 储存花弹一亮一暗图片
	byte n : 1;// 图片下标
}Jet[NUM];

/**** 函数申明区 ****/
void welcome();
void Init(int);// 初始化烟花
void Load();// 加载烟花图片
void Shoot();// 发射烟花
void Chose(DWORD&);// 筛选烟花
void Style(DWORD&);// 发射样式
void Show(DWORD*);// 绽放烟花