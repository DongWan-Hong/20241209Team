#include "pch.h"
#include "Block_Fire.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"

void CBlock_Fire::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_eBlockType = BLOCK_FIRE;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Rock_Man/tile_fire.bmp", L"Tile_Fire");
}

void CBlock_Fire::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();


	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Tile_Fire");

	BitBlt(hDC,						// ���� ���� DC
		m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
		m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,			// ���� ���� �̹����� ����, ����
		(int)m_tInfo.fCY,
		hMemDC,						// ������ �̹��� DC
		206,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
		3,
		SRCCOPY);					// ��� ȿ�� ����(�״�� ���)

	//int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	/*Rectangle(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top,
		m_tRect.right + iScrollX,
		m_tRect.bottom);*/
}