/*********************************************************************
Author: Roberto Bruttomesso <roberto.bruttomesso@gmail.com>

OpenSMT -- Copyright (C) 2009, Roberto Bruttomesso

OpenSMT is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenSMT is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenSMT. If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/

#ifndef SMTSOLVER_H
#define SMTSOLVER_H

#include "THandler.h"
#include "SolverTypes.h"
#include "Global.h"
#include "Egraph.h"
#include "Config.h"

class THandler; // Forward declaration

// 
// Interface that a SATSolver should implement 
//
class SMTSolver
{
public:

  SMTSolver ( Egraph & e, Config & c ) 
    : egraph( e )
    , config( c ) 
  { }
  
  virtual ~SMTSolver ( ) { }
  //
  // addClause
  //
  // Receive a clause in form of a list of
  // snodes each representing a literal
  // (atom or negated atom) and feeds a
  // corresponding clause in the SAT Solver
  //
  virtual bool   addSMTClause  ( vector< Enode * > &
#ifdef PRODUCE_PROOF
                               , const ipartitions_t = 0 
#endif
			       ) = 0;
  virtual lbool  smtSolve      ( )                                              = 0;
  virtual Var    newVar        ( bool = true, bool = true )                     = 0;
  virtual void   setFrozen     ( Var, bool )                                    = 0;

protected:

  THandler *  theory_handler; // Handles theory
  Egraph &    egraph;         // Stores Sgraph
  Config &    config;         // Stores Config
};

#endif
