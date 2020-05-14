//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

 int wspolrzedna_x = -8;
 int wspolrzedna_y = -8;
 int punkty_lewego = 0;
 int punkty_prawego = 0;
 int ilosc_odbic = 0;

 AnsiString punktacja_prawego="";
 AnsiString punktacja_lewego="";
 AnsiString suma_odbic="";

 
 AnsiString pokazWynik(AnsiString punktacja_lewego,AnsiString punktacja_prawego)
 {
   AnsiString punktacja="";
   punktacja = punktacja_lewego+":"+punktacja_prawego;
   return punktacja;
 }

 void reset(TImage * Pileczka, TTimer * poruszanie_pilki, TShape * Tlo,int punkty_lewego_gracza,int punkty_prawego_gracza, int ilosc_odbic_gracza,TImage *Paletka_Lewa, TImage *Paletka_Prawa)
 {
        ilosc_odbic=0;
        punkty_lewego=punkty_lewego_gracza;
        punkty_prawego=punkty_prawego_gracza;
        Pileczka->Left = Tlo->Width/2;
        Pileczka->Top = Tlo->Height/2;
        wspolrzedna_x = -8;
        wspolrzedna_y = -8;
        Paletka_Lewa->Top = 192;
        Paletka_Prawa->Top = 192;
        poruszanie_pilki->Interval = 20;
 }

 void totalny_reset(TShape *Tlo,TLabel * Label1, TLabel * Label2,TLabel * Label3, TButton * Button2,TImage *Pileczka, TImage *Paletka_Lewa, TImage *Paletka_Prawa, TTimer *poruszanie_pilki  )
{
           Button2->Visible = true;
           Pileczka->Visible = false;
           Paletka_Lewa->Visible = false;
           Paletka_Prawa->Visible =  false;
           poruszanie_pilki->Enabled = false;
           poruszanie_pilki->Interval = 20;
           wspolrzedna_x = -8;
           wspolrzedna_y = -8;
           punkty_lewego = 0;
           punkty_prawego = 0;
           ilosc_odbic = 0;
           Pileczka->Left = Tlo->Width/2;
           Pileczka->Top = Tlo->Height/2;
           Paletka_Lewa->Top = 192;
           Paletka_Prawa->Top = 192;
           punktacja_prawego="";
           punktacja_lewego="";
           suma_odbic="";
           Label1->Caption = "0:0 ";
           Label2->Caption = "Licznik odbic: 0 ";
           Label1->Visible = false;
           Label2->Visible = false;
           Label3->Visible = false;
}

bool decyzja()
{
   if(Application->MessageBox("Nast�pna runda?","Potwierd�",MB_YESNO|MB_ICONQUESTION)==IDYES)
                {
                        return true;
                }
      else
      {
                return false;
      }
}

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::poruszanie_pilkiTimer(TObject *Sender)
{
        Pileczka->Visible = true;

        Pileczka->Left += wspolrzedna_x;

        Pileczka->Top += wspolrzedna_y;


        if(Pileczka->Top <= Tlo->Top)
        {
          wspolrzedna_y = - wspolrzedna_y;
        }

        if(Pileczka->Top+Pileczka->Height >= Tlo->Top+Tlo->Height)
        {
          wspolrzedna_y = - wspolrzedna_y;
        }
        if(ilosc_odbic%3==0&&ilosc_odbic!=0)
        {
                if(poruszanie_pilki->Interval >= 19){
                    poruszanie_pilki->Interval = poruszanie_pilki->Interval-1;
                }
                else poruszanie_pilki->Interval = 20;
        }

        //skucha dla gracza lewego i prawego
        if(Pileczka->Left+Pileczka->Width < Paletka_Lewa->Left+Paletka_Lewa->Width-20)
        {
                poruszanie_pilki->Enabled = false;
                Pileczka->Visible = false;
                Label3->Caption ="Wygrywa gracz niebieski!";
                Label3->Visible = true;
                punkty_prawego +=1;
                punktacja_prawego = IntToStr(punkty_prawego);
                punktacja_lewego = IntToStr(punkty_lewego);
                Label1->Caption = pokazWynik(punktacja_lewego,punktacja_prawego);
                ilosc_odbic =0;
                Gora_Lewa->Enabled = false;
                Dol_Lewa->Enabled = false;
                Gora_Prawa->Enabled = false;
                Dol_Prawa->Enabled = false;

                if (decyzja()==false)
                {
                        totalny_reset(Tlo,Label1,Label2,Label3,Button2,Pileczka,Paletka_Lewa,Paletka_Prawa,poruszanie_pilki);
                        Form1->Close();
                }
                else {
                        Button2->Visible = true;
                        Label2->Caption = "Licznik odbic: 0 ";
                        reset(Pileczka,poruszanie_pilki,Tlo,punkty_lewego,punkty_prawego,ilosc_odbic,Paletka_Lewa,Paletka_Prawa);
                }
        }
        else if(Pileczka->Left > Paletka_Prawa->Left+Paletka_Prawa->Width+20)
        {      {
                poruszanie_pilki->Enabled = false;
                Pileczka->Visible = false;
                Label3->Caption ="Wygrywa gracz czerwony!";
                Label3->Visible = true;
                punkty_lewego +=1;
                punktacja_prawego = IntToStr(punkty_prawego);
                punktacja_lewego = IntToStr(punkty_lewego);
                Label1->Caption = pokazWynik(punktacja_lewego,punktacja_prawego);
                Gora_Lewa->Enabled = false;
                Dol_Lewa->Enabled = false;
                Gora_Prawa->Enabled = false;
                Dol_Prawa->Enabled = false;
                if (decyzja()==false)
                {
                        totalny_reset(Tlo,Label1,Label2,Label3,Button2,Pileczka,Paletka_Lewa,Paletka_Prawa,poruszanie_pilki);
                        Form1->Close();
                }
                else
                {
                Button2->Visible = true;
                Label2->Caption = "Licznik odbic: 0 ";
                reset(Pileczka,poruszanie_pilki,Tlo,punkty_lewego,punkty_prawego,ilosc_odbic,Paletka_Lewa,Paletka_Prawa);
                }
                }
        }
        else if(Pileczka->Left < Paletka_Lewa->Left)
                   {
                        if(Paletka_Lewa->Top-Pileczka->Width/2 < Pileczka->Top && Paletka_Lewa->Top+Paletka_Lewa->Height+Pileczka->Width/2 > Pileczka->Top)
                           {
                           wspolrzedna_x=-wspolrzedna_x;
                           ilosc_odbic +=1;
                           suma_odbic = IntToStr(ilosc_odbic);
                           Label2->Caption = "Licznik odbic: "+suma_odbic;
                           }
                   }
       else if(Pileczka->Left+Pileczka->Width > Paletka_Prawa->Left)
        {
                           if(Paletka_Prawa->Top-Pileczka->Width/2 < Pileczka->Top+Pileczka->Height && Paletka_Prawa->Top+Paletka_Prawa->Height+Pileczka->Width/2 > Pileczka->Top+Pileczka->Height)
                           {
                           wspolrzedna_x=-1.5*wspolrzedna_x;
                           ilosc_odbic +=1;
                           suma_odbic = IntToStr(ilosc_odbic);
                           Label2->Caption = "Licznik odbic: "+suma_odbic;
                           }





                /*if(Pileczka->Top+Pileczka->Height/2 >= Paletka_Prawa->Top-Pileczka->Width/3 &&
                   Pileczka->Top+Pileczka->Height/2 <= Paletka_Prawa->Top+Paletka_Prawa->Height/5)
                   {
                             if(wspolrzedna_x>0){wspolrzedna_x= -1.5*wspolrzedna_x ;
                             ilosc_odbic +=1;
                             suma_odbic = IntToStr(ilosc_odbic);
                             Label2->Caption = "Licznik odbic: "+suma_odbic;}
                   }
                   else if(Pileczka->Top+Pileczka->Height/2 > Paletka_Prawa->Top+Paletka_Prawa->Height/5 &&
                           Pileczka->Top+Pileczka->Height/2 < Paletka_Prawa->Top+(4*Paletka_Prawa->Height)/5)
                           {
                                if(wspolrzedna_x>0){wspolrzedna_x =-wspolrzedna_x  ;
                                ilosc_odbic +=1;
                                suma_odbic = IntToStr(ilosc_odbic);
                                Label2->Caption = "Licznik odbic: "+suma_odbic;}
                           }
                   else if(Paletka_Prawa->Top+(4*Paletka_Prawa->Height)/5 <= Pileczka->Top+Pileczka->Height/2 &&
                           Pileczka->Top+Pileczka->Height/2 <= Paletka_Prawa->Top+Paletka_Prawa->Height+Pileczka->Width/2)
                           {
                                if(wspolrzedna_x>0){wspolrzedna_x = -1.5*wspolrzedna_x;
                                ilosc_odbic +=1;
                                suma_odbic = IntToStr(ilosc_odbic);
                                Label2->Caption = "Licznik odbic: "+suma_odbic;}
                           }*/
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Gora_LewaTimer(TObject *Sender)
{
        if(Paletka_Lewa->Top > 15) Paletka_Lewa -> Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Gora_PrawaTimer(TObject *Sender)
{
        if(Paletka_Prawa->Top > 15) Paletka_Prawa -> Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Dol_LewaTimer(TObject *Sender)
{
        if(Paletka_Lewa->Top+Paletka_Lewa->Height < Tlo->Top+Tlo->Height-15) Paletka_Lewa -> Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Dol_PrawaTimer(TObject *Sender)
{
       if(Paletka_Prawa->Top+Paletka_Prawa->Height < Tlo->Top+Tlo->Height-15) Paletka_Prawa -> Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'w' || Key == 'W') Gora_Lewa->Enabled = true;
        if(Key == 's' || Key == 'S') Dol_Lewa->Enabled = true;
        if(Key == VK_UP) Gora_Prawa->Enabled = true;
        if(Key == VK_DOWN) Dol_Prawa->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
         if(Key == 'w' || Key == 'W') Gora_Lewa->Enabled = false;
         if(Key == 's' || Key == 'S') Dol_Lewa->Enabled = false;
         if(Key == VK_UP) Gora_Prawa->Enabled = false;
         if(Key == VK_DOWN) Dol_Prawa->Enabled = false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     Pileczka->Visible = true;
     poruszanie_pilki->Enabled = true;
     Paletka_Lewa->Visible = true;
     Paletka_Prawa->Visible = true;
     Label1->Visible = true;
     Button2->Visible = false;
     Label2->Visible = true;
     Label3->Visible = false;
     ilosc_odbic=0;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
       Form2->Visible = true;
       totalny_reset(Tlo,Label1,Label2,Label3,Button2,Pileczka,Paletka_Lewa,Paletka_Prawa,poruszanie_pilki);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Button2->Visible=true;
        Pileczka->Visible = false;
        poruszanie_pilki->Enabled = false;
        Paletka_Lewa->Visible = false;
        Paletka_Prawa->Visible = false;
        Label1->Visible = false;
        Label2->Visible = false;

        wspolrzedna_x = -8;
        wspolrzedna_y = -8;
        punkty_lewego = 0;
        punkty_prawego = 0;
        ilosc_odbic = 0;

        punktacja_prawego="";
        punktacja_lewego="";

        Label1->Caption = "0:0";
        Label3->Visible = false;
}
//---------------------------------------------------------------------------



