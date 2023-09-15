#pragma once

#include "vector2.h"

template<typename T>
class Transform2D
{
public:
    Transform2D()
    {
        mMatrix[0] = Vector2<T>(1.0, 0.0);
        mMatrix[1] = Vector2<T>(0.0, 1.0);
    }

    // Transform2D(const double aRotation, const Vector2D &aScale, const double aTilt, )

    Transform2D(const Vector2<T>& aX, const Vector2<T>& aY, const Vector2& aVec)
    {
        mMatrix[0] = aX;
        mMatrix[1] = aY;
        mMatrix[2] = aVec;
    }

    void scale(const Vector2D &p_scale);
    

private:
    Vector2<T> mMatrix[3];
};