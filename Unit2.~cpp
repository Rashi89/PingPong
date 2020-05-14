//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
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
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
     Form1->Visible = true;
     Form2->Visible = false;

}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
        Form2->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn3Click(TObject *Sender)
{
       Application->MessageBox("Gracz czerwony steruje klawiszami: W i S.\n"
		    "Gracz niebieski steruje klawiszami: strza³ka w górê i strza³ka w dó³ ","Sterowanie",
                    MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn4Click(TObject *Sender)
{
     Application->MessageBox("ZASADY\n"
                 "1. Ka¿dy z graczy steruje swoj¹ paletk¹.\n"
                 "2. Kiedy pi³ka odbije siê na brzegach paletki, wówczas\n"
                 "    pi³eczka zmieni k¹t odbicia i przyspieszy\n"
                 "3. Po 9 odbiciach pi³eczka przyspieszy\n","Zasady",MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

