link_directories(
	"${PROJECT_BINARY_DIR}/lib"
    "${PROJECT_BINARY_DIR}/3rdparty/gtest"
	)

aux_source_directory(. TEST_SRCS)

add_executable(test_oplib ${TEST_SRCS} ${GTEST_ROOT}/src/gtest_main.cc)
target_link_libraries(test_oplib oplib gtest gtest_main)
