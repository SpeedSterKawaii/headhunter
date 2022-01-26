#pragma once
#include <Windows.h>
#include <cstdint>

const std::uintptr_t current_module = reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL));

namespace func_defs
{
	using rbx_getscheduler_t = std::uintptr_t(__cdecl*)();
	using rbx_output_t = void(__fastcall*)(std::int16_t output_type, const char* str);
	using rbx_getstate_t = std::uintptr_t(__thiscall*)(std::uintptr_t SC, int* state_type);
	using rbx_pushvfstring_t = int(__cdecl*)(std::uintptr_t rl, const char* fmt, ...);
}

namespace addresses
{
	const std::uintptr_t rbx_getscheduler_addy = current_module + 0x00DE4AE0;
	const std::uintptr_t rbx_output_addy = current_module + 0x00220530;
	const std::uintptr_t rbx_getstate_addy = current_module + 0x003A65C0;
	const std::uintptr_t rbx_pushvfstring_addy = current_module + 0x015EA4E0;

	const std::uintptr_t spawn_func_addy = current_module + 0x003BE510;
	const std::uintptr_t deserializer_func_addy = current_module + 0x015EE590;

	const std::uintptr_t pushcclosure_addy = current_module + 0x0160E810;
	const std::uintptr_t pushcclosure_exit_addy = current_module + 0x0160E995;

	const std::uintptr_t test_func_addy = current_module + 0x016100F0;
	const std::uintptr_t xpcall_func_closure_addy = current_module + 0x16c7bd0 + 1; // not updated // *(_DWORD *)(closure + 24) = (unsigned int)sub_1AC0B90 ^ (closure + 24);// CLOSURE A
	const std::uintptr_t xpcall_string_spot_addy = current_module + 0x016145EA;

	const std::uintptr_t fake_ret_addy = current_module + 0x0102DF1D;
	const std::uintptr_t callcheck_addy = current_module + 0x17110f9; // not updated
}

namespace offsets
{
	namespace scheduler
	{
		constexpr std::uintptr_t jobs_start = 0x12C;
		constexpr std::uintptr_t jobs_end = 0x130;
	}

	namespace job
	{
		constexpr std::uintptr_t name = 0x10;
	}

	namespace waiting_scripts_job
	{
		constexpr std::uintptr_t datamodel = 0x28;
		constexpr std::uintptr_t script_context = 0x130;
	}

	namespace identity // not updated
	{
		constexpr std::uintptr_t extra_space = 0x6C;
		constexpr std::uintptr_t identity = 0x18;
	}

	namespace luastate
	{
		constexpr std::uintptr_t top = 0x18;
		constexpr std::uintptr_t base = 0xC;
	}
}