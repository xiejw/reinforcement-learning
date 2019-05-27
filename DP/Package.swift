// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "DynamicProgramming",
    targets: [
        .target(
            name: "PolicyEvaluation",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
        .target(
            name: "PolicyIteration",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
        .target(
            name: "ValueIteration",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
        .target(
            name: "GamblerProblem",
            dependencies: ["DynamicProgramming", "GamblerProblemLibrary"]
        ),
        .target(
            name: "DynamicProgramming",
            dependencies: []
        ),
        .target(
            name: "GridWorld",
            dependencies: ["DynamicProgramming"]
        ),
        .target(
            name: "GamblerProblemLibrary",
            dependencies: ["DynamicProgramming"]
        ),
        .testTarget(
            name: "PolicyEvaluationTests",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
        .testTarget(
            name: "PolicyIterationTests",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
        .testTarget(
            name: "ValueIterationTests",
            dependencies: ["DynamicProgramming", "GridWorld"]
        ),
    ]
)
