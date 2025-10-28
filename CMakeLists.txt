project(Pi-X-Library)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(
	"utils/"
	"logger/"

	"include/"

	"t_lib/type_info/"
	"t_lib/c_array/"
	"t_lib/memory/"
	"t_lib/smart_pointer/"
	"t_lib/sort/"
	"t_lib/random/"
	"t_lib/adt/array/"
	"t_lib/adt/tuple/"
	"t_lib/adt/stack/"
	"t_lib/adt/queue/"
	"t_lib/adt/deque/"
	"t_lib/adt/node/"
	"t_lib/adt/list/"
	"t_lib/adt/dyn_array/"
	"t_lib/adt/string/"
	"t_lib/math/"
	"t_lib/math/trig/"
	"t_lib/math/hyper/"
	"t_lib/math/stat/"
	"t_lib/math/complex/"
	"t_lib/math/vector/"
	"t_lib/math/matrix/"
	"t_lib/math/sys_lin_equ/"
	"t_lib/math/interpolation/"
	"t_lib/math/root_finding/"
	"t_lib/math/integration/"
	"t_lib/math/signal/"
	"t_lib/graphics/rgb/"
	"t_lib/graphics/image/"
)

add_executable(pix_tester
	src/main.cpp
	utils/utils.cpp
	logger/logger.cpp
)
