/**
 * @file src/vle/vpz/test/test7.cpp
 * @author The VLE Development Team
 */

/*
 * VLE Environment - the multimodeling and simulation environment
 * This file is a part of the VLE environment (http://vle.univ-littoral.fr)
 * Copyright (C) 2003 - 2008 The VLE Development Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */




#define BOOST_TEST_MAIN
#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vpz_classes_extensions

#include <boost/test/unit_test.hpp>
#include <boost/test/auto_unit_test.hpp>
#include <stdexcept>
#include <vle/vpz.hpp>

using namespace vle;
using namespace vpz;

BOOST_AUTO_TEST_CASE(obs_port)
{
  Observable obs("Obs");
  BOOST_REQUIRE_EQUAL(obs.exist("port"), false);
  BOOST_REQUIRE_THROW(obs.get("port"), utils::SaxParserError);
  BOOST_REQUIRE_THROW(obs.del("port"), utils::SaxParserError);
  BOOST_REQUIRE_NO_THROW(obs.add("port"));
  BOOST_REQUIRE_THROW(obs.add("port"), utils::SaxParserError);
  BOOST_REQUIRE_EQUAL(obs.exist("port"), true);
  BOOST_REQUIRE_NO_THROW(obs.get("port"));
  BOOST_REQUIRE_NO_THROW(obs.del("port"));
  BOOST_REQUIRE_EQUAL(obs.exist("port"), false);
}