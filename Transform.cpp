#include "Transform.h"

Transform::Transform()
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
    matRotate_ = XMMatrixRotationRollPitchYaw(rotate_.x, rotate_.y, rotate_.z);
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    return matScale_ * matRotate_ * matTranslate_;
}
