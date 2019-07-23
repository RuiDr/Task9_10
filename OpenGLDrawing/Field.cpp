// Field.cpp: 实现文件
//

#include "stdafx.h"
#include "OpenGLDrawing.h"
#include "Field.h"
#include "afxdialogex.h"


// Field 对话框

IMPLEMENT_DYNAMIC(Field, CDialogEx)

Field::Field(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_point(0)
	, field(0)
{
}

Field::~Field()
{
}

void Field::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_point);
	DDX_Text(pDX, IDC_EDIT2, field);
}


BEGIN_MESSAGE_MAP(Field, CDialogEx)
	ON_BN_CLICKED(IDOK, &Field::OnBnClickedOk)
END_MESSAGE_MAP()


// Field 消息处理程序
void Field::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_point=  GetDlgItemInt(IDC_EDIT1);
	field = GetDlgItemInt(IDC_EDIT2);
	CDialogEx::OnOK();
}
