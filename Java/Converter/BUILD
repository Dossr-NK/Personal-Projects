load("@rules_java//java:defs.bzl", "java_binary")

package(default_visibility = ["//visibility:public"])

java_binary(
    name = "Converter",
    srcs = ["src/Converter.java"],
    main_class = "Converter",
    deps = [":AreaLib", ":CurrencyLib", ":DataLib", ":Len/DisLib", ":MassLib", ":MiscellaneousLib", ":SizesLib", ":SpeedLib", ":TemperatureLib", ":TimeLib", ":VolumeLib"],
)

java_library(
    name = "AreaLib",
    srcs = glob(["src/conversion/area/*.java"]),
)

java_library(
    name = "CurrencyLib",
    srcs = glob(["src/conversion/currency/*.java"]),
)

java_library(
    name = "DataLib",
    srcs = glob(["src/conversion/data_storage/*.java"]),
)

java_library(
    name = "Len/DisLib",
    srcs = glob(["src/conversion/length_and_distance/*.java"]),
)

java_library(
    name = "MassLib",
    srcs = glob(["src/conversion/mass/*.java"]),
)

java_library(
    name = "MiscellaneousLib",
    srcs = glob(["src/conversion/miscellaneous/*.java"]),
)

java_library(
    name = "SizesLib",
    srcs = glob(["src/conversion/sizes/*.java"]),
)

java_library(
    name = "SpeedLib",
    srcs = glob(["src/conversion/speed/*.java"]),
)

java_library(
    name = "TemperatureLib",
    srcs = glob(["src/conversion/temperature/*.java"]),
)

java_library(
    name = "TimeLib",
    srcs = glob(["src/conversion/time/*.java"]),
)

java_library(
    name = "VolumeLib",
    srcs = glob(["src/conversion/volume/*.java"]),
)