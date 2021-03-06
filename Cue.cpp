///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cue.cpp
// Ballオブジェクトに対して物理干渉する
// プレイヤが直接干渉出来るオブジェクト
//	ryuji oka
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "Cue.h"
#include "TextureManager.h"
#include "Scene.h"
#include "Manager.h"
#include "InputKeyboard.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// マクロ定義
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define TOP (4)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// プロトタイプ宣言
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// グローバル変数
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// コンストラクタ
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Cue::Cue(int nPriority)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// デストラクタ
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Cue::~Cue()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Init関数
//	:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT Cue::Init(D3DXVECTOR3 pos,D3DXVECTOR3 rot,D3DXVECTOR3 scl,LPDIRECT3DTEXTURE9 pTexture,char *pModel)
{

	return S_OK;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Uninit関数
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Cue::Uninit(void)
{

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Update関数
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Cue::Update(void)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Draw関数
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Cue::Draw(void)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Create関数
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Cue* Cue::Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot,D3DXVECTOR3 scl,LPDIRECT3DTEXTURE9 pTexture,char *pModel,int nPriority)
{
	Cue *pRet = new Cue(nPriority);
	pRet->Init(pos,rot,scl,pTexture,pModel);
	return pRet;
}