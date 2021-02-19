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

/***** �궨���� ******/
#define NUM 13// �̻����������궨��
#define PI 3.1415926548

/***** �ṹ������ **********/

// �̻��ṹ
struct FIRE
{
	int r;// ��ǰ��ը�뾶
	int max_r;// ��ը���ľ����Ե���뾶
	int x, y;// ��ը�����ڴ��ڵ�����
	int cen_x, cen_y;// ��ը�������ͼƬ���Ͻǵ�����
	int width, height;// ͼƬ�Ŀ��
	int xy[240][240];// ����ͼƬ���ص�
	bool show;// �Ƿ�����
	bool draw;// ��ʼ������ص�
	DWORD t1, t2, dt;// �����ٶ�

}Fire[NUM];

// �̻����ṹ
struct JET
{
	int x, y;// ���������
	int hx, hy;// ��ߵ�����------����ֵ�� FIRE ����� x, y
	int height;// �̻��߶�
	bool shoot;// �Ƿ���Է���
	DWORD t1, t2, dt;// �����ٶ�
	IMAGE img[2];// ���滨��һ��һ��ͼƬ
	byte n : 1;// ͼƬ�±�
}Jet[NUM];

/**** ���������� ****/
void welcome();
void Init(int);// ��ʼ���̻�
void Load();// �����̻�ͼƬ
void Shoot();// �����̻�
void Chose(DWORD&);// ɸѡ�̻�
void Style(DWORD&);// ������ʽ
void Show(DWORD*);// �����̻�