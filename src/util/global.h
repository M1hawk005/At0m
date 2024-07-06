#ifndef GLOBAL_H
#define GLOBAL_H

#include <mutex>
#include <vector>
#include <array>

struct ClickPosition {
    float x;
    float y;
};

extern ClickPosition clickPosition;
extern std::mutex clickPositionMutex;

#endif // GLOBAL_H