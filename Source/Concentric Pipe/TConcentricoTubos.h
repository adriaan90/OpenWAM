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

//---------------------------------------------------------------------------
#ifndef TConcentricoTubosH
#define TConcentricoTubosH

#include "TConcentrico.h"

//#include <cmath>
#ifdef __BORLANDC__
#include <vcl.h>
#endif
#include <cstdio>
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class TConcentricoTubos: public TConcentrico {
  private:

  public:

	TConcentricoTubos(int NumeroConcentrico);

	~TConcentricoTubos();

	void LeeDatosTuboConcentrico(const char *FileWAM, fpos_t &filepos, TTubo **Tubo, TDPF **DPF);

	void CalculaTemperaturaPared(TBloqueMotor **Motor, double theta, TCondicionContorno **CC);

	void CalculaTemperaturaParedSinMotor(TCondicionContorno **CC);

	void CalculaResistenciasdePared(TCondicionContorno **CC);

};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
