//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::NowaGraMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
         Form1->Visible = true;
         Form2->Visible = false;
         Form3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SterowanieMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
             Application->MessageBox("Gracz czerwony steruje klawiszami: W i S.\n"
		    "Gracz niebieski steruje klawiszami: strza³ka w górê i strza³ka w dó³ ","Sterowanie",
                    MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ZasadyMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Application->MessageBox("ZASADY\n"
                 "1. Ka¿dy z graczy steruje swoj¹ paletk¹.\n"
                 "2. Kiedy pi³ka odbije siê na œrodku paletki, wówczas\n"
                 "    pi³eczka zmieni k¹t odbicia i przyspieszy\n"
                 "3. Po 9 odbiciach pi³eczka przyspieszy\n","Zasady",MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::KoniecMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
               Form2->Close();  
}
//---------------------------------------------------------------------------


