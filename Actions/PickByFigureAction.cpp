#include "PickByFigureAction.h"
#include "../ApplicationManager.h"
#include"../Figures/CRectangle.h"
#include"../CEllipse.h"
#include"../CLine.h"
#include"../CRhombus.h"
#include"../CTriangle.h"
#include<iostream>



PickByFigureAction::PickByFigureAction(ApplicationManager *pApp):Action(pApp)
{
}

void PickByFigureAction::ReadActionParameters()
{
	
}

void PickByFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int CorrectPicks = 0;
	int WrongPicks = 0;
	int numOfSelected = 0;
	int num;
	bool ended = true;
	string msg;
	if (pManager->CheckDrawings()) {
		do {
			int range = 5;
			num = std::rand() % range + 1;
			
			switch (num) {
			case 1: {
				msg = "Lines";
				numOfSelected = pManager->NumOfLines();

			}
					break;
			case 2: {
				msg = "Rectangles";
				numOfSelected = pManager->NumOfrect();
			}
					break;
			case 3: {
				msg = "Triangles";
				numOfSelected = pManager->NumOfTris();
			}
					break;
			case 4: {
				msg = "Rhombuses";
				numOfSelected = pManager->NumOfRhom();
			}
					break;
			case 5: {
				msg = "Elipses";
				numOfSelected = pManager->NumOfEli();
			}
					break;
			}
		} while (numOfSelected == 0);
		pOut->PrintMessage("Select All " + msg);
		while (numOfSelected > 0) {
			pIn->GetPointClicked(pClicked.x, pClicked.y);
			CFigure* selected = pManager->GetFigure(pClicked.x, pClicked.y);
			if (pClicked.y >= 0 && pClicked.y < UI.ToolBarHeight) {
				pOut->PrintMessage("Game Restarted");
				ended = false;
				break;
			}
			if (selected == NULL) {
				continue;
			}
			if (selected->checkHidden()) {
				continue;
			}
			
			switch (num) {
			case 2: {
				CRectangle* rPtr = dynamic_cast<CRectangle*>(selected);
				if (rPtr != NULL) {
					CorrectPicks++;
					numOfSelected--;
				}
				else {
					WrongPicks++;
				}
				selected->Hide(true);
			}
				break;
			case 1: {
				CLine* rPtr = dynamic_cast<CLine*>(selected);
				if (rPtr != NULL) {
					CorrectPicks++;
					numOfSelected--;
				}
				else {
					WrongPicks++;
				}
				selected->Hide(true);
			}
				break;
			case 3: {
				CTriangle* rPtr = dynamic_cast<CTriangle*>(selected);
				if (rPtr != NULL) {
					CorrectPicks++;
					numOfSelected--;
				}
				else {
					WrongPicks++;
				}
				selected->Hide(true);
			}
				break;
			case 4: {
				CRhombus* rPtr = dynamic_cast<CRhombus*>(selected);
				if (rPtr != NULL) {
					CorrectPicks++;
					numOfSelected--;
				}
				else {
					WrongPicks++;
				}
				selected->Hide(true);
			}
				break;
			
			case 5: {
				CEllipse* rPtr = dynamic_cast<CEllipse*>(selected);
				if (rPtr != NULL) {
					CorrectPicks++;
					numOfSelected--;
				}
				else {
					WrongPicks++;
				}

				selected->Hide(true);
			}
				break;
			}
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
		}
		if (ended) {
			pOut->PrintMessage("Game Ended, Final score is : Correct picks= " + std::to_string(CorrectPicks) + " , Wrong picks= " + std::to_string(WrongPicks));
		}
		pManager->Hide_UnhideAll(false);
	}
	else {
		pOut->PrintMessage("You need to draw some shapes before you play");
	}
}


PickByFigureAction::~PickByFigureAction()
{
}