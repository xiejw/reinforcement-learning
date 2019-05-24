// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "DynamicProgramming",
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
            name: "PolicyEvaluationTests",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
    ]
)
