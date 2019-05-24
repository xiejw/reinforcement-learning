// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "DP",
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .target(
            name: "DynamicProgramming",
            dependencies: []
        ),
        .target(
            name: "GridWorld",
            dependencies: ["DynamicProgramming"]
        ),
        .target(
            name: "PolicyEvaluation",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
        .testTarget(
            name: "DPTests",
            dependencies: ["DynamicProgramming"]
        ),
    ]
)
