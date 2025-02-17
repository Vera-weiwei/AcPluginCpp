// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- PolaBeamUi.cpp : Implementation of CPolaBeamUi
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "PolaBeamUi.h"

//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC(CPolaBeamUi, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(CPolaBeamUi, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	ON_BN_CLICKED(IDC_BUTTON_PICKPILLAR, &CPolaBeamUi::OnBnClickedButtonPickpillar)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
CPolaBeamUi::CPolaBeamUi(CWnd* pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog(CPolaBeamUi::IDD, pParent, hInstance) {
}

//-----------------------------------------------------------------------------
void CPolaBeamUi::DoDataExchange(CDataExchange* pDX) {
	CAdUiBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BEAM_SN, Edit_Beam_Sn_);
	DDX_Control(pDX, IDC_EDIT_BEAM_B, Edit_Beam_b_);
	DDX_Control(pDX, IDC_EDIT_BEAM_H, Edit_Beam_h_);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT CPolaBeamUi::OnAcadKeepFocus(WPARAM, LPARAM) {
	return (TRUE);
}

void CPolaBeamUi::OnBnClickedButtonPickpillar()
{
	CString temp;
	Edit_Beam_Sn_.GetWindowTextW(temp);
	beam_sn = _wtoi(temp);

	Edit_Beam_b_.GetWindowTextW(temp);
	beam_b = _wtof(temp);

	Edit_Beam_h_.GetWindowTextW(temp);
	beam_h = _wtof(temp);

	AcDbObjectPointer<CPolaCustomBeam> beam;
	beam.create();
	if (beam.openStatus() != Acad::eOk)
	{
		return;
	}
	beam->setBeamProperty(beam_sn);
	beam->setBeamWidth(beam_b);
	beam->setBeamHeight(beam_h);
	CPolaCustomBeam::SelectPillarDrawBeam(beam);
}
