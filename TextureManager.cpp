///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TextureManager.cpp
//	ryuji oka
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "TextureManager.h"
#include "Manager.h"
#include <string.h>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// プロトタイプ宣言
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// グローバル変数
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TextureManagerの初期化処理
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TextureManager::Init(int nMax)
{
	m_pTextureData = new TextureData[nMax];
	m_nTextureMax=nMax;
	// テクスチャポインタの初期化
	for (int i = 0; i < nMax; i++)
	{
		m_pTextureData[i].pTexture = NULL;
	}
	m_nTextureCount=0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TextureManagerの終了処理
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TextureManager::Uninit(void)
{
	if(m_pTextureData!=NULL)
	{
		for(int i=0; i<m_nTextureCount; i++)
		{
			m_pTextureData[i].pTexture->Release();
			m_pTextureData[i].pTexture=NULL;
		}
		delete[] m_pTextureData;
		m_pTextureData=NULL;
	}
	m_nTextureMax=0;
	m_nTextureCount=0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TextureManagerのLoad処理
// 管理番号を返す。読めなければ-1を返す
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int TextureManager::Load(const char *pTextureFileName)
{
	if(m_nTextureCount >= m_nTextureMax)
	{
		return -1;
	}

	for(int i=0; i<m_nTextureCount;i++)
	{
		if(strcmp(pTextureFileName,m_pTextureData[i].fileName)==0)
		{
			return i;
		}
	}
	
	LPDIRECT3DDEVICE9 pDevice=Manager::GetRenderer()->GetDevice();
	
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
								pTextureFileName,
								&m_pTextureData[m_nTextureCount].pTexture);

	//バッファをゼロクリア
	memset(m_pTextureData[m_nTextureCount].fileName, 0, sizeof(m_pTextureData[m_nTextureCount].fileName));
	
	//ファイル名のコピー
	strncpy_s(m_pTextureData[m_nTextureCount].fileName,pTextureFileName,sizeof(m_pTextureData[m_nTextureCount].fileName)-1);		//-1は終端文字を確保するため

	return ( m_nTextureCount++ );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TextureManager
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LPDIRECT3DTEXTURE9 TextureManager::GetTexture(int nId)
{
	if (m_pTextureData[nId].pTexture == NULL)
	{
		return (NULL);
	}

	return (m_pTextureData[nId].pTexture);
}
