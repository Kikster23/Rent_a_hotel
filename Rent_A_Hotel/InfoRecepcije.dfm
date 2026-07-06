object Form12: TForm12
  Left = 0
  Top = 0
  Caption = 'Form12'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 64
    Top = 40
    Width = 373
    Height = 45
    Caption = 'Informacije o recepcijama:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object ListView1: TListView
    Left = 64
    Top = 104
    Width = 457
    Height = 209
    Columns = <
      item
        Caption = 'Ime'
        Width = 80
      end
      item
        Caption = 'Grad'
        Width = 80
      end
      item
        Caption = 'Broj telefona'
        Width = 80
      end
      item
        Caption = 'Email'
        Width = 80
      end
      item
        Caption = 'Radno vrijeme'
        Width = 100
      end>
    TabOrder = 0
    ViewStyle = vsReport
  end
  object Povratak: TButton
    Left = 408
    Top = 352
    Width = 129
    Height = 49
    Caption = 'Povratak'
    TabOrder = 1
    OnClick = PovratakClick
  end
end
