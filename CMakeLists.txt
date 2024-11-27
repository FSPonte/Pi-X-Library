cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pi-X-Library)

include_directories(
	"include"

	"lib/type_info"
	"lib/smart_pointer"
	"lib/c_array"
	"lib/sort"
	"lib/random"

	"lib/memory"

	"lib/adt/array"
	"lib/adt/dyn_array"
	"lib/adt/stack"
	"lib/adt/queue"
	"lib/adt/deque"
	"lib/adt/node"
	"lib/adt/list"

	"lib/math"
	"lib/math/trig"
	"lib/math/hyper"
	"lib/math/stat"
	"lib/math/complex"
	"lib/math/vector"
	"lib/math/matrix"

	"lib/graphics/rgb"
	"lib/graphics/image"
)

add_executable(pix_tester
	src/main.cpp
)
