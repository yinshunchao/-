#pragma once
#include <graphics.h>
#include <vector>
#include <conio.h>
using namespace std;

typedef enum {
	CHESS_WHITE = -1,  // �׷�
	CHESS_BLACK = 1    // �ڷ�
} chess_kind_t;

struct ChessPos {
	int row;
	int col;
	ChessPos(int r = 0, int c = 0) :row(r), col(c) {}
};


//

class Chess
{
public:
	// ���̵ĳ�ʼ�����������̵�ͼƬ��Դ����ʼ�����̵��������
	void init();

	Chess(int gradeSize, int marginX, int marginY, float chessSize);

	// �ж���ָ������(x,y)λ�ã��Ƿ�����Ч���
	// �������Ч���������Ч�����λ��(�У��У������ڲ���pos��
	bool clickBoard(int x, int y, ChessPos* pos);

	// �����̵�ָ��λ�ã�pos��, ���ӣ�kind��
	void chessDown(ChessPos* pos, chess_kind_t kind);

	// ��ȡ���̵Ĵ�С��13�ߡ�15�ߡ�19�ߣ�
	int getGradeSize();

	// ��ȡָ��λ���Ǻ��壬���ǰ��壬���ǿհ�
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	// �ж�����Ƿ����
	bool checkOver();



private:
	// ���̳ߴ�
	int gradeSize;
	float margin_x;//49;
	int margin_y;// 49;
	float chessSize; //���Ӵ�С�����̷����С��

	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;

	// �洢��ǰ��Ϸ���̺����ӵ����,�հ�Ϊ0������1������-1
	vector<vector<int>> chessMap;

	// ��ʾ���巽, true:���巽  false: AI ���巽��AI����
	bool playerFlag;

	ChessPos lastPos; //�������λ��, Chess��private���ݳ�Ա

private:
	void updateGameMap(ChessPos* pos);
	bool checkWin();
};