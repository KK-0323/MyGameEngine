#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX	matWVP; //would\view\projectionの行列
};

class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//定数バッファ
public:
	Quad();
	~Quad();
	void Initialize();
	void Draw();
	void Release();
};

