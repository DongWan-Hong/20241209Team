#pragma once

#include "CScene.h"

class CStage_Silver : public CScene
{
public:
	CStage_Silver();
	~CStage_Silver();


	virtual void Initialize()override;  // �����Ҵ���ʱ�ȭ

	virtual void Update()override; // �ǽð� ����

	virtual void LateUpdate()override;

	virtual void Release()override; // �����Ҵ�����

	virtual void Render(HDC _hDC)override;


private:




};