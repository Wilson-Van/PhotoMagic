// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using PhotoMagic::FibLFSR;

BOOST_AUTO_TEST_CASE(testStepInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testCorrectSteps) {
  FibLFSR l1("1011011000110110");
  FibLFSR l2("0000000000000000");
  FibLFSR l3("1000000000000000");
  FibLFSR l4("1010000000000000");
  BOOST_REQUIRE_EQUAL(l1.step(), 0);
  BOOST_REQUIRE_EQUAL(l2.step(), 0);
  BOOST_REQUIRE_EQUAL(l3.step(), 1);
  BOOST_REQUIRE_EQUAL(l4.step(), 0);
}

BOOST_AUTO_TEST_CASE(testSequenceOfGenerateFromPDF) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(5), 3);
  BOOST_REQUIRE_EQUAL(l.generate(5), 6);
  BOOST_REQUIRE_EQUAL(l.generate(5), 14);
  BOOST_REQUIRE_EQUAL(l.generate(5), 24);
  BOOST_REQUIRE_EQUAL(l.generate(5), 1);
  BOOST_REQUIRE_EQUAL(l.generate(5), 13);
  BOOST_REQUIRE_EQUAL(l.generate(5), 28);
}

BOOST_AUTO_TEST_CASE(testGenerate10) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(10), 102);
}

BOOST_AUTO_TEST_CASE(testTapBits) {
  FibLFSR l1("1011010000000000");
  FibLFSR l2("1011011111111111");
  BOOST_REQUIRE_EQUAL(l1.step(), l2.step());
}

BOOST_AUTO_TEST_CASE(testOStream) {
  FibLFSR l("1011010000000000");
  boost::test_tools::output_test_stream out;
  boost::test_tools::output_test_stream exp;
  out << l;
  BOOST_TEST(out.is_equal("1011010000000000"));
}

BOOST_AUTO_TEST_CASE(testTransform) {
  FibLFSR l("1011011000110110");
  sf::Image i;
  i.create(1, 1, sf::Color(255, 0, 0));
  sf::Color expected(230, 157, 128);
  PhotoMagic::transform(i, &l);
  sf::Color pixel = i.getPixel(0, 0);
  BOOST_REQUIRE_EQUAL(pixel.r, expected.r);
  BOOST_REQUIRE_EQUAL(pixel.g, expected.g);
  BOOST_REQUIRE_EQUAL(pixel.b, expected.b);
}
