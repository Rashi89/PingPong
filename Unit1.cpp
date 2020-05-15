//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

 int wspolrzedna_x = -8;
 int wspolrzedna_y = -8;
 int punkty_lewego = 0;
 int punkty_prawego = 0;
 int ilosc_odbic = 0;
 int szybkosc = 20;

 AnsiString punktacja_prawego="";
 AnsiString punktacja_lewego="";
 AnsiString suma_odbic="";

 
 AnsiString pokazWynik(AnsiString punktacja_lewego,AnsiString punktacja_prawego)
 {
   AnsiString punktacja="";
   punktacja = punktacja_lewego+":"+punktacja_prawego;
   return punktacja;
 }
 int kto_zaczyna()
{
        randomize();
        if(random(4)==0) return 1;
        else if(random(4)==1) return 2;
        else if(random(4)==2) return 3;
        else if(random(4)==3) return 4;
}
 void reset(TImage * Pileczka, TTimer * poruszanie_pilki, TShape * Tlo,int punkty_lewego_gracza,int punkty_prawego_gracza, int ilosc_odbic_gracza,TImage *Paletka_Lewa, TImage *Paletka_Prawa)
 {
        ilosc_odbic=0;
        punkty_lewego=punkty_lewego_gracza;
        punkty_prawego=punkty_prawego_gracza;
        Pileczka->Left = Tlo->Width/2;
        Pileczka->Top = Tlo->Height/2;
        if(kto_zaczyna()==1)
        {
                wspolrzedna_x = 8;
                wspolrzedna_y = 8;
        }
        else if(kto_zaczyna()==2)
        {
                wspolrzedna_x = -8;
                wspolrzedna_y = 8;
        }
        else if(kto_zaczyna()==3)
        {
        wspolrzedna_x = -8;
        wspolrzedna_y = -8;
        }
        else if(kto_zaczyna()==4)
        {
                wspolrzedna_x = 8;
                wspolrzedna_y = -8;
        }
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
           if(kto_zaczyna()==1)
        {
                wspolrzedna_x = 8;
                wspolrzedna_y = 8;
        }
        else if(kto_zaczyna()==2)
        {
                wspolrzedna_x = -8;
                wspolrzedna_y = 8;
        }
        else if(kto_zaczyna()==3)
        {
        wspolrzedna_x = -8;
        wspolrzedna_y = -8;
        }
        else if(kto_zaczyna()==4)
        {
                wspolrzedna_x = 8;
                wspolrzedna_y = -8;
        }
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
   if(Application->MessageBox("Nastêpna runda?","PotwierdŸ",MB_YESNO|MB_ICONQUESTION)==IDYES)
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
        if(ilosc_odbic%9==0&&ilosc_odbic!=0)
        {
            switch (ilosc_odbic/9)
            {
             case 1: poruszanie_pilki->Interval = 15;
             break;
             case 2: poruszanie_pilki->Interval = 10;
             break;
             case 3: poruszanie_pilki->Interval = 8;
             break;
             case 4: poruszanie_pilki->Interval = 6;
             break;
             case 5: poruszanie_pilki->Interval = 4;
             break;
            }
        }
        if(wspolrzedna_x>40)
        {
           wspolrzedna_x = 20;
        }
        if(wspolrzedna_x<-40)
        {
         wspolrzedna_x = -20;
        }

        //skucha dla gracza lewego i prawego
        if(Pileczka->Left+Pileczka->Width < Paletka_Lewa->Left+Paletka_Lewa->Width-20)
        {
                poruszanie_pilki->Enabled = false;
                Pileczka->Visible = false;
                kto_wygrywa->Caption ="Wygrywa gracz niebieski!";
                kto_wygrywa->Visible = true;
                punkty_prawego +=1;
                punktacja_prawego = IntToStr(punkty_prawego);
                punktacja_lewego = IntToStr(punkty_lewego);
                wynik->Caption = pokazWynik(punktacja_lewego,punktacja_prawego);
                ilosc_odbic =0;
                Gora_Lewa->Enabled = false;
                Dol_Lewa->Enabled = false;
                Gora_Prawa->Enabled = false;
                Dol_Prawa->Enabled = false;

                if (decyzja()==false)
                {
                        if(punkty_lewego > punkty_prawego)
                        {
                          Form3->remis->Visible = false;
                          Form3->remis_ok->Visible = false;
                          Form3->czerwony_win->Visible = true;
                          Form3->czerwony_ok->Visible = true;
                          Form3->niebieski_win->Visible = false;
                          Form3->niebieski_ok->Visible = false;
                        }
                        else if(punkty_lewego < punkty_prawego)
                        {
                          Form3->remis->Visible = false;
                          Form3->remis_ok->Visible = false;
                          Form3->czerwony_win->Visible = false;
                          Form3->czerwony_ok->Visible = false;
                          Form3->niebieski_win->Visible = true;
                          Form3->niebieski_ok->Visible = true;
                        }
                        else if(punkty_lewego==punkty_prawego)
                        {
                          Form3->remis->Visible = true;
                          Form3->remis_ok->Visible = true;
                          Form3->czerwony_win->Visible = false;
                          Form3->czerwony_ok->Visible = false;
                          Form3->niebieski_win->Visible = false;
                          Form3->niebieski_ok->Visible = false;
                        }
                        Form3->ShowModal();
                        totalny_reset(Tlo,wynik,licznik,kto_wygrywa,start_gry,Pileczka,Paletka_Lewa,Paletka_Prawa,poruszanie_pilki);
                        Form1->Visible = false;
                        Form1->Close();
                }
                else {
                        start_gry->Visible = true;
                        licznik->Caption = "Licznik odbic: 0 ";
                        reset(Pileczka,poruszanie_pilki,Tlo,punkty_lewego,punkty_prawego,ilosc_odbic,Paletka_Lewa,Paletka_Prawa);
                }
        }
        else if(Pileczka->Left > Paletka_Prawa->Left+Paletka_Prawa->Width+20)
        {      {
                poruszanie_pilki->Enabled = false;
                Pileczka->Visible = false;
                kto_wygrywa->Caption ="Wygrywa gracz czerwony!";
                kto_wygrywa->Visible = true;
                punkty_lewego +=1;
                punktacja_prawego = IntToStr(punkty_prawego);
                punktacja_lewego = IntToStr(punkty_lewego);
                wynik->Caption = pokazWynik(punktacja_lewego,punktacja_prawego);
                Gora_Lewa->Enabled = false;
                Dol_Lewa->Enabled = false;
                Gora_Prawa->Enabled = false;
                Dol_Prawa->Enabled = false;
                if (decyzja()==false)
                {
                        if(punkty_lewego > punkty_prawego)
                        {
                          Form3->remis->Visible = false;
                          Form3->remis_ok->Visible = false;
                          Form3->czerwony_win->Visible = true;
                          Form3->czerwony_ok->Visible = true;
                          Form3->niebieski_win->Visible = false;
                          Form3->niebieski_ok->Visible = false;
                        }
                        else if(punkty_lewego < punkty_prawego)
                        {
                          Form3->remis->Visible = false;
                          Form3->remis_ok->Visible = false;
                          Form3->czerwony_win->Visible = false;
                          Form3->czerwony_ok->Visible = false;
                          Form3->niebieski_win->Visible = true;
                          Form3->niebieski_ok->Visible = true;
                        }
                        else if(punkty_lewego==punkty_prawego)
                        {
                          Form3->remis->Visible = true;
                          Form3->remis_ok->Visible = true;
                          Form3->czerwony_win->Visible = false;
                          Form3->czerwony_ok->Visible = false;
                          Form3->niebieski_win->Visible = false;
                          Form3->niebieski_ok->Visible = false;
                        }
                        Form3->ShowModal();
                        totalny_reset(Tlo,wynik,licznik,kto_wygrywa,start_gry,Pileczka,Paletka_Lewa,Paletka_Prawa,poruszanie_pilki);
                        Form1->Visible = false;
                        Form1->Close();
                }
                else
                {
                start_gry->Visible = true;
                licznik->Caption = "Licznik odbic: 0 ";
                reset(Pileczka,poruszanie_pilki,Tlo,punkty_lewego,punkty_prawego,ilosc_odbic,Paletka_Lewa,Paletka_Prawa);
                }
                }
        }
        else if(Pileczka->Left < Paletka_Lewa->Left)
                   {
                        if(Paletka_Lewa->Top-Pileczka->Width/2 < Pileczka->Top &&
                           Paletka_Lewa->Top+Paletka_Lewa->Height/4 > Pileczka->Top)
                           {
                                wspolrzedna_x=-wspolrzedna_x;
                                ilosc_odbic +=1;
                                suma_odbic = IntToStr(ilosc_odbic);
                                licznik->Caption = "Licznik odbic: "+suma_odbic;
                           }
                           else if(Paletka_Lewa->Top+Paletka_Lewa->Height/4 <= Pileczka->Top &&
                                   Paletka_Lewa->Top+(3*Paletka_Lewa->Height)/4 >= Pileczka->Top)
                                   {
                                        wspolrzedna_x=-1.5*wspolrzedna_x;
                                        ilosc_odbic +=1;
                                        suma_odbic = IntToStr(ilosc_odbic);
                                        licznik->Caption = "Licznik odbic: "+suma_odbic;
                                   }
                           else if(Paletka_Lewa->Top+(3*Paletka_Lewa->Height)/4 < Pileczka->Top &&
                                   Paletka_Lewa->Top+Paletka_Lewa->Height+Pileczka->Width/2 > Pileczka->Top)
                                   {
                                        wspolrzedna_x=-wspolrzedna_x;
                                        ilosc_odbic +=1;
                                        suma_odbic = IntToStr(ilosc_odbic);
                                        licznik->Caption = "Licznik odbic: "+suma_odbic;
                                   }
                   }
       else if(Pileczka->Left+Pileczka->Width > Paletka_Prawa->Left)
        {
                           if(Paletka_Prawa->Top-Pileczka->Width/2 < Pileczka->Top+Pileczka->Height
                           && Paletka_Prawa->Top+Paletka_Prawa->Height/4 > Pileczka->Top+Pileczka->Height)
                           {
                                wspolrzedna_x=-wspolrzedna_x;
                                ilosc_odbic +=1;
                                suma_odbic = IntToStr(ilosc_odbic);
                                licznik->Caption = "Licznik odbic: "+suma_odbic;
                           }
                           else if (Paletka_Prawa->Top+Paletka_Prawa->Height/4 <= Pileczka->Top+Pileczka->Height &&
                                    Paletka_Prawa->Top+(3*Paletka_Prawa->Height)/4 >= Pileczka->Top+Pileczka->Height)
                                    {
                                        wspolrzedna_x=-1.5*wspolrzedna_x;
                                        ilosc_odbic +=1;
                                        suma_odbic = IntToStr(ilosc_odbic);
                                        licznik->Caption = "Licznik odbic: "+suma_odbic;
                                    }
                           else if (Paletka_Prawa->Top+(3*Paletka_Prawa->Height)/4 < Pileczka->Top+Pileczka->Height &&
                                    Paletka_Prawa->Top+Paletka_Prawa->Height+Pileczka->Width/2 > Pileczka->Top+Pileczka->Height)
                                    {
                                        wspolrzedna_x=-wspolrzedna_x;
                                        ilosc_odbic +=1;
                                        suma_odbic = IntToStr(ilosc_odbic);
                                        licznik->Caption = "Licznik odbic: "+suma_odbic;
                                    }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Gora_LewaTimer(TObject *Sender)
{
        if(Paletka_Lewa->Top > 5) Paletka_Lewa -> Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Gora_PrawaTimer(TObject *Sender)
{
        if(Paletka_Prawa->Top > 5) Paletka_Prawa -> Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Dol_LewaTimer(TObject *Sender)
{
        if(Paletka_Lewa->Top+Paletka_Lewa->Height < Tlo->Top+Tlo->Height-5) Paletka_Lewa -> Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Dol_PrawaTimer(TObject *Sender)
{
       if(Paletka_Prawa->Top+Paletka_Prawa->Height < Tlo->Top+Tlo->Height-5) Paletka_Prawa -> Top +=10;
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

void __fastcall TForm1::start_gryClick(TObject *Sender)
{
     Pileczka->Visible = true;
     poruszanie_pilki->Enabled = true;
     Paletka_Lewa->Visible = true;
     Paletka_Prawa->Visible = true;
     wynik->Visible = true;
     start_gry->Visible = false;
     licznik->Visible = true;
     kto_wygrywa->Visible = false;
     ilosc_odbic=0;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
       Form2->Visible = true;
       totalny_reset(Tlo,wynik,licznik,kto_wygrywa,start_gry,Pileczka,Paletka_Lewa,Paletka_Prawa,poruszanie_pilki);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        start_gry->Visible=true;
        Pileczka->Visible = false;
        poruszanie_pilki->Enabled = false;
        Paletka_Lewa->Visible = false;
        Paletka_Prawa->Visible = false;
        wynik->Visible = false;
        licznik->Visible = false;

        if(kto_zaczyna()==1)
        {
                wspolrzedna_x = 8;
                wspolrzedna_y = 8;
        }
        else if(kto_zaczyna()==2)
        {
                wspolrzedna_x = -8;
                wspolrzedna_y = 8;
        }
        else if(kto_zaczyna()==3)
        {
        wspolrzedna_x = -8;
        wspolrzedna_y = -8;
        }
        else if(kto_zaczyna()==4)
        {
                wspolrzedna_x = 8;
                wspolrzedna_y = -8;
        }
        punkty_lewego = 0;
        punkty_prawego = 0;
        ilosc_odbic = 0;

        punktacja_prawego="";
        punktacja_lewego="";

        wynik->Caption = "0:0";
        kto_wygrywa->Visible = false;
}
//---------------------------------------------------------------------------




