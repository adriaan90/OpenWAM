/* --------------------------------------------------------------------------------*\
==========================|
 \\   /\ /\   // O pen     | OpenWAM: The Open Source 1D Gas-Dynamic Code
 \\ |  X  | //  W ave     |
 \\ \/_\/ //   A ction   | CMT-Motores Termicos / Universidad Politecnica Valencia
 \\/   \//    M odel    |
 ----------------------------------------------------------------------------------
 License

 This file is part of OpenWAM.

 OpenWAM is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 OpenWAM is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with OpenWAM.  If not, see <http://www.gnu.org/licenses/>.


 \*--------------------------------------------------------------------------------*/

/**
 * @file LaxWendroff.hpp
 * @author Francisco Jose Arnau <farnau@mot.upv.es>
 * @author Luis Miguel Garcia-Cuevas Gonzalez <farnau@mot.upv.es>
 *
 * @section LICENSE
 *
 * This file is part of OpenWAM.
 *
 * OpenWAM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenWAM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenWAM.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 * This file declares a Lax Wendroff finite-differences integrator for
 * one-dimensional pipes.
 */

#ifndef LaxWendroff_hpp
#define LaxWendroff_hpp

#include "BasicPipe.hpp"
#include "PipeSolver.hpp"
#include "Math_wam.h"

/**
 * @brief A Lax Wendroff integrator.
 * 
 * A two-steps Lax Wendroff integrator.  It is second order-accurate in both
 * time and space.
 */
class TLaxWendroff: public TPipeSolver
{
protected:
	RowVector Fhi12;
	RowVector Frho12;
	RowVector FRe12;
	RowVector FTPTubo12;
	RowVector FGamma12;
	RowVector FRmezcla12;
	RowVector FGamma1_12;
	RowArray Fx1;
	RowArray Fx2;
	RowArray Fx3;
	RowArray Fx4;
	RowArray Fx1_12;
	RowArray Fx2_12;
	RowArray Fx3_12;
	RowArray Fx4_12;
	RowArray FU_12;
public:
	/**
	 * @brief Default constructor.
	 * 
	 * Initialises the propagator with default values.
	 */
	TLaxWendroff();

	/**
	 * @brief Constructor.
	 * 
	 * Initialises the propagator and attaches it to a pipe.
	 * 
	 * @param pipe Pipe to attach to.
	 */
	TLaxWendroff(TBasicPipe * pipe);

	/**
	 * @brief Connects the Lax Wendroff integrator to a pipe.
	 * 
	 * @param pipe Pipe to connect to.
	 */
	virtual void Connect(TBasicPipe * pipe);

	/**
	 * @brief Integrate the flow.
	 * 
	 * Integrates the flow evolution inside the duct.
	 */
	void Solve();
};

#endif