/**
 * @file apps/vle/OptionGroup.hpp
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


#ifndef VLE_OPTIONGROUP_HPP
#define VLE_OPTIONGROUP_HPP

#include <glibmm/optioncontext.h>
#include <vector>

namespace vle { namespace apps {

    /**
     * @brief An abstract class to force checking of attributes members.
     */
    class OptionGroup : public Glib::OptionGroup
    {
    public:
        OptionGroup();

        virtual ~OptionGroup() {}

        bool manager() const { return mManager; }
        bool simulator() const { return mSimulator; }
        bool justRun() const { return mJustrun; }
        int port() const { return mPort; }
        int processor() const { return mProcess; }
        bool allInLocal() const { return mAllinlocal; }
        bool savevpz() const { return mSaveVpz; }
        bool infos() const { return mInfos; }
        bool version() const { return mVersion; }
        int verbose() const { return mVerbose; }
        const Glib::ustring& package() const { return mPackage; }

        /**
         * @brief Check the validity of the selected option from the command
         * line interface.
         * @throw vle::utils::InternalError.
         */
        void check();

    private:
        bool          mManager;
        bool          mSimulator;
        bool          mJustrun;
        int           mPort;
        int           mProcess;
        bool          mAllinlocal;
        bool          mSaveVpz;
        bool          mInfos;
        bool          mVersion;
        int           mVerbose;
        Glib::ustring mPackage;
    };

}} // namespace vle apps

#endif
