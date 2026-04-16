# pragma once
#include <cmath>

struct Vector2i
{
    int x, y;
    Vector2i(int x, int y) : x(x), y(y) {}
    Vector2i() = default;
    Vector2i operator+(const Vector2i& other) const { return Vector2i(x + other.x, y + other.y); }
    Vector2i operator-(const Vector2i& other) const { return Vector2i(x - other.x, y - other.y); }
    Vector2i operator*(const Vector2i& other) const { return Vector2i(x * other.x, y * other.y); }
    Vector2i operator/(const Vector2i& other) const { return Vector2i(x / other.x, y / other.y); }
    Vector2i& operator+=(const Vector2i& other) { x += other.x; y += other.y; return *this; }
    Vector2i& operator-=(const Vector2i& other) { x -= other.x; y -= other.y; return *this; }
    Vector2i& operator*=(const Vector2i& other) { x *= other.x; y *= other.y; return *this; }
    Vector2i& operator/=(const Vector2i& other) { x /= other.x; y /= other.y; return *this; }
    static const Vector2i ZERO;
    static const Vector2i ONE;
};
inline const Vector2i Vector2i::ZERO = Vector2i(0, 0);
inline const Vector2i Vector2i::ONE = Vector2i(1, 1);

struct Vector2f
{
    float x, y;
    Vector2f(float x, float y) : x(x), y(y) {}
    Vector2f() = default;
    Vector2f operator+(const Vector2f& other) const { return Vector2f(x + other.x, y + other.y); }
    Vector2f operator-(const Vector2f& other) const { return Vector2f(x - other.x, y - other.y); }
    Vector2f operator*(const Vector2f& other) const { return Vector2f(x * other.x, y * other.y); }
    Vector2f operator/(const Vector2f& other) const { return Vector2f(x / other.x, y / other.y); }
    Vector2f& operator+=(const Vector2f& other) { x += other.x; y += other.y; return *this; }
    Vector2f& operator-=(const Vector2f& other) { x -= other.x; y -= other.y; return *this; }
    Vector2f& operator*=(const Vector2f& other) { x *= other.x; y *= other.y; return *this; }
    Vector2f& operator/=(const Vector2f& other) { x /= other.x; y /= other.y; return *this; }
    static const Vector2f ZERO;
    static const Vector2f ONE;
};
inline const Vector2f Vector2f::ZERO = Vector2f(0, 0);
inline const Vector2f Vector2f::ONE = Vector2f(1, 1);

struct Vector3i
{
    int x, y, z;
    Vector2i xy;
    Vector3i(int x, int y, int z) : x(x), y(y), z(z), xy(x, y) {}
    Vector3i() = default;
    Vector3i operator+(const Vector3i& other) const { return Vector3i(x + other.x, y + other.y, z + other.z); }
    Vector3i operator-(const Vector3i& other) const { return Vector3i(x - other.x, y - other.y, z - other.z); }
    Vector3i operator*(const Vector3i& other) const { return Vector3i(x * other.x, y * other.y, z * other.z); }
    Vector3i operator/(const Vector3i& other) const { return Vector3i(x / other.x, y / other.y, z / other.z); }
    Vector3i& operator+=(const Vector3i& other) { x += other.x; y += other.y; z += other.z; return *this; }
    Vector3i& operator-=(const Vector3i& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
    Vector3i& operator*=(const Vector3i& other) { x *= other.x; y *= other.y; z *= other.z; return *this; }
    Vector3i& operator/=(const Vector3i& other) { x /= other.x; y /= other.y; z /= other.z; return *this; }
    static const Vector3i ZERO;
    static const Vector3i ONE;
};
inline const Vector3i Vector3i::ZERO = Vector3i(0, 0, 0);
inline const Vector3i Vector3i::ONE = Vector3i(1, 1, 1);

struct Vector3f
{
    float x, y, z;
    Vector2f xy;
    Vector3f(float x, float y, float z) : x(x), y(y), z(z), xy(x, y) {}
    Vector3f() = default;
    Vector3f operator+(const Vector3f& other) const { return Vector3f(x + other.x, y + other.y, z + other.z); }
    Vector3f operator-(const Vector3f& other) const { return Vector3f(x - other.x, y - other.y, z - other.z); }
    Vector3f operator*(const Vector3f& other) const { return Vector3f(x * other.x, y * other.y, z * other.z); }
    Vector3f operator/(const Vector3f& other) const { return Vector3f(x / other.x, y / other.y, z / other.z); }
    Vector3f& operator+=(const Vector3f& other) { x += other.x; y += other.y; z += other.z; return *this; }
    Vector3f& operator-=(const Vector3f& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
    Vector3f& operator*=(const Vector3f& other) { x *= other.x; y *= other.y; z *= other.z; return *this; }
    Vector3f& operator/=(const Vector3f& other) { x /= other.x; y /= other.y; z /= other.z; return *this; }
    static const Vector3f ZERO;
    static const Vector3f ONE;
};
inline const Vector3f Vector3f::ZERO = Vector3f(0, 0, 0);
inline const Vector3f Vector3f::ONE = Vector3f(1, 1, 1);