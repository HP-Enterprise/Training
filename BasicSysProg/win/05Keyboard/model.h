#pragma once

#define MODEL_MAX_BUFFER 64

// ��ǰ����
typedef struct tagModelFunctions ModelFunctions;

// ģ�Ͷ���
typedef struct tagModel
{
	// �ַ�������,��ż�����ַ�����
	wchar_t wcsBuffer[MODEL_MAX_BUFFER];
	// APIָ��
	ModelFunctions *pAPI;
} Model;

// API����
Model* ModelInit(Model*);

typedef wchar_t*(*fnModelGetString)(Model*);
typedef int(*fnModelGetStringCount)(Model*);
typedef Model*(*fnModelClear)(Model*);
typedef Model*(*fnModelPut)(Model*, wchar_t);

struct tagModelFunctions
{
	fnModelGetString GetString;
	fnModelGetStringCount GetStringCount;
	fnModelClear Clear;
	fnModelPut Put;
};