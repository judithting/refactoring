include_directories(${VIDEO_RENTAL_SOURCE_DIR}/lib)
link_directories(${VIDEO_RENTAL_BINARY_DIR}/lib)

# add the executable
add_executable (${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_lib)

# add the binary tree to the search path for include files
target_include_directories(${PROJECT_NAME} PUBLIC
	"${PROJECT_SOURCE_DIR}/include"
)
