/*************************************************************************/
/** Copyright.															**/
/** FileName: SGUI_ScrollBar.c											**/
/** Author: XuYulin,Jerry												**/
/** Description: Create and display a scrollbar on screen.				**/
/*************************************************************************/

//=======================================================================//
//= Include files.													    =//
//=======================================================================//
#include "SGUI_ScrollBar.h"

//=======================================================================//
//= Function define.										            =//
//=======================================================================//
/*************************************************************************/
/** Function Name:	SGUI_ScrollBar_Initialize							**/
/** Purpose:		Initialize a scroll bar structure.					**/
/** Params:																**/
/**	@ pstObj[in]:	Scroll bar object pointer.							**/
/**	@ pcstInitParam[in]: Initialize parameter data.						**/
/** Return:			None.												**/
/*************************************************************************/
void SGUI_ScrollBar_Initialize(SGUI_SCROLLBAR_STRUCT* pstObj, const SGUI_SCROLLBAR_PARAM* pcstInitParam)
{
	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if((NULL != pstObj) && (NULL != pcstInitParam))
	{
		SGUI_SystemIF_MemorySet(pstObj, 0x00, sizeof(SGUI_SCROLLBAR_STRUCT));
		SGUI_SystemIF_MemoryCopy(&(pstObj->stParam), (void*)pcstInitParam, sizeof(SGUI_SCROLLBAR_PARAM));
	}
}

/*************************************************************************/
/** Function Name:	SGUI_ScrollBar_SetValue								**/
/** Purpose:		Initialize a scroll bar structure.					**/
/** Params:																**/
/**	@ pstObj[in]:	Scroll bar object pointer.							**/
/**	@ sNewValue[in]: New value will be set.								**/
/** Return:			None.												**/
/*************************************************************************/
void SGUI_ScrollBar_SetValue(SGUI_SCROLLBAR_STRUCT* pstObj, SGUI_SIZE sNewValue)
{
	if(NULL != pstObj)
	{
		if(sNewValue > pstObj->stParam.sMaxValue)
		{
			pstObj->stData.sValue = pstObj->stParam.sMaxValue;
		}
		else
		{
			pstObj->stData.sValue = sNewValue;
		}
	}
}

/*************************************************************************/
/** Function Name:	SGUI_ScrollBar_RefreshScrollBar						**/
/** Purpose:		Display or update a scroll bar.						**/
/** Resources:		Scroll bar data structure.							**/
/** Params:																**/
/** @ pstObj[in]:	Scroll bar data structure pointer.					**/
/** Return:			None.												**/
/** Notice:			None.												**/
/*************************************************************************/
void SGUI_ScrollBar_Repaint(SGUI_SCR_DEV* pstDeviceIF, SGUI_SCROLLBAR_STRUCT* pstObj)
{
	/*----------------------------------*/
	/* Variable Declaration				*/
	/*----------------------------------*/
	SGUI_INT					uiScrollBlockPos;
	SGUI_SIZE					uiScrollBlockSize;
	SGUI_SCROLLBAR_PALETTE*     pstPalette;

	/*----------------------------------*/
	/* Initialize						*/
	/*----------------------------------*/
	if(SGUI_SCROLLBAR_VERTICAL == pstObj->stParam.eDirection)
	{
		uiScrollBlockSize = pstObj->stParam.stLayout.iWidth-2;
	}
	else
	{
		uiScrollBlockSize = pstObj->stParam.stLayout.iHeight-2;
	}
    pstPalette = &pstObj->stParam.stPalette;
	/*----------------------------------*/
	/* Process							*/
	/*----------------------------------*/
	if(((pstObj->stParam.stLayout.iHeight > 2) && (pstObj->stParam.stLayout.iWidth > 2)) && (pstObj->stParam.stLayout.iHeight != pstObj->stParam.stLayout.iWidth))
	{
		// Check new value must be less then max value.
		if(pstObj->stData.sValue > pstObj->stParam.sMaxValue)
		{
			pstObj->stData.sValue = pstObj->stParam.sMaxValue;
		}
		// Check Palette depth is current depth
        if(pstPalette->uiDepthBits != pstDeviceIF->uiDepthBits)
        {
            pstPalette->eBackgroundColor    = SGUI_Basic_MapColor(pstPalette->uiDepthBits,pstPalette->eBackgroundColor,pstDeviceIF->uiDepthBits);
            pstPalette->eHandleColor        = SGUI_Basic_MapColor(pstPalette->uiDepthBits,pstPalette->eHandleColor,pstDeviceIF->uiDepthBits);
            pstPalette->eEdgeColor          = SGUI_Basic_MapColor(pstPalette->uiDepthBits,pstPalette->eEdgeColor,pstDeviceIF->uiDepthBits);
            pstPalette->uiDepthBits         = pstDeviceIF->uiDepthBits;
        }
		// Draw scroll bar edge.
		SGUI_Basic_DrawRectangle(pstDeviceIF, pstObj->stParam.stLayout.iX, pstObj->stParam.stLayout.iY,
									pstObj->stParam.stLayout.iWidth, pstObj->stParam.stLayout.iHeight,
									pstPalette->eEdgeColor, pstPalette->eBackgroundColor);

		if(SGUI_SCROLLBAR_VERTICAL == pstObj->stParam.eDirection)
		{
			// Value lower limit is 0, scroll blocks must be greater then 0.
			if(pstObj->stParam.sMaxValue > 0)
			{
				uiScrollBlockPos = pstObj->stParam.stLayout.iY+1+((pstObj->stParam.stLayout.iHeight-uiScrollBlockSize-2)*pstObj->stData.sValue/pstObj->stParam.sMaxValue);
				// Redraw process block
				SGUI_Basic_DrawRectangle(pstDeviceIF, pstObj->stParam.stLayout.iX+1, uiScrollBlockPos,
										uiScrollBlockSize, uiScrollBlockSize, pstPalette->eHandleColor, pstPalette->eHandleColor);
			}
			else
			{
				SGUI_Basic_DrawRectangle(pstDeviceIF, pstObj->stParam.stLayout.iX+1, pstObj->stParam.stLayout.iY+1,
										uiScrollBlockSize, uiScrollBlockSize, pstPalette->eHandleColor, pstPalette->eHandleColor);
			}
		}
		else // Horizontal
		{
			// Value lower limit is 0, scroll blocks must be greater then 0.
			if(pstObj->stParam.sMaxValue > 0)
			{
				uiScrollBlockPos = pstObj->stParam.stLayout.iX+1+((pstObj->stParam.stLayout.iWidth-uiScrollBlockSize-2)*pstObj->stData.sValue/pstObj->stParam.sMaxValue);
				// Redraw process block
				SGUI_Basic_DrawRectangle(pstDeviceIF, uiScrollBlockPos, pstObj->stParam.stLayout.iY+1,
										uiScrollBlockSize, uiScrollBlockSize, pstPalette->eHandleColor, pstPalette->eHandleColor);
			}
			else
			{
				SGUI_Basic_DrawRectangle(pstDeviceIF, pstObj->stParam.stLayout.iX+1, pstObj->stParam.stLayout.iY+1,
										uiScrollBlockSize, uiScrollBlockSize, pstPalette->eHandleColor, pstPalette->eHandleColor);
			}
		}
	}
}
