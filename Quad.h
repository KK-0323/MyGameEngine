#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>

using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX	matWVP; //would\view\projectionの行列
};

//頂点情報
struct VERTEX
{
	XMFLOAT4 pos;	//位置
	XMFLOAT2 uv;	//UV座標
};

//前方宣言
class Texture;

class Quad
{
public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw(DirectX::XMMATRIX& worldMatrix);
	void Release();
private:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//定数バッファ
	Texture* pTexture_;	//テクスチャ
};

