
/*
 * Link: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true
 */

#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

TEST(hackerrank, generictest)
{
    vector<string> filesToTest{
        "abstract-classes-polymorphism",
        "balanced-brackets",
        "c-tutorial-basic-data-types",
        "c-tutorial-conditional-if-else",
        "c-tutorial-for-loop",
        "c-tutorial-functions",
        "caesar-cipher-1",
        "countingsort1",
        "diagonal-difference",
        "find-the-meidian",
        "fliping-matrix",
        "grid-challenge",
        "lonely-integer",
        "merge-two-sorted-linked-lists",
        "mini-max-sum",
        // "new-year-chaos",
        "plus-minus",
        "queue-using-two-stacks",
        "recursive-digit-sum",
        "simple-text-editor",
        "time-conversion",
        "tower-breakers-1",
        "zig-zag-sequence"};

    for (const string fileName : filesToTest)
    {
        stringstream pathToInputsSS;
        pathToInputsSS << "../" << fileName << "/inputs";
        string pathToInputs = pathToInputsSS.str();

        for (const auto &entry : filesystem::directory_iterator(pathToInputs))
        {
            string testNumber = entry.path().stem();
            string pathToInputFile = entry.path();

            stringstream pathToOutputFileSS;
            pathToOutputFileSS << "../" << fileName << "/results"
                               << "/" << testNumber << ".res";
            string pathToOutputFile = pathToOutputFileSS.str();

            stringstream commandSS;
            commandSS << "./" << fileName << " <" << pathToInputFile << " >" << pathToOutputFile;
            string command = commandSS.str();

            system(command.c_str());

            stringstream pathToExpectedFileSS;
            pathToExpectedFileSS << "../" << fileName << "/expected"
                                 << "/" << testNumber << ".out";
            string pathToExpectedFile = pathToExpectedFileSS.str();

            ifstream expectedIFS(pathToExpectedFile);
            string expectedContent((istreambuf_iterator<char>(expectedIFS)),
                                   (istreambuf_iterator<char>()));

            ifstream resultIFS(pathToOutputFile);
            string resultContent((istreambuf_iterator<char>(resultIFS)),
                                 (istreambuf_iterator<char>()));

            ASSERT_EQ(expectedContent, resultContent) << "fileName=" << fileName << ", testNumber=" << testNumber;
        }
    }
}