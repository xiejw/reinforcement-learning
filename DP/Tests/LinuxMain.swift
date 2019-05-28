import XCTest

import GamblerProblemTests
import PolicyEvaluationTests
import PolicyIterationTests
import ValueIterationTests

var tests = [XCTestCaseEntry]()
tests += PolicyEvaluationTests.allTests()
tests += PolicyIterationTests.allTests()
tests += ValueIterationTests.allTests()
tests += GamblerProblemTests.allTests()
XCTMain(tests)
