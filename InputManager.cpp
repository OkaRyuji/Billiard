//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// InputManager.cpp
// Input系統括
// ryuji oka
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "InputManager.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// プロトタイプ宣言
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// グローバル変数
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LPDIRECTINPUT8 InputManager::m_pDInput = NULL;
/////////////////////////////////////////////////////////////////////////////////
// 初期化
/////////////////////////////////////////////////////////////////////////////////
HRESULT InputManager::Init(HINSTANCE hInstance, HWND hWnd)
{
	HRESULT hr;

	if(m_pDInput == NULL)
	{
		hr = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDInput, NULL);

		return (hr);
	}

	return (S_OK);
}

/////////////////////////////////////////////////////////////////////////////////
// Uninit
/////////////////////////////////////////////////////////////////////////////////
void InputManager::Uninit(void)
{
	if(m_pDInput != NULL)
	{
		m_pDInput->Release();
		m_pDInput = NULL;
	}
}