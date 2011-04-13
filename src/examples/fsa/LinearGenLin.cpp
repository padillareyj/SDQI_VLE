/*
 * @file examples/fsa/Linear.cpp
 *
 * This file is part of VLE, a framework for multi-modeling, simulation
 * and analysis of complex dynamical systems
 * http://www.vle-project.org
 *
 * Copyright (c) 2003-2007 Gauthier Quesnel <quesnel@users.sourceforge.net>
 * Copyright (c) 2003-2010 ULCO http://www.univ-littoral.fr
 * Copyright (c) 2007-2010 INRA http://www.inra.fr
 *
 * See the AUTHORS or Authors.txt file for copyright owners and contributors
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


#include <vle/extension/difference-equation/Simple.hpp>
#include <vle/extension/difference-equation/Multiple.hpp>

namespace vd = vle::devs;
namespace ve = vle::extension;
namespace vv = vle::value;

namespace vle { namespace examples { namespace fsa {

class GenLin : public ve::DifferenceEquation::Simple
{
public:
    GenLin(const vd::DynamicsInit& init, const vd::InitEventList& evts)
        : ve::DifferenceEquation::Simple(init, evts)
    {
        a = vv::toDouble(evts.get("a"));
        X = createVar("X");
    }

    virtual ~GenLin()
    {}

    virtual double compute(const vd::Time& /*time*/)
    { return X(-1) + a; }

    virtual double initValue(const vd::Time& /*time*/)
    { return 0; }

private:
    double a;
    Var X;
};

DECLARE_DYNAMICS(GenLin)

}}} // namespace vle examples fsa