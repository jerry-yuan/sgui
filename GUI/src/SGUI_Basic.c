/*************************************************************************/
/** Copyright.															**/
/** FileName: GUI_Font.c												**/
/** Author: XuYulin														**/
/** Version: 1.0.0.0													**/
/** Description: GUI basic drawing operating.							**/
/*************************************************************************/

//=======================================================================//
//= Include files.													    =//
//=======================================================================//
#include "SGUI_Basic.h"

//=======================================================================//
//= Static variable declaration.									    =//
//=======================================================================//
SGUI_CBYTE SGUI_BASIC_FONT_H6[] = {
0x1F, 0x11, 0x1F, 0x00,	//0
0x00, 0x1F, 0x00, 0x00,	//1
0x1D, 0x15, 0x17, 0x00,	//2
0x15, 0x15, 0x1F, 0x00,	//3
0x07, 0x04, 0x1F, 0x00,	//4
0x17, 0x15, 0x1D, 0x00,	//5
0x1F, 0x15, 0x1D, 0x00,	//6
0x19, 0x05, 0x03, 0x00,	//7
0x1F, 0x15, 0x1F, 0x00,	//8
0x17, 0x15, 0x1F, 0x00,	//9
0x00, 0x10, 0x00, 0x00,	//.
0x04, 0x0E, 0x04, 0x00,	//+
0x04, 0x04, 0x04, 0x00,	//-
0x0A, 0x04, 0x0A, 0x00,	//**
0x18, 0x04, 0x03, 0x00, ///
0x00, 0x0E, 0x11, 0x00, //(
0x11, 0x0E, 0x00, 0x00, //)
0x00, 0x00, 0x00, 0x00, //space
};

/* Basic character font data */
SGUI_CBYTE SGUI_BASIC_FONT_H8[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// space index 0
0x00, 0x00, 0x5F, 0x00, 0x00, 0x00,	// !
0x00, 0x07, 0x00, 0x07, 0x00, 0x00,	// "
0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00,	// #
0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00,	// $
0x23, 0x13, 0x08, 0x64, 0x62, 0x00,	// %
0x36, 0x49, 0x55, 0x22, 0x50, 0x00,	// &
0x00, 0x05, 0x03, 0x00, 0x00, 0x00,	// '
0x00, 0x1C, 0x22, 0x41, 0x00, 0x00,	// (
0x00, 0x41, 0x22, 0x1C, 0x00, 0x00,	// )
0x08, 0x2A, 0x1C, 0x2A, 0x08, 0x00,	// *
0x08, 0x08, 0x3E, 0x08, 0x08, 0x00,	// +
0x00, 0x50, 0x30, 0x00, 0x00, 0x00,	// ,
0x08, 0x08, 0x08, 0x08, 0x08, 0x00,	// -
0x00, 0x30, 0x30, 0x00, 0x00, 0x00,	// .
0x20, 0x10, 0x08, 0x04, 0x02, 0x00,	// /
0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00,	// 0
0x00, 0x42, 0x7F, 0x40, 0x00, 0x00,	// 1
0x42, 0x61, 0x51, 0x49, 0x46, 0x00,	// 2
0x21, 0x41, 0x45, 0x4B, 0x31, 0x00,	// 3
0x18, 0x14, 0x12, 0x7F, 0x10, 0x00,	// 4
0x27, 0x45, 0x45, 0x45, 0x39, 0x00,	// 5
0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00,	// 6
0x01, 0x71, 0x09, 0x05, 0x03, 0x00,	// 7
0x36, 0x49, 0x49, 0x49, 0x36, 0x00,	// 8
0x06, 0x49, 0x49, 0x29, 0x1E, 0x00,	// 9
0x00, 0x36, 0x36, 0x00, 0x00, 0x00,	// :
0x00, 0x56, 0x36, 0x00, 0x00, 0x00,	// ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,	// <
0x14, 0x14, 0x14, 0x14, 0x14, 0x00,	// =
0x41, 0x22, 0x14, 0x08, 0x00, 0x00,	// >
0x02, 0x01, 0x51, 0x09, 0x06, 0x00,	// ?
0x32, 0x49, 0x79, 0x41, 0x3E, 0x00,	// @
0x7E, 0x11, 0x11, 0x11, 0x7E, 0x00,	// A
0x7F, 0x49, 0x49, 0x49, 0x36, 0x00,	// B
0x3E, 0x41, 0x41, 0x41, 0x22, 0x00,	// C
0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00,	// D
0x7F, 0x49, 0x49, 0x49, 0x41, 0x00,	// E
0x7F, 0x09, 0x09, 0x01, 0x01, 0x00,	// F
0x3E, 0x41, 0x41, 0x51, 0x32, 0x00,	// G
0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00,	// H
0x00, 0x41, 0x7F, 0x41, 0x00, 0x00,	// I
0x20, 0x40, 0x41, 0x3F, 0x01, 0x00,	// J
0x7F, 0x08, 0x14, 0x22, 0x41, 0x00,	// K
0x7F, 0x40, 0x40, 0x40, 0x40, 0x00,	// L
0x7F, 0x02, 0x04, 0x02, 0x7F, 0x00,	// M
0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00,	// N
0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00,	// O
0x7F, 0x09, 0x09, 0x09, 0x06, 0x00,	// P
0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00,	// Q
0x7F, 0x09, 0x19, 0x29, 0x46, 0x00,	// R
0x46, 0x49, 0x49, 0x49, 0x31, 0x00,	// S
0x01, 0x01, 0x7F, 0x01, 0x01, 0x00,	// T
0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00,	// U
0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00,	// V
0x7F, 0x20, 0x18, 0x20, 0x7F, 0x00,	// W
0x63, 0x14, 0x08, 0x14, 0x63, 0x00,	// X
0x03, 0x04, 0x78, 0x04, 0x03, 0x00,	// Y
0x61, 0x51, 0x49, 0x45, 0x43, 0x00,	// Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,	// [
0x02, 0x04, 0x08, 0x10, 0x20, 0x00,	// "\"
0x41, 0x41, 0x7F, 0x00, 0x00, 0x00,	// ]
0x04, 0x02, 0x01, 0x02, 0x04, 0x00,	// ^
0x40, 0x40, 0x40, 0x40, 0x40, 0x00,	// _
0x00, 0x01, 0x02, 0x04, 0x00, 0x00,	// `
0x20, 0x54, 0x54, 0x54, 0x78, 0x00,	// a
0x7F, 0x48, 0x44, 0x44, 0x38, 0x00,	// b
0x38, 0x44, 0x44, 0x44, 0x20, 0x00,	// c
0x38, 0x44, 0x44, 0x48, 0x7F, 0x00,	// d
0x38, 0x54, 0x54, 0x54, 0x18, 0x00,	// e
0x08, 0x7E, 0x09, 0x01, 0x02, 0x00,	// f
0x08, 0x14, 0x54, 0x54, 0x3C, 0x00,	// g
0x7F, 0x08, 0x04, 0x04, 0x78, 0x00,	// h
0x00, 0x44, 0x7D, 0x40, 0x00, 0x00,	// i
0x20, 0x40, 0x44, 0x3D, 0x00, 0x00,	// j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,	// k
0x00, 0x41, 0x7F, 0x40, 0x00, 0x00,	// l
0x7C, 0x04, 0x18, 0x04, 0x78, 0x00,	// m
0x7C, 0x08, 0x04, 0x04, 0x78, 0x00,	// n
0x38, 0x44, 0x44, 0x44, 0x38, 0x00,	// o
0x7C, 0x14, 0x14, 0x14, 0x08, 0x00,	// p
0x08, 0x14, 0x14, 0x18, 0x7C, 0x00,	// q
0x7C, 0x08, 0x04, 0x04, 0x08, 0x00,	// r
0x48, 0x54, 0x54, 0x54, 0x20, 0x00,	// s
0x04, 0x3F, 0x44, 0x40, 0x20, 0x00,	// t
0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00,	// u
0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,	// v
0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00,	// w
0x44, 0x28, 0x10, 0x28, 0x44, 0x00,	// x
0x0C, 0x50, 0x50, 0x50, 0x3C, 0x00,	// y
0x44, 0x64, 0x54, 0x4C, 0x44, 0x00,	// z
0x00, 0x08, 0x36, 0x41, 0x00, 0x00,	// {
0x00, 0x00, 0x7F, 0x00, 0x00, 0x00,	// |
0x00, 0x41, 0x36, 0x08, 0x00, 0x00,	// }
0x00, 0x01, 0x02, 0x00, 0x00, 0x00	// ` index 94
};

//=======================================================================//
//= Function implementation.										    =//
//=======================================================================//
/*************************************************************************/
/** Function Name:	GUI_DrawPoint										**/
/** Purpose:		Set a pixel color or draw a point.					**/
/** Resources:		None.												**/
/** Params:																**/
/**	@uiPosX:			X location of point by pixels.					**/
/**	@uiPosY:			Y location of point by pixels.					**/
/**	@uiColor:			Point color, GUI_COLOR_BKGCLR means clear pix, 	**/
/**						GUI_COLOR_FRGCLR means set pix.					**/
/** Return:			None.												**/
/*************************************************************************/
void SGUI_Basic_DrawPoint(SGUI_UINT uiPosX, SGUI_UINT uiPosY, SGUI_COLOR eColor)
{
	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if((uiPosX < LCD_SIZE_WIDTH) && (uiPosY < LCD_SIZE_HEIGHT))
	{
		if(GUI_COLOR_FRGCLR == eColor)
		{
#ifdef _SIMPLE_GUI_ENABLE_SIMULATOR_
			VTIF_SetPoint(uiPosX, uiPosY, 1);
#else
			// Call draw pix interface here.
#endif //_SIMPLE_GUI_ENABLE_SIMULATOR_
		}
		else if(GUI_COLOR_BKGCLR == eColor)
		{
#ifdef _SIMPLE_GUI_ENABLE_SIMULATOR_
			VTIF_SetPoint(uiPosX, uiPosY, 0);
#else
			// Call draw pix interface here.
#endif //_SIMPLE_GUI_ENABLE_SIMULATOR_
		}
	}
}

/*************************************************************************/
/** Function Name:	GUI_Basic_GetPoint									**/
/** Purpose:		Get a pixel color .									**/
/** Resources:		None.												**/
/** Params:																**/
/**	@uiPosX:			X location of point by pixels.					**/
/**	@uiPosY:			Y location of point by pixels.					**/
/** Return:			None.												**/
/*************************************************************************/
SGUI_COLOR GUI_Basic_GetPoint(SGUI_UINT uiPosX, SGUI_UINT uiPosY)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_COLOR					eColor;
	SGUI_UINT					uiPixValue;

	/*----------------------------------*/
	/* Initialize						*/
	/*----------------------------------*/
	eColor =					GUI_COLOR_BKGCLR;
	uiPixValue =				0;

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if((uiPosX < LCD_SIZE_WIDTH) && (uiPosY < LCD_SIZE_HEIGHT))
	{
#ifdef _SIMPLE_GUI_ENABLE_SIMULATOR_
		uiPixValue = VTIF_GetPoint(uiPosX, uiPosY);
#else
		// Call read pix interface here.
#endif //_SIMPLE_GUI_ENABLE_SIMULATOR_
		if(0 == uiPixValue)
		{
			eColor = GUI_COLOR_BKGCLR;
		}
		else
		{
			eColor = GUI_COLOR_FRGCLR;
		}
	}

	return eColor;
}

/*************************************************************************/
/** Function Name:	SGUI_Basic_ClearScreen								**/
/** Purpose:		Clean LCD screen display.							**/
/** Resources:		None.												**/
/** Params:			None.												**/
/** Return:			None.												**/
/*************************************************************************/
void SGUI_Basic_ClearScreen(void)
{
	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
#ifdef _SIMPLE_GUI_ENABLE_SIMULATOR_
	VTIF_ClearScreen();
#else
	// Call clear screen function here;
#endif //_SIMPLE_GUI_ENABLE_SIMULATOR_
}

/*************************************************************************/
/** Function Name:	GUI_DrawLine										**/
/** Purpose:		Draw a line by the Bresenham algorithm.				**/
/** Resources:		None.												**/
/** Params:																**/
/**	@uiStartX:			X coordinate of start point of line.			**/
/**	@uiStartY:			Y coordinate of start point of line.			**/
/**	@uiEndX:			X coordinate of end point of line.				**/
/**	@uiEndY:			Y coordinate of end point of line.				**/
/**	@ui_Color:			Line color.										**/
/** Return:			None.												**/
/*************************************************************************/
void SGUI_Basic_DrawLine(SGUI_UINT uiStartX, SGUI_UINT uiStartY, SGUI_UINT uiEndX, SGUI_UINT uiEndY, SGUI_COLOR eColor)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_INT					iDx, iDy;
	SGUI_INT					iIncX, iIncY;
	SGUI_INT					iErrX = 0, iErrY = 0;
	SGUI_UINT					i, uiDs;
	SGUI_UINT					uiCurrentPosX, uiCurrentPosY;

	/*----------------------------------*/
	/* Initialize						*/
	/*----------------------------------*/
	iErrX = 0;
	iErrY = 0;
    iDx = uiEndX - uiStartX;
    iDy = uiEndY - uiStartY;
	uiCurrentPosX = uiStartX;
	uiCurrentPosY = uiStartY;

	if(iDx > 0)
	{
		iIncX = 1;
	}
	else
	{
		if(iDx == 0)
		{
			iIncX = 0;
		}
		else
		{
			iIncX = -1;
			iDx = -iDx;
		}
	}

	if(iDy > 0)
	{
		iIncY = 1;
	}
	else
	{
		if(iDy == 0)
		{
			iIncY = 0;
		}
		else
		{
			iIncY = -1;
			iDy = -iDy;
		}
	}

	if(iDx > iDy)
	{
		uiDs = iDx;
	}
	else
	{
		uiDs = iDy;
	}

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	for(i = 0; i <= uiDs+1; i++)
	{
		SGUI_Basic_DrawPoint(uiCurrentPosX,uiCurrentPosY, eColor);
		iErrX += iDx;
		if(iErrX > uiDs)
		{
			iErrX -= uiDs;
			uiCurrentPosX += iIncX;
		}
		iErrY += iDy;
		if(iErrY > uiDs)
		{
			iErrY -= uiDs;
			uiCurrentPosY += iIncY;
		}
	}
}

/*************************************************************************/
/** Function Name:	GUI_DrawRectangle									**/
/** Purpose:		Draw a SGUI_RECT_AREA by upper left coordinate, 	**/
/**					width and height.									**/
/** Resources:		None.												**/
/** Params:																**/
/**	@pBitMapData:		Bitmap data array pointer.						**/
/**	@uiPosColumn:		Column position of display upper left point.	**/
/**	@uiPosPage:			Page Position of display upper left point.		**/
/**	@uidColumn:			Size of Bitmap by column.						**/
/**	@uidPage:			Size of Bitmap by Page.							**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void SGUI_Basic_DrawRectangle(SGUI_UINT uiStartX, SGUI_UINT uiStartY, SGUI_UINT uiWidth, SGUI_UINT uiHeight, SGUI_COLOR eEdgeColor, SGUI_COLOR eFillColor)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_UINT					uiColumnIndex;

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if((uiWidth > 0) && (uiHeight > 0))
	{
		if((uiWidth == 1) && (uiHeight == 1))
		{
			SGUI_Basic_DrawPoint(uiStartX, uiStartY, eEdgeColor);
		}
		else if(uiWidth == 1)
		{
			SGUI_Basic_DrawLine(uiStartX, uiStartY, uiStartX, uiStartY+uiHeight-1, eEdgeColor);
		}
		else if(uiHeight == 1)
		{
			SGUI_Basic_DrawLine(uiStartX, uiStartY, uiStartX+uiWidth-1, uiStartY, eEdgeColor);
		}
		else
		{
			// Draw edge.
			// Check and set changed page and column index is in edge display action.
			SGUI_Basic_DrawLine(uiStartX, uiStartY, uiStartX, uiStartY+uiHeight-1, eEdgeColor);
			SGUI_Basic_DrawLine(uiStartX+uiWidth-1, uiStartY, uiStartX+uiWidth-1, uiStartY+uiHeight-1, eEdgeColor);
			SGUI_Basic_DrawLine(uiStartX, uiStartY, uiStartX+uiWidth-1, uiStartY, eEdgeColor);
			SGUI_Basic_DrawLine(uiStartX, uiStartY+uiHeight-1, uiStartX+uiWidth-1, uiStartY+uiHeight-1, eEdgeColor);
			// Fill area.
			if((eFillColor != GUI_COLOR_TRANS) && (uiWidth > 2) && (uiHeight > 2))
			{
				for(uiColumnIndex=(uiStartX+1); uiColumnIndex<(uiStartX+uiWidth-1); uiColumnIndex++)
				{
					SGUI_Basic_DrawLine(uiColumnIndex, uiStartY+1, uiColumnIndex, uiStartY+uiHeight-2, eFillColor);
				}
			}
		}
	}
}

/*************************************************************************/
/** Function Name:	GUI_DrawCircle										**/
/** Purpose:		Draw a circle by circle center positon and radius.	**/
/** Resources:		None.												**/
/** Params:																**/
/**	@uiCx:				Circle center X coordinate.						**/
/**	@uiCy:				Circle center Y coordinate.						**/
/**	@uiRadius:			Circle radius.									**/
/**	@eEdgeColor:		Circle edge color.								**/
/**	@eFillColor:		Circle fill color.								**/
/** Return:			None.												**/
/*************************************************************************/
void SGUI_Basic_DrawCircle(SGUI_UINT uiCx, SGUI_UINT uiCy, SGUI_UINT uiRadius, SGUI_COLOR eEdgeColor, SGUI_COLOR eFillColor)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_UINT					uiPosXOffset, uiPosYOffset;
	SGUI_UINT					uiPosXOffset_Old, uiPosYOffset_Old;
	SGUI_INT					iXChange, iYChange, iRadiusError;

	/*----------------------------------*/
	/* Initialize						*/
	/*----------------------------------*/
	uiPosXOffset				= uiRadius;
	uiPosYOffset				= 0;
	uiPosXOffset_Old			= 0xFFFF;
	uiPosYOffset_Old			= 0xFFFF;
	iXChange					= 1 - 2 * uiRadius;
	iYChange					= 1;
	iRadiusError				= 0;

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if(uiRadius < 1)
	{
		SGUI_Basic_DrawPoint(uiCx, uiCy, eEdgeColor);
	}
	else
	{
		while(uiPosXOffset >= uiPosYOffset)
		{
			if((uiPosXOffset_Old != uiPosXOffset) || (uiPosYOffset_Old != uiPosYOffset) )
			{
				// Fill the circle
				if((uiRadius > 1) && (eFillColor != GUI_COLOR_TRANS) && (uiPosXOffset_Old != uiPosXOffset))
				{

					SGUI_Basic_DrawLine(uiCx-uiPosXOffset, uiCy-uiPosYOffset+1, uiCx-uiPosXOffset, uiCy+uiPosYOffset-1, eFillColor);
					SGUI_Basic_DrawLine(uiCx+uiPosXOffset, uiCy-uiPosYOffset+1, uiCx+uiPosXOffset, uiCy+uiPosYOffset-1, eFillColor);
					uiPosXOffset_Old = uiPosXOffset;
				}
				SGUI_Basic_DrawLine(uiCx-uiPosYOffset, uiCy-uiPosXOffset+1, uiCx-uiPosYOffset, uiCy+uiPosXOffset-1, eFillColor);
				SGUI_Basic_DrawLine(uiCx+uiPosYOffset, uiCy-uiPosXOffset+1, uiCx+uiPosYOffset, uiCy+uiPosXOffset-1, eFillColor);
				uiPosYOffset_Old = uiPosYOffset;

				// Draw edge.
				SGUI_Basic_DrawPoint(uiCx+uiPosXOffset, uiCy+uiPosYOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx-uiPosXOffset, uiCy+uiPosYOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx-uiPosXOffset, uiCy-uiPosYOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx+uiPosXOffset, uiCy-uiPosYOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx+uiPosYOffset, uiCy+uiPosXOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx-uiPosYOffset, uiCy+uiPosXOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx-uiPosYOffset, uiCy-uiPosXOffset, eEdgeColor);
				SGUI_Basic_DrawPoint(uiCx+uiPosYOffset, uiCy-uiPosXOffset, eEdgeColor);
			}
			uiPosYOffset++;
			iRadiusError += iYChange;
			iYChange += 2;
			if ((2 * iRadiusError + iXChange) > 0)
			{
				uiPosXOffset--;
				iRadiusError += iXChange;
				iXChange += 2;
			}
		}
	}
}

/*************************************************************************/
/** Function Name:	GUI_ReverseBlockColor								**/
/** Purpose:		Reverse color in a SGUI_RECT_AREA area.				**/
/** Resources:		None.												**/
/** Params:																**/
/**	@uiPosX:			Upper left X coordinate of SGUI_RECT_AREA area.	**/
/**	@uiPosY:			Upper left Y coordinate of SGUI_RECT_AREA area.	**/
/**	@uiWidth:			SGUI_RECT_AREA area width.						**/
/**	@uiHeight:			SGUI_RECT_AREA area Height.						**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void SGUI_Basic_ReverseBlockColor(SGUI_UINT uiStartX, SGUI_UINT uiStartY, SGUI_UINT uiWidth, SGUI_UINT uiHeight)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_UINT					i_W, i_H;

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	for(i_W=0; i_W<uiWidth; i_W++)
	{
        for(i_H=0; i_H<uiHeight; i_H++)
		{
			if(GUI_Basic_GetPoint(uiStartX+i_W, uiStartY+i_H) == GUI_COLOR_FRGCLR)
			{
                SGUI_Basic_DrawPoint(uiStartX+i_W, uiStartY+i_H, GUI_COLOR_BKGCLR);
			}
			else
			{
				SGUI_Basic_DrawPoint(uiStartX+i_W, uiStartY+i_H, GUI_COLOR_FRGCLR);
			}
		}
	}
}

/*************************************************************************/
/** Function Name:	SGUI_Basic_DrawBitMap								**/
/** Purpose:		Draw a rectangular area bit map on LCD screen.		**/
/** Resources:		Bit map data.										**/
/** Params:																**/
/**	@pstDisplayArea:	Display area position and size.					**/
/**	@pstDataArea:		Data area size and display offset.				**/
/**	@pDataBuffer:		Bit map data buffer.							**/
/**	@eDrawMode			Bit map display mode(normal or reverse color).	**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void SGUI_Basic_DrawBitMap(SGUI_RECT_AREA* pstDisplayArea, SGUI_RECT_AREA* pstDataArea, SGUI_BYTE* pDataBuffer, SGUI_DRAW_MODE eDrawMode)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_INT					iDrawPixX, iDrawPixY;
	SGUI_INT					iBmpPixX, iBmpPixY;
	SGUI_UINT					uiDrawnWidthIndex, uiDrawnHeightIndex;
	SGUI_UINT					uiPixIndex;
	SGUI_BYTE*					pData;

	/*----------------------------------*/
	/* Initialize						*/
	/*----------------------------------*/
	uiDrawnWidthIndex			= 0;
	uiDrawnHeightIndex			= 0;

	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	// Only draw in visible area of screen.
	if(	(RECTANGLE_X_START(*pstDisplayArea) < LCD_SIZE_WIDTH) && (RECTANGLE_Y_START(*pstDisplayArea) < LCD_SIZE_HEIGHT) &&
		(RECTANGLE_X_END(*pstDisplayArea) > 0) && (RECTANGLE_Y_END(*pstDisplayArea) > 0))
	{
		// Recalculate display area and data area.
		if(RECTANGLE_X_START(*pstDisplayArea) < 0)
		{
			RECTANGLE_X_START(*pstDataArea) += RECTANGLE_X_START(*pstDisplayArea);
			RECTANGLE_WIDTH(*pstDisplayArea) += RECTANGLE_X_START(*pstDisplayArea);
			RECTANGLE_X_START(*pstDisplayArea) = 0;
		}
		if(RECTANGLE_Y_START(*pstDisplayArea) < 0)
		{
			RECTANGLE_Y_START(*pstDataArea) += RECTANGLE_Y_START(*pstDisplayArea);
			RECTANGLE_HEIGHT(*pstDisplayArea) += RECTANGLE_Y_START(*pstDisplayArea);
			RECTANGLE_Y_START(*pstDisplayArea) = 0;
		}
		// Only process drawing when valid display data existed
		if((RECTANGLE_VALID_WIDTH(*pstDataArea) > 0) && (RECTANGLE_VALID_HEIGHT(*pstDataArea) > 0))
		{
			// Set loop start parameter of x coordinate
			iDrawPixX = RECTANGLE_X_START(*pstDisplayArea);
			iBmpPixX = 0;
			if(RECTANGLE_X_START(*pstDataArea) > 0)
			{
				iDrawPixX += RECTANGLE_X_START(*pstDataArea);
			}
			else
			{
				iBmpPixX -= RECTANGLE_X_START(*pstDataArea);
			}
			uiDrawnWidthIndex = iBmpPixX;
			// Loop for x coordinate;
			while((uiDrawnWidthIndex<RECTANGLE_WIDTH(*pstDataArea)) && (iDrawPixX<=RECTANGLE_X_END(*pstDisplayArea)) && (iDrawPixX<LCD_SIZE_WIDTH))
			{
				// Redirect to data array for column.
				pData = pDataBuffer + iBmpPixX;
				// Set loop start parameter of y coordinate
				iDrawPixY = RECTANGLE_Y_START(*pstDisplayArea);
				iBmpPixY = 0;
				if(RECTANGLE_Y_START(*pstDataArea) > 0)
				{
					iDrawPixY += RECTANGLE_Y_START(*pstDataArea);
				}
				else
				{
					iBmpPixY -= RECTANGLE_Y_START(*pstDataArea);
				}
				uiDrawnHeightIndex = iBmpPixY;
				uiPixIndex = iBmpPixY % 8;
				pData += (iBmpPixY / 8) * RECTANGLE_WIDTH(*pstDataArea);
				// Loop for y coordinate;
				while((uiDrawnHeightIndex<RECTANGLE_HEIGHT(*pstDataArea)) && (iDrawPixY<=RECTANGLE_Y_END(*pstDisplayArea)) && (iDrawPixY<LCD_SIZE_HEIGHT))
				{
					if(uiPixIndex == 8)
					{
						uiPixIndex = 0;
						pData += RECTANGLE_WIDTH(*pstDataArea);
					}
					if(GET_BIT(*pData, uiPixIndex) != eDrawMode)
					{
						SGUI_Basic_DrawPoint(iDrawPixX, iDrawPixY, GUI_COLOR_FRGCLR);
					}
					else
					{
						SGUI_Basic_DrawPoint(iDrawPixX, iDrawPixY, GUI_COLOR_BKGCLR);
					}
					uiDrawnHeightIndex ++;
					uiPixIndex ++;
					iDrawPixY ++;
					iBmpPixY ++;
				}
				uiDrawnWidthIndex ++;
				iDrawPixX ++;
				iBmpPixX ++;
			}
		}
	}
}
