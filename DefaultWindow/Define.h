#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0
#define PI			3.141592f

#define OBJ_NOEVENT			0
#define OBJ_DEAD			1	

#define VK_MAX				0xff // �����ڵ�

#define VK_MAX				0xff

#define G_FORCE                9.80665f
#define SQUARE(X)            (X)*(X)
#define RADIAN(Degree)        (Degree)*PI/180.f
#define DEGREE(Radian)        (Radian)*180.f/PI
// �����ڵ�

extern HWND		g_hWnd;
//extern int g_CurrentStage; // ���� �������� � ������������ 

enum BULLET_ID{ BUL_NORMAL,BUL_ELEC,BUL_GUT,BUL_ICE,BUL_CUT,BULFIRE, BUL_ELEC_SMALL,BUL_END }; // �Ѿ� Ÿ��  // ���� �ڵ�
enum DIRECTION { DIR_NONE,DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

enum DRAWPOINT { HEAD, TAIL, DRAWPOINT_END }; // ä�� �ڵ�
enum DRAWDIR { NO_DIR, HORIZONTAL, VERTICAL, DRAWDIR_END };




enum BEHAVOR_STATE { IDLE, ATTACK, CHASE, JUMP, PATROL, END };


enum StateType
{
	SEARCH,
	READY,
	FIRE,
};






enum BLOCKTYPE { BLOCK_ICE, BLOCK_FIRE, BLOCK_ELEC, BLOCK_CUT, BLOCK_GUT, BLOCKTYPE_END };

enum BOSSTYPE { BT_CUTMAN, BT_FIREMAN, BT_ELECMAN, BT_ICEMAN, BT_GUTSMAN, BT_END };
enum OBJID 
{ 
	OBJ_PLAYER, 
	OBJ_BULLET,OBJ_BLOCK,
	OBJ_MONSTER,
	OBJ_BOSS,
	OBJ_BOSSBULLET ,
	OBJ_MOUSE, 
	OBJ_EFFECT,// ������ �ڵ忡 ���� �߰�
	OBJ_END 
};



enum class GROUP_TYPE 
{
	OBJ_PLAYER,
	OBJ_PLYAER_MISSILE,
	OBJ_MONSTER,
	OBJ_BOSS,
	OBJ_BOSS_MISSLE,
	OBJ_ITEM,
	OBJ_BLOCK,
	OBJ_BUTTON,
	OBJ_END
};

enum class SCENE_TYPE // �� �Ŵ��� 
{
	STAGE_START,
	STAGE_Hong, // ���� �������� 1
	STAGE_Silver,//���� �������� 2
	STAGE_Hero, // ���� �������� 3
	STAGE_Chae, // ä�� �������� 4 
	STAGE_Moo,  // ���� �������� 5
	SCENE_END = 32, // �ص�
   
};

enum UI_TYPE
{
	UI_HP_PLAYER,
	UI_HP_BOSS,
	UI_END
};


typedef struct tagInfo
{
	float		fX, fY;// �߽���
	float		fCX, fCY;// ����, ���� ����

}INFO;

typedef struct tagLinePoint
{
	float		fX, fY;

	tagLinePoint()	{ZeroMemory(this, sizeof(tagLinePoint));}
		tagLinePoint(float _fX, float _fY)
		: fX(_fX), fY(_fY)
	{	}

}LINEPOINT;

typedef struct tagLine
{
	LINEPOINT	tLPoint;
	LINEPOINT	tRPoint;

	tagLine() { 	ZeroMemory(this, sizeof(tagLine));	}
	tagLine(LINEPOINT& _tLPoint, LINEPOINT& _tRPoint)
		: tLPoint(_tLPoint), tRPoint(_tRPoint) {	}

}LINE;
 
typedef struct tagBoxPoint // ������ �ڵ�
{
	float		fX, fY;

	tagBoxPoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagBoxPoint(float _fX, float _fY)
		: fX(_fX), fY(_fY)
	{	}

}BOXPOINT;


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

struct tagFinder
{
public:
	tagFinder(const TCHAR* pString) : m_pString(pString) {}

public:
	template<typename T>
	bool	operator()(T& rObj)
	{
		return !lstrcmp(m_pString, rObj.first);
	}

private:
	const TCHAR* m_pString;
};

struct DeleteMap
{
public:
	template<typename T>
	void	operator()(T& Pair)
	{
		if (Pair.second)
		{
			delete Pair.second;
			Pair.second = nullptr;
		}
	}
};

typedef struct tagBox // �����ڵ�
{
	LINEPOINT	tLT;
	LINEPOINT	tRT;
	LINEPOINT	tLB;
	LINEPOINT	tRB;

	tagBox() { ZeroMemory(this, sizeof(tagLine)); }
	/*tagBox(LINEPOINT& _tLT, LINEPOINT& _tRT, LINEPOINT& _tLB, LINEPOINT& _tRB)
		: tLT(_tLT), tRT(_tRT), tLB(_tLB), tRB(_tRB) {	}*/
	tagBox(LINEPOINT& _tCenter, float _fSize)
		:
		tLT{ _tCenter.fX - _fSize * 0.5f, _tCenter.fY - _fSize * 0.5f },
		tRT{ _tCenter.fX + _fSize * 0.5f, _tCenter.fY - _fSize * 0.5f },
		tLB{ _tCenter.fX - _fSize * 0.5f, _tCenter.fY + _fSize * 0.5f },
		tRB{ _tCenter.fX + _fSize * 0.5f, _tCenter.fY + _fSize * 0.5f }
	{}

}BOX;

///
/// ���⼭���� ä����
///
typedef struct tagFloatPoint
{
	float        fX, fY;

	tagFloatPoint() { ZeroMemory(this, sizeof(tagFloatPoint)); }
	tagFloatPoint(float _fX, float _fY)
		: fX(_fX), fY(_fY)
	{    }
	tagFloatPoint operator +(tagFloatPoint& rhs)
	{
		return (tagFloatPoint(fX + rhs.fX, fY + rhs.fY));
	}
	tagFloatPoint operator +(int i)
	{
		return (tagFloatPoint(fX + (float)i, fY + (float)i));
	}

}FPOINT;


typedef struct tagAniInfo
{
	FPOINT    tImgLT;
	FPOINT    tPosLT;
	FPOINT    tSize;
	INFO    tTargetInfo;
    int    iDuration;
	int        iMaxFrame;

	tagAniInfo() { ZeroMemory(this, sizeof(tagAniInfo)); }
	tagAniInfo(FPOINT _tImgLT, FPOINT _tPosLT, FPOINT _tSize, INFO _tTargetInfo, int _iDuration, int _iMaxFrame)
	{
		tImgLT = _tImgLT; tPosLT = _tPosLT; tSize = _tSize; tTargetInfo = _tTargetInfo; _iDuration = _iDuration; iMaxFrame = _iMaxFrame;
	}
}ANINFO;


typedef struct tagImage // �������ڵ� �̹��� ��ǥ ���°�(�ӽ�)
{
	int _iX;
	int _iY;

	bool operator==(tagImage rhs)
	{
		return (_iX == rhs._iX) && (_iY == rhs._iY);
	}

}IMAGE;

typedef struct tagImageInfo // �������ڵ� �̹��� ��ǥ ���°�(�ӽ�)
{
	int _iX;
	int _iY;
	int _iCX;
	int _iCY;

	bool operator==(tagImageInfo rhs)
	{
		return (_iX == rhs._iX) && (_iY == rhs._iY);
	}

}IMAGEINFO;
//Define.h�� �߰�


#define ANIMATION_CREATE(ANIKEY, THIS, FRAMESIZE, FRAMETIME, FRAMECOUNT, IMGKEY)    CAnimMgr::Get_Instance()->Insert_Animation(ANIKEY, CAbstractFactory<CAnimation>::Create(THIS, FRAMESIZE, FRAMETIME, FRAMECOUNT, IMGKEY))
#define ANIMATION_EDIT(KEY, LTX, LTY, FRAMESIZE, IDX)                                CAnimMgr::Get_Instance()->Edit_Animation(KEY, {LTX, LTY}, FRAMESIZE, IDX)
// SSIZE��ũ�δ� �ڸ��� ������ LT��ǥ�� �����ϰ� ���� ���� X����ŭ �����ϰ� �̵��� �ص� �Ǵ� ���
// IDX(������ �ε���)�� ��� �� ������ ���� �־ �ڵ����� �ڸ��� �뵵�Դϴ� (L�� ĳ���Ͱ� ������ �ٶ󺸴� ������ ���, R�� ����)
#define ANIMATION_EDIT_SSIZE_L(KEY, LTX, LTY, FRAMESIZE, FRAMECOUNT)        for (int i = 0; i < FRAMECOUNT; ++i){ CAnimMgr::Get_Instance()->Edit_Animation(KEY, {LTX + FRAMESIZE.fX * i, LTY}, FRAMESIZE, i); }
#define ANIMATION_EDIT_SSIZE_R(KEY, LTX, LTY, FRAMESIZE, FRAMECOUNT)        for (int i = 0; i < FRAMECOUNT; ++i){ CAnimMgr::Get_Instance()->Edit_Animation(KEY, {LTX - FRAMESIZE.fX * i, LTY}, FRAMESIZE, i); }
#define ANIMATION_RENDER(HDCHDC, ANIKEY, THIS)                                CAnimMgr::Get_Instance()->Render(HDCHDC, ANIKEY, THIS)