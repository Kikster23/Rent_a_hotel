object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Form9'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object Label1: TLabel
    Left = 32
    Top = 24
    Width = 62
    Height = 15
    Caption = ' Ime hotela:'
  end
  object Label2: TLabel
    Left = 32
    Top = 80
    Width = 28
    Height = 15
    Caption = 'Grad:'
  end
  object Label4: TLabel
    Left = 32
    Top = 138
    Width = 70
    Height = 15
    Caption = 'Broj telefona:'
  end
  object Label5: TLabel
    Left = 196
    Top = 24
    Width = 32
    Height = 15
    Caption = 'Email:'
  end
  object Label6: TLabel
    Left = 196
    Top = 80
    Width = 79
    Height = 15
    Caption = 'Radno vrijeme:'
  end
  object EditGrad: TEdit
    Left = 32
    Top = 101
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object EditVrijeme: TEdit
    Left = 196
    Top = 101
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object EditBrTel: TEdit
    Left = 32
    Top = 159
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object Ucitaj: TButton
    Left = 8
    Top = 368
    Width = 94
    Height = 41
    Caption = 'U'#269'itaj recepcije'
    TabOrder = 3
    OnClick = UcitajClick
  end
  object Dodaj: TButton
    Left = 119
    Top = 368
    Width = 130
    Height = 41
    Caption = 'Dodaj novu recepciju'
    TabOrder = 4
    OnClick = DodajClick
  end
  object Obrisi: TButton
    Left = 262
    Top = 368
    Width = 99
    Height = 41
    Caption = 'Obri'#353'i recepciju'
    TabOrder = 5
    OnClick = ObrisiClick
  end
  object Uredi: TButton
    Left = 380
    Top = 368
    Width = 101
    Height = 41
    Caption = 'Uredi recepciju'
    TabOrder = 6
    OnClick = UrediClick
  end
  object Povratak: TButton
    Left = 503
    Top = 384
    Width = 106
    Height = 49
    Caption = 'Povratak'
    TabOrder = 7
    OnClick = PovratakClick
  end
  object EditEmail: TEdit
    Left = 196
    Top = 45
    Width = 121
    Height = 23
    TabOrder = 8
  end
  object EditIme: TEdit
    Left = 32
    Top = 45
    Width = 121
    Height = 23
    TabOrder = 9
  end
  object ListView1: TListView
    Left = 32
    Top = 200
    Width = 417
    Height = 150
    Columns = <
      item
        Caption = 'Ime'
        Width = 70
      end
      item
        Caption = 'Grad'
        Width = 60
      end
      item
        Caption = 'Broj telefona'
        Width = 80
      end
      item
        Caption = 'Email'
        Width = 100
      end
      item
        Caption = 'Radno vrijeme'
        Width = 90
      end>
    TabOrder = 10
    ViewStyle = vsReport
  end
end
