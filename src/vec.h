#ifndef GLIC_VEC_HEADER
#define GLIC_VEC_HEADER

namespace glic {
    // function pointer aliases
    typedef float gl1float(float);
    typedef float gl2float(float, float);

    // vector types
    struct vec2 {
        float x, y;

        vec2(float x) : x(x), y(x) {}
        vec2(float x, float y) : x(x), y(y) {}

        // helpers
        vec2 apply(gl1float* function) const { return vec2(function(x), function(y)); }
        static vec2 zip(const gl2float *function, const vec2& x, const vec2& y){ return vec2(function(x.x, y.x), function(x.y, y.y)); }

        // overloads
        vec2& operator +=(const float v){ x += v; y += v; return *this; }
        vec2& operator +=(const vec2& v){ x += v.x; y += v.y; return *this; }
        
        vec2& operator -=(const float v){ x -= v; y -= v; return *this; }
        vec2& operator -=(const vec2& v){ x -= v.x; y -= v.y; return *this; }

        vec2& operator *=(const float v){ x *= v; y *= v; return *this; }
        vec2& operator *=(const vec2& v){ x *= v.x; y *= v.y; return *this; }

        vec2& operator /=(const float v){ x /= v; y /= v; return *this; }
        vec2& operator /=(const vec2& v){ x /= v.x; y /= v.y; return *this; }

        vec2 operator +(const float v) const { vec2 self(*this); self += v; return self; }
        vec2 operator +(const vec2& v) const { vec2 self(*this); self += v; return self; }

        vec2 operator -(const float v) const { vec2 self(*this); self -= v; return self; }
        vec2 operator -(const vec2& v) const { vec2 self(*this); self -= v; return self; }

        vec2 operator *(const float v) const { vec2 self(*this); self *= v; return self; }
        vec2 operator *(const vec2& v) const { vec2 self(*this); self *= v; return self; }

        vec2 operator /(const float v) const { vec2 self(*this); self /= v; return self; }
        vec2 operator /(const vec2& v) const { vec2 self(*this); self /= v; return self; }

        vec2& operator++(){ ++x; ++y; return *this; }
        vec2 operator++(int){ vec2 copy(*this); ++x; ++y; return copy; }
        vec2& operator--(){ --x; --y; return *this; }
        vec2 operator--(int){ vec2 copy(*this); --x; --y; return copy; }

        vec2 operator -() const { return vec2(-x, -y); }
    };

    vec2 operator +(const float v, const vec2& vec){ return vec2(vec.x + v, vec.y + v); }
    vec2 operator -(const float v, const vec2& vec){ return vec2(vec.x - v, vec.y - v); }
    vec2 operator *(const float v, const vec2& vec){ return vec2(vec.x * v, vec.y * v); }
    vec2 operator /(const float v, const vec2& vec){ return vec2(vec.x / v, vec.y / v); }

    struct vec3 {
        float x, y, z;
        
        vec3(float x) : x(x), y(x), z(x) {}
        vec3(float x, float y, float z) : x(x), y(y), z(z) {}

        // helpers
        vec3 apply(const gl1float* function) const { return vec3(function(x), function(y), function(z)); }
        static vec3 zip(const gl2float *function, const vec3& x, const vec3& y){ return vec3(function(x.x, y.x), function(x.y, y.y), function(x.z, y.z)); }

        // overloads
        vec3& operator +=(const float v){ x += v; y += v; z += v; return *this; }
        vec3& operator +=(const vec3& v){ x += v.x; y += v.y; z += v.z; return *this; }
        
        vec3& operator -=(const float v){ x -= v; y -= v; z -= v; return *this; }
        vec3& operator -=(const vec3& v){ x -= v.x; y -= v.y; z -= v.z; return *this; }

        vec3& operator *=(const float v){ x *= v; y *= v; z *= v; return *this; }
        vec3& operator *=(const vec3& v){ x *= v.x; y *= v.y; z *= v.z; return *this; }

        vec3& operator /=(const float v){ x /= v; y /= v; z /= v; return *this; }
        vec3& operator /=(const vec3& v){ x /= v.x; y /= v.y; z /= v.z; return *this; }

        vec3 operator +(const float v) const { vec3 self(*this); self += v; return self; }
        vec3 operator +(const vec3& v) const { vec3 self(*this); self += v; return self; }

        vec3 operator -(const float v) const { vec3 self(*this); self -= v; return self; }
        vec3 operator -(const vec3& v) const { vec3 self(*this); self -= v; return self; }

        vec3 operator *(const float v) const { vec3 self(*this); self *= v; return self; }
        vec3 operator *(const vec3& v) const { vec3 self(*this); self *= v; return self; }

        vec3 operator /(const float v) const { vec3 self(*this); self /= v; return self; }
        vec3 operator /(const vec3& v) const { vec3 self(*this); self /= v; return self; }

        vec3& operator++(){ ++x; ++y; ++z; return *this; }
        vec3 operator++(int){ vec3 copy(*this); ++x; ++y; ++z;return copy; }
        vec3& operator--(){ --x; --y; --z; return *this; }
        vec3 operator--(int){ vec3 copy(*this); --x; --y; --z; return copy; }

        vec3 operator -() const { return vec3(-x, -y, -z); }
    };

    vec3 operator +(const float v, const vec3& vec){ return vec3(vec.x + v, vec.y + v, vec.z + v); }
    vec3 operator -(const float v, const vec3& vec){ return vec3(vec.x - v, vec.y - v, vec.z - v); }
    vec3 operator *(const float v, const vec3& vec){ return vec3(vec.x * v, vec.y * v, vec.z * v); }
    vec3 operator /(const float v, const vec3& vec){ return vec3(vec.x / v, vec.y / v, vec.z / v); }

    struct vec4 {
        float x, y, z, w;

        vec4(float x) : x(x), y(x), z(x), w(x) {}
        vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        // helpers
        vec4 apply(gl1float *function) const { return vec4(function(x), function(y), function(z), function(w)); }
        static vec4 zip(const gl2float *function, const vec4& x, const vec4& y){ return vec4(function(x.x, y.x), function(x.y, y.y), function(x.z, y.z), function(x.w, y.w)); }

        // overloads
        vec4& operator +=(const float v){ x += v; y += v; z += v; w += v; return *this; }
        vec4& operator +=(const vec4& v){ x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
        
        vec4& operator -=(const float v){ x -= v; y -= v; z -= v; w -= v; return *this; }
        vec4& operator -=(const vec4& v){ x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }

        vec4& operator *=(const float v){ x *= v; y *= v; z *= v; w *= v; return *this; }
        vec4& operator *=(const vec4& v){ x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; }

        vec4& operator /=(const float v){ x /= v; y /= v; z /= v; w /= v; return *this; }
        vec4& operator /=(const vec4& v){ x /= v.x; y /= v.y; z /= v.z; w /= v.w; return *this; }

        vec4 operator +(const float v) const { vec4 self(*this); self += v; return self; }
        vec4 operator +(const vec4& v) const { vec4 self(*this); self += v; return self; }

        vec4 operator -(const float v) const { vec4 self(*this); self -= v; return self; }
        vec4 operator -(const vec4& v) const { vec4 self(*this); self -= v; return self; }

        vec4 operator *(const float v) const { vec4 self(*this); self *= v; return self; }
        vec4 operator *(const vec4& v) const { vec4 self(*this); self *= v; return self; }

        vec4 operator /(const float v) const { vec4 self(*this); self /= v; return self; }
        vec4 operator /(const vec4& v) const { vec4 self(*this); self /= v; return self; }

        vec4& operator++(){ ++x; ++y; ++z; ++w; return *this; }
        vec4 operator++(int){ vec4 copy(*this); ++x; ++y; ++z; ++w; return copy; }
        vec4& operator--(){ --x; --y; --z; --w; return *this; }
        vec4 operator--(int){ vec4 copy(*this); --x; --y; --z; --w; return copy; }

        vec4 operator -() const { return vec4(-x, -y, -z, -w); }
    };
    
    vec4 operator +(const float v, const vec4& vec){ return vec4(vec.x + v, vec.y + v, vec.z + v, vec.w + v); }
    vec4 operator -(const float v, const vec4& vec){ return vec4(vec.x - v, vec.y - v, vec.z - v, vec.w - v); }
    vec4 operator *(const float v, const vec4& vec){ return vec4(vec.x * v, vec.y * v, vec.z * v, vec.w * v); }
    vec4 operator /(const float v, const vec4& vec){ return vec4(vec.x / v, vec.y / v, vec.z / v, vec.w / v); }
};

#endif