#ifndef CRHOM_H
#define CRHOM_H

#include "Figures\CFigure.h"

class CRhombus : public CFigure
{
private:
	int d;
	Point C,P1,P2,P3,P4;
public:
	CRhombus(Point , GfxInfo FigureGfxInfo );
	void ChngFigSize(double figSize);
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void GetFigPoints(Point & P1);
};

#endif