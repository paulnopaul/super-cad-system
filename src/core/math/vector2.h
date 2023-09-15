#pragma once

#include <cmath>


template<typename T, typename Number>
class Vector2
{
public:
    Vector2() : mX(0), mY(0) {}
    Vector2(const Vector2& v) = default;

    Vector2(T aX, T aY) : mX(aX), mY(aY) {}

    Vector2 operator+(const Vector2& aV) const
    {
        return Vector2(mX + aV.mX, mY + aV.mY)
    }

    void operator+=(const Vector2& aV)
    {
        mX += aV.mX;
        mY += aV.mY;
    }

    Vector2 operator-(const Vector2& aV) const
    {
        return Vector2(mX - aV.mX, mY - aV.mY)
    }

    void operator-=(const Vector2& aV)
    {
        mX -= aV.mX;
        mY -= aV.mY;
    }

    // cross product
    Vector2 operator^(const Vector2& aV) const
    {
        // TODO think
        return Vector2();
    }

    void operator^=(const Vector2& aV)
    {
        // TODO think
    }

    // Dot product
    Number operator*(const Vector2& aV) const
    {
        return mX * aV.mX + mY * aV.mY;
    }

    Vector2 operator*(const Number aNum) const
    {
        return Vector2(mX * aNum, mY * aNum)
    }

    void operator*=(const Number aNum)
    {
        mX *= aNum;
        mY *= aNum;
    }

    bool operator==(const Vector2& aV) const
    {
        return mX == aV.mX && mY == aV.mY;
    }

    const Number len() const
    {
        return sqrt(mX * mX + mY * mY);
    }

    void normalize();

    const Number norm() const;
    
private:
    T mX, mY;
};

using Vector2D = Vector2<double, double>;
using Vector2F = Vector2<float, float>;