#pragma once
#include <Windows.h>
#include <cstdint>

#include "addresses/addresses.hpp"


extern void rbx_spawn(std::uintptr_t rl);
extern void rbx_deserialize(std::uintptr_t rl, const char* chunk_name, const char* bytecode, int byte_len);
extern void rbx_decrement_top(std::uintptr_t rl, std::int32_t amount);
extern void rbx_setidentity(std::uintptr_t rl, std::int8_t identity);
extern void rbx_testfunc(std::uintptr_t rl);


extern func_defs::rbx_getscheduler_t rbx_getscheduler;
extern func_defs::rbx_getstate_t rbx_getstate;
extern func_defs::rbx_output_t rbx_output;
extern func_defs::rbx_pushvfstring_t rbx_pushvfstring;