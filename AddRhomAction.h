#ifndef ADD_RHOM_ACTION_H
#define ADD_RHOM_ACTION_H

#include "Actions\Action.h"

//Add Rhombuse Action class
class AddRhomAction: public Action
{
private:
	Point P1; //Rhombus Midpoint
	GfxInfo RhomGfxInfo;
public:
	AddRhomAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();
	
	//Add rhombus to the ApplicationManager
	virtual void Execute() ;
	
};

#endif