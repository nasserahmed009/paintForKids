#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddLineAction.h"
#include "AddEllipseAction.h"
#include "AddTriAction.h"
#include "AddRhomAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhomAction(this);
			break;

		case SELECT:
			if (FigCount != 0) {
				int Px, Py;
				pIn->GetPointClicked(Px,Py);
				Point pClicked;
				pClicked.x = Px;
				pClicked.y = Py;
				for (int i = 0; i < FigCount; i++) {
					if (FigList[i]->IsSelected()) {
						FigList[i]->SetSelected(false);
						FigList[i]->ChngDrawClr(BLACK);
					}
				}
				for (int i = FigCount-1; i >= 0; i--) {
					if (FigList[i]->PointInFigure(pClicked)) {
							FigList[i]->SetSelected(true);
							FigList[i]->ChngDrawClr(MAGENTA);
							pOut->PrintMessage("Selected");
							break;
					}
				}
			}
			else {
				pOut->PrintMessage("Please draw figures first");
			};
			break;

		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color , Click anywhere");
				pOut->DrawColorPallete(2);
				ChooseClr = pIn->GetClr();
				switch(ChooseClr){
				case PICK_BLACK: UI.DrawColor = BLACK;
								 break;
				case PICK_WHITE: UI.DrawColor = WHITE;
								 break;
				case PICK_RED:   UI.DrawColor = RED;
								 break;
				case PICK_GREEN: UI.DrawColor = GREEN;
								 break;
				case PICK_BLUE:  UI.DrawColor = BLUE;
								 break;
				}
				pOut->ClearColorPallete();
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color , Click anywhere");
				pOut->DrawColorPallete(1);
				ChooseClr = pIn->GetClr();
				switch(ChooseClr){
				case PICK_BLACK: UI.FillColor = BLACK;
								 break;
				case PICK_WHITE: UI.FillColor = WHITE;
								 break;
				case PICK_RED:   UI.FillColor = RED;
								 break;
				case PICK_GREEN: UI.FillColor = GREEN;
								 break;
				case PICK_BLUE:  UI.FillColor = BLUE;
								 break;
				}
				pOut->ClearColorPallete();
				break;
		case DEL:
				pOut->PrintMessage("Action: a click on the Delete button");
				break;
		case SAVE:
				pOut->PrintMessage("Action: a click on the Save button, Click anywhere");
				break;
		case SAVE_BY_TYPE:
				pOut->PrintMessage("Action: a click on the Save By Type button, Click anywhere");
				break;
		case LOAD:
				pOut->PrintMessage("Action: a click on the Load button, Click anywhere");
				
				break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return ;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
