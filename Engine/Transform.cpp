#include "Transform.h"

Transform::Transform()
    :matScale_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matTranslate_(XMMatrixIdentity())
{
    position_ = { 0.0f,0.0f,0.0f };
    rotate_ = { 0.0f,0.0f,0.0f };
    scale_ = { 1.0f,1.0f,1.0f };
}

Transform::~Transform()
{
}

void Transform::Calculation()
{
    matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
    matRotate_ = XMMatrixRotationRollPitchYaw(XMConvertToRadians(rotate_.x), XMConvertToRadians(rotate_.y), XMConvertToRadians(rotate_.z));
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    return matScale_ * matRotate_ * matTranslate_;
}

XMMATRIX Transform::GetNormalMatrix()
{
    return matRotate_ * XMMatrixInverse(nullptr, matScale_);
}
