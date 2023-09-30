template<typename T>
class Transform2D
{
public:
    Transform2D() : mRotation(0), mTranslation(0, 0) {}

    Transform2D(T aRotation, Vector2<T, T> aTranslation)
        : mRotation(aRotation), mTranslation(aTranslation) {}

    Vector2<T, T> operator*(const Vector2<T, T>& aV) const
    {
        T newX = aV.mX * cos(mRotation) - aV.mY * sin(mRotation) + mTranslation.mX;
        T newY = aV.mX * sin(mRotation) + aV.mY * cos(mRotation) + mTranslation.mY;
        return Vector2<T, T>(newX, newY);
    }

    Transform2D& operator*=(const Transform2D& aT)
    {
        mRotation += aT.mRotation;
        mTranslation += aT.mTranslation;
        return *this;
    }

    void scale(const Vector2<T, T>& aScale)
    {
        mRotation *= aScale.len();
        mTranslation *= aScale;
    }

    void rotate(T aAngle)
    {
        mRotation += aAngle;
    }

    void translate(const Vector2<T, T>& aOffset)
    {
        mTranslation += aOffset;
    }

    Transform2D inverse() const
    {
        T invRotation = -mRotation;
        Vector2<T, T> invTranslation = Vector2<T, T>(-mTranslation.mX, -mTranslation.mY);
        return Transform2D(invRotation, invTranslation);
    }

    Transform2D interpolate_with(const Transform2D& aTransform, T aWeight) const
    {
        T newRotation = mRotation * (1 - aWeight) + aTransform.mRotation * aWeight;
        Vector2<T, T> newTranslation = mTranslation * (1 - aWeight) + aTransform.mTranslation * aWeight;
        return Transform2D(newRotation, newTranslation);
    }

private:
    T mRotation;
    Vector2<T, T> mTranslation;
};

using Transform2Dd = Transform2D<double>;
using Transform2Df = Transform2D<float>;