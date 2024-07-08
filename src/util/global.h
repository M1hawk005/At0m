#ifndef GLOBAL_H
#define GLOBAL_H

#include <mutex>
#include <vector>
#include <array>

struct MousePosition {
    float x;
    float y;
    bool updated;
};

extern MousePosition mousePosition;
extern std::mutex mousePositionMutex;

#endif // GLOBAL_H