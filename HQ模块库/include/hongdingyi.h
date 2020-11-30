#pragma once
#ifdef WINDLL
#define PORTDLLCLASS __declspec(dllexport)
#else
#define PORTDLLCLASS
#endif

