project(Corwar_lib)

file(GLOB HEADER_FILES "includes/*.h")
file(GLOB SOURCE_FILES "src/*.c")

add_library(Corwar_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Corwar_lib libft)