// Simple RayTracing Header
// Reference https://github.com/Tecla/Rayito
//
#ifndef __RAYTRACING_H__
#define __RAYTRACING_H__

#include <cmath>
#include <list>
#include <algorithm>

namespace RAYTRACING
{

// constant
const float kRayTMin = 0.00001f;
const float kRayTMax = 1.0e30f;

class Color
{
    float m_r, m_g, m_b;
    
    Color()                          : m_r(0.0f), m_g(0.0f), m_b(0.0f)    { }
    Color(const Color& c)            : m_r(c.m_r), m_g(c.m_g), m_b(c.m_b) { }
    Color(float r, float g, float b) : m_r(r), m_g(g), m_b(b)             { }
    explicit Color(float f)          : m_r(f), m_g(f), m_b(f)             { }
    
    
    void clamp(float min = 0.0f, float max = 1.0f)
    {
        m_r = std::max(min, std::min(max, m_r));
        m_g = std::max(min, std::min(max, m_g));
        m_b = std::max(min, std::min(max, m_b));
    }
    
    
    Color& operator =(const Color& c)
    {
        m_r = c.m_r;
        m_g = c.m_g;
        m_b = c.m_b;
        return *this;
    }
    
    Color& operator +=(const Color& c)
    {
        m_r += c.m_r;
        m_g += c.m_g;
        m_b += c.m_b;
        return *this;
    }
    
    Color& operator -=(const Color& c)
    {
        m_r -= c.m_r;
        m_g -= c.m_g;
        m_b -= c.m_b;
        return *this;
    }
    
    Color& operator *=(const Color& c)
    {
        m_r *= c.m_r;
        m_g *= c.m_g;
        m_b *= c.m_b;
        return *this;
    }
    
    Color& operator /=(const Color& c)
    {
        m_r /= c.m_r;
        m_g /= c.m_g;
        m_b /= c.m_b;
        return *this;
    }
    
    Color& operator *=(float f)
    {
        m_r *= f;
        m_g *= f;
        m_b *= f;
        return *this;
    }
    
    Color& operator /=(float f)
    {
        m_r /= f;
        m_g /= f;
        m_b /= f;
        return *this;
    }
};

class Vector
{
    float m_x, m_y, m_z;
    
    Vector()                          : m_x(0.0f), m_y(0.0f), m_z(0.0f)    { }
    Vector(const Vector& v)           : m_x(v.m_x), m_y(v.m_y), m_z(v.m_z) { }
    Vector(float x, float y, float z) : m_x(x), m_y(y), m_z(z)             { }
    explicit Vector(float f)          : m_x(f), m_y(f), m_z(f)             { }
    
    
    float length2() const { return m_x * m_x + m_y * m_y + m_z * m_z; }
    float length()  const { return std::sqrt(length2()); }
    
    // Returns old length from before normalization (ignore the return value 
    // if you don't need it)
    float  normalize() { float len = length(); *this /= len; return len; }
    // Return a vector in this same direction, but normalized
    Vector normalized() const { Vector r(*this); r.normalize(); return r; }
    
    
    Vector& operator =(const Vector& v)
    {
        m_x = v.m_x;
        m_y = v.m_y;
        m_z = v.m_z;
        return *this;
    }
    
    Vector& operator +=(const Vector& v)
    {
        m_x += v.m_x;
        m_y += v.m_y;
        m_z += v.m_z;
        return *this;
    }
    
    Vector& operator -=(const Vector& v)
    {
        m_x -= v.m_x;
        m_y -= v.m_y;
        m_z -= v.m_z;
        return *this;
    }
    
    Vector& operator *=(float f)
    {
        m_x *= f;
        m_y *= f;
        m_z *= f;
        return *this;
    }
    
    Vector& operator /=(float f)
    {
        m_x /= f;
        m_y /= f;
        m_z /= f;
        return *this;
    }
};

// dot(v1, v2) = length(v1) * length(v2) * cos(angle between v1, v2)
inline float dot(const Vector& v1, const Vector& v2)
{
    // In cartesian coordinates, it simplifies to this simple calculation:
    return v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z;
}


// cross(v1, v2) = length(v1) * length(v2) * sin(angle between v1, v2);
// result is perpendicular to both v1, v2.
inline Vector cross(const Vector& v1, const Vector& v2)
{
    // In cartesian coordinates, it simplifies down to this calculation:
    return Vector(v1.m_y * v2.m_z - v1.m_z * v2.m_y,
                  v1.m_z * v2.m_x - v1.m_x * v2.m_z,
                  v1.m_x * v2.m_y - v1.m_y * v2.m_x);
}



}

#endif
