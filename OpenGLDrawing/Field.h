#pragma once


// Field 对话框

class Field : public CDialogEx
{
	DECLARE_DYNAMIC(Field)

public:
	Field(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Field();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_point;
	int field;
	afx_msg void OnBnClickedOk();
};
