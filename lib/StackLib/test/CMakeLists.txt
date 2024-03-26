add_executable(Test StackTesting.cpp)

target_link_libraries(Test PRIVATE gtest_main StackLib)

target_include_directories(Test PRIVATE
        ".."
)