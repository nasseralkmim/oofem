/*
 *
 *                 #####    #####   ######  ######  ###   ###
 *               ##   ##  ##   ##  ##      ##      ## ### ##
 *              ##   ##  ##   ##  ####    ####    ##  #  ##
 *             ##   ##  ##   ##  ##      ##      ##     ##
 *            ##   ##  ##   ##  ##      ##      ##     ##
 *            #####    #####   ##      ######  ##     ##
 *
 *
 *             OOFEM : Object Oriented Finite Element Code
 *
 *               Copyright (C) 1993 - 2011   Borek Patzak
 *
 *
 *
 *       Czech Technical University, Faculty of Civil Engineering,
 *   Department of Structural Mechanics, 166 29 Prague, Czech Republic
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef fei2dlinelin_h
#define fei2dlinelin_h

#include "feinterpol2d.h"

namespace oofem {
/**
 * Class representing a 2d line with linear interpolation.
 * @todo{Some more routines to be implemented here}
 * @author Mikael Öhman
 */
class FEI2dLineLin : public FEInterpolation2d
{
protected:
    int xind, yind;

public:
    FEI2dLineLin(int ind1, int ind2) : FEInterpolation2d(1) {
        xind = ind1;
        yind = ind2;
    }
    ~FEI2dLineLin() { }

    virtual void local2global(FloatArray &answer, const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time);
    virtual int  global2local(FloatArray &answer, const FloatArray &gcoords, const FEICellGeometry &cellgeo, double time);

    // "Bulk"
    virtual void evalN(FloatArray &answer, const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time);
    virtual void evaldNdx(FloatMatrix &answer, const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time);
    virtual double giveTransformationJacobian(const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time);
    virtual double giveArea(const FEICellGeometry &cellgeo) { return 0.0;};

    // Edge (same as bulk for this type, so they are all ignored) (perhaps do it the other way around?).
    virtual void computeLocalEdgeMapping(IntArray &edgeNodes, int iedge) {};
    virtual void edgeEvalN(FloatArray &answer, const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time) { };
    virtual void edgeEvaldNds(FloatArray &answer, int iedge,
                              const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time) {};
    virtual void edgeLocal2global(FloatArray &answer, int iedge,
                                  const FloatArray &lcoords, const FEICellGeometry &cellgeo, double time) {};
    virtual double edgeGiveTransformationJacobian(int iedge, const FloatArray &lcoords,
                                                  const FEICellGeometry &cellgeo, double time) {};

protected:
    double edgeComputeLength(IntArray &edgeNodes, const FEICellGeometry &cellgeo);
};
} // end namespace oofem
#endif // fei2dlinelin_h