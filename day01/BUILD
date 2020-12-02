
cc_library(
    name = "solver",
    srcs = ["solver.cc"],
    hdrs = ["solver.hh"]
)

cc_test(
    name = "test",
    srcs = ["test.cc"],
    deps = [":solver", "@googletest//:gtest_main"]
)

cc_binary(
    name = "part1",
    srcs = ["part1.cc"],
    data = ["//day01:input"],
    deps = [":solver"]
)
