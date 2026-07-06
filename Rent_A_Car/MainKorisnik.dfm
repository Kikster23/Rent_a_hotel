object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 375
  ClientWidth = 505
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object NovaRezervacija: TButton
    Left = 32
    Top = 40
    Width = 177
    Height = 49
    Caption = 'Nova rezervacija'
    TabOrder = 0
    OnClick = NovaRezervacijaClick
  end
  object MojeRezervacije: TButton
    Left = 32
    Top = 112
    Width = 177
    Height = 49
    Caption = 'Moje rezervacije'
    TabOrder = 1
    OnClick = MojeRezervacijeClick
  end
  object Ponuda: TButton
    Left = 32
    Top = 180
    Width = 177
    Height = 53
    Caption = 'Preuzmi ponudu hotela:'
    TabOrder = 2
    OnClick = PonudaClick
  end
  object Odjava: TButton
    Left = 352
    Top = 304
    Width = 121
    Height = 49
    Caption = 'Odjavi se '
    TabOrder = 3
    OnClick = OdjavaClick
  end
  object Info: TButton
    Left = 32
    Top = 260
    Width = 177
    Height = 53
    Caption = 'Informacije o recepcijama:'
    TabOrder = 4
    OnClick = InfoClick
  end
end
