#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>     // Include the Catch2 testing framework

// Include the header containing the ConcatRemove function
#include "concatRemove.hpp" 

TEST_CASE("Test ConcatRemove function") {
    // Test case 1: Valid input, can convert s to t using exactly k operations
    REQUIRE(ConcatRemove("abc", "def", 6) == "yes");

    // Test case 2: Valid input, more movements available than necessary
    REQUIRE(ConcatRemove("abc", "def", 7) == "yes");

    // Test case 3: Valid input, fewer movements available
    REQUIRE(ConcatRemove("abc", "def", 5) == "no");

    // Test case 4: Valid input, s and t are the same strings
    REQUIRE(ConcatRemove("abc", "abc", 6) == "yes");

    // Test case 5: Invalid input, s contains invalid characters
    REQUIRE(ConcatRemove("a1b2c", "def", 6) == "no");

    // Test case 6: Invalid input, t contains invalid characters
    REQUIRE(ConcatRemove("abc", "d3ef", 6) == "no");

    // Test case 7: Invalid input, k is out of range
    REQUIRE(ConcatRemove("abc", "def", 101) == "Invalid input!");
}
