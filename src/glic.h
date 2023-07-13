#ifndef GLIC_H
#define GLIC_H

#include <cmath>

namespace glic {
    typedef float glffloat(float);
    typedef float gl2float(float, float);

    // vector types
    struct vec2 {
        float x, y;
        vec2(float x, float y) : x(x), y(y) {}

        // helpers
        vec2 apply(glffloat* function) const { return vec2(function(x), function(y)); }
        static vec2 zip(gl2float *function, vec2 x, vec2 y){ return vec2(function(x.x, y.x), function(x.y, y.y)); }
    };

    struct vec3 {
        float x, y, z;
        vec3(float x, float y, float z) : x(x), y(y), z(z) {}

        // helpers
        vec3 apply(glffloat* function) const { return vec3(function(x), function(y), function(z)); }
        static vec3 zip(gl2float *function, vec3 x, vec3 y){ return vec3(function(x.x, y.x), function(x.y, y.y), function(x.z, y.z)); }
    };

    struct vec4 {
        float x, y, z, w;
        vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        // helpers
        vec4 apply(glffloat *function) const { return vec4(function(x), function(y), function(z), function(w)); }
        static vec4 zip(gl2float *function, vec4 x, vec4 y){ return vec4(function(x.x, y.x), function(x.y, y.y), function(x.z, y.z), function(x.w, y.w)); }
    };

    // trigonometry

    float radians(const float degrees){ return degrees * 180.0 / M_PI; }
    vec2 radians(const vec2 degrees){ return degrees.apply(radians); }
    vec3 radians(const vec3 degrees){ return degrees.apply(radians); }
    vec4 radians(const vec4 degrees){ return  degrees.apply(radians); }

    float degrees(const float radians){ return radians * M_PI / 180.0; }
    vec2 degrees(const vec2 radians){ return radians.apply(degrees); }
    vec3 degrees(const vec3 radians){ return radians.apply(degrees); }
    vec4 degrees(const vec4 radians){ return radians.apply(degrees); }

    float sin(const float angle){ return std::sin(angle); }
    vec2 sin(const vec2 angle){ return angle.apply(std::sin); }
    vec3 sin(const vec3 angle){ return angle.apply(std::sin); }
    vec4 sin(const vec4 angle){ return angle.apply(std::sin); }

    float cos(const float angle){ return std::cos(angle); }
    vec2 cos(const vec2 angle){ return angle.apply(std::cos); }
    vec3 cos(const vec3 angle){ return angle.apply(std::cos); }
    vec4 cos(const vec4 angle){ return angle.apply(std::cos); }

    float tan(const float angle){ return std::tan(angle); }
    vec2 tan(const vec2 angle){ return angle.apply(std::tan); }
    vec3 tan(const vec3 angle){ return angle.apply(std::tan); }
    vec4 tan(const vec4 angle){ return angle.apply(std::tan); }

    float asin(const float angle){ return std::asin(angle); }
    vec2 asin(const vec2 angle){ return angle.apply(std::asin); }
    vec3 asin(const vec3 angle){ return angle.apply(std::asin); }
    vec4 asin(const vec4 angle){ return angle.apply(std::asin); }

    float acos(const float angle){ return std::acos(angle); }
    vec2 acos(const vec2 angle){ return angle.apply(std::acos); }
    vec3 acos(const vec3 angle){ return angle.apply(std::acos); }
    vec4 acos(const vec4 angle){ return angle.apply(std::acos); }

    float atan(const float angle){ return std::atan(angle); }
    vec2 atan(const vec2 angle){ return angle.apply(std::atan); }
    vec3 atan(const vec3 angle){ return angle.apply(std::atan); }
    vec4 atan(const vec4 angle){ return angle.apply(std::atan); }

    float atan(const float y, const float x){ return std::atan2(y, x); }
    vec2 atan(const vec2 y, const vec2 x){ return vec2::zip(std::atan2, y, x); }
    vec3 atan(const vec3 y, const vec3 x){ return vec3::zip(std::atan2, y, x); }
    vec4 atan(const vec4 y, const vec4 x){ return vec4::zip(std::atan2, y, x); }

    // exponential

    float pow(const float x, const float y){ return std::pow(x, y); }
    vec2 pow(const vec2 x, const vec2 y){ return vec2::zip(std::pow, x, y); }
    vec3 pow(const vec3 x, const vec3 y){ return vec3::zip(std::pow, x, y); }
    vec4 pow(const vec4 x, const vec4 y){ return vec4::zip(std::pow, x, y); }

    float exp(const float x){ return std::exp(x); }
    vec2 exp(const vec2 x){ return x.apply(std::exp); }
    vec3 exp(const vec3 x){ return x.apply(std::exp); }
    vec4 exp(const vec4 x){ return x.apply(std::exp); }

    float exp2(const float x){ return std::exp2(x); }
    vec2 exp2(const vec2 x){ return x.apply(std::exp2); }
    vec3 exp2(const vec3 x){ return x.apply(std::exp2); }
    vec4 exp2(const vec4 x){ return x.apply(std::exp2); }

    float log(const float x){ return std::log(x); }
    vec2 log(const vec2 x){ return x.apply(std::log); }
    vec3 log(const vec3 x){ return x.apply(std::log); }
    vec4 log(const vec4 x){ return x.apply(std::log); }

    float log2(const float x){ return std::log2(x); }
    vec2 log2(const vec2 x){ return x.apply(std::log2); }
    vec3 log2(const vec3 x){ return x.apply(std::log2); }
    vec4 log2(const vec4 x){ return x.apply(std::log2); }

    float sqrt(const float x){ return std::sqrt(x); }
    vec2 sqrt(const vec2 x){ return x.apply(std::sqrt); }
    vec3 sqrt(const vec3 x){ return x.apply(std::sqrt); }
    vec4 sqrt(const vec4 x){ return x.apply(std::sqrt); }

    float inversesqrt(const float x){ return 1.0 / std::sqrt(x); }
    vec2 inversesqrt(const vec2 x){ return x.apply(inversesqrt); }
    vec3 inversesqrt(const vec3 x){ return x.apply(inversesqrt); }
    vec4 inversesqrt(const vec4 x){ return x.apply(inversesqrt); }

    // common

    float abs(const float x){ return std::abs(x); }
    vec2 abs(const vec2 x){ return x.apply(std::abs); }
    vec3 abs(const vec3 x){ return x.apply(std::abs); }
    vec4 abs(const vec4 x){ return x.apply(std::abs); }

    float sign(const float x){ return (x > 0) - (x < 0); }
    vec2 sign(const vec2 x){ return x.apply(sign); }
    vec3 sign(const vec3 x){ return x.apply(sign); }
    vec4 sign(const vec4 x){ return x.apply(sign); }

    float floor(const float x){ return std::floor(x); }
    vec2 floor(const vec2 x){ return x.apply(std::floor); }
    vec3 floor(const vec3 x){ return x.apply(std::floor); }
    vec4 floor(const vec4 x){ return x.apply(std::floor); }

    float ceil(const float x){ return std::ceil(x); }
    vec2 ceil(const vec2 x){ return x.apply(std::ceil); }
    vec3 ceil(const vec3 x){ return x.apply(std::ceil); }
    vec4 ceil(const vec4 x){ return x.apply(std::ceil); }

    float fract(const float x){ return x - std::floor(x); }
    vec2 fract(const vec2 x){ return x.apply(fract); }
    vec3 fract(const vec3 x){ return x.apply(fract); }
    vec4 fract(const vec4 x){ return x.apply(fract); }

    float mod(const float x, const float y){ return std::fmod(x, y); }
    vec2 mod(const vec2 x, const vec2 y){ return vec2::zip(std::fmod, x, y); }
    vec3 mod(const vec3 x, const vec3 y){ return vec3::zip(std::fmod, x, y); }
    vec4 mod(const vec4 x, const vec4 y){ return vec4::zip(std::fmod, x, y); }

    vec2 mod(const vec2 x, const float y){ return vec2(std::fmod(x.x, y), std::fmod(x.y, y)); }
    vec3 mod(const vec3 x, const float y){ return vec3(std::fmod(x.x, y), std::fmod(x.y, y), std::fmod(x.z, y)); }
    vec4 mod(const vec4 x, const float y){ return vec4(std::fmod(x.x, y), std::fmod(x.y, y), std::fmod(x.z, y), std::fmod(x.w, y)); }

    float min(const float x, const float y){ return std::min(x, y); }
    vec2 min(const vec2 x, const vec2 y){ return vec2::zip(min, x, y); }
    vec3 min(const vec3 x, const vec3 y){ return vec3::zip(min, x, y); }
    vec4 min(const vec4 x, const vec4 y){ return vec4::zip(min, x, y); }

    vec2 min(const vec2 x, const float y){ return vec2(std::min(x.x, y), std::min(x.y, y)); }
    vec3 min(const vec3 x, const float y){ return vec3(std::min(x.x, y), std::min(x.y, y), std::min(x.z, y)); }
    vec4 min(const vec4 x, const float y){ return vec4(std::min(x.x, y), std::min(x.y, y), std::min(x.z, y), std::min(x.w, y)); }
    
    float max(const float x, const float y){ return std::max(x, y); }
    vec2 max(const vec2 x, const vec2 y){ return vec2::zip(max, x, y); }
    vec3 max(const vec3 x, const vec3 y){ return vec3::zip(max, x, y); }
    vec4 max(const vec4 x, const vec4 y){ return vec4::zip(max, x, y); }

    vec2 max(const vec2 x, const float y){ return vec2(std::max(x.x, y), std::max(x.y, y)); }
    vec3 max(const vec3 x, const float y){ return vec3(std::max(x.x, y), std::max(x.y, y), std::max(x.z, y)); }
    vec4 max(const vec4 x, const float y){ return vec4(std::max(x.x, y), std::max(x.y, y), std::max(x.z, y), std::max(x.w, y)); }

    float clamp(const float x, const float minval, const float maxval){ return min(max(x, minval), maxval); }
    vec2 clamp(const vec2 x, const vec2 minval, const vec2 maxval){ return min(max(x, minval), maxval); }
    vec3 clamp(const vec3 x, const vec3 minval, const vec3 maxval){ return min(max(x, minval), maxval); }
    vec4 clamp(const vec4 x, const vec4 minval, const vec4 maxval){ return min(max(x, minval), maxval); }

    vec2 clamp(const vec2 x, const float minval, const float maxval){ return min(max(x, minval), maxval); }
    vec3 clamp(const vec3 x, const float minval, const float maxval){ return min(max(x, minval), maxval); }
    vec4 clamp(const vec4 x, const float minval, const float maxval){ return min(max(x, minval), maxval); }

    float mix(const float x, const float y, const float a){
        #if __cplusplus >= 202002L
            return std::lerp(x, y, a);
        #else
            return x + a * (y - x);
        #endif
    }

    vec2 mix(const vec2 x, const vec2 y, const vec2 a){ return vec2(mix(x.x, y.x, a.x), mix(x.y, y.y, a.y)); }
    vec3 mix(const vec3 x, const vec3 y, const vec3 a){ return vec3(mix(x.x, y.x, a.x), mix(x.y, y.y, a.y), mix(x.z, y.z, a.z)); }
    vec4 mix(const vec4 x, const vec4 y, const vec4 a){ return vec4(mix(x.x, y.x, a.x), mix(x.y, y.y, a.y), mix(x.z, y.z, a.z), mix(x.w, y.w, a.w)); }

    vec2 mix(const vec2 x, const vec2 y, const float a){ return vec2(mix(x.x, y.x, a), mix(x.y, y.y, a)); }
    vec3 mix(const vec3 x, const vec3 y, const float a){ return vec3(mix(x.x, y.x, a), mix(x.y, y.y, a), mix(x.z, y.z, a)); }
    vec4 mix(const vec4 x, const vec4 y, const float a){ return vec4(mix(x.x, y.x, a), mix(x.y, y.y, a), mix(x.z, y.z, a), mix(x.w, y.w, a)); }

    float step(const float edge, const float x){ return x >= edge; }
    vec2 step(const vec2 edge, const vec2 x){ return vec2::zip(step, edge, x); }
    vec3 step(const vec3 edge, const vec3 x){ return vec3::zip(step, edge, x); }
    vec4 step(const vec4 edge, const vec4 x){ return vec4::zip(step, edge, x); }

    float step(const float edge, const float x){ return x >= edge; }
    vec2 step(const float edge, const vec2 x){ return vec2(step(edge, x.x), step(edge, x.y)); }
    vec3 step(const float edge, const vec3 x){ return vec3(step(edge, x.x), step(edge, x.y), step(edge, x.z)); }
    vec4 step(const float edge, const vec4 x){ return vec4(step(edge, x.x), step(edge, x.y), step(edge, x.z), step(edge, x.w)); }
    
    // left off at smoothstep
};
#endif