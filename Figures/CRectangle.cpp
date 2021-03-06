#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

bool CRectangle::PointInFigure(Point P1)
{
	bool inX = ((Corner1.x < P1.x) && (P1.x < Corner2.x)) || ((Corner2.x < P1.x) && (P1.x < Corner1.x));
	bool inY = ((Corner1.y < P1.y) && (P1.y < Corner2.y)) || ((Corner2.y < P1.y) && (P1.y < Corner1.y));

	if ( inX && inY ) {
		return true;
	}
	else {
		return false;
	}
	
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}