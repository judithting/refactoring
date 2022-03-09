set(VIDEORENTAL_INCLUDE_DIR ../include)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if(VIDEORENTAL_WITH_TESTS)
    if(APPLE)
		add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
		add_definitions(-D__GLIBCXX__)
	endif()

	enable_testing()

	set(TEST_PROGRAM ${PROJECT_NAME}_test)
	add_executable(${TEST_PROGRAM}
		main.cpp
		statement.cpp
	)
    
	target_include_directories(${TEST_PROGRAM} PUBLIC
		${VIDEORENTAL_INCLUDE_DIR}
	)

	# Standard linking to gtest stuff.
	target_link_libraries(${TEST_PROGRAM}
		gtest_main
		${PROJECT_NAME}_lib
	)

	include(GoogleTest)
	gtest_discover_tests(${TEST_PROGRAM})
endif()
