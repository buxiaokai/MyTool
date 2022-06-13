#pragma once
#include "memory.h"
#include "offsets.h"


class vec3{
public:
    vec3();
    vec3(float _x, float _y, float _z);
    vec3 operator+(const vec3& other);
    vec3 operator+=(const vec3& other);
    float x = 0, y = 0, z = 0;

};
class player_info{
public:
    player_info(memory_tool::memory_manager* mem,uintptr_t address);
    int health;
    bool dormant;
    int team;
    vec3 pos, top;
};
class player_Struct{
public:
    uintptr_t player_ptr;
    int id;
    uintptr_t* prev;
    uintptr_t* next;
};
struct vec_view{
    float vec_4[4][4];
    float* operator[](int index){
        return vec_4[index];
    }
};
class esp_struct{
public:
    bool valid = false;
    int health = 0;
    vec3 pos, top;
};
bool world2screen(vec3 pos, vec3 &out, vec_view matrix, float screen_X, float screen_Y);
