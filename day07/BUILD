
cc_library(
    name = "solver",
    srcs = ["solver.cc"],
    hdrs = ["solver.hh"]
)

cc_test(
    name = "test1",
    srcs = ["test1.cc"],
    deps = [":solver", "@googletest//:gtest_main"]
)

cc_binary(
    name = "part1",
    srcs = ["part1.cc"],
    data = [":input"],
    deps = [":solver"]
)

# cc_test(
#     name = "test2",
#     srcs = ["test2.cc"],
#     deps = [":solver", "@googletest//:gtest_main"]
# )

# cc_binary(
#     name = "part2",
#     srcs = ["part2.cc"],
#     data = [":input"],
#     deps = [":solver"]
# )
