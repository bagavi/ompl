/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2015, Rice University
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Rice University nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Ryan Luna */

#ifndef PLANAR_MANIPULATOR_LINEAR_MOTION_VALIDATOR_
#define PLANAR_MANIPULATOR_LINEAR_MOTION_VALIDATOR_

#include <ompl/base/MotionValidator.h>
#include <ompl/base/SpaceInformation.h>
#include "PlanarManipulator.h"

// Special motion validator for planar manipulator that checks for self collisions
// between adjacent links (wrap around)
class PMLinearMotionValidator : public ompl::base::MotionValidator
{
public:
    PMLinearMotionValidator(ompl::base::SpaceInformation *si, const PlanarManipulator *manip);
    PMLinearMotionValidator(const ompl::base::SpaceInformationPtr &si, const PlanarManipulator *manip);
    virtual ~PMLinearMotionValidator();

    virtual bool checkMotion(const ompl::base::State *s1, const ompl::base::State *s2) const;
    virtual bool checkMotion(const ompl::base::State *s1, const ompl::base::State *s2,
                             std::pair<ompl::base::State *, double> &lastValid) const;

protected:
    void defaultSettings();
    ompl::base::StateSpace *ss_;
    const PlanarManipulator *manip_;
    bool hasBounds_;
};

#endif