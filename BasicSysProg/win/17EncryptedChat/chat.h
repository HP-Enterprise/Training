#pragma once

#define MAX_NICK_LEN 32
#define MAX_MESSAGE_LEN 256

typedef struct tagMsgPack
{
    wchar_t wszNick[MAX_NICK_LEN]; // �ǳ�
    wchar_t wszMsg[MAX_MESSAGE_LEN]; // ����
} MsgPack;

typedef struct tagChat
{
    HWND hwndMain;
    HWND hwndHistory;
    HWND hwndList;
    HWND hwndInput;
    HWND hwndSend;
    HWND hwndRefresh;
    HFONT hfontText;

    wchar_t wszNick[MAX_NICK_LEN];

    HANDLE ev15673;
    HANDLE ev15683;
} Chat;

extern Chat g_chat;

typedef struct tagBroadcastPack
{
    char tag[8]; // ��־λ IC2016IC
    char cmd[4]; // REPT ����ȫ��㲥�Լ����; MYID �����Լ������
    unsigned char len; // ��Ϣ�峤��
    char buf[256]; // ��Ϣ��
} BroadcastPack;

void ChatStartup(Chat*);
void ChatShutdown(Chat*);
// �������ڹ㲥��Ϣ
void ChatBroadcast(char*, int);
void OnBroadcast();
// ������Ϣ
void ChatAcceptOrRead();
void ChatSend(wchar_t *pIP, wchar_t *pwszText);