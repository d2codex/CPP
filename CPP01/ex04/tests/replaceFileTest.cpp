/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceFileTest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:44:18 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:45:19 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "tests.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <fstream>


struct FileTestCase
{
    std::string desc;
    std::string inputFile;
    std::string expectedFile;
    std::string inputContent;
	std::string expectedContent;
    std::string s1;
    std::string s2;
    bool shouldFail; // For cases like permission denied or missing file
};

/**
 * @brief Compares two files byte-by-byte.
 *
 * Opens both files in binary mode and compares their contents.
 *
 * @param file1 First file path.
 * @param file2 Second file path.
 * @return True if files match exactly.
 */
static bool filesMatch(const std::string& file1, const std::string& file2)
{
	//std::ios::binary tells stream to read file as raw bytes
	//do not perform any text translation
	//ifstream (const char* filename, ios_base::openmode mode = ios_base::in);
    std::ifstream f1(file1.c_str(), std::ios::in | std::ios::binary);
    std::ifstream f2(file2.c_str(), std::ios::in | std::ios::binary);

    if (!f1 || !f2)
        return (false);

    std::istreambuf_iterator<char> it1(f1);
    std::istreambuf_iterator<char> it2(f2);
    std::istreambuf_iterator<char> end;

    return (std::equal(it1, end, it2));
}

/**
 * @brief Creates a file and writes the given content.
 *
 * @param filename Path of file to create.
 * @param content  Content to write into the file.
 */
static void createFile(const std::string& filename, const std::string& content)
{
    std::ofstream out(filename.c_str());
    out << content;
    out.close();
}

/**
 * @brief Runs unit tests for replaceFile().
 *
 * For each test case, it creates input/expected files, runs
 * replaceFile(), compares output, and cleans up temporary files.
 *
 * @return int Number of failed tests.
 */
int replaceFileTest()
{
    int passed = 0;
    int failed = 0;

    FileTestCase test[] = {
        {
            "Normal case",
            "testFiles/tmp_normal.txt",
            "testFiles/tmp_normal_expected.txt",
            "hello world\nhello world\n",
			"hello planet\nhello planet\n",
            "world", "planet",
            false
        },
        {
            "No match case",
            "testFiles/tmp_nomatch.txt",
            "testFiles/tmp_nomatch_expected.txt",
			"hello world\n",
            "hello world\n",
            "x", "y",
            false
        },
        {
            "Empty file case",
            "testFiles/tmp_empty.txt",
            "testFiles/tmp_empty_expected.txt",
            "",
			"\n",
            "a", "b",
            false
        },
        {
            "Missing file case",
            "testFiles/tmp_missing.txt",
            "testFiles/tmp_missing_expected.txt",
            "",
			"",
            "a", "b",
            true
        }
    };
	std::cout << YEL "=== Running test for replaceFile() ===\n" RESET;
    size_t numTests = sizeof(test) / sizeof(test[0]);

    for (size_t i = 0; i < numTests; ++i)
    {
		FileTestCase& t = test[i];
        std::cout << "Test[" << i << "] " << t.desc << '\n';

        // Create input & expected files only if not a missing-file test
        if (!t.shouldFail)
        {
            createFile(t.inputFile, t.inputContent);
            createFile(t.expectedFile, t.expectedContent);
        }

        // Run replaceFile()
        int result = replaceFile(t.inputFile, t.s1, t.s2);

        if (t.shouldFail)
        {
            if (result != 0)
                passed++;
            else
                failed++;
        }
        else
        {
            // Compare output with expected
            std::string outFile = t.inputFile + ".replace";

            if (result == 0 && filesMatch(outFile, t.expectedFile))
			{
				std::cout << GRN "TEST PASSED\n" RESET;
                passed++;
			}
            else
			{
				std::cout << RED "TEST FAILED\n" RESET;
                failed++;
			}
        }

        // Cleanup
		std::remove(t.inputFile.c_str());
        std::remove((t.inputFile + ".replace").c_str());
        std::remove(t.expectedFile.c_str());
    }
	std::cout << BLU "========= replaceFile summary ========" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
