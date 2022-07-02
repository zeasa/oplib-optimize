link_directories(
	"${PROJECT_BINARY_DIR}/lib"
    "${PROJECT_BINARY_DIR}/3rdparty/gtest"
	)

aux_source_directory(. TEST_SRCS)

add_executable(test_encode ${TEST_SRCS} ${GTEST_ROOT}/src/gtest_main.cc)
target_link_libraries(test_encode testbench_encode gtest gtest_main)
