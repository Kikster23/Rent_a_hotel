object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 400
  ClientWidth = 626
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object Label3: TLabel
    Left = 368
    Top = 16
    Width = 53
    Height = 15
    Caption = 'Aktivnost:'
  end
  object Label2: TLabel
    Left = 200
    Top = 16
    Width = 61
    Height = 15
    Caption = 'Korisnik_ID:'
  end
  object Label1: TLabel
    Left = 40
    Top = 16
    Width = 39
    Height = 15
    Caption = 'Datum:'
  end
  object EditAktivnost: TEdit
    Left = 368
    Top = 37
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object EditKorisnik: TEdit
    Left = 200
    Top = 37
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object DateTimeDatum: TDateTimePicker
    Left = 40
    Top = 37
    Width = 121
    Height = 23
    Date = 45908.000000000000000000
    Time = 0.082573217594472230
    TabOrder = 2
  end
  object Ucitaj: TButton
    Left = 40
    Top = 272
    Width = 97
    Height = 41
    Caption = 'U'#269'itaj logove'
    TabOrder = 3
    OnClick = UcitajClick
  end
  object Dodaj: TButton
    Left = 164
    Top = 272
    Width = 97
    Height = 41
    Caption = 'Dodaj logove'
    TabOrder = 4
    OnClick = DodajClick
  end
  object Izbriši: TButton
    Left = 288
    Top = 272
    Width = 97
    Height = 41
    Caption = 'Izbri'#353'i logove'
    TabOrder = 5
    OnClick = IzbrišiClick
  end
  object Uredi: TButton
    Left = 416
    Top = 272
    Width = 97
    Height = 41
    Caption = 'Uredi logove'
    TabOrder = 6
    OnClick = UrediClick
  end
  object Povratak: TButton
    Left = 503
    Top = 328
    Width = 106
    Height = 49
    Caption = 'Povratak'
    TabOrder = 7
    OnClick = PovratakClick
  end
  object ListView1: TListView
    Left = 40
    Top = 94
    Width = 265
    Height = 150
    Columns = <
      item
        Caption = 'Datum'
        Width = 80
      end
      item
        Caption = 'Korisnik_ID'
        Width = 80
      end
      item
        Caption = 'Aktivnost'
        Width = 80
      end>
    TabOrder = 8
    ViewStyle = vsReport
  end
  object XMLDocument1: TXMLDocument
    FileName = 'C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xml'
    Left = 440
    Top = 120
    DOMVendorDesc = 'MSXML'
  end
end
