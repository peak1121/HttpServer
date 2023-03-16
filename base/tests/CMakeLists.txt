add_executable(atomic_unittest Atomic_unittest.cc)
target_link_libraries(atomic_unittest base)

# add_executable(thread_bench Thread_bench.cc)
# target_link_libraries(thread_bench base)

add_executable(thread_test Thread_test.cc)
target_link_libraries(thread_test base)

add_executable(timestamp_test TimeStamp_test.cc)
target_link_libraries(timestamp_test base)


