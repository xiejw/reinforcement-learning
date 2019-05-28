import XCTest

import PolicyEvaluationTests

var tests = [XCTestCaseEntry]()
tests += PolicyEvaluationTests.allTests()
tests += PolicyIterationTests.allTests()
tests += ValueIterationTests.allTests()
tests += GamblerProblemTests.allTests()
XCTMain(tests)
