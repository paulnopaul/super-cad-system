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
    Number operator^(const Vector2& aV) const
    {
        return mX * aV.mY - mY * aV.mX;
    }

    void operator^=(const Vector2& aV)
    {
        Number temp = mX;
        mX = mX * aV.mY - mY * aV.mX;
        mY = temp * aV.mY - mY * aV.mX;
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

    Vector2 operator-() const
    {
        return Vector2(-mX, -mY);
    }

    Vector2 operator/(const Number aNum) const
    {
        return Vector2(mX / aNum, mY / aNum);
    }

    void operator/=(const Number aNum)
    {
        mX /= aNum;
        mY /= aNum;
    }

    bool operator==(const Vector2& aV) const
    {
        return mX == aV.mX && mY == aV.mY;
    }

    operator std::pair<T, T>() const
    {
        return std::make_pair(mX, mY);
    }

    const Number len() const
    {
        return sqrt(mX * mX + mY * mY);
    }

    void normalize()
    {
        Number norm_val = norm();
        if (norm_val != 0)
        {
            mX /= norm_val;
            mY /= norm_val;
        }
    }

    const Number norm() const
    {
        return len();
    }
    
private:
    T mX, mY;
};

using Vector2D = Vector2<double, double>;
using Vector2F = Vector2<float, float>;