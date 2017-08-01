#ifndef __HIFU_CAPTURE_H__
#define __HIFU_CAPTURE_H__
//#include <windows.h>

#define HIFU_CAPTURE_CUR_VERSION (1)
#define HIFU_CAPTURE_SIGNATURE "HiFuCapt"

/*
������ ����� ����������:
HiFu_CaptureHeaderCommon;
<�������� �������, ��. HiFu_CaptureHeaderCommon.HeaderPos>
HiFu_CaptureHeader
<�������� �������, ��. HiFu_CaptureHeader.ImagePos>
HiFu_CaptureHeader.NumImages x
	HiFu_CaptureImage
	<�������� �������, ��. HiFu_CaptureHeader.ImageBitmapOffset>
	BitmapArea
*/


// ��� ������������ - ��� MS Visual studio
#if defined(_MSC_VER)
#pragma pack (push,1)
#endif

// ����� ��������� ��� ���� ������ �������� ��������� ����� (�� ������ ��������)
typedef struct {
  char Signature[8];            // ��������� �����
  unsigned int Size;						// ������ ��������� ��������� (sizeof(HiFu_CaptureHeader))
  unsigned int Version;					// ����� ������ ���������
  unsigned int HeaderPos;				// �������� ��������� � �����
} HiFu_CaptureHeaderCommon;

// ��������� (����� ��������)
typedef struct {
  unsigned long	ImageWidth;					// ������ ����������� � ��������
  unsigned long	ImageHeight;				// ������ ����������� � ��������
  unsigned long	ImageLineSize;			// ����� ������ ����������� � ������ (��� ������������)
  unsigned long	ImageSize;					// ������ ������ ����� ��������, ������� ���������
  unsigned long	ImageBitmapOffset;	// �������� bitmap ������ ������� ��������
  unsigned long	ImagePos;           // ������ ������� �������� � �����
  unsigned int NumImages;           // ����� ��������
  unsigned int NumLeft;             // ���������� ����� �� ������������� (��������������� ����)
  unsigned int NumRight;            // ���������� ������ �� ������������� (��������������� ����)
  unsigned int CurNo;               // ����� ������� 
} HiFu_CaptureHeaderV1;

// ������ ������ ����������
typedef HiFu_CaptureHeaderV1 HiFu_CaptureHeader;

// ��������� ��������
typedef struct {
  UR_Coordinate Pos;					// ����� ������� �����
  double CenterShift;					// �������� �� ������������ �������� (������������� - �����)
} HiFu_CaptureImageV1;

// ������ ������ ����������
typedef HiFu_CaptureImageV1 HiFu_CaptureImage;


#if defined(_MSC_VER)
#pragma pack (pop)
#endif

#endif
