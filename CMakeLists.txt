project(Pi-X-Library)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
	"utils"
	"include"
	"lib/type_info"
	"lib/memory"
	"lib/smart_pointer"
	"lib/c_array"
	"lib/sort"
	"lib/random"
	"lib/adt/array"
	"lib/adt/tuple"
	"lib/adt/dyn_array"
	"lib/adt/stack"
	"lib/adt/queue"
	"lib/adt/deque"
	"lib/adt/node"
	"lib/adt/list"
	"lib/adt/string"
	"lib/math"
	"lib/math/trig"
	"lib/math/hyper"
	"lib/math/stat"
	"lib/math/complex"
	"lib/math/vector"
	"lib/math/matrix"
	"lib/math/signal"
	"lib/graphics/rgb"
	"lib/graphics/image"
)

add_executable(pix_tester
	src/main.cpp
	utils/utils.cpp
)
