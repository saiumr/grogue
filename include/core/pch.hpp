#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

#include "core/assert.hpp"
#include "core/debugbreak.hpp"
#include "core/ecs.hpp"
#include "core/log.hpp"
#include "core/math.hpp"
#include "sol/sol.hpp"
#include "core/sparse_sets.hpp"
#include "core/magic_enum.hpp"
#include "core/singleton.hpp"
#include "core/utility.hpp"
#include "core/refl.hpp"
#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_map>
#include <chrono>
#include <type_traits>
#include <utility>
#include <queue>
#include <algorithm>