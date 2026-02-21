project(Pi-X-Library)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-O3 -Wall -Wextra -Wpedantic)

include_directories(
	"include/"

	"utils/"

	"lib/type_info/"
	"lib/c_array/"
	"lib/memory/"
	"lib/smart_pointer/"
	"lib/sort/"
	"lib/random/"
	"lib/adt/array/"
	"lib/adt/tuple/"
	"lib/adt/stack/"
	"lib/adt/queue/"
	"lib/adt/deque/"
	"lib/adt/node/"
	"lib/adt/list/"
	"lib/adt/dyn_array/"
	"lib/adt/string/"
	"lib/math/"
	"lib/math/trig/"
	"lib/math/hyper/"
	"lib/math/stat/"
	"lib/math/complex/"
	"lib/math/vector/"
	"lib/math/matrix/"
	"lib/math/sys_lin_equ/"
	"lib/math/interpolation/"
	"lib/math/root_finding/"
	"lib/math/integration/"
	"lib/math/signal/"
	"lib/graphics/rgb/"
	"lib/graphics/image/"

	"lib/logger/"
	"lib/progress_bar/"
)

add_executable(pix_tester
	src/main.cpp
	utils/utils.cpp
	lib/logger/logger.cpp
	lib/progress_bar/progress_bar.cpp
)
