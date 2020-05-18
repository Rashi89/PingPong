//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TImage *Menu;
        TImage *Lapki;
        TShape *Shape1;
        TImage *lapka_czarna1;
        TImage *lapka_czerwona1;
        TImage *lapka_czerwona2;
        TImage *lapka_czarna2;
        TImage *NowaGra;
        TImage *Sterowanie;
        TImage *Zasady;
        TImage *Koniec;
        void __fastcall NowaGraMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall SterowanieMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ZasadyMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall KoniecMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);

private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
