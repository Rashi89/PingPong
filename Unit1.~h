//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Tlo;
        TImage *Paletka_Lewa;
        TImage *Paletka_Prawa;
        TImage *Pileczka;
        TTimer *poruszanie_pilki;
        TTimer *Gora_Lewa;
        TTimer *Dol_Lewa;
        TTimer *Dol_Prawa;
        TTimer *Gora_Prawa;
        TLabel *Label1;
        TButton *Button2;
        TLabel *Label2;
        TLabel *Label3;
        void __fastcall poruszanie_pilkiTimer(TObject *Sender);
        void __fastcall Gora_LewaTimer(TObject *Sender);
        void __fastcall Dol_LewaTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Gora_PrawaTimer(TObject *Sender);
        void __fastcall Dol_PrawaTimer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
