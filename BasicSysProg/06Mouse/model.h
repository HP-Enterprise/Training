#pragma once

#define MAX_POINT_NUM 16

// ��ǰ����
typedef struct tagModelFunctions ModelFunctions;

typedef struct tagPoint
{
    int x;
    int y;
} Point;

// ģ�Ͷ���
typedef struct tagModel
{
	// �㻺����
	Point points[MAX_POINT_NUM];
    // ����Ŀ
    int nCount;
	// APIָ��
	ModelFunctions *pAPI;
} Model;

// API����
Model* ModelInit(Model*);

typedef Point*(*fnModelGetPoints)(Model*);
typedef int(*fnModelGetCount)(Model*);
typedef Model*(*fnModelClear)(Model*);
typedef Model*(*fnModelPut)(Model*, Point);
typedef Model*(*fnModelMove)(Model*, int, Point);

struct tagModelFunctions
{
	fnModelGetPoints GetPoints;
	fnModelGetCount GetCount;
	fnModelClear Clear;
	fnModelPut Put;
    fnModelMove Move;
};