#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Transform.h"

using namespace DirectX;

struct CONSTANT_BUFFER
{
	XMMATRIX matWVP; //would\view\projectionの行列
	XMMATRIX matNormal;//法線変換用の行列
	XMMATRIX matWorld; //ワールド行列
};

//頂点情報
struct VERTEX
{
	XMFLOAT4 pos;	//位置
	XMFLOAT2 uv;	//UV座標
	XMFLOAT4 normal;//法線ベクトル
};

//前方宣言
class Texture;

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(Transform& transform);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//定数バッファ
	Texture* pTexture_;	//テクスチャ
};

