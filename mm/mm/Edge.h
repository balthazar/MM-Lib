/******************************************************************************
 * Copyright (c) 2013-2014, Amsterdam University of Applied Sciences (HvA) and
 *                          Centrum Wiskunde & Informatica (CWI)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   * Riemer van Rozen - rozen@cwi.nl - HvA / CWI
 ******************************************************************************/
/*!
 * \namespace MM
 * \class     Edge
 * \brief     The Edge abtraction is an abstract element
 *            connecting a source node and a target node.
 * \file      Edge.h
 * \author    Riemer van Rozen
 * \date      July 10th 2013
 */
/******************************************************************************/

#ifndef __mm__Edge__
#define __mm__Edge__

namespace MM
{
  class Node;
  class Instance;
  class Edge : public MM::Element
  {
  private:
    static const MM::CHAR COLON_CHAR; /**> colon character */
    MM::Name * srcName;               /**> source node name (parsed) */
    MM::Name * tgtName;               /**> target node name (parsed) */
    MM::Node * srcNode;               /**> source node (resolved) */
    MM::Node * tgtNode;               /**> target node (resolved) */
    MM::Exp  * exp;                   /**> expression (parsed) */
  protected:
    Edge(MM::Name * name, MM::Name * src, MM::Exp * exp, MM::Name * tgt);
    virtual ~Edge();
  public:
    MM::VOID recycle(MM::Recycler * r);
    virtual MM::TID getTypeId();
    virtual MM::BOOLEAN instanceof(MM::TID tid);
    MM::Node * getSource();
    MM::Node * getTarget();
    MM::Exp * getExp();    
    MM::VOID setExp(MM::Exp * exp);
    MM::VOID setSource(MM::Node * src);
    MM::VOID setTarget(MM::Node * tgt);
    MM::Name * getSourceName();
    MM::Name * getTargetName();
    virtual MM::VOID toString(MM::String * buf) = 0;
    virtual MM::VOID toString(MM::String * buf, MM::UINT32 indent);
  };
}
#endif /* defined(__mm__Edge__) */

