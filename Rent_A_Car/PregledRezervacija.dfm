object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Form7'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 27
    Width = 45
    Height = 15
    Caption = 'Korisnik:'
  end
  object Label2: TLabel
    Left = 24
    Top = 88
    Width = 32
    Height = 15
    Caption = 'Hotel:'
  end
  object Label5: TLabel
    Left = 225
    Top = 88
    Width = 18
    Height = 15
    Caption = 'Do:'
  end
  object Label4: TLabel
    Left = 224
    Top = 27
    Width = 19
    Height = 15
    Caption = 'Od:'
  end
  object ComboKorisnik: TComboBox
    Left = 24
    Top = 48
    Width = 145
    Height = 23
    TabOrder = 0
  end
  object ComboHotel: TComboBox
    Left = 24
    Top = 109
    Width = 145
    Height = 23
    TabOrder = 1
  end
  object Dodaj: TButton
    Left = 24
    Top = 368
    Width = 125
    Height = 41
    Caption = 'Dodaj novu rezervaciju'
    TabOrder = 2
    OnClick = DodajClick
  end
  object Obriši: TButton
    Left = 182
    Top = 368
    Width = 125
    Height = 41
    Caption = 'Obri'#353'i rezervaciju'
    TabOrder = 3
    OnClick = ObrišiClick
  end
  object DateTimeOd: TDateTimePicker
    Left = 224
    Top = 48
    Width = 113
    Height = 23
    Date = 45908.000000000000000000
    Time = 0.033329317127936520
    TabOrder = 4
  end
  object DateTimeDo: TDateTimePicker
    Left = 224
    Top = 109
    Width = 113
    Height = 23
    Date = 45908.000000000000000000
    Time = 0.033329317127936520
    TabOrder = 5
  end
  object Promijeni: TButton
    Left = 340
    Top = 368
    Width = 125
    Height = 41
    Caption = 'Promijeni rezervaciju'
    TabOrder = 6
    OnClick = PromijeniClick
  end
  object Povratak: TButton
    Left = 495
    Top = 384
    Width = 106
    Height = 49
    Caption = 'Povratak'
    TabOrder = 7
    OnClick = PovratakClick
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 176
    Width = 441
    Height = 169
    DataSource = DataSource1
    TabOrder = 8
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Korisnik_ID'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Hotel_ID'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Datum_OD'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Datum_DO'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Ukupna_Cijena'
        Width = 80
        Visible = True
      end>
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\Kiki\Docum' +
      'ents\Projekt_Joha_Ujevic\Joha_Ujevic.mdb;Persist Security Info=F' +
      'alse'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 424
    Top = 72
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Rezervacije'
    Left = 536
    Top = 72
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 544
    Top = 168
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 512
    Top = 224
  end
end
