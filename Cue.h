#pragma once
#ifndef _Cue_H_
#define _Cue_H_

class Cue
{
public:
	Cue(int nPriority=4);
	~Cue();
	
	static Cue* Create(D3DXVECTOR3 pos,D3DXVECTOR3 rot,D3DXVECTOR3 scl,LPDIRECT3DTEXTURE9 pTexture,char *pModel,int nPriority=4);
	HRESULT Init(D3DXVECTOR3 pos,D3DXVECTOR3 rot,D3DXVECTOR3 scl,LPDIRECT3DTEXTURE9 pTexture,char *pModel);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:

};
#endif