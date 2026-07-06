object Form14: TForm14
  Left = 0
  Top = 0
  Caption = 'Form14'
  ClientHeight = 338
  ClientWidth = 418
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object Label3: TLabel
    Left = 24
    Top = 24
    Width = 43
    Height = 21
    Caption = 'Jezik:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 264
    Top = 24
    Width = 45
    Height = 21
    Caption = 'Tema:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 136
    Width = 87
    Height = 21
    Caption = 'Vrsta fonta:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 272
    Top = 136
    Width = 110
    Height = 21
    Caption = 'Veli'#269'ina fonta:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ComboJezik: TComboBox
    Left = 24
    Top = 51
    Width = 119
    Height = 23
    ItemIndex = 0
    TabOrder = 0
    Text = 'HR'
    Items.Strings = (
      'HR'
      'EN')
  end
  object ComboTema: TComboBox
    Left = 264
    Top = 51
    Width = 119
    Height = 23
    ItemIndex = 0
    TabOrder = 1
    Text = 'Svjetla'
    Items.Strings = (
      'Svjetla'
      'Tamna')
  end
  object ComboVrsta: TComboBox
    Left = 24
    Top = 171
    Width = 119
    Height = 23
    ItemIndex = 0
    TabOrder = 2
    Text = 'Arial'
    Items.Strings = (
      'Arial'
      'Calibri'
      'Helvetica')
  end
  object ComboVelicina: TComboBox
    Left = 272
    Top = 171
    Width = 119
    Height = 23
    TabOrder = 3
    Text = '8'
    Items.Strings = (
      '8'
      '10'
      '12'
      '')
  end
  object Button1: TButton
    Left = 238
    Top = 256
    Width = 153
    Height = 57
    Caption = 'Spremi postavke:'
    TabOrder = 4
    OnClick = Button1Click
  end
end
