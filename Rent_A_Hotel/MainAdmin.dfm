object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 342
  ClientWidth = 609
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object PregledKorisnika: TButton
    Left = 32
    Top = 32
    Width = 113
    Height = 57
    Caption = 'Pregled korisnika'
    TabOrder = 0
    OnClick = PregledKorisnikaClick
  end
  object PregledHotela: TButton
    Left = 184
    Top = 32
    Width = 105
    Height = 57
    Caption = 'Pregled hotela'
    TabOrder = 1
    OnClick = PregledHotelaClick
  end
  object PregledRezervacija: TButton
    Left = 328
    Top = 32
    Width = 121
    Height = 57
    Caption = 'Pregled rezervacija'
    TabOrder = 2
    OnClick = PregledRezervacijaClick
  end
  object PregledLogova: TButton
    Left = 487
    Top = 32
    Width = 106
    Height = 57
    Caption = 'Pregled logova'
    TabOrder = 3
    OnClick = PregledLogovaClick
  end
  object Odjava: TButton
    Left = 416
    Top = 272
    Width = 113
    Height = 41
    Caption = 'Odjavi se '
    TabOrder = 4
    OnClick = OdjavaClick
  end
  object PregledRecepcija: TButton
    Left = 32
    Top = 184
    Width = 113
    Height = 57
    Caption = 'Pregled recepcija'
    TabOrder = 5
    OnClick = PregledRecepcijaClick
  end
end
