#pragma once
/*
 * EvisionPnP 导出宏(跨平台)
 * Windows(MSVC): __declspec(dllexport)
 * GCC/Clang(Linux/macOS): __attribute__((visibility("default")))
 */
#if defined(_MSC_VER)
#define EVISION_PNP_EXPORT __declspec(dllexport)
#else
#define EVISION_PNP_EXPORT __attribute__((visibility("default")))
#endif
