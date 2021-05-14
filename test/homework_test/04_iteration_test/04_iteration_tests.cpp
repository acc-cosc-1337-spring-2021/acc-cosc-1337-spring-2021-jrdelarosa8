#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify get_gc_content function")
{
	std::string dna;

	dna = "AGCTATAG";
	REQUIRE(get_gc_content(dna) == 0.375);

	dna = "CGCTATAG";
	REQUIRE(get_gc_content(dna) == 0.50);
}

TEST_CASE("Verify get_reverse_string function")
{
	std::string dna;

	dna = "AGCTATAG";
	REQUIRE(get_reverse_string(dna) == "GATATCGA");

	dna = "CGCTATAG";
	REQUIRE(get_reverse_string(dna) == "GATATCGC");
}

TEST_CASE("Verify get_dna_complement function")
{
	std::string dna;

	dna = "AAAACCCGGT";
	REQUIRE(get_dna_complement(dna) == "ACCGGGTTTT");

	dna = "CCCGGAAAAT";
	REQUIRE(get_dna_complement(dna) == "ATTTTCCGGG");
}
